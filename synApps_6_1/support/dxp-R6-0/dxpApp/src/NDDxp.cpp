/* NDDxp.cpp
 *
 * Driver for XIA DSP modules (Saturn, MicroDXP, xMAP, and Mercury 
 * 
 * Mark Rivers
 * University of Chicago
 *
 */

/* Standard includes... */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* EPICS includes */
#include <epicsString.h>
#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsEvent.h>
#include <epicsMutex.h>
#include <epicsExit.h>
#include <envDefs.h>
#include <iocsh.h>

/* Handel includes */
#include <handel.h>
#include <handel_errors.h>
#include <handel_generic.h>
#include <xerxes_generic.h>
#include <md_generic.h>
#include <handel_constants.h>

/* MCA includes */
#include <drvMca.h>

/* Area Detector includes */
#include <asynNDArrayDriver.h>

#define epicsExportSharedSymbols
#include "NDDxp.h"
#include <epicsExport.h>

#define MAX_CHANNELS_PER_CARD      4
#define DXP_ALL                   -1
#define MAX_MCA_BINS           16384
#define MCA_BIN_RES              256
#define DXP_MAX_SCAS              64
#define LEN_SCA_NAME              10
#define MAPPING_CLOCK_PERIOD     320e-9

/* It is much easier to define a maximum fixed number of low-level DXP parameters.
 * The actual maximum is currently 273 for the MicroDXP, so this is safe for now, and is
 * easy to increase in the future */
#define DXP_MAX_LL_PARAMS        300

/** < The maximum number of 16-bit words in the mapping mode buffer */
#define MAPPING_BUFFER_WORDS 1048576
#define MEGABYTE             1048576

#define CALLHANDEL( handel_call, msg ) { \
    xiastatus = handel_call; \
    status = this->xia_checkError( pasynUser, xiastatus, msg ); \
}

/** Only used for debugging/error messages to identify where the message comes from*/
static const char *driverName = "NDDxp";

typedef enum {
    NDDxpModelXMAP, 
    NDDxpModelMercury,
    NDDxpModelSaturn, 
    NDDxpModelMicroDXP
} NDDxpModel_t;

typedef enum {
    NDDxpModeMCA, 
    NDDxpModeSpectraMapping,
    NDDxpModeSCAMapping,
    NDDxpModeListMapping
} NDDxpCollectMode_t;

typedef enum {
    NDDxpListModeGate, 
    NDDxpListModeSync,
    NDDxpListModeClock
} NDDxpListMode_t;

typedef enum {
    NDDxpPresetModeNone,
    NDDxpPresetModeReal,
    NDDxpPresetModeLive,
    NDDxpPresetModeEvents,
    NDDxpPresetModeTriggers
} NDDxpPresetMode_t;

typedef enum {
    NDDxpPixelAdvanceGate,
    NDDxpPixelAdvanceSync,
} NDDxpPixelAdvanceMode_t;

typedef enum {
    NDDxpOutputDisabled,
    NDDxpOutputFastFilter,
    NDDxpOutputBaselineFilter,
    NDDxpOutputEnergyFilter,
    NDDxpOutputEnergyActive,
} NDDxpOutputMode_t;

typedef enum {
    NDDxpPreampReset,
    NDDxpPreampRC
} NDDxpPreamp_t;

typedef enum {
    NDDxpTraceADC, 
    NDDxpTraceBaselineHistory,
    NDDxpTraceTriggerFilter, 
    NDDxpTraceBaselineFilter, 
    NDDxpTraceEnergyFilter,
    NDDxpTraceBaselineSamples, 
    NDDxpTraceEnergySamples
} NDDxpTraceMode_t;

static const char *NDDxpTraceCommands[] = {"adc_trace", "baseline_history",
                                           "trigger_filter", "baseline_filter", "energy_filter",
                                           "baseline_samples", "energy_samples"};

static char *NDDxpBufferCharString[2]     = {"a", "b"};
static char *NDDxpBufferFullString[2]     = {"buffer_full_a", "buffer_full_b"};
static char *NDDxpBufferString[2]         = {"buffer_a", "buffer_b"};
static char *NDDxpListBufferLenString[2]  = {"list_buffer_len_a", "list_buffer_len_b"};

static char SCA_NameLow[DXP_MAX_SCAS][LEN_SCA_NAME];
static char SCA_NameHigh[DXP_MAX_SCAS][LEN_SCA_NAME];

/* These values are static because we need to access them in the qsort callback, 
 * no class reference available */
static unsigned short numLLParams;
static char *LLParamNames[DXP_MAX_LL_PARAMS];
static unsigned short LLParamValues[DXP_MAX_LL_PARAMS];
static int LLParamSort[DXP_MAX_LL_PARAMS];

typedef struct moduleStatistics {
    double realTime;
    double triggerLiveTime;
    double energyLiveTime;
    double triggers;
    double events;
    double icr;
    double ocr;
    double underflows;
    double overflows;
} moduleStatistics;

/* Mapping mode parameters */
#define NDDxpCollectModeString              "DxpCollectMode"
#define NDDxpListModeString                 "DxpListMode"
#define NDDxpPixelAdvanceModeString         "DxpPixelAdvanceMode"
#define NDDxpCurrentPixelString             "DxpCurrentPixel"
#define NDDxpNextPixelString                "DxpNextPixel"
#define NDDxpPixelsPerBufferString          "DxpPixelsPerBuffer"
#define NDDxpAutoPixelsPerBufferString      "DxpAutoPixelsPerBuffer"
#define NDDxpPixelsPerRunString             "DxpPixelsPerRun"
#define NDDxpBufferOverrunString            "DxpBufferOverrun"
#define NDDxpMBytesReadString               "DxpMBytesRead"
#define NDDxpReadRateString                 "DxpReadRate"
#define NDDxpIgnoreGateString               "DxpIgnoreGate"
#define NDDxpSyncCountString                "DxpSyncCount"
#define NDDxpInputLogicPolarityString       "DxpInputLogicPolarity"

/* Internal asyn driver parameters */
#define NDDxpErasedString                   "DxpErased"
#define NDDxpAcquiringString                "NDDxpAcquiring"  /* Internal use only !!! */
#define NDDxpBufferCounterString            "DxpBufferCounter"
#define NDDxpPollTimeString                 "DxpPollTime"
#define NDDxpForceReadString                "DxpForceRead"
#define NDDxpApplyString                    "DxpApply"
#define NDDxpAutoApplyString                "DxpAutoApply"

/* Diagnostic trace parameters */
#define NDDxpTraceModeString                "DxpTraceMode"
#define NDDxpTraceTimeString                "DxpTraceTime"
#define NDDxpNewTraceTimeString             "DxpNewTraceTime" /* Internal use only !!! */
#define NDDxpTraceDataString                "DxpTraceData"
#define NDDxpTraceTimeArrayString           "DxpTraceTimeArray"
#define NDDxpBaselineHistogramString        "DxpBaselineHistogram"
#define NDDxpBaselineEnergyString           "DxpBaselineEnergy" /* Internal use only !!! */
#define NDDxpBaselineEnergyArrayString      "DxpBaselineEnergyArray"

/* Runtime statistics */
#define NDDxpTriggerLiveTimeString          "DxpTriggerLiveTime"
#define NDDxpTriggersString                 "DxpTriggers"
#define NDDxpEventsString                   "DxpEvents"
#define NDDxpOverflowsString                "DxpOverflows"
#define NDDxpUnderflowsString               "DxpUnderflows"
#define NDDxpInputCountRateString           "DxpInputCountRate"
#define NDDxpOutputCountRateString          "DxpOutputCountRate"

/* High-level DXP parameters */
#define NDDxpPeakingTimeString              "DxpPeakingTime"
#define NDDxpDynamicRangeString             "DxpDynamicRange"
#define NDDxpTriggerThresholdString         "DxpTriggerThreshold"
#define NDDxpBaselineThresholdString        "DxpBaselineThreshold"
#define NDDxpEnergyThresholdString          "DxpEnergyThreshold"
#define NDDxpCalibrationEnergyString        "DxpCalibrationEnergy"
#define NDDxpADCPercentRuleString           "DxpADCPercentRule"
#define NDDxpMCABinWidthString              "DxpMCABinWidth"
#define NDDxpMaxEnergyString                "DxpMaxEnergy"
#define NDDxpPreampGainString               "DxpPreampGain"
#define NDDxpGainString                     "DxpGain"
#define NDDxpFineGainString                 "DxpFineGain"
#define NDDxpNumMCAChannelsString           "DxpNumMCAChannels"
#define NDDxpDetectorPolarityString         "DxpDetectorPolarity"
#define NDDxpResetDelayString               "DxpResetDelay"
#define NDDxpDecayTimeString                "DxpDecayTime"
#define NDDxpGapTimeString                  "DxpGapTime"
#define NDDxpTriggerPeakingTimeString       "DxpTriggerPeakingTime"
#define NDDxpTriggerGapTimeString           "DxpTriggerGapTime"
#define NDDxpBaselineAverageString          "DxpBaselineAverage"
#define NDDxpBaselineCutString              "DxpBaselineCut"
#define NDDxpEnableBaselineCutString        "DxpEnableBaselineCut"
#define NDDxpMaxWidthString                 "DxpMaxWidth"
#define NDDxpPresetModeString               "DxpPresetMode"
#define NDDxpPresetEventsString             "DxpPresetEvents"
#define NDDxpPresetTriggersString           "DxpPresetTriggers"
#define NDDxpSpectrumXAxisString            "DxpSpectrumXAxis"
#define NDDxpTriggerOutputString            "DxpTriggerOutput"
#define NDDxpLiveTimeOutputString           "DxpLiveTimeOutput"

/* SCA parameters */
#define NDDxpNumSCAsString                  "DxpNumSCAs"
#define NDDxpMaxSCAsString                  "DxpMaxSCAs"
/* For each SCA there are 3 parameters
  * DXPSCA$(N)Low
  * DXPSCA$(N)High
  * DXPSCA$(N)Counts
*/

/* INI file parameters */
#define NDDxpSaveSystemFileString           "DxpSaveSystemFile"
#define NDDxpSaveSystemString               "DxpSaveSystem"

/* Low-level DXP parameters */
#define NDDxpNumLLParamsString              "DxpNumLLParams"
#define NDDxpReadLLParamsString             "DxpReadLLParams"
/* For each low-level parameter
  * DxpLL_$(PARAM_NAME)
*/

class NDDxp : public asynNDArrayDriver
{
public:
    NDDxp(const char *portName, int nCChannels, int maxBuffers, size_t maxMemory);

    /* virtual methods to override from asynNDArrayDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
    virtual asynStatus readInt32Array(asynUser *pasynUser, epicsInt32 *value, size_t nElements, size_t *nIn);
    void report(FILE *fp, int details);

    /* Local methods to this class */
    asynStatus xia_checkError( asynUser* pasynUser, epicsInt32 xiastatus, const char *xiacmd );
    void shutdown();

    void acquisitionTask();
    asynStatus pollMappingMode();
    int getChannel(asynUser *pasynUser, int *addr);
    int getModuleType();
    asynStatus apply(int channel, int forceApply=0);
    asynStatus setPresets(asynUser *pasynUser, int addr);
    asynStatus setDxpParam(asynUser *pasynUser, int addr, int function, double value);
    asynStatus getDxpParams(asynUser *pasynUser, int addr);
    asynStatus setLLDxpParam(asynUser *pasynUser, int addr, int value);
    asynStatus getLLDxpParams(asynUser *pasynUser, int addr);
    asynStatus setSCAs(asynUser *pasynUser, int addr);
    asynStatus getSCAs(asynUser *pasynUser, int addr);
    asynStatus getSCAData(asynUser *pasynUser, int addr);
    asynStatus getAcquisitionStatus(asynUser *pasynUser, int addr);
    asynStatus getModuleStatistics(asynUser *pasynUser, int addr, moduleStatistics *stats);
    asynStatus getAcquisitionStatistics(asynUser *pasynUser, int addr);
    asynStatus getMcaData(asynUser *pasynUser, int addr);
    asynStatus getMappingData();
    asynStatus getTrace(asynUser* pasynUser, int addr,
                        epicsInt32* data, size_t maxLen, size_t *actualLen);
    asynStatus getBaselineHistogram(asynUser* pasynUser, int addr,
                        epicsInt32* data, size_t maxLen, size_t *actualLen);
    asynStatus configureCollectMode();
    asynStatus setNumChannels(asynUser *pasynUser, epicsInt32 newsize, epicsInt32 *rbValue);
    asynStatus startAcquiring(asynUser *pasynUser);
    asynStatus stopAcquiring(asynUser *pasynUser);

protected:
    /* Mapping mode parameters */
    int NDDxpCollectMode;                   /** < Change mapping mode (0=mca; 1=spectra mapping; 2=sca mapping) (int32 read/write) addr: all/any */
    #define FIRST_DXP_PARAM NDDxpCollectMode
    int NDDxpListMode;                      /** < Change list mode variant (0=Gate; 1=Sync; 2=Clock) (int32 read/write) addr: all/any */
    int NDDxpPixelAdvanceMode;              /** < Mapping mode only: pixel advance mode (int) */
    int NDDxpCurrentPixel;                  /** < Mapping mode only: read the current pixel that is being acquired into (int) */
    int NDDxpNextPixel;                     /** < Mapping mode only: force a pixel increment in the mapping buffer (write only int). Value is ignored. */
    int NDDxpPixelsPerBuffer;
    int NDDxpAutoPixelsPerBuffer;
    int NDDxpPixelsPerRun;                  /** < Preset value how many pixels to acquire in one run (r/w) mapping mode*/
    int NDDxpBufferOverrun;
    int NDDxpMBytesRead;
    int NDDxpReadRate;
    int NDDxpIgnoreGate;
    int NDDxpSyncCount;
    int NDDxpInputLogicPolarity;

    /* Internal asyn driver parameters */
    int NDDxpErased;               /** < Erased flag. (0=not erased; 1=erased) */
    int NDDxpAcquiring;            /** < Internal acquiring flag, not exposed via drvUser */
    int NDDxpBufferCounter;        /** < Count how many buffers have been collected (read) mapping mode */
    int NDDxpPollTime;             /** < Status/data polling time in seconds */
    int NDDxpForceRead;            /** < Force reading MCA spectra - used for mcaData when addr=ALL */
    int NDDxpApply;                /** < Force apply */
    int NDDxpAutoApply;            /** < Auto-apply */

    /* Diagnostic trace parameters */
    int NDDxpTraceMode;            /** < Select what type of trace to do: ADC, baseline hist, .. etc. */
    int NDDxpTraceTime;            /** < Set the trace sample time in us. */
    int NDDxpNewTraceTime;         /** < Flag indicating trace time changed */
    int NDDxpTraceData;            /** < The trace array data (read) */
    int NDDxpTraceTimeArray;       /** < The trace timebase array (read) */
    int NDDxpBaselineHistogram;    /** < The baseline histogram array data (read) */
    int NDDxpBaselineEnergy;       /** < The baseline histogram energy per bin (read) */
    int NDDxpBaselineEnergyArray;  /** < The baseline histogram energy array (read) */

    /* Runtime statistics */
    int NDDxpTriggerLiveTime;           /** < live time in seconds (double) */
    int NDDxpTriggers;                  /** < number of triggers received (double) */
    int NDDxpEvents;                    /** < total number of events registered (double) */
    int NDDxpOverflows;                 /** < number of overflows (double) */
    int NDDxpUnderflows;                /** < number of underflows (double) */
    int NDDxpInputCountRate;            /** < input count rate in Hz (double) */
    int NDDxpOutputCountRate;           /** < output count rate in Hz (double) */

    /* High-level DXP parameters */
    int NDDxpPeakingTime;
    int NDDxpDynamicRange;
    int NDDxpTriggerThreshold;
    int NDDxpBaselineThreshold;
    int NDDxpEnergyThreshold;
    int NDDxpCalibrationEnergy;
    int NDDxpADCPercentRule;
    int NDDxpMCABinWidth;
    int NDDxpMaxEnergy;            /** < Maximum energy */
    int NDDxpPreampGain;
    int NDDxpGain;
    int NDDxpFineGain;
    int NDDxpNumMCAChannels;
    int NDDxpDetectorPolarity;
    int NDDxpResetDelay;
    int NDDxpDecayTime;
    int NDDxpGapTime;
    int NDDxpTriggerPeakingTime;
    int NDDxpTriggerGapTime;
    int NDDxpBaselineAverage;
    int NDDxpBaselineCut;
    int NDDxpEnableBaselineCut;
    int NDDxpMaxWidth;
    int NDDxpPresetMode;
    int NDDxpPresetEvents;
    int NDDxpPresetTriggers;
    int NDDxpSpectrumXAxis;
    int NDDxpTriggerOutput;
    int NDDxpLiveTimeOutput;

    /* SCA parameters */
    int NDDxpMaxSCAs;
    int NDDxpNumSCAs;
    int NDDxpSCALow[DXP_MAX_SCAS];
    int NDDxpSCAHigh[DXP_MAX_SCAS];
    int NDDxpSCACounts[DXP_MAX_SCAS];

    /* INI file parameters */
    int NDDxpSaveSystemFile;
    int NDDxpSaveSystem;

    /* Commands from MCA interface */
    int mcaData;                   /* int32Array, write/read */
    int mcaStartAcquire;           /* int32, write */
    int mcaStopAcquire;            /* int32, write */
    int mcaErase;                  /* int32, write */
    int mcaReadStatus;             /* int32, write */
    int mcaChannelAdvanceSource;   /* int32, write */
    int mcaNumChannels;            /* int32, write */
    int mcaAcquireMode;            /* int32, write */
    int mcaSequence;               /* int32, write */
    int mcaPrescale;               /* int32, write */
    int mcaPresetSweeps;           /* int32, write */
    int mcaPresetLowChannel;       /* int32, write */
    int mcaPresetHighChannel;      /* int32, write */
    int mcaDwellTime;              /* float64, write/read */
    int mcaPresetLiveTime;         /* float64, write */
    int mcaPresetRealTime;         /* float64, write */
    int mcaPresetCounts;           /* float64, write */
    int mcaAcquiring;              /* int32, read */
    int mcaElapsedLiveTime;        /* float64, read */
    int mcaElapsedRealTime;        /* float64, read */
    int mcaElapsedCounts;          /* float64, read */

    /* Low-level DXP parameters */
    int NDDxpNumLLParams;
    int NDDxpReadLLParams;        /** < Force read of values of low-level parameters */
    int NDDxpLLParamNames[DXP_MAX_LL_PARAMS];
    int NDDxpLLParamVals[DXP_MAX_LL_PARAMS];

private:
    /* Data */
    unsigned long **pMcaRaw;
    unsigned long *pMapTemp;
    epicsUInt16 *pMapRaw;
    epicsFloat64 *tmpStats;

    NDDxpModel_t deviceType;
    NDDxpPreamp_t preampType;
    int nCards;
    int nChannels;
    int supportsMapping;
    int channelsPerCard;
    
    int numPeakingTimes;
    double *peakingTimes;

    epicsEvent *cmdStartEvent;
    epicsEvent *cmdStopEvent;
    epicsEvent *stoppedEvent;

    epicsUInt32 *currentBuf;
    int traceLength;
    int baselineLength;
    epicsInt32 *traceBuffer;
    epicsFloat64 *traceTimeBuffer;
    epicsInt32 *baselineBuffer;
    epicsFloat64 *baselineEnergyBuffer;
    epicsFloat64 *spectrumXAxisBuffer;
    
    moduleStatistics moduleStats[MAX_CHANNELS_PER_CARD];

    char polling;

};

static void c_shutdown(void* arg)
{
    NDDxp *pNDDxp = (NDDxp*)arg;
    pNDDxp->shutdown();
    free(pNDDxp);
}

static void acquisitionTaskC(void *drvPvt)
{
    NDDxp *pNDDxp = (NDDxp *)drvPvt;
    pNDDxp->acquisitionTask();
}

static int paramCompare(const void *p1, const void *p2)
{
    int ip1 = *(int *)p1;
    int ip2 = *(int *)p2;
    
    return(strcmp(LLParamNames[ip1], LLParamNames[ip2]));
}

extern "C" int NDDxpConfig(const char *portName, int nChannels,
                            int maxBuffers, size_t maxMemory)
{
    new NDDxp(portName, nChannels, maxBuffers, maxMemory);
    return 0;
}

/* Note: we use nChannels+1 for maxAddr because the last address is used for "all" channels" */
NDDxp::NDDxp(const char *portName, int nChannels, int maxBuffers, size_t maxMemory)
    : asynNDArrayDriver(portName, nChannels + 1, maxBuffers, maxMemory,
            asynInt32Mask | asynFloat64Mask | asynInt32ArrayMask | asynFloat64ArrayMask | asynGenericPointerMask | asynOctetMask | asynDrvUserMask,
            asynInt32Mask | asynFloat64Mask | asynInt32ArrayMask | asynFloat64ArrayMask | asynGenericPointerMask | asynOctetMask,
            ASYN_MULTIDEVICE | ASYN_CANBLOCK, 1, 0, 0)
{
    int status = asynSuccess;
    int i, ch;
    int sca;
    char tmpStr[MAX_DSP_PARAM_NAME_LEN + 10];
    int xiastatus = 0;
    unsigned short runTasks;
    unsigned long ulongTmp;
    const char *functionName = "NDDxp";

    this->nChannels = nChannels;

    /* Mapping mode parameters */
    createParam(NDDxpCollectModeString,            asynParamInt32,   &NDDxpCollectMode);
    createParam(NDDxpListModeString,               asynParamInt32,   &NDDxpListMode);
    createParam(NDDxpPixelAdvanceModeString,       asynParamInt32,   &NDDxpPixelAdvanceMode);
    createParam(NDDxpCurrentPixelString,           asynParamInt32,   &NDDxpCurrentPixel);
    createParam(NDDxpNextPixelString,              asynParamInt32,   &NDDxpNextPixel);
    createParam(NDDxpPixelsPerBufferString,        asynParamInt32,   &NDDxpPixelsPerBuffer);
    createParam(NDDxpAutoPixelsPerBufferString,    asynParamInt32,   &NDDxpAutoPixelsPerBuffer);
    createParam(NDDxpPixelsPerRunString,           asynParamInt32,   &NDDxpPixelsPerRun);
    createParam(NDDxpBufferOverrunString,          asynParamInt32,   &NDDxpBufferOverrun);
    createParam(NDDxpMBytesReadString,             asynParamFloat64, &NDDxpMBytesRead);
    createParam(NDDxpReadRateString,               asynParamFloat64, &NDDxpReadRate);
    createParam(NDDxpIgnoreGateString,             asynParamInt32,   &NDDxpIgnoreGate);
    createParam(NDDxpSyncCountString,              asynParamInt32,   &NDDxpSyncCount);
    createParam(NDDxpInputLogicPolarityString,     asynParamInt32,   &NDDxpInputLogicPolarity);

    /* Internal asyn driver parameters */
    createParam(NDDxpErasedString,                 asynParamInt32,   &NDDxpErased);
    createParam(NDDxpAcquiringString,              asynParamInt32,   &NDDxpAcquiring);
    createParam(NDDxpBufferCounterString,          asynParamInt32,   &NDDxpBufferCounter);
    createParam(NDDxpPollTimeString,               asynParamFloat64, &NDDxpPollTime);
    createParam(NDDxpForceReadString,              asynParamInt32,   &NDDxpForceRead);
    createParam(NDDxpApplyString,                  asynParamInt32,   &NDDxpApply);
    createParam(NDDxpAutoApplyString,              asynParamInt32,   &NDDxpAutoApply);

    /* Diagnostic trace parameters */
    createParam(NDDxpTraceModeString,              asynParamInt32,   &NDDxpTraceMode);
    createParam(NDDxpTraceTimeString,              asynParamFloat64, &NDDxpTraceTime);
    createParam(NDDxpNewTraceTimeString,           asynParamInt32,   &NDDxpNewTraceTime);
    createParam(NDDxpTraceDataString,              asynParamInt32Array, &NDDxpTraceData);
    createParam(NDDxpTraceTimeArrayString,         asynParamFloat64Array, &NDDxpTraceTimeArray);
    createParam(NDDxpBaselineHistogramString,      asynParamInt32Array, &NDDxpBaselineHistogram);
    createParam(NDDxpBaselineEnergyString,         asynParamFloat64, &NDDxpBaselineEnergy);
    createParam(NDDxpBaselineEnergyArrayString,    asynParamFloat64Array, &NDDxpBaselineEnergyArray);

    /* Runtime statistics */
    createParam(NDDxpTriggerLiveTimeString,        asynParamFloat64, &NDDxpTriggerLiveTime);
    createParam(NDDxpTriggersString,               asynParamInt32,   &NDDxpTriggers);
    createParam(NDDxpEventsString,                 asynParamInt32,   &NDDxpEvents);
    createParam(NDDxpOverflowsString,              asynParamInt32,   &NDDxpOverflows);
    createParam(NDDxpUnderflowsString,             asynParamInt32,   &NDDxpUnderflows);
    createParam(NDDxpInputCountRateString,         asynParamFloat64, &NDDxpInputCountRate);
    createParam(NDDxpOutputCountRateString,        asynParamFloat64, &NDDxpOutputCountRate);

    /* High-level DXP parameters */
    createParam(NDDxpPeakingTimeString,            asynParamFloat64, &NDDxpPeakingTime);
    createParam(NDDxpDynamicRangeString,           asynParamFloat64, &NDDxpDynamicRange);
    createParam(NDDxpTriggerThresholdString,       asynParamFloat64, &NDDxpTriggerThreshold);
    createParam(NDDxpBaselineThresholdString,      asynParamFloat64, &NDDxpBaselineThreshold);
    createParam(NDDxpEnergyThresholdString,        asynParamFloat64, &NDDxpEnergyThreshold);
    createParam(NDDxpCalibrationEnergyString,      asynParamFloat64, &NDDxpCalibrationEnergy);
    createParam(NDDxpADCPercentRuleString,         asynParamFloat64, &NDDxpADCPercentRule);
    createParam(NDDxpMCABinWidthString,            asynParamFloat64, &NDDxpMCABinWidth);
    createParam(NDDxpMaxEnergyString,              asynParamFloat64, &NDDxpMaxEnergy);
    createParam(NDDxpPreampGainString,             asynParamFloat64, &NDDxpPreampGain);
    createParam(NDDxpGainString,                   asynParamFloat64, &NDDxpGain);
    createParam(NDDxpFineGainString,               asynParamFloat64, &NDDxpFineGain);
    createParam(NDDxpNumMCAChannelsString,         asynParamInt32,   &NDDxpNumMCAChannels);
    createParam(NDDxpDetectorPolarityString,       asynParamInt32,   &NDDxpDetectorPolarity);
    createParam(NDDxpResetDelayString,             asynParamFloat64, &NDDxpResetDelay);
    createParam(NDDxpDecayTimeString,              asynParamFloat64, &NDDxpDecayTime);
    createParam(NDDxpGapTimeString,                asynParamFloat64, &NDDxpGapTime);
    createParam(NDDxpTriggerPeakingTimeString,     asynParamFloat64, &NDDxpTriggerPeakingTime);
    createParam(NDDxpTriggerGapTimeString,         asynParamFloat64, &NDDxpTriggerGapTime);
    createParam(NDDxpBaselineAverageString,        asynParamInt32,   &NDDxpBaselineAverage);
    createParam(NDDxpBaselineCutString,            asynParamFloat64, &NDDxpBaselineCut);
    createParam(NDDxpEnableBaselineCutString,      asynParamInt32,   &NDDxpEnableBaselineCut);
    createParam(NDDxpMaxWidthString,               asynParamFloat64, &NDDxpMaxWidth);
    createParam(NDDxpPresetModeString,             asynParamInt32,   &NDDxpPresetMode);
    createParam(NDDxpPresetEventsString,           asynParamInt32,   &NDDxpPresetEvents);
    createParam(NDDxpPresetTriggersString,         asynParamInt32,   &NDDxpPresetTriggers);
    createParam(NDDxpSpectrumXAxisString,          asynParamFloat64Array, &NDDxpSpectrumXAxis);
    createParam(NDDxpTriggerOutputString,          asynParamInt32,   &NDDxpTriggerOutput);
    createParam(NDDxpLiveTimeOutputString,         asynParamInt32,   &NDDxpLiveTimeOutput);

    /* SCA parameters */
    createParam(NDDxpNumSCAsString,                asynParamInt32,   &NDDxpNumSCAs);
    createParam(NDDxpMaxSCAsString,                asynParamInt32,   &NDDxpMaxSCAs);
    for (sca=0; sca<DXP_MAX_SCAS; sca++) {
        /* Create SCA name strings that Handel uses */
        sprintf(SCA_NameLow[sca],  "sca%d_lo", sca);
        sprintf(SCA_NameHigh[sca], "sca%d_hi", sca);
        /* Create asyn parameters for SCAs */
        sprintf(tmpStr, "DxpSCA%dLow", sca);
        createParam(tmpStr,                        asynParamInt32,   &NDDxpSCALow[sca]);
        sprintf(tmpStr, "DxpSCA%dHigh", sca);
        createParam(tmpStr,                        asynParamInt32,   &NDDxpSCAHigh[sca]);
        sprintf(tmpStr, "DxpSCA%dCounts", sca);
        createParam(tmpStr,                        asynParamInt32,   &NDDxpSCACounts[sca]);
    }

    /* INI file parameters */
    createParam(NDDxpSaveSystemFileString,         asynParamOctet,   &NDDxpSaveSystemFile);
    createParam(NDDxpSaveSystemString,             asynParamInt32,   &NDDxpSaveSystem);

    /* Commands from MCA interface */
    createParam(mcaDataString,                     asynParamInt32Array, &mcaData);
    createParam(mcaStartAcquireString,             asynParamInt32,   &mcaStartAcquire);
    createParam(mcaStopAcquireString,              asynParamInt32,   &mcaStopAcquire);
    createParam(mcaEraseString,                    asynParamInt32,   &mcaErase);
    createParam(mcaReadStatusString,               asynParamInt32,   &mcaReadStatus);
    createParam(mcaChannelAdvanceSourceString,     asynParamInt32,   &mcaChannelAdvanceSource);
    createParam(mcaNumChannelsString,              asynParamInt32,   &mcaNumChannels);
    createParam(mcaAcquireModeString,              asynParamInt32,   &mcaAcquireMode);
    createParam(mcaSequenceString,                 asynParamInt32,   &mcaSequence);
    createParam(mcaPrescaleString,                 asynParamInt32,   &mcaPrescale);
    createParam(mcaPresetSweepsString,             asynParamInt32,   &mcaPresetSweeps);
    createParam(mcaPresetLowChannelString,         asynParamInt32,   &mcaPresetLowChannel);
    createParam(mcaPresetHighChannelString,        asynParamInt32,   &mcaPresetHighChannel);
    createParam(mcaDwellTimeString,                asynParamFloat64, &mcaDwellTime);
    createParam(mcaPresetLiveTimeString,           asynParamFloat64, &mcaPresetLiveTime);
    createParam(mcaPresetRealTimeString,           asynParamFloat64, &mcaPresetRealTime);
    createParam(mcaPresetCountsString,             asynParamFloat64, &mcaPresetCounts);
    createParam(mcaAcquiringString,                asynParamInt32,   &mcaAcquiring);
    createParam(mcaElapsedLiveTimeString,          asynParamFloat64, &mcaElapsedLiveTime);
    createParam(mcaElapsedRealTimeString,          asynParamFloat64, &mcaElapsedRealTime);
    createParam(mcaElapsedCountsString,            asynParamFloat64, &mcaElapsedCounts);

    /* Low-level DXP parameters */
    status = xiaGetNumParams(0, &numLLParams);
    if (numLLParams > DXP_MAX_LL_PARAMS) {
        printf("Error: actual number of DXP params=%d, more than allowed maximum of %d\n", 
                numLLParams, DXP_MAX_LL_PARAMS);
    }
    for (i=0; i < numLLParams; i++) {
        LLParamNames[i] = (char *) malloc(MAX_DSP_PARAM_NAME_LEN * sizeof(char *));
        status = xiaGetParamName(0, i, LLParamNames[i]);
        LLParamSort[i] = i;
    }
    /* Sort the parameters in alphabetical order, much nicer to display */
    qsort(LLParamSort, numLLParams, sizeof(int), paramCompare);  

    createParam(NDDxpNumLLParamsString,            asynParamInt32,   &NDDxpNumLLParams);
    createParam(NDDxpReadLLParamsString,           asynParamInt32,   &NDDxpReadLLParams);
    for (i=0; i<DXP_MAX_LL_PARAMS; i++) {
        sprintf(tmpStr, "DxpLL%dName", i);
        createParam(tmpStr,                        asynParamOctet,   &NDDxpLLParamNames[i]);
        sprintf(tmpStr, "DxpLL%dVal", i);
        createParam(tmpStr,                        asynParamInt32,   &NDDxpLLParamVals[i]);
    }
    
    for (ch=0; ch<this->nChannels; ch++) {
        setIntegerParam(ch, NDDxpNumLLParams, numLLParams);
        for (i=0; i<numLLParams; i++) {
            setStringParam(ch, NDDxpLLParamNames[i], LLParamNames[LLParamSort[i]]);
        }
        for (i=numLLParams; i<DXP_MAX_LL_PARAMS; i++) {
            setStringParam(ch, NDDxpLLParamNames[i], "Unused");
            setIntegerParam(ch, NDDxpLLParamVals[i], 0);
        }
    }

    this->deviceType = (NDDxpModel_t) this->getModuleType();
    switch (this->deviceType)
    {
    case NDDxpModelXMAP:
        this->supportsMapping = 1;
        setIntegerParam(NDDxpMaxSCAs, 64);
        break;
    case NDDxpModelMercury:
        this->supportsMapping = 1;
        setIntegerParam(NDDxpMaxSCAs, 64);
        break;
    case NDDxpModelMicroDXP:
        this->supportsMapping = 0;
        setIntegerParam(NDDxpMaxSCAs, 16);
        break;
    case NDDxpModelSaturn:
        this->supportsMapping = 0;
        setIntegerParam(NDDxpMaxSCAs, 16);
        break;
    }
    /* TODO: this solution is a bit crude and not always correct... */
    this->nCards = ((this->nChannels-1) / this->channelsPerCard) + 1;
    
    /* Register the epics exit function to be called when the IOC exits... */
    xiastatus = epicsAtExit(c_shutdown, this);

    /* Set the parameters in param lib */
    status |= setIntegerParam(NDDxpCollectMode, 0);
    /* Clear the acquiring flag, must do this or things don't work right because acquisitionTask does not set till 
     * acquire first starts */
    for (i=0; i<=this->nChannels; i++) setIntegerParam(i, mcaAcquiring, 0);

    /* Create the start and stop events that will be used to signal our
     * acquisitionTask when to start/stop polling the HW     */
    this->cmdStartEvent = new epicsEvent();
    this->cmdStopEvent = new epicsEvent();
    this->stoppedEvent = new epicsEvent();

    /* Allocate a memory pointer for each of the channels */
    this->pMcaRaw = (unsigned long**) calloc(this->nChannels, sizeof(unsigned long*));
    /* Allocate a memory area for each spectrum */
    for (ch=0; ch<this->nChannels; ch++) {
        this->pMcaRaw[ch] = (unsigned long*)calloc(MAX_MCA_BINS, sizeof(unsigned long));
    }
    
    this->tmpStats = (epicsFloat64*)calloc(28, sizeof(epicsFloat64));
    this->currentBuf = (epicsUInt32*)calloc(this->nChannels, sizeof(epicsUInt32));

    xiastatus = xiaGetSpecialRunData(0, "adc_trace_length",  &(this->traceLength));
    if (xiastatus != XIA_SUCCESS) printf("Error calling xiaGetSpecialRunData for adc_trace_length");

    /* Allocate a buffer for the trace data */
    this->traceBuffer = (epicsInt32 *)malloc(this->traceLength * sizeof(epicsInt32));

    /* Allocate a buffer for the trace time array */
    this->traceTimeBuffer = (epicsFloat64 *)malloc(this->traceLength * sizeof(epicsFloat64));

    xiastatus = xiaGetRunData(0, "baseline_length", &ulongTmp);
    this->baselineLength = ulongTmp;
    if (xiastatus != XIA_SUCCESS) printf("Error calling xiaGetRunData for baseline_length");

    /* Allocate a buffer for the baseline histogram data */
    this->baselineBuffer = (epicsInt32 *)malloc(this->baselineLength * sizeof(epicsInt32));

    /* Allocate a buffer for the baseline energy array */
    this->baselineEnergyBuffer = (epicsFloat64 *)malloc(this->baselineLength * sizeof(epicsFloat64));

    /* Allocating temporary buffers for use in mapping mode. */
    this->pMapTemp = (unsigned long*)malloc(MAPPING_BUFFER_WORDS * sizeof(unsigned long));
    this->pMapRaw = (epicsUInt16*)malloc(MAPPING_BUFFER_WORDS * sizeof(epicsUInt16));
    
    /* Allocate an internal buffer long enough to hold all the energy values in a spectrum */
    this->spectrumXAxisBuffer = (epicsFloat64*)calloc(MAX_MCA_BINS, sizeof(epicsFloat64));

    /* On the Saturn enable special timing mode in RUNTASKS so we can use ROI pulse output
     * Hardcoding this here should be TEMPORARY until low-level parameters can be controlled by EPICS? */
    if (this->deviceType == NDDxpModelSaturn) {
        xiastatus = xiaGetParameter(0, "RUNTASKS", &runTasks);
        if (xiastatus != XIA_SUCCESS) printf("Error calling xiaGetParameter for RUNTASKS");
        /* Set bit 11 */
        runTasks |= 0x800;
        xiastatus = xiaSetParameter(0, "RUNTASKS", runTasks);
        if (xiastatus != XIA_SUCCESS) printf("Error calling xiaSetParameter for RUNTASKS");
    }
    
    if (this->deviceType == NDDxpModelMicroDXP) {
        /* On the MicroDXP read the list of peaking times */
        unsigned short usTemp;
        /* Read out number of peaking times to pre-allocate peaking time array */
        xiastatus = xiaBoardOperation(0, "get_number_pt_per_fippi", &usTemp);
        this->numPeakingTimes = usTemp;
        this->peakingTimes = (double *)malloc(this->numPeakingTimes * sizeof(double));
        xiastatus = xiaBoardOperation(0, "get_current_peaking_times", this->peakingTimes);
        /* Read the pre-amp type */
        xiastatus = xiaBoardOperation(0, "get_preamp_type", &usTemp);
        this->preampType = (NDDxpPreamp_t)usTemp;
    }

    /* Start up acquisition thread */
    setDoubleParam(NDDxpPollTime, 0.001);
    this->polling = 1;
    status = (epicsThreadCreate("acquisitionTask",
                epicsThreadPriorityMedium,
                epicsThreadGetStackSize(epicsThreadStackMedium),
                (EPICSTHREADFUNC)acquisitionTaskC, this) == NULL);
    if (status)
    {
        printf("%s:%s epicsThreadCreate failure for image task\n",
                driverName, functionName);
        return;
    }

    /* Read actual values of all parameters from Handel.  
     * Reading low-level parameters also reads high-level parameters */
    getLLDxpParams(this->pasynUserSelf, DXP_ALL);

    /* Set default values for parameters that cannot be read from Handel */
    for (i=0; i<=this->nChannels; i++) {
        setIntegerParam(i, NDDxpTraceMode, NDDxpTraceADC);
        setDoubleParam (i, NDDxpTraceTime, 0.1);
        setIntegerParam(i, NDDxpNewTraceTime, 1);
        setDoubleParam (i, NDDxpBaselineEnergy, 0.);
        setIntegerParam(i, NDDxpPresetMode, NDDxpPresetModeNone);
        setIntegerParam(i, NDDxpPresetEvents, 0);
        setIntegerParam(i, NDDxpPresetTriggers, 0);
        setIntegerParam(i, NDDxpForceRead, 0);
        setDoubleParam (i, mcaPresetCounts, 0.0);
        setDoubleParam (i, mcaElapsedCounts, 0.0);
        setDoubleParam (i, mcaPresetRealTime, 0.0);
        setDoubleParam (i, mcaPresetRealTime, 0.0);
        /* This parameter is a little special.  It can be read from Handel, but only for xMAP systems
         * and the dxpHighLevel.template file current has a record for this parameter on all systems,
         * because that is the only file that gets loaded for each detector element, and this record
         * is needed per element. */
        setIntegerParam(i, NDDxpCurrentPixel, 0);
    }

    /* Read the MCA and DXP parameters once */
    this->getDxpParams(this->pasynUserSelf, DXP_ALL);
    this->getAcquisitionStatus(this->pasynUserSelf, DXP_ALL);
    this->getAcquisitionStatistics(this->pasynUserSelf, DXP_ALL);
    
    // Enable array callbacks by default
    setIntegerParam(NDArrayCallbacks, 1);

    // Disable auto-apply
    setIntegerParam(NDDxpAutoApply, 0);
}

/* virtual methods to override from ADDriver */
asynStatus NDDxp::writeInt32( asynUser *pasynUser, epicsInt32 value)
{
    asynStatus status = asynSuccess;
    int function = pasynUser->reason;
    int channel, rbValue, xiastatus;
    int addr, i;
    int acquiring, numChans, mode;
    const char* functionName = "writeInt32";
    int firstCh, ignored;
    char fileName[MAX_FILENAME_LEN];

    channel = this->getChannel(pasynUser, &addr);
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: [%s]: function=%d value=%d addr=%d channel=%d\n",
        driverName, functionName, this->portName, function, value, addr, channel);

    /* Set the parameter and readback in the parameter library.  This may be overwritten later but that's OK */
    status = setIntegerParam(addr, function, value);

    if ((function == NDDxpCollectMode)         ||
        (function == NDDxpListMode)            ||
        (function == NDDxpPixelsPerRun)        ||
        (function == NDDxpPixelsPerBuffer)     ||
        (function == NDDxpAutoPixelsPerBuffer) ||
        (function == NDDxpSyncCount)           ||
        (function == NDDxpIgnoreGate)          ||
        (function == NDDxpPixelAdvanceMode)    ||
        (function == NDDxpInputLogicPolarity))
    {
        status = this->configureCollectMode();
    } 
    else if (function == NDDxpNextPixel) 
    {
        for (firstCh=0; firstCh<this->nChannels; firstCh+=this->channelsPerCard)
        {
            CALLHANDEL( xiaBoardOperation(firstCh, "mapping_pixel_next", &ignored), "mapping_pixel_next" )
        }
        setIntegerParam(addr, function, 0);
    }
    else if (function == NDDxpApply)
    {
        if (value) this->apply(DXP_ALL, 1);
    }
    else if (function == mcaErase) 
    {
        getIntegerParam(addr, mcaNumChannels, &numChans);
        getIntegerParam(addr, mcaAcquiring, &acquiring);
        if (acquiring) {
            xiaStopRun(channel);
            CALLHANDEL(xiaStartRun(channel, 0), "xiaStartRun(channel, 0)");
        } else {
            setIntegerParam(addr, NDDxpErased, 1);
            if (channel == DXP_ALL) {
                for (i=0; i<this->nChannels; i++) {
                    setIntegerParam(i, NDDxpErased, 1);
                    memset(this->pMcaRaw[i], 0, numChans * sizeof(pMcaRaw[0][0]));
                }
            } else {
                memset(this->pMcaRaw[addr], 0, numChans * sizeof(pMcaRaw[0][0]));
            }
            /* Need to call getAcquisitionStatistics to set elapsed values to 0 */
            this->getAcquisitionStatistics(pasynUser, addr);
        }
    } 
    else if (function == mcaStartAcquire) 
    {
        status = this->startAcquiring(pasynUser);
    } 
    else if (function == mcaStopAcquire) 
    {
        CALLHANDEL(xiaStopRun(channel), "xiaStopRun(detChan)");
        /* Wait for the acquisition task to realize the run has stopped and do the callbacks */
        while (1) {
            getIntegerParam(addr, mcaAcquiring, &acquiring);
            if (!acquiring) break;
            this->unlock();
            epicsThreadSleep(epicsThreadSleepQuantum());
            this->lock();
        }
    } 
    else if (function == mcaNumChannels) 
    {
        // rbValue not used here, call setIntegerParam if needed.
        status = this->setNumChannels(pasynUser, value, &rbValue);
    } 
    else if (function == mcaReadStatus) 
    {
        getIntegerParam(NDDxpCollectMode, &mode);
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "%s::%s mcaReadStatus [%d] mode=%d\n", 
            driverName, functionName, function, mode);
        /* We let the polling task set the acquiring flag, so that we can be sure that
         * the statistics and data have been read when needed.  DON'T READ ACQUIRE STATUS HERE */
        getIntegerParam(addr, mcaAcquiring, &acquiring);
        if (mode == NDDxpModeMCA) {
            /* If we are acquiring then read the statistics, else we use the cached values */
            if (acquiring) status = this->getAcquisitionStatistics(pasynUser, addr);
        }
    }
    else if ((function == NDDxpPresetMode)   ||
             (function == NDDxpPresetEvents) ||
             (function == NDDxpPresetTriggers)) 
    {
        this->setPresets(pasynUser, addr);
    } 
    else if (function == NDDxpReadLLParams) 
    {
        this->getLLDxpParams(pasynUser, addr);
    } 
    else if ((function == NDDxpDetectorPolarity) ||
             (function == NDDxpEnableBaselineCut)||
             (function == NDDxpBaselineAverage)  ||
             (function == NDDxpTriggerOutput)    ||
             (function == NDDxpLiveTimeOutput)) 
    {
        this->setDxpParam(pasynUser, addr, function, (double)value);
    }
    else if ((function == NDDxpNumSCAs)    ||
             ((function >= NDDxpSCALow[0]) &&
              (function <= NDDxpSCAHigh[DXP_MAX_SCAS-1]))) 
    {
        this->setSCAs(pasynUser, addr);
    }
    else if ((function >= NDDxpLLParamVals[0]) &&
             (function <= NDDxpLLParamVals[numLLParams-1])) 
    {
        this->setLLDxpParam(pasynUser, addr, value);
    }
    else if (function == NDDxpSaveSystem) 
    {
        if (value) {
            callParamCallbacks(addr, addr);
            status = getStringParam(NDDxpSaveSystemFile, sizeof(fileName), fileName);
            if (status || (strlen(fileName) == 0)) {
                asynPrint(pasynUser, ASYN_TRACE_ERROR,
                    "%s::%s error, bad system file name, status=%d, fileName=%s\n",
                    driverName, functionName, status, fileName);
                goto done;
            }
            CALLHANDEL(xiaSaveSystem("handel_ini", fileName), "xiaSaveSystem(handel_ini, fileName)");
            /* Set the save command back to 0 */
            setIntegerParam(addr, NDDxpSaveSystem, 0);
        }
    }
    done:

    /* Call the callback */
    callParamCallbacks(addr, addr);
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}

asynStatus NDDxp::writeFloat64( asynUser *pasynUser, epicsFloat64 value)
{
    asynStatus status = asynSuccess;
    int function = pasynUser->reason;
    int addr;
    int channel;
    const char *functionName = "writeFloat64";

    channel = this->getChannel(pasynUser, &addr);
    asynPrint(pasynUser, ASYN_TRACE_FLOW,
        "%s:%s: [%s]: function=%d value=%f addr=%d channel=%d\n",
        driverName, functionName, this->portName, function, value, addr, channel);

    /* Set the parameter and readback in the parameter library.  This may be overwritten later but that's OK */
    status = setDoubleParam(addr, function, value);

    if ((function == mcaPresetRealTime) ||
        (function == mcaPresetLiveTime)) 
    {
        this->setPresets(pasynUser, addr);
    } 
    else if 
       ((function == NDDxpPeakingTime) ||
        (function == NDDxpDynamicRange) ||
        (function == NDDxpTriggerThreshold) ||
        (function == NDDxpBaselineThreshold) ||
        (function == NDDxpEnergyThreshold) ||
        (function == NDDxpCalibrationEnergy) ||
        (function == NDDxpADCPercentRule) ||
        (function == NDDxpMaxEnergy) ||
        (function == NDDxpPreampGain) ||
        (function == NDDxpGain) ||
        (function == NDDxpFineGain) ||
        (function == NDDxpDetectorPolarity) ||
        (function == NDDxpResetDelay) ||
        (function == NDDxpDecayTime) ||
        (function == NDDxpGapTime) ||
        (function == NDDxpTriggerPeakingTime) ||
        (function == NDDxpTriggerGapTime) ||
        (function == NDDxpBaselineCut) ||
        (function == NDDxpMaxWidth))
    {
        this->setDxpParam(pasynUser, addr, function, value);
    }
    else if  (function == NDDxpTraceTime)
    {
        /* Set a flag indicating the trace time has changed for this channel */
        setIntegerParam(addr, NDDxpNewTraceTime, 1);
    }
    /* Call the callback */
    callParamCallbacks(addr, addr);

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}

asynStatus NDDxp::readInt32Array(asynUser *pasynUser, epicsInt32 *value, size_t nElements, size_t *nIn)
{
    asynStatus status = asynSuccess;
    int function = pasynUser->reason;
    int addr;
    int channel;
    int nBins, acquiring,mode;
    int ch;
    int i;
    const char *functionName = "readInt32Array";

    channel = this->getChannel(pasynUser, &addr);

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s::%s addr=%d channel=%d function=%d\n",
        driverName, functionName, addr, channel, function);
    if (function == NDDxpTraceData) 
    {
        status = this->getTrace(pasynUser, channel, value, nElements, nIn);
    } 
    else if (function == NDDxpBaselineHistogram) 
    {
        status = this->getBaselineHistogram(pasynUser, channel, value, nElements, nIn);
    } 
    else if (function == mcaData) 
    {
        if (channel == DXP_ALL)
        {
            // if the MCA ALL channel is being read - force reading of all individual
            // channels using the NDDxpForceRead command.
            for (ch=0; ch<this->nChannels; ch++)
            {
                setIntegerParam(ch, NDDxpForceRead, 1);
                callParamCallbacks(ch, ch);
                setIntegerParam(ch, NDDxpForceRead, 0);
                callParamCallbacks(ch, ch);
            }
            goto done;
        }
        getIntegerParam(channel, mcaNumChannels, &nBins);
        if (nBins > (int)nElements) nBins = (int)nElements;
        getIntegerParam(channel, mcaAcquiring, &acquiring);
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "%s::%s getting mcaData. ch=%d mcaNumChannels=%d mcaAcquiring=%d\n",
            driverName, functionName, channel, nBins, acquiring);
        *nIn = nBins;
        getIntegerParam(NDDxpCollectMode, &mode);

        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "%s::%s mode=%d acquiring=%d\n",
            driverName, functionName, mode, acquiring);
        if (acquiring)
        {
            if (mode == NDDxpModeMCA)
            {
                /* While acquiring we'll force reading the data from the HW */
                this->getMcaData(pasynUser, addr);
            } else if ((mode == NDDxpModeSpectraMapping) || (mode == NDDxpModeSCAMapping))
            {
                /*  Nothing needed here, the last data read from the mapping buffer has already been
                 *  copied to the buffer pointed to by pMcaRaw. */
            }
        }
        for (i=0; i<nBins; i++) {
            value[i] = pMcaRaw[addr][i];
        }
    } 
    else {
            asynPrint(pasynUser, ASYN_TRACE_ERROR,
                "%s::%s Function not implemented: [%d]\n",
                driverName, functionName, function);
            status = asynError;
    }
    done:
    
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}

int NDDxp::getChannel(asynUser *pasynUser, int *addr)
{
    int channel;
    pasynManager->getAddr(pasynUser, addr);

    channel = *addr;
    if (*addr == this->nChannels) channel = DXP_ALL;
    return channel;
}

asynStatus NDDxp::apply(int channel, int forceApply)
{
    int i;
    asynStatus status=asynSuccess;
    int xiastatus, ignore;
    int autoApply;
    static const char *functionName = "apply";

    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: enter channel=%d, forceApply=%d\n",
        driverName, functionName, channel, forceApply);
    if (this->deviceType == NDDxpModelSaturn) return(asynSuccess);

    getIntegerParam(NDDxpAutoApply, &autoApply);
    if (!autoApply && !forceApply) {
        return(asynSuccess);
    }

    if (channel == DXP_ALL) {
        for (i=0; i<this->nChannels; i+=this->channelsPerCard)
        {
            xiastatus = xiaBoardOperation(i, "apply", &ignore);
            status = this->xia_checkError(this->pasynUserSelf, xiastatus, "apply");
        }
    } else {
        xiastatus = xiaBoardOperation(channel, "apply", &ignore);
        status = this->xia_checkError(this->pasynUserSelf, xiastatus, "apply");
    }
    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}


asynStatus NDDxp::setPresets(asynUser *pasynUser, int addr)
{
    asynStatus status = asynSuccess;
    NDDxpPresetMode_t presetMode;
    double presetReal;
    double presetLive;
    int presetEvents;
    int presetTriggers;
    double presetValue;
    double presetType;
    unsigned long runActive=0;
    int channel=addr;
    int channel0;
    char presetString[40];
    const char* functionName = "setPresets";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) channel0 = 0; else channel0 = channel;

    getDoubleParam(addr,  mcaPresetRealTime,   &presetReal);
    getDoubleParam(addr,  mcaPresetLiveTime,   &presetLive);
    getIntegerParam(addr, NDDxpPresetEvents,   &presetEvents);
    getIntegerParam(addr, NDDxpPresetTriggers, &presetTriggers);
    getIntegerParam(addr, NDDxpPresetMode,     (int *)&presetMode);

    xiaGetRunData(channel0, "run_active", &runActive);
    xiaStopRun(channel);
    
    switch (presetMode) {
        case  NDDxpPresetModeNone:
            presetValue = 0;
            presetType = XIA_PRESET_NONE;
            strcpy(presetString, "preset_standard");
            break;

        case NDDxpPresetModeReal:
            presetValue = presetReal;
            presetType = XIA_PRESET_FIXED_REAL;
            strcpy(presetString, "preset_runtime");
            break;

        case NDDxpPresetModeLive:
            presetValue = presetLive;
            presetType = XIA_PRESET_FIXED_LIVE;
            strcpy(presetString, "preset_livetime");
            break;

        case NDDxpPresetModeEvents:
            presetValue = presetEvents;
            presetType = XIA_PRESET_FIXED_EVENTS;
            strcpy(presetString, "error");
            break;

        case NDDxpPresetModeTriggers:
            presetValue = presetTriggers;
            presetType = XIA_PRESET_FIXED_TRIGGERS;
            strcpy(presetString, "error");
            break;
        default:
            asynPrint(pasynUser, ASYN_TRACE_ERROR,
                "%s:%s: unknown presetMode=%d\n",
                driverName, functionName, presetMode);
            break;
    }

    if (this->deviceType == NDDxpModelSaturn) {
        if (strcmp(presetString, "error") == 0) {
            asynPrint(pasynUser, ASYN_TRACE_ERROR,
                "%s:%s: error, preset events and triggers are not available on the Saturn\n",
                driverName, functionName);
            status = asynError;
        } else {            
            xiaSetAcquisitionValues(channel, presetString, &presetValue);
        }
    } else {
        xiaSetAcquisitionValues(channel, "preset_type", &presetType);
        xiaSetAcquisitionValues(channel, "preset_value", &presetValue);
        this->apply(channel);
    }
    asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
        "%s:%s: addr=%d channel=%d set presets mode=%d, value=%f\n",
        driverName, functionName, addr, channel, presetMode, presetValue);

    if (runActive) xiaStartRun(channel, 1);
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}

asynStatus NDDxp::setDxpParam(asynUser *pasynUser, int addr, int function, double value)
{
    int channel = addr;
    int channel0;
    unsigned long runActive=0;
    double dvalue=value;
    int numMcaChannels;
    int xiastatus=0;
    int bin;
    double binEnergyEV;
    asynStatus status=asynSuccess;
    static const char *functionName = "setDxpParam";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d, function=%d, value=%f\n",
        driverName, functionName, addr, function, value);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) channel0 = 0; else channel0 = channel;

    xiaGetRunData(channel0, "run_active", &runActive);
    xiaStopRun(channel);

    if (function == NDDxpPeakingTime) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            // The peaking time cannot be changed directly on the MicroDXP, it is changed by selecting a PARSET
            // Find the closest peaking time to the requested one
            double minDiff=1e9;
            double diff;
            int minIndex=0;
            for (int i=0; i<this->numPeakingTimes; i++) {
                diff = fabs(this->peakingTimes[i] - value);
                if (diff < minDiff) {
                    minDiff = diff;
                    minIndex = i;
                }
            }
            dvalue = minIndex;
            xiastatus = xiaSetAcquisitionValues(0, "parset", &dvalue);
            setDoubleParam(NDDxpPeakingTime, this->peakingTimes[minIndex]);
            unsigned short parsetAndGenset = AV_MEM_PARSET | AV_MEM_GENSET;
            xiastatus = xiaBoardOperation(0, "apply", (void*)&parsetAndGenset);
        } else {
            xiastatus = xiaSetAcquisitionValues(channel, "peaking_time", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting peaking_time");
        }
        /* Sometimes the gap time is rejected because the peaking time has not yet been 
         * accepted, so we set it again here */
        getDoubleParam(addr, NDDxpGapTime, &dvalue);
        if ((this->deviceType == NDDxpModelXMAP) || 
            (this->deviceType == NDDxpModelMercury)) {
            /* On the xMAP the parameter that can be written is minimum_gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "minimum_gap_time", &dvalue);
        } else if (this->deviceType == NDDxpModelSaturn) {
            /* On the Saturn and it is gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "gap_time", &dvalue);
        } else if (this->deviceType == NDDxpModelMicroDXP) {
            /* On the MicroDXP it is energy_gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "energy_gap_time", &dvalue);
        }
        status = this->xia_checkError(pasynUser, xiastatus, "setting gap time");
    } else if (function == NDDxpDynamicRange) {
        /* dynamic_range is only supported on the xMAP and Mercury */
        if ((this->deviceType == NDDxpModelXMAP) || 
            (this->deviceType == NDDxpModelMercury)) {
            /* Convert from eV to keV */
            dvalue = value * 1000.;
            xiastatus = xiaSetAcquisitionValues(channel, "dynamic_range", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting dynamic_range");
        }
    } else if (function == NDDxpTriggerThreshold) {
        /* Convert from keV to eV */
        dvalue = value * 1000.;
        xiastatus = xiaSetAcquisitionValues(channel, "trigger_threshold", &dvalue);
        status = this->xia_checkError(pasynUser, xiastatus, "setting trigger_threshold");
    } else if (function == NDDxpBaselineThreshold) {
         dvalue = value * 1000.;    /* Convert to eV */
         xiastatus = xiaSetAcquisitionValues(channel, "baseline_threshold", &dvalue);
         status = this->xia_checkError(pasynUser, xiastatus, "setting baseline_threshold");
    } else if (function == NDDxpEnergyThreshold) {
        /* Convert from keV to eV */
        dvalue = value * 1000.;
        xiastatus = xiaSetAcquisitionValues(channel, "energy_threshold", &dvalue);
        status = this->xia_checkError(pasynUser, xiastatus, "setting energy_threshold");
    } else if (function == NDDxpCalibrationEnergy) {
        /* Convert from keV to eV */
        dvalue = value * 1000.;
        xiastatus = xiaSetAcquisitionValues(channel, "calibration_energy", &dvalue);
        status = this->xia_checkError(pasynUser, xiastatus, "setting calibration_energy");
    } else if (function == NDDxpADCPercentRule) {
        if (this->deviceType != NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "adc_percent_rule", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting adc_percent_rule");
        }
    } else if (function == NDDxpPreampGain) {
        if (this->deviceType != NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "preamp_gain", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting preamp_gain");
        }
    } else if (function == NDDxpGain) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "gain", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting gain");
        }
    } else if (function == NDDxpFineGain) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "gain_trim", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting gain_trim");
        }
    } else if (function == NDDxpDetectorPolarity) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "polarity", &dvalue);
        } else {
            xiastatus = xiaSetAcquisitionValues(channel, "detector_polarity", &dvalue);
        }
        status = this->xia_checkError(pasynUser, xiastatus, "setting detector polarity");
    } else if (function == NDDxpResetDelay) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            if (this->preampType == NDDxpPreampReset) {
                xiastatus = xiaSetAcquisitionValues(channel, "preamp_value", &dvalue);
            }
        } else {
            xiastatus = xiaSetAcquisitionValues(channel, "reset_delay", &dvalue);
        }
    } else if (function == NDDxpDecayTime) {
        if (this->deviceType == NDDxpModelMicroDXP) {
              if (this->preampType == NDDxpPreampRC) {
                  xiastatus = xiaSetAcquisitionValues(channel, "preamp_value", &dvalue);
              }
        } else {
            xiastatus = xiaSetAcquisitionValues(channel, "decay_time", &dvalue);
        }
    } else if (function == NDDxpGapTime) {
        if ((this->deviceType == NDDxpModelXMAP) || 
            (this->deviceType == NDDxpModelMercury)) {
            /* On the xMAP the parameter that can be written is minimum_gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "minimum_gap_time", &dvalue);
        } else if (this->deviceType == NDDxpModelSaturn) {
            /* On the Saturn and it is gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "gap_time", &dvalue);
        } else if (this->deviceType == NDDxpModelMicroDXP) {
            /* On the MicroDXP it is energy_gap_time */
            xiastatus = xiaSetAcquisitionValues(channel, "energy_gap_time", &dvalue);
        }
        status = this->xia_checkError(pasynUser, xiastatus, "setting gap time");
    } else if (function == NDDxpTriggerPeakingTime) {
         if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "trigger_peak_time", &dvalue);
         } else {
            xiastatus = xiaSetAcquisitionValues(channel, "trigger_peaking_time", &dvalue);
         }
         status = this->xia_checkError(pasynUser, xiastatus, "setting trigger_peaking_time");
    } else if (function == NDDxpTriggerGapTime) {
        xiastatus = xiaSetAcquisitionValues(channel, "trigger_gap_time", &dvalue);
        status = this->xia_checkError(pasynUser, xiastatus, "setting trigger_gap_time");
    } else if (function == NDDxpBaselineAverage) {
        if ((this->deviceType == NDDxpModelXMAP) || 
            (this->deviceType == NDDxpModelMercury)) {
            xiastatus = xiaSetAcquisitionValues(channel, "baseline_average", &dvalue);
        } else if (this->deviceType == NDDxpModelSaturn) {
            xiastatus = xiaSetAcquisitionValues(channel, "baseline_filter_length", &dvalue);
        } else if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "baseline_length", &dvalue);
        }
        status = this->xia_checkError(pasynUser, xiastatus, "setting baseline filter length");
    } else if (function == NDDxpMaxWidth) {
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiastatus = xiaSetAcquisitionValues(channel, "max_width", &dvalue);
        } else {
            xiastatus = xiaSetAcquisitionValues(channel, "maxwidth", &dvalue);
        }
        status = this->xia_checkError(pasynUser, xiastatus, "setting maxwidth");
    } else if (function == NDDxpBaselineCut) {
        /* Only the Saturn supports this */
        if (this->deviceType == NDDxpModelSaturn) {
            xiastatus = xiaSetAcquisitionValues(channel, "baseline_cut", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting baseline_cut");
        }
    } else if (function == NDDxpEnableBaselineCut) {
        /* Only the Saturn supports this */
        if (this->deviceType == NDDxpModelSaturn) {
            xiastatus = xiaSetAcquisitionValues(channel, "enable_baseline_cut", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting enable_baseline_cut");
        }
    } else if (function == NDDxpTriggerOutput) {
        /* This is only supported on the Mercury */
        if (this->deviceType == NDDxpModelMercury) {
            xiastatus = xiaSetAcquisitionValues(channel, "trigger_output", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "trigger_output");
        }
    } else if (function == NDDxpLiveTimeOutput) {
        /* This is only supported on the Mercury */
        if (this->deviceType == NDDxpModelMercury) {
            xiastatus = xiaSetAcquisitionValues(channel, "livetime_output", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "livetime_output");
        }
    } else if (function == NDDxpMaxEnergy) {
        getIntegerParam(addr, mcaNumChannels, &numMcaChannels);
        if (numMcaChannels <= 0.)
            numMcaChannels = 2048;
        /* Set the bin width in eV */
        dvalue = value * 1000. / numMcaChannels;
        xiastatus = xiaSetAcquisitionValues(channel, "mca_bin_width", &dvalue);
        status = this->xia_checkError(pasynUser, xiastatus, "setting mca_bin_width");
        if (this->deviceType != NDDxpModelMicroDXP) {
            /* We always make the calibration energy be 50% of MaxEnergy */
            dvalue = value * 1000. / 2.;
            xiastatus = xiaSetAcquisitionValues(channel, "calibration_energy", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting calibration_energy");
            /* Must re-apply the ADC percent rule when changing calibration energy */
            getDoubleParam(addr, NDDxpADCPercentRule, &dvalue);
            xiastatus = xiaSetAcquisitionValues(channel, "adc_percent_rule", &dvalue);
            status = this->xia_checkError(pasynUser, xiastatus, "setting adc_percent_rule");
        } 
        
        /* create a waveform which contain the value (in keV) of all the energy bins in the spectrum */
        binEnergyEV = value / numMcaChannels;
        for(bin=0; bin<numMcaChannels; bin++)
        {
        	*(this->spectrumXAxisBuffer+bin) = (bin+1) * binEnergyEV;
        }
        doCallbacksFloat64Array(this->spectrumXAxisBuffer, numMcaChannels, NDDxpSpectrumXAxis, addr); 
    }
    this->apply(channel);
    this->getDxpParams(pasynUser, addr);
    if (runActive) xiaStartRun(channel, 1);
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: status=%d, exit\n",
        driverName, functionName, status);
    return asynSuccess;
}

asynStatus NDDxp::setSCAs(asynUser *pasynUser, int addr)
{
    int channel = addr;
    int channel0;
    unsigned long runActive=0;
    int xiastatus;
    int i;
    int numSCAs, maxSCAs;
    int low, high;
    double dTmp;
    asynStatus status=asynSuccess;
    static const char *functionName = "setSCAs";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) channel0 = 0; else channel0 = channel;
    xiaGetRunData(channel0, "run_active", &runActive);
    xiaStopRun(channel);

    /* We get the number of SCAs from the channel 0, force all detectors to be the same */
    getIntegerParam(0, NDDxpNumSCAs, &numSCAs);
    getIntegerParam(0, NDDxpMaxSCAs, &maxSCAs);
    if (numSCAs > maxSCAs) {
        numSCAs = maxSCAs;
        setIntegerParam(NDDxpNumSCAs, numSCAs);
    }
    dTmp = numSCAs;
    CALLHANDEL(xiaSetAcquisitionValues(DXP_ALL, "number_of_scas", &dTmp), "number_of_scas");
    for (i=0; i<numSCAs; i++) {
        status = getIntegerParam(addr, NDDxpSCALow[i], &low);
        if (status || (low < 0)) {
            low = 0;
            setIntegerParam(addr, NDDxpSCALow[i], low);
        }
        status = getIntegerParam(addr, NDDxpSCAHigh[i], &high);
        if (status || (high < 0)) {
            high = 0;
            setIntegerParam(addr, NDDxpSCAHigh[i], high);
        }
        if (high < low) {
            high = low;
            setIntegerParam(addr, NDDxpSCAHigh[i], high);
        }
        dTmp = (double) low;
        CALLHANDEL(xiaSetAcquisitionValues(channel, SCA_NameLow[i], &dTmp), SCA_NameLow[i]);
        dTmp = (double) high;
        CALLHANDEL(xiaSetAcquisitionValues(channel, SCA_NameHigh[i], &dTmp), SCA_NameHigh[i]);
    }
    this->apply(channel);
    getSCAs(pasynUser, addr);
    if (runActive) xiaStartRun(channel, 1);
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}

asynStatus NDDxp::getSCAs(asynUser *pasynUser, int addr)
{
    int channel = addr;
    int xiastatus;
    int i;
    int numSCAs;
    int low, high;
    double dTmp;
    asynStatus status=asynSuccess;
    static const char *functionName = "getSCAs";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;

    CALLHANDEL(xiaGetAcquisitionValues(channel, "number_of_scas", &dTmp), "number_of_scas");
    numSCAs = (int) dTmp;
    setIntegerParam(addr, NDDxpNumSCAs, numSCAs);
    for (i=0; i<numSCAs; i++) {
        CALLHANDEL(xiaGetAcquisitionValues(channel, SCA_NameLow[i], &dTmp), SCA_NameLow[i]);
        low = (int) dTmp;
        setIntegerParam(addr, NDDxpSCALow[i], low);
        CALLHANDEL(xiaGetAcquisitionValues(channel, SCA_NameHigh[i], &dTmp), SCA_NameHigh[i]);
        high = (int) dTmp;
        setIntegerParam(addr, NDDxpSCAHigh[i], high);
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}

asynStatus NDDxp::getSCAData(asynUser *pasynUser, int addr)
{
    int channel = addr;
    asynStatus status=asynSuccess;
    int xiastatus;
    int i;
    int scaCounts[DXP_MAX_SCAS];
    int numSCAs;
    const char *functionName = "getSCAData";
    
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getSCAData(pasynUser, i);
        }
    } else {
        /* The SCA data on the xMAP and Mercury is double, it is long on other products */
        getIntegerParam(addr, NDDxpNumSCAs, &numSCAs);
        if ((this->deviceType == NDDxpModelXMAP) || 
            (this->deviceType == NDDxpModelMercury)) {
            double dTmp[DXP_MAX_SCAS];
            CALLHANDEL(xiaGetRunData(channel, "sca", dTmp), "sca");
            for (i=0; i<numSCAs; i++)
            {
                scaCounts[i] = (int) dTmp[i];
            }
        } else {
            CALLHANDEL(xiaGetRunData(channel, "sca", scaCounts), "sca");
        }
        for (i=0; i<numSCAs; i++) 
        {
            setIntegerParam(addr, NDDxpSCACounts[i], scaCounts[i]);
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}


asynStatus NDDxp::setNumChannels(asynUser* pasynUser, epicsInt32 value, epicsInt32 *rbValue)
{
    asynStatus status = asynSuccess;
    int xiastatus;
    int i;
    int modulus, realnbins, mode=0;
    double dblNbins;
    static const char* functionName = "setNumChannels";

    asynPrint(pasynUser, ASYN_TRACE_FLOW,
        "%s:%s: new number of bins: %d\n", 
        driverName, functionName, value);

    if (value > MAX_MCA_BINS || value < MCA_BIN_RES)
    {
        status = asynError;
        return status;
    }

    /* TODO: check here whether the xmap is acquiring (if so, break out...)  */

    /* MCA number of bins has a resolution of MCA_BIN_RES (256)
     * bins per channel. Since the user can enter any value we must cap this to
     * the closest multiple of 256 */
    modulus = value % MCA_BIN_RES;
    if (modulus == 0) realnbins = value;
    else if (modulus < MCA_BIN_RES/2) realnbins = value - modulus;
    else realnbins = value + (MCA_BIN_RES - modulus);
    *rbValue = realnbins;
    dblNbins = (epicsFloat64)*rbValue;

    for (i=0; i<this->nChannels; i++)
    {
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "xiaSetAcquisitionValues ch=%d nbins=%.1f\n", 
            i, dblNbins);
        xiastatus = xiaSetAcquisitionValues(i, "number_mca_channels", &dblNbins);
        status = this->xia_checkError(pasynUser, xiastatus, "number_mca_channels");
        if (status == asynError)
            {
            asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
                "%s::%s [%s] can not set nbins=%u (%.3f) ch=%u\n",
                driverName, functionName, this->portName, *rbValue, dblNbins, i);
            return status;
            }
        setIntegerParam(i, mcaNumChannels, *rbValue);
        callParamCallbacks(i);
    }
    
    /* We also need to set the number of channels for the DXP_ALL channel, it is used in mcaErase */
    setIntegerParam(this->nChannels, mcaNumChannels, *rbValue);
    callParamCallbacks(this->nChannels);

    /* If in mapping mode we need to modify the Y size as well in order to fit in the 2MB buffer!
     * We also need to read out the new length of the mapping buffer because that can possibly change... */
    getIntegerParam(NDDxpCollectMode, &mode);
    if (mode != NDDxpModeMCA) configureCollectMode();
    this->apply(DXP_ALL);

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}


asynStatus NDDxp::configureCollectMode()
{
    asynStatus status = asynSuccess;
    NDDxpCollectMode_t collectMode;
    NDDxpListMode_t listMode;
    int xiastatus, acquiring;
    int i;
    int firstCh, bufLen;
    double dTmp;
    int pixelsPerBuffer;
    int autoPixelsPerBuffer;
    int pixelsPerRun;
    int syncCount;
    int ignoreGate;
    int inputLogicPolarity;
    NDDxpPixelAdvanceMode_t pixelAdvanceMode;
    const char* functionName = "configureCollectMode";

    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: enter\n",
        driverName, functionName);
    getIntegerParam(NDDxpCollectMode, (int *)&collectMode);
    
    if (collectMode < NDDxpModeMCA || collectMode > NDDxpModeListMapping) {
	      asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, 
            "%s:%s: invalid collect mode = %d\n",
            driverName, functionName, collectMode);
        return asynError;
    }

    getIntegerParam(mcaAcquiring, &acquiring);
    if (acquiring) {
	      asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, 
            "%s:%s: cannot change collect mode while acquiring\n",
            driverName, functionName);
        return asynError;
    }
    
    /* Changing the mapping mode is time-consuming.  
     * If the current mapping mode matches the desired one then skip this */
    xiastatus = xiaGetAcquisitionValues(0, "mapping_mode", &dTmp);
    status = this->xia_checkError(pasynUserSelf, xiastatus, "GET mapping_mode");
    if ((int)dTmp != collectMode) {
        asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
            "%s::%s Changing collectMode to %d, device type=%d\n",
            driverName, functionName, collectMode, deviceType);
        dTmp = (double)collectMode;
        xiastatus = xiaSetAcquisitionValues(DXP_ALL, "mapping_mode", &dTmp);
        status = this->xia_checkError(pasynUserSelf, xiastatus, "mapping_mode");
        if (status == asynError) return status;
        this->apply(DXP_ALL);
    }

    switch(collectMode)
    {
    case NDDxpModeMCA:
        getIntegerParam(mcaNumChannels, (int*)&bufLen);
        setIntegerParam(NDDataType, NDUInt32);
        for (i=0; i<this->nChannels; i++)
        {
            /* Clear the normal mapping mode status settings */
            setIntegerParam(i, NDDxpEvents, 0);
            setIntegerParam(i, NDDxpOverflows, 0);
            setIntegerParam(i, NDDxpUnderflows, 0);
            setDoubleParam(i, NDDxpInputCountRate, 0);
            setDoubleParam(i, NDDxpOutputCountRate, 0);

            /* Set the new ArraySize down to just one buffer length */
            setIntegerParam(i, NDArraySize, (int)bufLen);
            callParamCallbacks(i,i);
        }
        break;
    case NDDxpModeSpectraMapping:
    case NDDxpModeSCAMapping:
    case NDDxpModeListMapping:
        getIntegerParam(NDDxpPixelAdvanceMode, (int *)&pixelAdvanceMode);
        getIntegerParam(NDDxpPixelsPerRun, &pixelsPerRun);
        getIntegerParam(NDDxpPixelsPerBuffer, &pixelsPerBuffer);
        if (pixelsPerBuffer == 0) pixelsPerBuffer = -1; /* Handel will compute maximum */
        getIntegerParam(NDDxpAutoPixelsPerBuffer, &autoPixelsPerBuffer);
        if (autoPixelsPerBuffer) pixelsPerBuffer = -1;  /* Handel will compute maximum */
        getIntegerParam(NDDxpSyncCount, &syncCount);
        if (syncCount < 1) syncCount = 1;
        getIntegerParam(NDDxpIgnoreGate, &ignoreGate);
        getIntegerParam(NDDxpInputLogicPolarity, &inputLogicPolarity);
        setIntegerParam(NDDataType, NDUInt16);
            
        if (collectMode == NDDxpModeListMapping) {
            getIntegerParam(NDDxpListMode, (int *)&listMode);
            if ((listMode < NDDxpListModeGate) || (listMode > NDDxpListModeClock)) listMode = NDDxpListModeClock;
            dTmp = (double)listMode;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting list_mode_variant = %f\n", 
                driverName, functionName, DXP_ALL, dTmp);
            xiastatus = xiaSetAcquisitionValues(DXP_ALL, "list_mode_variant", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "list_mode_variant");
        }
        for (firstCh=0; firstCh<this->nChannels; firstCh+=this->channelsPerCard)
        {
            dTmp = XIA_MAPPING_CTL_SYNC;
            if (pixelAdvanceMode == NDDxpPixelAdvanceGate) dTmp = XIA_MAPPING_CTL_GATE;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting pixel_advance_mode = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "pixel_advance_mode", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "pixel_advance_mode");

            dTmp = pixelsPerRun;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting num_map_pixels = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "num_map_pixels", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "num_map_pixels");

            dTmp = pixelsPerBuffer;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting num_map_pixels_per_buffer = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "num_map_pixels_per_buffer", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "num_map_pixels_per_buffer");

            /* The xMAP and Mercury actually divides the sync input by N+1, e.g. sync_count=0 does no division
             * of sync clock.  We subtract 1 so user-units are intuitive. */
            dTmp = syncCount-1;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting sync_count = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "sync_count", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "sync_count");

            dTmp = ignoreGate;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting gate_ignore = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "gate_ignore", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "gate_ignore");

            dTmp = inputLogicPolarity;
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] setting input_logic_polarity = %f\n", 
                driverName, functionName, firstCh, dTmp);
            xiastatus = xiaSetAcquisitionValues(firstCh, "input_logic_polarity", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "input_logic_polarity");
            
            /* Apply the values */
            this->apply(firstCh);

            /* Clear the normal MCA mode status settings */
            for (i=0; i<this->channelsPerCard; i++)
            {
                setIntegerParam(firstCh+i, NDDxpTriggers, 0);
                setDoubleParam(firstCh+i, mcaElapsedRealTime, 0);
                setDoubleParam(firstCh+i, NDDxpTriggerLiveTime, 0);
                setDoubleParam(firstCh+i, mcaElapsedLiveTime, 0);
                callParamCallbacks(firstCh+i, firstCh+i);
            }
            /* Read back the actual settings */
            getDxpParams(this->pasynUserSelf, firstCh);
        }
        break;
    }

    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: returning status=%d\n",
        driverName, functionName, status);
    return status;
}

asynStatus NDDxp::getAcquisitionStatus(asynUser *pasynUser, int addr)
{
    int acquiring=0;
    unsigned long runActive;
    int ivalue;
    int channel=addr;
    asynStatus status=asynSuccess;
    int xiastatus;
    int i;
    //static const char *functionName = "getAcquisitionStatus";
    
    /* Note: we use the internal parameter NDDxpAcquiring rather than mcaAcquiring here
     * because we need to do callbacks in acquisitionTask() on all other parameters before
     * we do callbacks on mcaAcquiring, and callParamCallbacks does not allow control over the order. */

    if (addr == this->nChannels) channel = DXP_ALL;
    else if (addr == DXP_ALL) addr = this->nChannels;
    if (channel == DXP_ALL) { /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getAcquisitionStatus(pasynUser, i);
            getIntegerParam(i, NDDxpAcquiring, &ivalue);
            acquiring = MAX(acquiring, ivalue);
        }
        setIntegerParam(addr, NDDxpAcquiring, acquiring);
    } else {
        /* Get the run time status from the handel library - informs whether the
         * HW is acquiring or not.        */
        CALLHANDEL( xiaGetRunData(channel, "run_active", &runActive), "xiaGetRunData (run_active)" )
        /* If Handel thinks the run is active, but the hardware does not, then
         * stop the run */
        if (runActive == XIA_RUN_HANDEL)
            CALLHANDEL( xiaStopRun(channel), "xiaStopRun")
        /* Get the acquiring state from the XIA hardware */
        acquiring = (runActive & XIA_RUN_HARDWARE);
        setIntegerParam(addr, NDDxpAcquiring, acquiring);
    }
    //asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
    //    "%s::%s addr=%d channel=%d: acquiring=%d\n",
    //    driverName, functionName, addr, channel, acquiring);
    return(status);
}

asynStatus NDDxp::getModuleStatistics(asynUser *pasynUser, int addr, moduleStatistics *stats)
{
    /* This function returns the module statistics with a single block read.
     * It is more than 30 times faster on the USB Saturn than reading individual
     * parameters. */
    int i;
    int status;
    static const char *functionName = "getModuleStatistics";
     
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    status = xiaGetRunData(addr, "module_statistics_2", (double *)stats);
    /* It appears that the xMAP sometimes returns 0 energy live time when it should not.
     * Fix this here */
    for (i=0; i<this->channelsPerCard; i++) {
        if (stats[i].energyLiveTime == 0.) {
            if ((stats[i].triggers > 0.) && (stats[i].events > 0)) 
                stats[i].energyLiveTime = stats[i].triggerLiveTime * stats[i].events / stats[i].triggers;
            else
                stats[i].energyLiveTime = stats[i].triggerLiveTime;
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return((asynStatus)status);
}     
     

asynStatus NDDxp::getAcquisitionStatistics(asynUser *pasynUser, int addr)
{
    double dvalue, triggerLiveTime=0, energyLiveTime=0, realTime=0, icr=0, ocr=0;
    moduleStatistics *stats;
    int events=0, triggers=0, overflows=0, underflows=0;
    int ivalue;
    int channel=addr;
    int erased;
    int i;
    const char *functionName = "getAcquisitionStatistics";

    if (addr == this->nChannels) channel = DXP_ALL;
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s::%s addr=%d channel=%d\n", 
        driverName, functionName, addr, channel);
    if (channel == DXP_ALL) { /* All channels */
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
            "%s::%s start DXP_ALL\n", 
            driverName, functionName);
        addr = this->nChannels;
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getAcquisitionStatistics(pasynUser, i);
            getDoubleParam(i, mcaElapsedLiveTime, &dvalue);
            energyLiveTime = MAX(energyLiveTime, dvalue);
            getDoubleParam(i, NDDxpTriggerLiveTime, &dvalue);
            triggerLiveTime = MAX(triggerLiveTime, dvalue);
            getDoubleParam(i, mcaElapsedRealTime, &realTime);
            realTime = MAX(realTime, dvalue);
            getIntegerParam(i, NDDxpEvents, &ivalue);
            events = MAX(events, ivalue);
            getIntegerParam(i, NDDxpOverflows, &ivalue);
            overflows = MAX(overflows, ivalue);
            getIntegerParam(i, NDDxpUnderflows, &ivalue);
            underflows = MAX(underflows, ivalue);
            getIntegerParam(i, NDDxpTriggers, &ivalue);
            triggers = MAX(triggers, ivalue);
            getDoubleParam(i, NDDxpInputCountRate, &dvalue);
            icr = MAX(icr, dvalue);
            getDoubleParam(i, NDDxpOutputCountRate, &dvalue);
            ocr = MAX(ocr, dvalue);
        }
        setDoubleParam(addr, mcaElapsedLiveTime, energyLiveTime);
        setDoubleParam(addr, NDDxpTriggerLiveTime, triggerLiveTime);
        setDoubleParam(addr, mcaElapsedRealTime, realTime);
        setIntegerParam(addr,NDDxpEvents, events);
        setIntegerParam(addr,NDDxpOverflows, overflows);
        setIntegerParam(addr,NDDxpOverflows, overflows);
        setIntegerParam(addr,NDDxpTriggers, triggers);
        setDoubleParam(addr, NDDxpInputCountRate, icr);
        setDoubleParam(addr, NDDxpOutputCountRate, ocr);
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
            "%s::%s end DXP_ALL\n", 
            driverName, functionName);
    } else {
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "%s::%s start channel %d\n", 
            driverName, functionName, addr);
        getIntegerParam(addr, NDDxpErased, &erased);
        if (erased) {
            setDoubleParam(addr, mcaElapsedLiveTime, 0);
            setDoubleParam(addr, mcaElapsedRealTime, 0);
            setIntegerParam(addr, NDDxpEvents, 0);
            setIntegerParam(addr, NDDxpOverflows, 0);
            setIntegerParam(addr, NDDxpUnderflows, 0);
            setDoubleParam(addr, NDDxpInputCountRate, 0);
            setDoubleParam(addr, NDDxpOutputCountRate, 0);
            setIntegerParam(addr, NDDxpTriggers, 0);
            setDoubleParam(addr, NDDxpTriggerLiveTime, 0);
        } else {
            /* We only read the module statistics data if this is the first channel in a module.
             * This assumes we are reading in numerical order, else we may get stale data! */
            if ((channel % this->channelsPerCard) == 0) getModuleStatistics(pasynUser, channel, &moduleStats[0]);
            stats = &moduleStats[channel % this->channelsPerCard];
            /* There is a bug in the Saturn firmware.  It does not correctly compute the energy live time
             * because it ignores overflow and underflow events.  It does correctly include the overflow
             * and underflow events in OCR, so we compute energy live time here. */
            if (this->deviceType == NDDxpModelSaturn) {
                stats->energyLiveTime = stats->realTime * stats->ocr / stats->icr;
            }
            setIntegerParam(addr, NDDxpTriggers, (int)stats->triggers);
            setIntegerParam(addr, NDDxpEvents, (int)stats->events);
            setIntegerParam(addr, NDDxpOverflows, (int)stats->overflows);
            setIntegerParam(addr, NDDxpUnderflows, (int)stats->underflows);
            setDoubleParam(addr, mcaElapsedRealTime, stats->realTime);
            setDoubleParam(addr, mcaElapsedLiveTime, stats->energyLiveTime);
            setDoubleParam(addr, NDDxpTriggerLiveTime, stats->triggerLiveTime);
            setDoubleParam(addr, NDDxpInputCountRate, stats->icr);
            setDoubleParam(addr, NDDxpOutputCountRate, stats->ocr);

            asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
                "%s::%s  channel %d \n"
                "              events=%f\n" 
                "              overflows=%f\n" 
                "              underflows=%f\n" 
                "            triggers=%f\n" 
                "           real time=%f\n" 
                "     energy livetime=%f\n" 
                "    trigger livetime=%f\n" 
                "    input count rate=%f\n" 
                "   output count rate=%f\n",
                driverName, functionName, addr, 
                stats->events,
                stats->overflows,
                stats->underflows,
                stats->triggers,
                stats->realTime,
                stats->energyLiveTime,
                stats->triggerLiveTime,
                stats->icr,
                stats->ocr);
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(asynSuccess);
}

asynStatus NDDxp::getDxpParams(asynUser *pasynUser, int addr)
{
    int i;
    double mcaBinWidth, numMcaChannels;
    double dvalue;
    double emax;
    int channel=addr;
    asynStatus status = asynSuccess;
    int xiastatus;
    unsigned long bufLen;
    double dTmp;
    int collectMode;
    //int listMode;
    int pixelsPerBuffer;
    int pixelsPerRun;
    int syncCount;
    int ignoreGate;
    int inputLogicPolarity;
    NDDxpPixelAdvanceMode_t pixelAdvanceMode;
    const char* functionName = "getDxpParams";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getDxpParams(pasynUser, i);
        }
    } else {
        xiaGetAcquisitionValues(channel, "energy_threshold", &dvalue);
        /* Convert energy threshold from eV to keV */
        dvalue /= 1000.;
        setDoubleParam(channel, NDDxpEnergyThreshold, dvalue);
        xiaGetAcquisitionValues(channel, "peaking_time", &dvalue);
        setDoubleParam(channel, NDDxpPeakingTime, dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "energy_gap_time", &dvalue);
        } else {
            xiaGetAcquisitionValues(channel, "gap_time", &dvalue);
        }
        setDoubleParam(channel, NDDxpGapTime, dvalue);
        xiaGetAcquisitionValues(channel, "trigger_threshold", &dvalue);
        /* Convert trigger threshold from eV to keV */
        dvalue = dvalue / 1000.;
        setDoubleParam(channel, NDDxpTriggerThreshold, dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "trigger_peak_time", &dvalue);
        } else {
            xiaGetAcquisitionValues(channel, "trigger_peaking_time", &dvalue);
        }
        setDoubleParam(channel, NDDxpTriggerPeakingTime, dvalue);
        xiaGetAcquisitionValues(channel, "trigger_gap_time", &dvalue);
        setDoubleParam(channel, NDDxpTriggerGapTime, dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "gain", &dvalue);
            setDoubleParam(channel, NDDxpGain, dvalue);
            xiaGetAcquisitionValues(channel, "gain_trim", &dvalue);
            setDoubleParam(channel, NDDxpFineGain, dvalue);
        } else {        
            xiaGetAcquisitionValues(channel, "preamp_gain", &dvalue);
            setDoubleParam(channel, NDDxpPreampGain, dvalue);
        }
        if ((this->deviceType == NDDxpModelXMAP) ||
            (this->deviceType == NDDxpModelMercury)) {
           xiaGetAcquisitionValues(channel, "baseline_average", &dvalue);
        } else if (this->deviceType == NDDxpModelSaturn) {
           xiaGetAcquisitionValues(channel, "baseline_filter_length", &dvalue);
        } else if (this->deviceType == NDDxpModelMicroDXP) {
           xiaGetAcquisitionValues(channel, "baseline_length", &dvalue);
        }
        setIntegerParam(channel, NDDxpBaselineAverage, (int)dvalue);
        xiaGetAcquisitionValues(channel, "baseline_threshold", &dvalue);
        dvalue/= 1000.;  /* Convert to keV */
        setDoubleParam(channel, NDDxpBaselineThreshold, dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "max_width", &dvalue);
        } else {
            xiaGetAcquisitionValues(channel, "maxwidth", &dvalue);
        }
        setDoubleParam(channel, NDDxpMaxWidth, dvalue);
        if (this->deviceType == NDDxpModelMercury){
            xiaGetAcquisitionValues(channel, "trigger_output", &dvalue);
            setIntegerParam(channel, NDDxpTriggerOutput, (int)dvalue);
            xiaGetAcquisitionValues(channel, "livetime_output", &dvalue);
            setIntegerParam(channel, NDDxpLiveTimeOutput, (int)dvalue);
        }
        if (this->deviceType == NDDxpModelSaturn) {
            xiaGetAcquisitionValues(channel, "baseline_cut", &dvalue);
            setDoubleParam(channel, NDDxpBaselineCut, dvalue);
            xiaGetAcquisitionValues(channel, "enable_baseline_cut", &dvalue);
            setIntegerParam(channel, NDDxpEnableBaselineCut, (int)dvalue);
        } else {
            setDoubleParam(channel, NDDxpBaselineCut, 0.0);
            setIntegerParam(channel, NDDxpEnableBaselineCut, 0);
        }
        if (this->deviceType == NDDxpModelMicroDXP) {
            // Is there anything equivalent to adc_percent_rule for the MicroDXP?
        } else {
            xiaGetAcquisitionValues(channel, "adc_percent_rule", &dvalue);
            setDoubleParam(channel, NDDxpADCPercentRule, dvalue);
        }
        if ((this->deviceType == NDDxpModelXMAP) ||
            (this->deviceType == NDDxpModelMercury)){
            xiaGetAcquisitionValues(channel, "dynamic_range", &dvalue);
        } else dvalue = 0.;
        /* Convert from eV to keV */
        dvalue /= 1000.;
        setDoubleParam(channel, NDDxpDynamicRange, dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            // Is there anything equivalent to calibration_energy for the MicroDXP?
        } else {
            xiaGetAcquisitionValues(channel, "calibration_energy", &dvalue);
            /* Convert from eV to keV */
            dvalue /= 1000.;
            setDoubleParam(channel, NDDxpCalibrationEnergy, dvalue);
        }
        xiaGetAcquisitionValues(channel, "mca_bin_width", &mcaBinWidth);
        /* Convert from eV to keV */
        mcaBinWidth /= 1000.;
        setDoubleParam(channel, NDDxpMCABinWidth, mcaBinWidth);
        xiaGetAcquisitionValues(channel, "number_mca_channels", &numMcaChannels);
        setIntegerParam(channel, mcaNumChannels, (int)numMcaChannels);
        /* Compute emax from mcaBinWidth and mcaNumChannels */
        emax = numMcaChannels * mcaBinWidth;
        setDoubleParam(channel, NDDxpMaxEnergy, emax);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "polarity", &dvalue);
        } else {
            xiaGetAcquisitionValues(channel, "detector_polarity", &dvalue);
        }
        setIntegerParam(channel, NDDxpDetectorPolarity, (int)dvalue);
        if (this->deviceType == NDDxpModelMicroDXP) {
            xiaGetAcquisitionValues(channel, "preamp_value", &dvalue);
            if (this->preampType == NDDxpPreampRC) {
                setDoubleParam(channel, NDDxpDecayTime, dvalue);
            } else {
                setDoubleParam(channel, NDDxpResetDelay, dvalue);
            }
        } else {
            xiaGetAcquisitionValues(channel, "decay_time", &dvalue);
            setDoubleParam(channel, NDDxpDecayTime, dvalue);
            xiaGetAcquisitionValues(channel, "reset_delay", &dvalue);
            setDoubleParam(channel, NDDxpResetDelay, dvalue);
        }
        
        /* If this is an xMAP or Mercury and this is channel 0 then read the mapping parameters */
        if ((channel == 0) && 
            ((this->deviceType == NDDxpModelXMAP) ||
             (this->deviceType == NDDxpModelMercury))) {
            // Read mapping parameters, which are assumed to be the same for all modules 
            dTmp = 0;
            xiastatus = xiaGetAcquisitionValues(channel, "mapping_mode", &dTmp);
            status = this->xia_checkError(pasynUserSelf, xiastatus, "GET mapping_mode");
            asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                "%s::%s [%d] Got mapping_mode = %.1f\n", 
                driverName, functionName, channel, dTmp);
            collectMode = (int)dTmp;
            setIntegerParam(NDDxpCollectMode, collectMode);

            if (collectMode != NDDxpModeMCA) {
                /* list_mode_variant does not seem to be able to be read? */
                //dTmp = 0;
                //xiastatus = xiaGetAcquisitionValues(channel, "list_mode_variant", &dTmp);
                //status = this->xia_checkError(pasynUserSelf, xiastatus, "GET list_mode_variant");
                //asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                //    "%s::%s [%d] Got list_mode_variant = %.1f\n", 
                //    driverName, functionName, channel, dTmp);
                //listMode = (int)dTmp;
                //setIntegerParam(NDDxpListMode, listMode);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "pixel_advance_mode", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET pixel_advance_mode");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got pixel_advance_mode = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                pixelAdvanceMode = NDDxpPixelAdvanceSync;
                if (dTmp == XIA_MAPPING_CTL_GATE) pixelAdvanceMode = NDDxpPixelAdvanceGate;
                setIntegerParam(NDDxpPixelAdvanceMode, pixelAdvanceMode);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "num_map_pixels", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET num_map_pixels");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got num_map_pixels = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                pixelsPerRun = (int)dTmp;
                setIntegerParam(NDDxpPixelsPerRun, pixelsPerRun);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "num_map_pixels_per_buffer", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET num_map_pixels_per_buffer");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got num_map_pixels_per_buffer = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                pixelsPerBuffer = (int)dTmp;
                setIntegerParam(NDDxpPixelsPerBuffer, pixelsPerBuffer);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "sync_count", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET sync_count");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got sync_count = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                /* We add 1 to sync count because xMAP and Mercury actually divides by N+1 */
                syncCount = (int)dTmp + 1;
                setIntegerParam(NDDxpSyncCount, syncCount);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "gate_ignore", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET gate_ignore");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got gate_ignore = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                ignoreGate = (int)dTmp;
                setIntegerParam(NDDxpIgnoreGate, ignoreGate);

                dTmp = 0;
                xiastatus = xiaGetAcquisitionValues(channel, "input_logic_polarity", &dTmp);
                status = this->xia_checkError(pasynUserSelf, xiastatus, "GET input_logic_polarity");
                asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                    "%s::%s [%d] Got input_logic_polarity = %.1f\n", 
                    driverName, functionName, channel, dTmp);
                inputLogicPolarity = (int)dTmp;
                setIntegerParam(NDDxpInputLogicPolarity, inputLogicPolarity);

                /* In list mode Handel returns an error reading buffer_len, so hardcode it */
                if (collectMode == NDDxpModeListMapping) {
                    bufLen = MAPPING_BUFFER_WORDS;
                } 
                else {
                    bufLen = 0;
                    xiastatus = xiaGetRunData(channel, "buffer_len", &bufLen);
                    status = this->xia_checkError(pasynUserSelf, xiastatus, "GET buffer_len");
                    asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
                        "%s::%s [%d] Got buffer_len = %lu\n", 
                        driverName, functionName, channel, bufLen);
                }
                setIntegerParam(channel, NDArraySize, (int)bufLen);
            }
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: status=%d, exit\n",
        driverName, functionName, status);
    return(asynSuccess);
}


asynStatus NDDxp::getLLDxpParams(asynUser *pasynUser, int addr)
{
    int i, numParams, param;
    int channel = ((addr < this->nChannels) ? addr : DXP_ALL);
    static const char *functionName = "getLLDxpParams";
    
    getIntegerParam(NDDxpNumLLParams, &numParams);

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (channel == DXP_ALL) {  /* All channels */
        addr = this->nChannels;
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getLLDxpParams(pasynUser, i);
        }
    } else {
        xiaGetParamData(addr, "values", LLParamValues);
        for (param=0; param<numParams; param++) {
            setIntegerParam(addr, NDDxpLLParamVals[param], LLParamValues[LLParamSort[param]]);
        }
        /* Read the high-level parameters too */
        getDxpParams(pasynUser, addr);
        callParamCallbacks(addr, addr);
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(asynSuccess);
}
        

asynStatus NDDxp::setLLDxpParam(asynUser *pasynUser, int addr, int value)
{
    int i;
    int function = pasynUser->reason;
    asynStatus status = asynSuccess;
    int xiastatus;
    char paramName[MAX_DSP_PARAM_NAME_LEN];
    int channel = ((addr < this->nChannels) ? addr : DXP_ALL);
    static const char* functionName = "setLLDxpParam";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d, value=%d\n",
        driverName, functionName, addr, value);
    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->setLLDxpParam(pasynUser, i, value);
        }
    } else {
        /* Note: we need to get the parameter Name, given pasynUser->reason, which is the index of the
         * parameter Value.  We rely on the fact that createParam is called in the order Name, Value for
         * each low-level parameter, so the index is just one less than pasynUser->reason; */
        getStringParam(addr, function-1, sizeof(paramName), paramName);
        xiastatus = xiaSetParameter(channel, paramName, (unsigned short)value);
        status = xia_checkError(pasynUser, xiastatus, "xiaSetParameter");
        /* Read back the parameters  */
        getLLDxpParams(pasynUser, addr);
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return(status);
}
        

asynStatus NDDxp::getMcaData(asynUser *pasynUser, int addr)
{
    asynStatus status = asynSuccess;
    int xiastatus, paramStatus;
    int arrayCallbacks;
    int nChannels;
    int channel=addr;
    int i;
    //NDArray *pArray;
    NDDataType_t dataType;
    epicsTimeStamp now;
    const char* functionName = "getMcaData";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;

    paramStatus  = getIntegerParam(mcaNumChannels, &nChannels);
    paramStatus |= getIntegerParam(NDArrayCallbacks, &arrayCallbacks);
    paramStatus |= getIntegerParam(NDDataType, (int *)&dataType);

    epicsTimeGetCurrent(&now);

    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getMcaData(pasynUser, i);
        }
    } else {
        /* Read the MCA spectrum from Handel.
        * For most devices this means getting 1 channel spectrum here.
        * For the XMAP we get all 4 channels on the board in one go here */
        CALLHANDEL( xiaGetRunData(addr, "mca", this->pMcaRaw[addr]),"xiaGetRunData")
        asynPrintIO(pasynUser, ASYN_TRACEIO_DRIVER, (const char *)pMcaRaw[addr], nChannels*sizeof(pMcaRaw[0][0]),
            "%s::%s Got MCA spectrum channel:%d ptr:%p\n",
            driverName, functionName, channel, pMcaRaw[addr]);

// In the future we may want to do array callbacks with the MCA data.  For now we are not doing this.
//        if (arrayCallbacks)
//       {
//            /* Allocate a buffer for callback */
//            pArray = this->pNDArrayPool->alloc(1, &nChannels, dataType, 0, NULL);
//            pArray->timeStamp = now.secPastEpoch + now.nsec / 1.e9;
//            pArray->uniqueId = spectrumCounter;
//            /* TODO: Need to copy the data here */
//            doCallbacksGenericPointer(pArray, NDArrayData, addr);
//            pArray->release();
//       }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}

/** Reads the mapping data for all of the modules in the system */
asynStatus NDDxp::getMappingData()
{
    asynStatus status = asynSuccess;
    int xiastatus;
    int arrayCallbacks;
    NDDataType_t dataType;
    int buf = 0, channel, i, k, l;
    NDArray *pArray=NULL;
    epicsUInt16 *pOut=0;
    epicsUInt16 *pStats;
    int mappingMode, pixelOffset, dataOffset, events, triggers, nChans;
    double realTime, triggerLiveTime, energyLiveTime, icr, ocr;
    size_t dims[2];
    int bufferCounter, arraySize;
    epicsTimeStamp now, after;
    double mBytesRead;
    double readoutTime, readoutBurstRate, MBbufSize;
    const char* functionName = "getMappingData";

    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: enter\n",
        driverName, functionName);

    getIntegerParam(NDDataType, (int *)&dataType);
    getIntegerParam(NDDxpBufferCounter, &bufferCounter);
    bufferCounter++;
    setIntegerParam(NDDxpBufferCounter, bufferCounter);
    getIntegerParam(NDArraySize, &arraySize);
    getDoubleParam(NDDxpMBytesRead, &mBytesRead);
    getIntegerParam(NDArrayCallbacks, &arrayCallbacks);
    MBbufSize = (double)((arraySize)*sizeof(epicsUInt16)) / (double)MEGABYTE;

    /* First read and reset the buffers, do this as quickly as possible */
    for (channel=0; channel<this->nChannels; channel+=this->channelsPerCard)
    {
        buf = this->currentBuf[channel];

        /* The buffer is full so read it out */
        epicsTimeGetCurrent(&now);
        xiastatus = xiaGetRunData(channel, NDDxpBufferString[buf], this->pMapTemp);
        status = xia_checkError(this->pasynUserSelf, xiastatus, "GetRunData mapping");
        epicsTimeGetCurrent(&after);
        readoutTime = epicsTimeDiffInSeconds(&after, &now);
        readoutBurstRate = MBbufSize / readoutTime;
        mBytesRead += MBbufSize;
        setDoubleParam(NDDxpMBytesRead, mBytesRead);
        setDoubleParam(NDDxpReadRate, readoutBurstRate);
        /* Notify system that we read out the buffer */
        xiastatus = xiaBoardOperation(channel, "buffer_done", NDDxpBufferCharString[buf]);
        status = xia_checkError(this->pasynUserSelf, xiastatus, "buffer_done");
        if (buf == 0) this->currentBuf[channel] = 1;
        else this->currentBuf[channel] = 0;
        callParamCallbacks();
        /* xisGetRunData requires an unsigned long buffer, but the data are actually only 16 bits.
         * Convert to 16-bit data here */
        for (i=0; i<arraySize; i++) {
            pMapRaw[i] = (epicsUInt16) pMapTemp[i];
        }
    
        asynPrint(this->pasynUserSelf, ASYN_TRACEIO_DRIVER, 
            "%s::%s Got data! size=%.3fMB (%d) dt=%.3fs speed=%.3fMB/s\n",
            driverName, functionName, MBbufSize, arraySize, readoutTime, readoutBurstRate);
        asynPrint(this->pasynUserSelf, ASYN_TRACEIO_DRIVER, 
            "%s::%s channel=%d, tag0=0x%x, tag1=0x%x, headerSize=%d, mappingMode=%d, runNumber=%d, bufferNumber=%d, bufferID=%d, numPixels=%d, firstPixel=%d\n",
            driverName, functionName, channel, pMapRaw[0], pMapRaw[1], pMapRaw[2], pMapRaw[3], pMapRaw[4], pMapRaw[5], pMapRaw[7], pMapRaw[8], pMapRaw[9]);
    
        /* If this is MCA mapping mode then copy the spectral data for the first pixel
         * in this buffer to the mcaRaw buffers.
         * This provides an update of the spectra and statistics while mapping is in progress
         * if the user sets the MCA spectra to periodically read. */
        mappingMode = pMapRaw[3];
        if (mappingMode == NDDxpModeSpectraMapping) {
            pixelOffset = 256;
            dataOffset = pixelOffset + 256;
            for (i=0; i<this->channelsPerCard; i++) {
                k = channel + i;
                nChans = pMapRaw[pixelOffset + 8 + i];
                for (l=0; l<nChans; l++) {
                    pMcaRaw[k][l] = pMapRaw[dataOffset + l];
                }
                dataOffset += nChans;
                pStats = &pMapRaw[pixelOffset + 32 + i*8];
                realTime        = (pStats[0] + (pStats[1]<<16)) * MAPPING_CLOCK_PERIOD;
                triggerLiveTime = (pStats[2] + (pStats[3]<<16)) * MAPPING_CLOCK_PERIOD;
                triggers        =  pStats[4] + (pStats[5]<<16);
                events          =  pStats[6] + (pStats[7]<<16);
                if (triggers > 0.) 
                    energyLiveTime = (triggerLiveTime * events) / triggers;
                else
                    energyLiveTime = triggerLiveTime;
                if (triggerLiveTime > 0.)
                    icr = triggers / triggerLiveTime;
                else
                    icr = 0.;
                if (realTime > 0.)
                    ocr = events / realTime;
                else
                    ocr = 0.;
                setDoubleParam(k, mcaElapsedRealTime, realTime);
                setDoubleParam(k, mcaElapsedLiveTime, energyLiveTime);
                setDoubleParam(k, NDDxpTriggerLiveTime, triggerLiveTime);
                setIntegerParam(k,NDDxpEvents, events);
                setIntegerParam(k, NDDxpTriggers, triggers);
                setDoubleParam(k, NDDxpInputCountRate, icr);
                setDoubleParam(k, NDDxpOutputCountRate, ocr);
                callParamCallbacks(k, k);
            }
        }
            
        if (arrayCallbacks)
        {
            /* Now rearrange the data and do the callbacks */
            /* If this is the first module then allocate an NDArray for the callback */
            if (channel == 0) {
               dims[0] = arraySize;
               dims[1] = this->nCards;
               pArray = this->pNDArrayPool->alloc(2, dims, dataType, 0, NULL );
               pOut = (epicsUInt16 *)pArray->pData;
            }
            
            memcpy(pOut, pMapRaw, arraySize * sizeof(epicsUInt16));
            pOut += arraySize;
        }
    }
    if (arrayCallbacks) 
    {
        pArray->timeStamp = now.secPastEpoch + now.nsec / 1.e9;
        pArray->uniqueId = bufferCounter;
        doCallbacksGenericPointer(pArray, NDArrayData, 0);
        pArray->release();
    }
    asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s::%s Done reading! Ch=%d bufchar=%s\n",
        driverName, functionName, channel, NDDxpBufferCharString[buf]);

    return status;
}

/* Get trace data */
asynStatus NDDxp::getTrace(asynUser* pasynUser, int addr,
                           epicsInt32* data, size_t maxLen, size_t *actualLen)
{
    asynStatus status = asynSuccess;
    int xiastatus, channel=addr;
    int i, j;
    int newTraceTime;
    double info[2];
    double traceTime;
    int traceMode;
    const char *functionName = "getTrace";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getTrace(pasynUser, i, data, maxLen, actualLen);
        }
    } else {
        getDoubleParam(channel, NDDxpTraceTime, &traceTime);
        getIntegerParam(channel, NDDxpNewTraceTime, &newTraceTime);
        getIntegerParam(channel, NDDxpTraceMode, &traceMode);
        info[0] = 0.;
        /* Convert from us to ns */
        info[1] = traceTime * 1000.;

        xiastatus = xiaDoSpecialRun(channel, (char *)NDDxpTraceCommands[traceMode], info);
        status = this->xia_checkError(pasynUser, xiastatus, NDDxpTraceCommands[traceMode]);
        // Don't return error, read it out or we get stuck permanently with module busy
        // if (status == asynError) return asynError;

        *actualLen = this->traceLength;
        if (maxLen < *actualLen) *actualLen = maxLen;

        xiastatus = xiaGetSpecialRunData(channel, "adc_trace", this->traceBuffer);
        status = this->xia_checkError( pasynUser, xiastatus, "adc_trace" );
        if (status == asynError) return status;

        memcpy(data, this->traceBuffer, *actualLen * sizeof(epicsInt32));
        
        if (newTraceTime) {
            setIntegerParam(channel, NDDxpNewTraceTime, 0);  /* Clear flag */
            for (j=0; j<this->traceLength; j++) this->traceTimeBuffer[j] = j*traceTime;
            doCallbacksFloat64Array(this->traceTimeBuffer, this->traceLength, NDDxpTraceTimeArray, channel);
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}

/* Get trace data */
asynStatus NDDxp::getBaselineHistogram(asynUser* pasynUser, int addr,
                                       epicsInt32* data, size_t maxLen, size_t *actualLen)
{
    asynStatus status = asynSuccess;
    int i, j;
    int xiastatus, channel=addr;
    double dynamicRange, keVPerBin, eVPerBin, energyPerBin, offset;
    unsigned short baseBinning, slowLen, baseLen;
    double calibrationEnergy, ADCPercentRule;
    const char *functionName = "getBaselineHistogram";

    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: enter addr=%d\n",
        driverName, functionName, addr);
    if (addr == this->nChannels) channel = DXP_ALL;
    if (channel == DXP_ALL) {  /* All channels */
        for (i=0; i<this->nChannels; i++) {
            /* Call ourselves recursively but with a specific channel */
            this->getTrace(pasynUser, i, data, maxLen, actualLen);
        }
    } else {
        *actualLen = this->baselineLength;
        if (maxLen < *actualLen) *actualLen = maxLen;

        xiastatus = xiaGetRunData(channel, "baseline", this->baselineBuffer);
        status = this->xia_checkError(pasynUser, xiastatus, "baseline" );
        if (status == asynError) return status;

        memcpy(data, this->baselineBuffer, *actualLen * sizeof(epicsInt32));
        
        /* Compute the energy increment per bin */
        if ((this->deviceType == NDDxpModelXMAP) ||
            (this->deviceType == NDDxpModelMercury)) {
            xiaGetAcquisitionValues(channel, "dynamic_range", &dynamicRange);
            keVPerBin = dynamicRange/1024/1000.;
        } else {
            xiaGetParameter(channel, "BASEBINNING", &baseBinning);
            xiaGetParameter(channel, "SLOWLEN", &slowLen);
            xiaGetParameter(channel, "BASELEN", &baseLen);
            xiaGetAcquisitionValues(channel, "calibration_energy", &calibrationEnergy);
            xiaGetAcquisitionValues(channel, "adc_percent_rule", &ADCPercentRule);
            eVPerBin = ((2 << (baseBinning - 1)) * (calibrationEnergy /
                       (4 * slowLen * baseLen))) / (ADCPercentRule / 100.);
            asynPrint(pasynUser, ASYN_TRACEIO_DRIVER,
                "%s:%s: evPerBin=%f, baseBinning=%d, slowLen=%d, baseLen=%d, calibrationEnergy=%f, adc_percent_rule=%f\n",
                driverName, functionName, eVPerBin, baseBinning, slowLen, baseLen, calibrationEnergy, ADCPercentRule);
            keVPerBin = eVPerBin/1000.;
        }
        getDoubleParam(channel, NDDxpBaselineEnergy, &energyPerBin);
        if (keVPerBin != energyPerBin) {
            setDoubleParam(channel, NDDxpBaselineEnergy, keVPerBin);
            offset = -this->baselineLength * keVPerBin/2.;
            for (j=0; j<this->baselineLength; j++) this->baselineEnergyBuffer[j] = offset + j*keVPerBin;
            doCallbacksFloat64Array(this->baselineEnergyBuffer, this->baselineLength, NDDxpBaselineEnergyArray, channel);
        }
    }
    asynPrint(pasynUser, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}



asynStatus NDDxp::startAcquiring(asynUser *pasynUser)
{
    asynStatus status = asynSuccess;
    int xiastatus;
    int channel, addr, i;
    int acquiring, erased, resume=1;
    int firstCh;
    const char *functionName = "startAcquire";

    channel = this->getChannel(pasynUser, &addr);
    getIntegerParam(addr, mcaAcquiring, &acquiring);
    getIntegerParam(addr, NDDxpErased, &erased);
    if (erased) resume=0;

    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW,
        "%s::%s ch=%d acquiring=%d, erased=%d\n",
        driverName, functionName, channel, acquiring, erased);
    /* if already acquiring we just ignore and return */
    if (acquiring) return status;

    /* make sure we use buffer A to start with */
    for (firstCh=0; firstCh<this->nChannels; firstCh+=this->channelsPerCard) this->currentBuf[firstCh] = 0;

    // do xiaStart command
    CALLHANDEL( xiaStartRun(channel, resume), "xiaStartRun()" )

    setIntegerParam(addr, NDDxpErased, 0); /* reset the erased flag */
    setIntegerParam(addr, mcaAcquiring, 1); /* Set the acquiring flag */

    if (channel == DXP_ALL) {
        for (i=0; i<this->nChannels; i++) {
            setIntegerParam(i, mcaAcquiring, 1);
            setIntegerParam(i, NDDxpErased, 0);
            callParamCallbacks(i, i);
        }
    }

    callParamCallbacks(addr, addr);

    // signal cmdStartEvent to start the polling thread
    this->cmdStartEvent->signal();
    asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s: exit\n",
        driverName, functionName);
    return status;
}

/** Thread used to poll the hardware for status and data.
 *
 */
void NDDxp::acquisitionTask()
{
    asynUser *pasynUser = this->pasynUserSelf;
    int paramStatus;
    int i;
    int mode;
    int acquiring = 0;
    epicsFloat64 pollTime, sleeptime, dtmp;
    epicsTimeStamp now, start;
    const char* functionName = "acquisitionTask";

    asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s:%s acquisition task started!\n",
        driverName, functionName);
//    epicsEventTryWait(this->stopEventId); /* clear the stop event if it wasn't already */

    this->lock();

    while (this->polling) /* ... round and round and round we go until the IOC is shut down */
    {

        getIntegerParam(this->nChannels, mcaAcquiring, &acquiring);

        if (!acquiring)
        {
            /* Release the lock while we wait for an event that says acquire has started, then lock again */
            this->unlock();
            /* Wait for someone to signal the cmdStartEvent */
            asynPrint(pasynUser, ASYN_TRACE_FLOW, 
                "%s:%s Waiting for acquisition to start!\n",
                driverName, functionName);
            this->cmdStartEvent->wait();
            this->lock();
            getIntegerParam(NDDxpCollectMode, &mode);
            asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
                "%s::%s [%s]: started! (mode=%d)\n", 
                driverName, functionName, this->portName, mode);
        }
        epicsTimeGetCurrent(&start);

        /* In this loop we only read the acquisition status to minimise overhead.
         * If a transition from acquiring to done is detected then we read the statistics
         * and the data. */
        this->getAcquisitionStatus(this->pasynUserSelf, DXP_ALL);
        getIntegerParam(this->nChannels, NDDxpAcquiring, &acquiring);
        if (!acquiring)
        {
            /* There must have just been a transition from acquiring to not acquiring */

            if (mode == NDDxpModeMCA) {
                /* In MCA mode we force a read of the data */
                asynPrint(pasynUser, ASYN_TRACE_FLOW, 
                    "%s::%s Detected acquisition stop! Now reading statistics\n",
                    driverName, functionName);
                this->getAcquisitionStatistics(this->pasynUserSelf, DXP_ALL);
                asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
                    "%s::%s Detected acquisition stop! Now reading data\n",
                    driverName, functionName);
                this->getMcaData(this->pasynUserSelf, DXP_ALL);
                this->getSCAData(this->pasynUserSelf, DXP_ALL);
            }
            else {
                /* In mapping modes need to make an extra call to pollMappingMode because there could be
                 * 2 mapping mode buffers that still need to be read out. 
                 * This call will read out the first one, and just below this !acquiring block
                 * there is a second call to pollMapping mode which is
                 * done on every main loop in mapping modes. */
                 this->pollMappingMode();
            }
        } 
        if (mode != NDDxpModeMCA)
        {
            this->pollMappingMode();
        }

        /* Do callbacks for all channels for everything except mcaAcquiring*/
        for (i=0; i<=this->nChannels; i++) callParamCallbacks(i, i);
        /* Copy internal acquiring flag to mcaAcquiring */
        for (i=0; i<=this->nChannels; i++) {
            getIntegerParam(i, NDDxpAcquiring, &acquiring);
            setIntegerParam(i, mcaAcquiring, acquiring);
            callParamCallbacks(i, i);
        }
        
        paramStatus |= getDoubleParam(NDDxpPollTime, &pollTime);
        epicsTimeGetCurrent(&now);
        dtmp = epicsTimeDiffInSeconds(&now, &start);
        sleeptime = pollTime - dtmp;
        if (sleeptime > 0.0)
        {
            //asynPrint(pasynUser, ASYN_TRACE_FLOW, 
            //    "%s::%s Sleeping for %f seconds\n",
            //    driverName, functionName, sleeptime);
            this->unlock();
            epicsThreadSleep(sleeptime);
            this->lock();
        }
    }
}

/** Check if the current mapping buffer is full in which case it reads out the data */
asynStatus NDDxp::pollMappingMode()
{
    asynStatus status = asynSuccess;
    asynUser *pasynUser = this->pasynUserSelf;
    int xiastatus;
    int ignored;
    int ch, buf=0, allFull=1, anyFull=0;
    unsigned short isFull;
    unsigned long currentPixel = 0;
    const char* functionName = "pollMappingMode";
    NDDxpCollectMode_t mappingMode;
    
    getIntegerParam(NDDxpCollectMode, (int *)&mappingMode);

    for (ch=0; ch<this->nChannels; ch+=this->channelsPerCard)
    {
        buf = this->currentBuf[ch];

        if (mappingMode == NDDxpModeListMapping) {
            CALLHANDEL( xiaGetRunData(ch, NDDxpListBufferLenString[buf], &currentPixel), "NDDxpListBufferLenString[buf]")
        }
        else {
            CALLHANDEL( xiaGetRunData(ch, "current_pixel", &currentPixel) , "current_pixel" )
        }
        setIntegerParam(ch, NDDxpCurrentPixel, (int)currentPixel);
        callParamCallbacks(ch);
        CALLHANDEL( xiaGetRunData(ch, NDDxpBufferFullString[buf], &isFull), "NDDxpBufferFullString[buf]" )
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
            "%s::%s %s isfull=%d\n",
            driverName, functionName, NDDxpBufferFullString[buf], isFull);
        if (!isFull) allFull = 0;
        if (isFull)  anyFull = 1;
    }

    /* In list mapping mode if any buffer is full then switch buffers on the non-full ones.
     * Note: this is prone to error because they could have already switched! */
    if (anyFull && (mappingMode == NDDxpModeListMapping)) {
        for (ch=0; ch<this->nChannels; ch+=this->channelsPerCard) {
            CALLHANDEL( xiaGetRunData(ch, NDDxpBufferFullString[buf], &isFull), "NDDxpBufferFullString[buf]" )
            if (isFull) continue;
            CALLHANDEL( xiaBoardOperation(ch, "buffer_switch", &ignored), "buffer_switch" )
        }
        /* Now wait until all modules report they are full */
        do {
            allFull = 1;
            for (ch=0; ch<this->nChannels; ch+=this->channelsPerCard) {
                CALLHANDEL( xiaGetRunData(ch, NDDxpBufferFullString[buf], &isFull), "NDDxpBufferFullString[buf]" )
                if (!isFull) allFull = 0;
            }
        } while (allFull != 1);
    }
    /* If all of the modules have full buffers then read them all out */
    if (allFull)
    {
        status = this->getMappingData();
    }
    return status;
}


void NDDxp::report(FILE *fp, int details)
{
    asynNDArrayDriver::report(fp, details);
}



asynStatus NDDxp::xia_checkError( asynUser* pasynUser, epicsInt32 xiastatus, const char *xiacmd )
{
    if (xiastatus == XIA_SUCCESS) return asynSuccess;

    asynPrint( pasynUser, ASYN_TRACE_ERROR, 
        "### NDDxp: XIA ERROR: %d (%s)\n", 
        xiastatus, xiacmd );
    return asynError;
}

void NDDxp::shutdown()
{
    int status;
    double pollTime;
    
    getDoubleParam(NDDxpPollTime, &pollTime);
    asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, 
        "%s: shutting down in %f seconds\n", driverName, 2*pollTime);
    this->polling = 0;
    epicsThreadSleep(2*pollTime);
    status = xiaExit();
    if (status == XIA_SUCCESS)
    {
        printf("%s shut down successfully.\n",
            driverName);
        return;
    }
    printf("xiaExit() error: %d\n", status);
    return;
}

int NDDxp::getModuleType()
{
    /* This function returns an enum of type DXP_MODULE_TYPE for the module type.
     * It returns the type of the first module in the system.
     * IMPORTANT ASSUMPTION: It is assumed that a single EPICS IOC will only
     * be controlling a single type of XIA module (xMAP, Mercury, Saturn, MicroDXP)
     * If there is an error it returns -1.
     */
    char module_alias[MAXALIAS_LEN];
    char module_type[MAXITEM_LEN];
    int status = 0;

    /* Get the module alias for the first channel */
    status |= xiaGetModules_VB(0, module_alias);
    /* Get the module type for this module */
    status |= xiaGetModuleItem(module_alias, "module_type", module_type);
    /* Get the number of channels per module for this module */
    status |= xiaGetModuleItem(module_alias, "number_of_channels", &this->channelsPerCard);
    if (status) return -1;
    /* Look for known module types */
    if (strcmp(module_type, "xmap") == 0) return(NDDxpModelXMAP);
    if (strcmp(module_type, "dxpx10p") == 0) return(NDDxpModelSaturn);
    if (strcmp(module_type, "udxp") == 0) return(NDDxpModelMicroDXP);
    if (strcmp(module_type, "mercury") == 0) return(NDDxpModelMercury);
    return -1;
}

static const iocshArg NDDxpConfigArg0 = {"Asyn port name", iocshArgString};
static const iocshArg NDDxpConfigArg1 = {"Number of channels", iocshArgInt};
static const iocshArg NDDxpConfigArg2 = {"Maximum number of buffers", iocshArgInt};
static const iocshArg NDDxpConfigArg3 = {"Maximum amount of memory (bytes)", iocshArgInt};
static const iocshArg * const NDDxpConfigArgs[] =  {&NDDxpConfigArg0,
                                                    &NDDxpConfigArg1,
                                                    &NDDxpConfigArg2,
                                                    &NDDxpConfigArg3};
static const iocshFuncDef configNDDxp = {"NDDxpConfig", 4, NDDxpConfigArgs};
static void configNDDxpCallFunc(const iocshArgBuf *args)
{
    NDDxpConfig(args[0].sval, args[1].ival, args[2].ival, args[3].ival);
}

static const iocshArg xiaLogLevelArg0 = { "logging level",iocshArgInt};
static const iocshArg * const xiaLogLevelArgs[1] = {&xiaLogLevelArg0};
static const iocshFuncDef xiaLogLevelFuncDef = {"xiaSetLogLevel",1,xiaLogLevelArgs};
static void xiaLogLevelCallFunc(const iocshArgBuf *args)
{
    xiaSetLogLevel(args[0].ival);
}

static const iocshArg xiaLogOutputArg0 = { "logging output file",iocshArgString};
static const iocshArg * const xiaLogOutputArgs[1] = {&xiaLogOutputArg0};
static const iocshFuncDef xiaLogOutputFuncDef = {"xiaSetLogOutput",1,xiaLogOutputArgs};
static void xiaLogOutputCallFunc(const iocshArgBuf *args)
{
    xiaSetLogOutput(args[0].sval);
}

static const iocshArg xiaInitArg0 = { "ini file",iocshArgString};
static const iocshArg * const xiaInitArgs[1] = {&xiaInitArg0};
static const iocshFuncDef xiaInitFuncDef = {"xiaInit",1,xiaInitArgs};
static void xiaInitCallFunc(const iocshArgBuf *args)
{
    xiaInit(args[0].sval);
}

static const iocshFuncDef xiaStartSystemFuncDef = {"xiaStartSystem",0,0};
static void xiaStartSystemCallFunc(const iocshArgBuf *args)
{
    xiaStartSystem();
}

static const iocshArg xiaSaveSystemArg0 = { "ini file",iocshArgString};
static const iocshArg * const xiaSaveSystemArgs[1] = {&xiaSaveSystemArg0};
static const iocshFuncDef xiaSaveSystemFuncDef = {"xiaSaveSystem",1,xiaSaveSystemArgs};
static void xiaSaveSystemCallFunc(const iocshArgBuf *args)
{
    xiaSaveSystem((char *)"handel_ini", args[0].sval);
}



static void NDDxpRegister(void)
{
    iocshRegister(&configNDDxp, configNDDxpCallFunc);
    iocshRegister(&xiaInitFuncDef,xiaInitCallFunc);
    iocshRegister(&xiaLogLevelFuncDef,xiaLogLevelCallFunc);
    iocshRegister(&xiaLogOutputFuncDef,xiaLogOutputCallFunc);
    iocshRegister(&xiaStartSystemFuncDef,xiaStartSystemCallFunc);
    iocshRegister(&xiaSaveSystemFuncDef,xiaSaveSystemCallFunc);
}

extern "C" {
epicsExportRegistrar(NDDxpRegister);
}
