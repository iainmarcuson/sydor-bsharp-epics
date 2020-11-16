/* digitelRecord.h generated from digitelRecord.dbd */

#ifndef INC_digitelRecord_H
#define INC_digitelRecord_H

#include "devSup.h"

/* Declare Device Support Entry Table */
struct digitelRecord;
typedef struct {
    dset common;
    long (* readWrite)(struct digitelRecord *pr);
} digiteldset;

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    digitelS1VS_Off                 /* Off */,
    digitelS1VS_On                  /* On */
} digitelS1VS;
#define digitelS1VS_NUM_CHOICES 2

typedef enum {
    digitelMODR_STBY                /* STBY */,
    digitelMODR_OPER                /* OPER */,
    digitelMODR_CONN                /* CONN */,
    digitelMODR_COOL                /* COOL */,
    digitelMODR_PERR                /* PERR */,
    digitelMODR_LOCK                /* LOCK */
} digitelMODR;
#define digitelMODR_NUM_CHOICES 6

typedef enum {
    digitelS3BS_Real_Time           /* Real Time */,
    digitelS3BS_Heat_On_Time        /* Heat On Time */
} digitelS3BS;
#define digitelS3BS_NUM_CHOICES 2

typedef enum {
    digitelCMOR_Off                 /* Off */,
    digitelCMOR_On                  /* On */
} digitelCMOR;
#define digitelCMOR_NUM_CHOICES 2

typedef enum {
    digitelDSPL_VOLTS               /* VOLTS */,
    digitelDSPL_CURR                /* CURR */,
    digitelDSPL_PRES                /* PRES */
} digitelDSPL;
#define digitelDSPL_NUM_CHOICES 3

typedef enum {
    digitelTYPE_Digitel_MPC         /* MPC */,
    digitelTYPE_Digitel_500         /* D500 */,
    digitelTYPE_Digitel_1500        /* D1500 */,
    digitelTYPE_Digitel_QPC         /* QPC */
} digitelTYPE;
#define digitelTYPE_NUM_CHOICES 4

typedef enum {
    digitelMODS_STBY                /* STBY */,
    digitelMODS_OPER                /* OPER */
} digitelMODS;
#define digitelMODS_NUM_CHOICES 2

typedef enum {
    digitelSET1_Off                 /* Off */,
    digitelSET1_On                  /* On */
} digitelSET1;
#define digitelSET1_NUM_CHOICES 2

typedef enum {
    digitelBKIN_Absent              /* Absent */,
    digitelBKIN_Installed           /* Installed */
} digitelBKIN;
#define digitelBKIN_NUM_CHOICES 2

typedef enum {
    digitelBAKS_Disabled            /* Disabled */,
    digitelBAKS_Enabled             /* Enabled */
} digitelBAKS;
#define digitelBAKS_NUM_CHOICES 2

typedef enum {
    digitelKLCK_Unlocked            /* Unlocked */,
    digitelKLCK_Locked              /* Locked */
} digitelKLCK;
#define digitelKLCK_NUM_CHOICES 2

typedef enum {
    digitelS1MS_Pressure            /* Pressure */,
    digitelS1MS_Current             /* Current */
} digitelS1MS;
#define digitelS1MS_NUM_CHOICES 2

typedef enum {
    digitelPTYP_30__Liter_sec       /* 30  Liter/sec */,
    digitelPTYP_60__Liter_sec       /* 60  Liter/sec */,
    digitelPTYP_120_Liter_sec       /* 120 Liter/sec */,
    digitelPTYP_220_Liter_sec       /* 220 Liter/sec */,
    digitelPTYP_400_Liter_sec       /* 400 Liter/sec */,
    digitelPTYP_700_Liter_sec       /* 700 Liter/sec */,
    digitelPTYP_1200_Liter_sec      /* 1200 Liter/sec */
} digitelPTYP;
#define digitelPTYP_NUM_CHOICES 7

typedef struct digitelRecord {
    char                name[61];   /* Record Name */
    char                desc[41];   /* Descriptor */
    char                asg[29];    /* Access Security Group */
    epicsEnum16         scan;       /* Scan Mechanism */
    epicsEnum16         pini;       /* Process at iocInit */
    epicsInt16          phas;       /* Scan Phase */
    char                evnt[40];   /* Event Name */
    epicsInt16          tse;        /* Time Stamp Event */
    DBLINK              tsel;       /* Time Stamp Link */
    epicsEnum16         dtyp;       /* Device Type */
    epicsInt16          disv;       /* Disable Value */
    epicsInt16          disa;       /* Disable */
    DBLINK              sdis;       /* Scanning Disable */
    epicsMutexId        mlok;       /* Monitor lock */
    ELLLIST             mlis;       /* Monitor List */
    epicsUInt8          disp;       /* Disable putField */
    epicsUInt8          proc;       /* Force Processing */
    epicsEnum16         stat;       /* Alarm Status */
    epicsEnum16         sevr;       /* Alarm Severity */
    epicsEnum16         nsta;       /* New Alarm Status */
    epicsEnum16         nsev;       /* New Alarm Severity */
    epicsEnum16         acks;       /* Alarm Ack Severity */
    epicsEnum16         ackt;       /* Alarm Ack Transient */
    epicsEnum16         diss;       /* Disable Alarm Sevrty */
    epicsUInt8          lcnt;       /* Lock Count */
    epicsUInt8          pact;       /* Record active */
    epicsUInt8          putf;       /* dbPutField process */
    epicsUInt8          rpro;       /* Reprocess  */
    struct asgMember    *asp;       /* Access Security Pvt */
    struct processNotify *ppn;      /* pprocessNotify */
    struct processNotifyRecord *ppnr; /* pprocessNotifyRecord */
    struct scan_element *spvt;      /* Scan Private */
    struct rset         *rset;      /* Address of RSET */
    struct dset         *dset;      /* DSET address */
    void                *dpvt;      /* Device Private */
    struct dbRecordType *rdes;      /* Address of dbRecordType */
    struct lockRecord   *lset;      /* Lock Set */
    epicsEnum16         prio;       /* Scheduling Priority */
    epicsUInt8          tpro;       /* Trace Processing */
    char                bkpt;       /* Break Point */
    epicsUInt8          udf;        /* Undefined */
    epicsEnum16         udfs;       /* Undefined Alarm Sevrty */
    epicsTimeStamp      time;       /* Time */
    DBLINK              flnk;       /* Forward Process Link */
    char                modl[13];   /* Device Model Number */
    char                vers[10];   /* Device Firmware Vers */
    DBLINK              inp;        /* Device Specification */
    epicsFloat64        val;        /* Pressure */
    epicsFloat64        lval;       /* Pressure (log10 form) */
    epicsFloat64        hihi;       /* Pressure Hihi Alarm */
    epicsFloat64        lolo;       /* Pressure Lolo Alarm */
    epicsFloat64        high;       /* Pressure High Alarm */
    epicsFloat64        low;        /* Pressure Low Alarm */
    epicsEnum16         hhsv;       /* Pressure Hihi Severity */
    epicsEnum16         llsv;       /* Pressure Lolo Severity */
    epicsEnum16         hsv;        /* Pressure High Severity */
    epicsEnum16         lsv;        /* Pressure Low Severity */
    epicsFloat64        hyst;       /* Alarm Deadband */
    epicsFloat64        lalm;       /* Last Value Alarmed */
    epicsEnum16         dspl;       /* Display Mode */
    epicsEnum16         klck;       /* Keyboard Lock */
    epicsEnum16         mods;       /* Mode */
    epicsEnum16         modr;       /* Mode Readback */
    epicsEnum16         baks;       /* Bake */
    epicsEnum16         bakr;       /* Bake Readback */
    epicsFloat64        cool;       /* Cooldown Time */
    epicsEnum16         cmor;       /* Cooldown Mode */
    epicsEnum16         set1;       /* Setpoint 1 */
    epicsEnum16         set2;       /* Setpoint 2 */
    epicsEnum16         set3;       /* Setpoint 3 */
    epicsEnum16         set4;       /* Setpoint 4 */
    epicsFloat64        accw;       /* Acc Power */
    epicsFloat64        acci;       /* Acc Current */
    epicsEnum16         ptyp;       /* Pump Type */
    epicsEnum16         type;       /* Controller Type */
    epicsFloat64        sp1s;       /* SP1 Setpoint */
    epicsFloat64        sp1r;       /* SP1 SP Readback */
    epicsFloat64        s1hs;       /* SP1 Hysteresis */
    epicsFloat64        s1hr;       /* SP1 HY Readback */
    epicsEnum16         s1ms;       /* SP1 Mode */
    epicsEnum16         s1mr;       /* SP1 Mode Readback */
    epicsEnum16         s1vs;       /* SP1 HV Interlock */
    epicsEnum16         s1vr;       /* SP1 HVI Readback */
    epicsFloat64        sp2s;       /* SP2 Setpoint */
    epicsFloat64        sp2r;       /* SP2 SP Readback */
    epicsFloat64        s2hs;       /* SP2 Hysteresis */
    epicsFloat64        s2hr;       /* SP2 HY Readback */
    epicsEnum16         s2ms;       /* SP2 Mode */
    epicsEnum16         s2mr;       /* SP2 Mode Readback */
    epicsEnum16         s2vs;       /* SP2 HV Interlock */
    epicsEnum16         s2vr;       /* SP2 HVI Readback */
    epicsFloat64        sp3s;       /* SP3 Setpoint */
    epicsFloat64        sp3r;       /* SP3 SP Readback */
    epicsFloat64        s3hs;       /* SP3 Hysteresis */
    epicsFloat64        s3hr;       /* SP3 HY Readback */
    epicsEnum16         s3ms;       /* SP3 Mode */
    epicsEnum16         s3mr;       /* SP3 Mode Readback */
    epicsEnum16         s3vs;       /* SP3 HV Interlock */
    epicsEnum16         s3vr;       /* SP3 HVI Readback */
    epicsEnum16         s3bs;       /* Bake Time Mode Set */
    epicsEnum16         s3br;       /* Bake Time Mode Read */
    epicsFloat64        s3ts;       /* Bake Time Set */
    epicsFloat64        s3tr;       /* Bake Time Read */
    epicsFloat64        sp4s;       /* SP4 Setpoint */
    epicsFloat64        sp4r;       /* SP4 SP Readback */
    epicsFloat64        s4hs;       /* SP4 Hysteresis */
    epicsFloat64        s4hr;       /* SP4 HY Readback */
    epicsEnum16         s4ms;       /* SP4 Mode */
    epicsEnum16         s4mr;       /* SP4 Mode Readback */
    epicsEnum16         s4vs;       /* SP4 HV Interlock */
    epicsEnum16         s4vr;       /* SP4 HVI Readback */
    epicsFloat32        hopr;       /* Pressure Display Hi */
    epicsFloat32        lopr;       /* Pressure Display Lo */
    epicsFloat32        hctr;       /* Current Display Hi */
    epicsFloat32        lctr;       /* Current Display Lo */
    epicsFloat32        hvtr;       /* Voltage Display Hi */
    epicsFloat32        lvtr;       /* Voltage Display Lo */
    epicsFloat32        hlpr;       /* Log Pres Display Hi */
    epicsFloat32        llpr;       /* Log Pres Display Lo */
    DBLINK              siml;       /* Sim Mode Location */
    epicsEnum16         simm;       /* Sim Mode Value */
    DBLINK              slmo;       /* Sim Location Mode */
    epicsEnum16         svmo;       /* Sim Value Mode */
    DBLINK              sls1;       /* Sim Location SP1 */
    epicsEnum16         svs1;       /* Sim Value SP1 */
    DBLINK              sls2;       /* Sim Location SP2 */
    epicsEnum16         svs2;       /* Sim Value SP2 */
    DBLINK              slcr;       /* Sim Location Current */
    epicsFloat64        svcr;       /* Sim Value Current */
    epicsUInt32         tonl;       /* Time Online */
    epicsFloat64        crnt;       /* Current */
    epicsFloat64        volt;       /* Voltage */
    epicsUInt32         flgs;       /* Mod Flags */
    epicsUInt32         spfg;       /* Setpoint Flags */
    epicsEnum16         bkin;       /* Bake Installed */
    epicsFloat64        ival;       /* init pressure */
    epicsFloat64        ilva;       /* init pressure (log10) */
    epicsEnum16         imod;       /* init mode */
    epicsEnum16         ibak;       /* init bake */
    epicsFloat64        icol;       /* init cooldown time */
    epicsEnum16         isp1;       /* init set1 */
    epicsEnum16         isp2;       /* init set2 */
    epicsEnum16         isp3;       /* init set3 */
    epicsEnum16         isp4;       /* init set4 */
    epicsFloat64        iacw;       /* init Acc power */
    epicsFloat64        iaci;       /* init Acc current */
    epicsEnum16         ipty;       /* init pump type */
    epicsEnum16         ibkn;       /* init Bake Installed */
    epicsFloat64        is1;        /* init sp1 */
    epicsFloat64        ih1;        /* init sp1 HY */
    epicsEnum16         im1;        /* init sp1 mode */
    epicsEnum16         ii1;        /* init sp1 HVI */
    epicsFloat64        is2;        /* init sp2 */
    epicsFloat64        ih2;        /* init sp2 HY */
    epicsEnum16         im2;        /* init sp2 mode */
    epicsEnum16         ii2;        /* init sp2 HVI */
    epicsFloat64        is3;        /* init sp3 */
    epicsFloat64        ih3;        /* init sp3 HY */
    epicsEnum16         im3;        /* init sp3 mode */
    epicsEnum16         ii3;        /* init sp3 HVI */
    epicsEnum16         ib3;        /* init sp3 bake time md */
    epicsFloat64        is4;        /* init sp4 */
    epicsFloat64        ih4;        /* init sp4 HY */
    epicsEnum16         im4;        /* init sp4 mode */
    epicsEnum16         ii4;        /* init sp4 HVI */
    epicsFloat64        it3;        /* init sp3 bake time */
    epicsUInt32         iton;       /* init tonl */
    epicsFloat64        icrn;       /* init current */
    epicsFloat64        ivol;       /* init voltage */
    epicsInt32          cycl;       /* Cycle count */
    epicsInt16          err;        /* Error Count */
    epicsInt16          ierr;       /* init Error Count */
} digitelRecord;

typedef enum {
	digitelRecordNAME = 0,
	digitelRecordDESC = 1,
	digitelRecordASG = 2,
	digitelRecordSCAN = 3,
	digitelRecordPINI = 4,
	digitelRecordPHAS = 5,
	digitelRecordEVNT = 6,
	digitelRecordTSE = 7,
	digitelRecordTSEL = 8,
	digitelRecordDTYP = 9,
	digitelRecordDISV = 10,
	digitelRecordDISA = 11,
	digitelRecordSDIS = 12,
	digitelRecordMLOK = 13,
	digitelRecordMLIS = 14,
	digitelRecordDISP = 15,
	digitelRecordPROC = 16,
	digitelRecordSTAT = 17,
	digitelRecordSEVR = 18,
	digitelRecordNSTA = 19,
	digitelRecordNSEV = 20,
	digitelRecordACKS = 21,
	digitelRecordACKT = 22,
	digitelRecordDISS = 23,
	digitelRecordLCNT = 24,
	digitelRecordPACT = 25,
	digitelRecordPUTF = 26,
	digitelRecordRPRO = 27,
	digitelRecordASP = 28,
	digitelRecordPPN = 29,
	digitelRecordPPNR = 30,
	digitelRecordSPVT = 31,
	digitelRecordRSET = 32,
	digitelRecordDSET = 33,
	digitelRecordDPVT = 34,
	digitelRecordRDES = 35,
	digitelRecordLSET = 36,
	digitelRecordPRIO = 37,
	digitelRecordTPRO = 38,
	digitelRecordBKPT = 39,
	digitelRecordUDF = 40,
	digitelRecordUDFS = 41,
	digitelRecordTIME = 42,
	digitelRecordFLNK = 43,
	digitelRecordMODL = 44,
	digitelRecordVERS = 45,
	digitelRecordINP = 46,
	digitelRecordVAL = 47,
	digitelRecordLVAL = 48,
	digitelRecordHIHI = 49,
	digitelRecordLOLO = 50,
	digitelRecordHIGH = 51,
	digitelRecordLOW = 52,
	digitelRecordHHSV = 53,
	digitelRecordLLSV = 54,
	digitelRecordHSV = 55,
	digitelRecordLSV = 56,
	digitelRecordHYST = 57,
	digitelRecordLALM = 58,
	digitelRecordDSPL = 59,
	digitelRecordKLCK = 60,
	digitelRecordMODS = 61,
	digitelRecordMODR = 62,
	digitelRecordBAKS = 63,
	digitelRecordBAKR = 64,
	digitelRecordCOOL = 65,
	digitelRecordCMOR = 66,
	digitelRecordSET1 = 67,
	digitelRecordSET2 = 68,
	digitelRecordSET3 = 69,
	digitelRecordSET4 = 70,
	digitelRecordACCW = 71,
	digitelRecordACCI = 72,
	digitelRecordPTYP = 73,
	digitelRecordTYPE = 74,
	digitelRecordSP1S = 75,
	digitelRecordSP1R = 76,
	digitelRecordS1HS = 77,
	digitelRecordS1HR = 78,
	digitelRecordS1MS = 79,
	digitelRecordS1MR = 80,
	digitelRecordS1VS = 81,
	digitelRecordS1VR = 82,
	digitelRecordSP2S = 83,
	digitelRecordSP2R = 84,
	digitelRecordS2HS = 85,
	digitelRecordS2HR = 86,
	digitelRecordS2MS = 87,
	digitelRecordS2MR = 88,
	digitelRecordS2VS = 89,
	digitelRecordS2VR = 90,
	digitelRecordSP3S = 91,
	digitelRecordSP3R = 92,
	digitelRecordS3HS = 93,
	digitelRecordS3HR = 94,
	digitelRecordS3MS = 95,
	digitelRecordS3MR = 96,
	digitelRecordS3VS = 97,
	digitelRecordS3VR = 98,
	digitelRecordS3BS = 99,
	digitelRecordS3BR = 100,
	digitelRecordS3TS = 101,
	digitelRecordS3TR = 102,
	digitelRecordSP4S = 103,
	digitelRecordSP4R = 104,
	digitelRecordS4HS = 105,
	digitelRecordS4HR = 106,
	digitelRecordS4MS = 107,
	digitelRecordS4MR = 108,
	digitelRecordS4VS = 109,
	digitelRecordS4VR = 110,
	digitelRecordHOPR = 111,
	digitelRecordLOPR = 112,
	digitelRecordHCTR = 113,
	digitelRecordLCTR = 114,
	digitelRecordHVTR = 115,
	digitelRecordLVTR = 116,
	digitelRecordHLPR = 117,
	digitelRecordLLPR = 118,
	digitelRecordSIML = 119,
	digitelRecordSIMM = 120,
	digitelRecordSLMO = 121,
	digitelRecordSVMO = 122,
	digitelRecordSLS1 = 123,
	digitelRecordSVS1 = 124,
	digitelRecordSLS2 = 125,
	digitelRecordSVS2 = 126,
	digitelRecordSLCR = 127,
	digitelRecordSVCR = 128,
	digitelRecordTONL = 129,
	digitelRecordCRNT = 130,
	digitelRecordVOLT = 131,
	digitelRecordFLGS = 132,
	digitelRecordSPFG = 133,
	digitelRecordBKIN = 134,
	digitelRecordIVAL = 135,
	digitelRecordILVA = 136,
	digitelRecordIMOD = 137,
	digitelRecordIBAK = 138,
	digitelRecordICOL = 139,
	digitelRecordISP1 = 140,
	digitelRecordISP2 = 141,
	digitelRecordISP3 = 142,
	digitelRecordISP4 = 143,
	digitelRecordIACW = 144,
	digitelRecordIACI = 145,
	digitelRecordIPTY = 146,
	digitelRecordIBKN = 147,
	digitelRecordIS1 = 148,
	digitelRecordIH1 = 149,
	digitelRecordIM1 = 150,
	digitelRecordII1 = 151,
	digitelRecordIS2 = 152,
	digitelRecordIH2 = 153,
	digitelRecordIM2 = 154,
	digitelRecordII2 = 155,
	digitelRecordIS3 = 156,
	digitelRecordIH3 = 157,
	digitelRecordIM3 = 158,
	digitelRecordII3 = 159,
	digitelRecordIB3 = 160,
	digitelRecordIS4 = 161,
	digitelRecordIH4 = 162,
	digitelRecordIM4 = 163,
	digitelRecordII4 = 164,
	digitelRecordIT3 = 165,
	digitelRecordITON = 166,
	digitelRecordICRN = 167,
	digitelRecordIVOL = 168,
	digitelRecordCYCL = 169,
	digitelRecordERR = 170,
	digitelRecordIERR = 171
} digitelFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int digitelRecordSizeOffset(dbRecordType *prt)
{
    digitelRecord *prec = 0;

    assert(prt->no_fields == 172);
    prt->papFldDes[digitelRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[digitelRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[digitelRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[digitelRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[digitelRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[digitelRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[digitelRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[digitelRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[digitelRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[digitelRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[digitelRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[digitelRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[digitelRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[digitelRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[digitelRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[digitelRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[digitelRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[digitelRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[digitelRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[digitelRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[digitelRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[digitelRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[digitelRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[digitelRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[digitelRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[digitelRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[digitelRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[digitelRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[digitelRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[digitelRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[digitelRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[digitelRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[digitelRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[digitelRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[digitelRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[digitelRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[digitelRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[digitelRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[digitelRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[digitelRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[digitelRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[digitelRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[digitelRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[digitelRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[digitelRecordMODL]->size = sizeof(prec->modl);
    prt->papFldDes[digitelRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[digitelRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[digitelRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[digitelRecordLVAL]->size = sizeof(prec->lval);
    prt->papFldDes[digitelRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[digitelRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[digitelRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[digitelRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[digitelRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[digitelRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[digitelRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[digitelRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[digitelRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[digitelRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[digitelRecordDSPL]->size = sizeof(prec->dspl);
    prt->papFldDes[digitelRecordKLCK]->size = sizeof(prec->klck);
    prt->papFldDes[digitelRecordMODS]->size = sizeof(prec->mods);
    prt->papFldDes[digitelRecordMODR]->size = sizeof(prec->modr);
    prt->papFldDes[digitelRecordBAKS]->size = sizeof(prec->baks);
    prt->papFldDes[digitelRecordBAKR]->size = sizeof(prec->bakr);
    prt->papFldDes[digitelRecordCOOL]->size = sizeof(prec->cool);
    prt->papFldDes[digitelRecordCMOR]->size = sizeof(prec->cmor);
    prt->papFldDes[digitelRecordSET1]->size = sizeof(prec->set1);
    prt->papFldDes[digitelRecordSET2]->size = sizeof(prec->set2);
    prt->papFldDes[digitelRecordSET3]->size = sizeof(prec->set3);
    prt->papFldDes[digitelRecordSET4]->size = sizeof(prec->set4);
    prt->papFldDes[digitelRecordACCW]->size = sizeof(prec->accw);
    prt->papFldDes[digitelRecordACCI]->size = sizeof(prec->acci);
    prt->papFldDes[digitelRecordPTYP]->size = sizeof(prec->ptyp);
    prt->papFldDes[digitelRecordTYPE]->size = sizeof(prec->type);
    prt->papFldDes[digitelRecordSP1S]->size = sizeof(prec->sp1s);
    prt->papFldDes[digitelRecordSP1R]->size = sizeof(prec->sp1r);
    prt->papFldDes[digitelRecordS1HS]->size = sizeof(prec->s1hs);
    prt->papFldDes[digitelRecordS1HR]->size = sizeof(prec->s1hr);
    prt->papFldDes[digitelRecordS1MS]->size = sizeof(prec->s1ms);
    prt->papFldDes[digitelRecordS1MR]->size = sizeof(prec->s1mr);
    prt->papFldDes[digitelRecordS1VS]->size = sizeof(prec->s1vs);
    prt->papFldDes[digitelRecordS1VR]->size = sizeof(prec->s1vr);
    prt->papFldDes[digitelRecordSP2S]->size = sizeof(prec->sp2s);
    prt->papFldDes[digitelRecordSP2R]->size = sizeof(prec->sp2r);
    prt->papFldDes[digitelRecordS2HS]->size = sizeof(prec->s2hs);
    prt->papFldDes[digitelRecordS2HR]->size = sizeof(prec->s2hr);
    prt->papFldDes[digitelRecordS2MS]->size = sizeof(prec->s2ms);
    prt->papFldDes[digitelRecordS2MR]->size = sizeof(prec->s2mr);
    prt->papFldDes[digitelRecordS2VS]->size = sizeof(prec->s2vs);
    prt->papFldDes[digitelRecordS2VR]->size = sizeof(prec->s2vr);
    prt->papFldDes[digitelRecordSP3S]->size = sizeof(prec->sp3s);
    prt->papFldDes[digitelRecordSP3R]->size = sizeof(prec->sp3r);
    prt->papFldDes[digitelRecordS3HS]->size = sizeof(prec->s3hs);
    prt->papFldDes[digitelRecordS3HR]->size = sizeof(prec->s3hr);
    prt->papFldDes[digitelRecordS3MS]->size = sizeof(prec->s3ms);
    prt->papFldDes[digitelRecordS3MR]->size = sizeof(prec->s3mr);
    prt->papFldDes[digitelRecordS3VS]->size = sizeof(prec->s3vs);
    prt->papFldDes[digitelRecordS3VR]->size = sizeof(prec->s3vr);
    prt->papFldDes[digitelRecordS3BS]->size = sizeof(prec->s3bs);
    prt->papFldDes[digitelRecordS3BR]->size = sizeof(prec->s3br);
    prt->papFldDes[digitelRecordS3TS]->size = sizeof(prec->s3ts);
    prt->papFldDes[digitelRecordS3TR]->size = sizeof(prec->s3tr);
    prt->papFldDes[digitelRecordSP4S]->size = sizeof(prec->sp4s);
    prt->papFldDes[digitelRecordSP4R]->size = sizeof(prec->sp4r);
    prt->papFldDes[digitelRecordS4HS]->size = sizeof(prec->s4hs);
    prt->papFldDes[digitelRecordS4HR]->size = sizeof(prec->s4hr);
    prt->papFldDes[digitelRecordS4MS]->size = sizeof(prec->s4ms);
    prt->papFldDes[digitelRecordS4MR]->size = sizeof(prec->s4mr);
    prt->papFldDes[digitelRecordS4VS]->size = sizeof(prec->s4vs);
    prt->papFldDes[digitelRecordS4VR]->size = sizeof(prec->s4vr);
    prt->papFldDes[digitelRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[digitelRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[digitelRecordHCTR]->size = sizeof(prec->hctr);
    prt->papFldDes[digitelRecordLCTR]->size = sizeof(prec->lctr);
    prt->papFldDes[digitelRecordHVTR]->size = sizeof(prec->hvtr);
    prt->papFldDes[digitelRecordLVTR]->size = sizeof(prec->lvtr);
    prt->papFldDes[digitelRecordHLPR]->size = sizeof(prec->hlpr);
    prt->papFldDes[digitelRecordLLPR]->size = sizeof(prec->llpr);
    prt->papFldDes[digitelRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[digitelRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[digitelRecordSLMO]->size = sizeof(prec->slmo);
    prt->papFldDes[digitelRecordSVMO]->size = sizeof(prec->svmo);
    prt->papFldDes[digitelRecordSLS1]->size = sizeof(prec->sls1);
    prt->papFldDes[digitelRecordSVS1]->size = sizeof(prec->svs1);
    prt->papFldDes[digitelRecordSLS2]->size = sizeof(prec->sls2);
    prt->papFldDes[digitelRecordSVS2]->size = sizeof(prec->svs2);
    prt->papFldDes[digitelRecordSLCR]->size = sizeof(prec->slcr);
    prt->papFldDes[digitelRecordSVCR]->size = sizeof(prec->svcr);
    prt->papFldDes[digitelRecordTONL]->size = sizeof(prec->tonl);
    prt->papFldDes[digitelRecordCRNT]->size = sizeof(prec->crnt);
    prt->papFldDes[digitelRecordVOLT]->size = sizeof(prec->volt);
    prt->papFldDes[digitelRecordFLGS]->size = sizeof(prec->flgs);
    prt->papFldDes[digitelRecordSPFG]->size = sizeof(prec->spfg);
    prt->papFldDes[digitelRecordBKIN]->size = sizeof(prec->bkin);
    prt->papFldDes[digitelRecordIVAL]->size = sizeof(prec->ival);
    prt->papFldDes[digitelRecordILVA]->size = sizeof(prec->ilva);
    prt->papFldDes[digitelRecordIMOD]->size = sizeof(prec->imod);
    prt->papFldDes[digitelRecordIBAK]->size = sizeof(prec->ibak);
    prt->papFldDes[digitelRecordICOL]->size = sizeof(prec->icol);
    prt->papFldDes[digitelRecordISP1]->size = sizeof(prec->isp1);
    prt->papFldDes[digitelRecordISP2]->size = sizeof(prec->isp2);
    prt->papFldDes[digitelRecordISP3]->size = sizeof(prec->isp3);
    prt->papFldDes[digitelRecordISP4]->size = sizeof(prec->isp4);
    prt->papFldDes[digitelRecordIACW]->size = sizeof(prec->iacw);
    prt->papFldDes[digitelRecordIACI]->size = sizeof(prec->iaci);
    prt->papFldDes[digitelRecordIPTY]->size = sizeof(prec->ipty);
    prt->papFldDes[digitelRecordIBKN]->size = sizeof(prec->ibkn);
    prt->papFldDes[digitelRecordIS1]->size = sizeof(prec->is1);
    prt->papFldDes[digitelRecordIH1]->size = sizeof(prec->ih1);
    prt->papFldDes[digitelRecordIM1]->size = sizeof(prec->im1);
    prt->papFldDes[digitelRecordII1]->size = sizeof(prec->ii1);
    prt->papFldDes[digitelRecordIS2]->size = sizeof(prec->is2);
    prt->papFldDes[digitelRecordIH2]->size = sizeof(prec->ih2);
    prt->papFldDes[digitelRecordIM2]->size = sizeof(prec->im2);
    prt->papFldDes[digitelRecordII2]->size = sizeof(prec->ii2);
    prt->papFldDes[digitelRecordIS3]->size = sizeof(prec->is3);
    prt->papFldDes[digitelRecordIH3]->size = sizeof(prec->ih3);
    prt->papFldDes[digitelRecordIM3]->size = sizeof(prec->im3);
    prt->papFldDes[digitelRecordII3]->size = sizeof(prec->ii3);
    prt->papFldDes[digitelRecordIB3]->size = sizeof(prec->ib3);
    prt->papFldDes[digitelRecordIS4]->size = sizeof(prec->is4);
    prt->papFldDes[digitelRecordIH4]->size = sizeof(prec->ih4);
    prt->papFldDes[digitelRecordIM4]->size = sizeof(prec->im4);
    prt->papFldDes[digitelRecordII4]->size = sizeof(prec->ii4);
    prt->papFldDes[digitelRecordIT3]->size = sizeof(prec->it3);
    prt->papFldDes[digitelRecordITON]->size = sizeof(prec->iton);
    prt->papFldDes[digitelRecordICRN]->size = sizeof(prec->icrn);
    prt->papFldDes[digitelRecordIVOL]->size = sizeof(prec->ivol);
    prt->papFldDes[digitelRecordCYCL]->size = sizeof(prec->cycl);
    prt->papFldDes[digitelRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[digitelRecordIERR]->size = sizeof(prec->ierr);
    prt->papFldDes[digitelRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[digitelRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[digitelRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[digitelRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[digitelRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[digitelRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[digitelRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[digitelRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[digitelRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[digitelRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[digitelRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[digitelRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[digitelRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[digitelRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[digitelRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[digitelRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[digitelRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[digitelRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[digitelRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[digitelRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[digitelRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[digitelRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[digitelRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[digitelRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[digitelRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[digitelRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[digitelRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[digitelRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[digitelRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[digitelRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[digitelRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[digitelRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[digitelRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[digitelRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[digitelRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[digitelRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[digitelRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[digitelRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[digitelRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[digitelRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[digitelRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[digitelRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[digitelRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[digitelRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[digitelRecordMODL]->offset = (unsigned short)((char *)&prec->modl - (char *)prec);
    prt->papFldDes[digitelRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[digitelRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[digitelRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[digitelRecordLVAL]->offset = (unsigned short)((char *)&prec->lval - (char *)prec);
    prt->papFldDes[digitelRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[digitelRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[digitelRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[digitelRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[digitelRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[digitelRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[digitelRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[digitelRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[digitelRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[digitelRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[digitelRecordDSPL]->offset = (unsigned short)((char *)&prec->dspl - (char *)prec);
    prt->papFldDes[digitelRecordKLCK]->offset = (unsigned short)((char *)&prec->klck - (char *)prec);
    prt->papFldDes[digitelRecordMODS]->offset = (unsigned short)((char *)&prec->mods - (char *)prec);
    prt->papFldDes[digitelRecordMODR]->offset = (unsigned short)((char *)&prec->modr - (char *)prec);
    prt->papFldDes[digitelRecordBAKS]->offset = (unsigned short)((char *)&prec->baks - (char *)prec);
    prt->papFldDes[digitelRecordBAKR]->offset = (unsigned short)((char *)&prec->bakr - (char *)prec);
    prt->papFldDes[digitelRecordCOOL]->offset = (unsigned short)((char *)&prec->cool - (char *)prec);
    prt->papFldDes[digitelRecordCMOR]->offset = (unsigned short)((char *)&prec->cmor - (char *)prec);
    prt->papFldDes[digitelRecordSET1]->offset = (unsigned short)((char *)&prec->set1 - (char *)prec);
    prt->papFldDes[digitelRecordSET2]->offset = (unsigned short)((char *)&prec->set2 - (char *)prec);
    prt->papFldDes[digitelRecordSET3]->offset = (unsigned short)((char *)&prec->set3 - (char *)prec);
    prt->papFldDes[digitelRecordSET4]->offset = (unsigned short)((char *)&prec->set4 - (char *)prec);
    prt->papFldDes[digitelRecordACCW]->offset = (unsigned short)((char *)&prec->accw - (char *)prec);
    prt->papFldDes[digitelRecordACCI]->offset = (unsigned short)((char *)&prec->acci - (char *)prec);
    prt->papFldDes[digitelRecordPTYP]->offset = (unsigned short)((char *)&prec->ptyp - (char *)prec);
    prt->papFldDes[digitelRecordTYPE]->offset = (unsigned short)((char *)&prec->type - (char *)prec);
    prt->papFldDes[digitelRecordSP1S]->offset = (unsigned short)((char *)&prec->sp1s - (char *)prec);
    prt->papFldDes[digitelRecordSP1R]->offset = (unsigned short)((char *)&prec->sp1r - (char *)prec);
    prt->papFldDes[digitelRecordS1HS]->offset = (unsigned short)((char *)&prec->s1hs - (char *)prec);
    prt->papFldDes[digitelRecordS1HR]->offset = (unsigned short)((char *)&prec->s1hr - (char *)prec);
    prt->papFldDes[digitelRecordS1MS]->offset = (unsigned short)((char *)&prec->s1ms - (char *)prec);
    prt->papFldDes[digitelRecordS1MR]->offset = (unsigned short)((char *)&prec->s1mr - (char *)prec);
    prt->papFldDes[digitelRecordS1VS]->offset = (unsigned short)((char *)&prec->s1vs - (char *)prec);
    prt->papFldDes[digitelRecordS1VR]->offset = (unsigned short)((char *)&prec->s1vr - (char *)prec);
    prt->papFldDes[digitelRecordSP2S]->offset = (unsigned short)((char *)&prec->sp2s - (char *)prec);
    prt->papFldDes[digitelRecordSP2R]->offset = (unsigned short)((char *)&prec->sp2r - (char *)prec);
    prt->papFldDes[digitelRecordS2HS]->offset = (unsigned short)((char *)&prec->s2hs - (char *)prec);
    prt->papFldDes[digitelRecordS2HR]->offset = (unsigned short)((char *)&prec->s2hr - (char *)prec);
    prt->papFldDes[digitelRecordS2MS]->offset = (unsigned short)((char *)&prec->s2ms - (char *)prec);
    prt->papFldDes[digitelRecordS2MR]->offset = (unsigned short)((char *)&prec->s2mr - (char *)prec);
    prt->papFldDes[digitelRecordS2VS]->offset = (unsigned short)((char *)&prec->s2vs - (char *)prec);
    prt->papFldDes[digitelRecordS2VR]->offset = (unsigned short)((char *)&prec->s2vr - (char *)prec);
    prt->papFldDes[digitelRecordSP3S]->offset = (unsigned short)((char *)&prec->sp3s - (char *)prec);
    prt->papFldDes[digitelRecordSP3R]->offset = (unsigned short)((char *)&prec->sp3r - (char *)prec);
    prt->papFldDes[digitelRecordS3HS]->offset = (unsigned short)((char *)&prec->s3hs - (char *)prec);
    prt->papFldDes[digitelRecordS3HR]->offset = (unsigned short)((char *)&prec->s3hr - (char *)prec);
    prt->papFldDes[digitelRecordS3MS]->offset = (unsigned short)((char *)&prec->s3ms - (char *)prec);
    prt->papFldDes[digitelRecordS3MR]->offset = (unsigned short)((char *)&prec->s3mr - (char *)prec);
    prt->papFldDes[digitelRecordS3VS]->offset = (unsigned short)((char *)&prec->s3vs - (char *)prec);
    prt->papFldDes[digitelRecordS3VR]->offset = (unsigned short)((char *)&prec->s3vr - (char *)prec);
    prt->papFldDes[digitelRecordS3BS]->offset = (unsigned short)((char *)&prec->s3bs - (char *)prec);
    prt->papFldDes[digitelRecordS3BR]->offset = (unsigned short)((char *)&prec->s3br - (char *)prec);
    prt->papFldDes[digitelRecordS3TS]->offset = (unsigned short)((char *)&prec->s3ts - (char *)prec);
    prt->papFldDes[digitelRecordS3TR]->offset = (unsigned short)((char *)&prec->s3tr - (char *)prec);
    prt->papFldDes[digitelRecordSP4S]->offset = (unsigned short)((char *)&prec->sp4s - (char *)prec);
    prt->papFldDes[digitelRecordSP4R]->offset = (unsigned short)((char *)&prec->sp4r - (char *)prec);
    prt->papFldDes[digitelRecordS4HS]->offset = (unsigned short)((char *)&prec->s4hs - (char *)prec);
    prt->papFldDes[digitelRecordS4HR]->offset = (unsigned short)((char *)&prec->s4hr - (char *)prec);
    prt->papFldDes[digitelRecordS4MS]->offset = (unsigned short)((char *)&prec->s4ms - (char *)prec);
    prt->papFldDes[digitelRecordS4MR]->offset = (unsigned short)((char *)&prec->s4mr - (char *)prec);
    prt->papFldDes[digitelRecordS4VS]->offset = (unsigned short)((char *)&prec->s4vs - (char *)prec);
    prt->papFldDes[digitelRecordS4VR]->offset = (unsigned short)((char *)&prec->s4vr - (char *)prec);
    prt->papFldDes[digitelRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[digitelRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[digitelRecordHCTR]->offset = (unsigned short)((char *)&prec->hctr - (char *)prec);
    prt->papFldDes[digitelRecordLCTR]->offset = (unsigned short)((char *)&prec->lctr - (char *)prec);
    prt->papFldDes[digitelRecordHVTR]->offset = (unsigned short)((char *)&prec->hvtr - (char *)prec);
    prt->papFldDes[digitelRecordLVTR]->offset = (unsigned short)((char *)&prec->lvtr - (char *)prec);
    prt->papFldDes[digitelRecordHLPR]->offset = (unsigned short)((char *)&prec->hlpr - (char *)prec);
    prt->papFldDes[digitelRecordLLPR]->offset = (unsigned short)((char *)&prec->llpr - (char *)prec);
    prt->papFldDes[digitelRecordSIML]->offset = (unsigned short)((char *)&prec->siml - (char *)prec);
    prt->papFldDes[digitelRecordSIMM]->offset = (unsigned short)((char *)&prec->simm - (char *)prec);
    prt->papFldDes[digitelRecordSLMO]->offset = (unsigned short)((char *)&prec->slmo - (char *)prec);
    prt->papFldDes[digitelRecordSVMO]->offset = (unsigned short)((char *)&prec->svmo - (char *)prec);
    prt->papFldDes[digitelRecordSLS1]->offset = (unsigned short)((char *)&prec->sls1 - (char *)prec);
    prt->papFldDes[digitelRecordSVS1]->offset = (unsigned short)((char *)&prec->svs1 - (char *)prec);
    prt->papFldDes[digitelRecordSLS2]->offset = (unsigned short)((char *)&prec->sls2 - (char *)prec);
    prt->papFldDes[digitelRecordSVS2]->offset = (unsigned short)((char *)&prec->svs2 - (char *)prec);
    prt->papFldDes[digitelRecordSLCR]->offset = (unsigned short)((char *)&prec->slcr - (char *)prec);
    prt->papFldDes[digitelRecordSVCR]->offset = (unsigned short)((char *)&prec->svcr - (char *)prec);
    prt->papFldDes[digitelRecordTONL]->offset = (unsigned short)((char *)&prec->tonl - (char *)prec);
    prt->papFldDes[digitelRecordCRNT]->offset = (unsigned short)((char *)&prec->crnt - (char *)prec);
    prt->papFldDes[digitelRecordVOLT]->offset = (unsigned short)((char *)&prec->volt - (char *)prec);
    prt->papFldDes[digitelRecordFLGS]->offset = (unsigned short)((char *)&prec->flgs - (char *)prec);
    prt->papFldDes[digitelRecordSPFG]->offset = (unsigned short)((char *)&prec->spfg - (char *)prec);
    prt->papFldDes[digitelRecordBKIN]->offset = (unsigned short)((char *)&prec->bkin - (char *)prec);
    prt->papFldDes[digitelRecordIVAL]->offset = (unsigned short)((char *)&prec->ival - (char *)prec);
    prt->papFldDes[digitelRecordILVA]->offset = (unsigned short)((char *)&prec->ilva - (char *)prec);
    prt->papFldDes[digitelRecordIMOD]->offset = (unsigned short)((char *)&prec->imod - (char *)prec);
    prt->papFldDes[digitelRecordIBAK]->offset = (unsigned short)((char *)&prec->ibak - (char *)prec);
    prt->papFldDes[digitelRecordICOL]->offset = (unsigned short)((char *)&prec->icol - (char *)prec);
    prt->papFldDes[digitelRecordISP1]->offset = (unsigned short)((char *)&prec->isp1 - (char *)prec);
    prt->papFldDes[digitelRecordISP2]->offset = (unsigned short)((char *)&prec->isp2 - (char *)prec);
    prt->papFldDes[digitelRecordISP3]->offset = (unsigned short)((char *)&prec->isp3 - (char *)prec);
    prt->papFldDes[digitelRecordISP4]->offset = (unsigned short)((char *)&prec->isp4 - (char *)prec);
    prt->papFldDes[digitelRecordIACW]->offset = (unsigned short)((char *)&prec->iacw - (char *)prec);
    prt->papFldDes[digitelRecordIACI]->offset = (unsigned short)((char *)&prec->iaci - (char *)prec);
    prt->papFldDes[digitelRecordIPTY]->offset = (unsigned short)((char *)&prec->ipty - (char *)prec);
    prt->papFldDes[digitelRecordIBKN]->offset = (unsigned short)((char *)&prec->ibkn - (char *)prec);
    prt->papFldDes[digitelRecordIS1]->offset = (unsigned short)((char *)&prec->is1 - (char *)prec);
    prt->papFldDes[digitelRecordIH1]->offset = (unsigned short)((char *)&prec->ih1 - (char *)prec);
    prt->papFldDes[digitelRecordIM1]->offset = (unsigned short)((char *)&prec->im1 - (char *)prec);
    prt->papFldDes[digitelRecordII1]->offset = (unsigned short)((char *)&prec->ii1 - (char *)prec);
    prt->papFldDes[digitelRecordIS2]->offset = (unsigned short)((char *)&prec->is2 - (char *)prec);
    prt->papFldDes[digitelRecordIH2]->offset = (unsigned short)((char *)&prec->ih2 - (char *)prec);
    prt->papFldDes[digitelRecordIM2]->offset = (unsigned short)((char *)&prec->im2 - (char *)prec);
    prt->papFldDes[digitelRecordII2]->offset = (unsigned short)((char *)&prec->ii2 - (char *)prec);
    prt->papFldDes[digitelRecordIS3]->offset = (unsigned short)((char *)&prec->is3 - (char *)prec);
    prt->papFldDes[digitelRecordIH3]->offset = (unsigned short)((char *)&prec->ih3 - (char *)prec);
    prt->papFldDes[digitelRecordIM3]->offset = (unsigned short)((char *)&prec->im3 - (char *)prec);
    prt->papFldDes[digitelRecordII3]->offset = (unsigned short)((char *)&prec->ii3 - (char *)prec);
    prt->papFldDes[digitelRecordIB3]->offset = (unsigned short)((char *)&prec->ib3 - (char *)prec);
    prt->papFldDes[digitelRecordIS4]->offset = (unsigned short)((char *)&prec->is4 - (char *)prec);
    prt->papFldDes[digitelRecordIH4]->offset = (unsigned short)((char *)&prec->ih4 - (char *)prec);
    prt->papFldDes[digitelRecordIM4]->offset = (unsigned short)((char *)&prec->im4 - (char *)prec);
    prt->papFldDes[digitelRecordII4]->offset = (unsigned short)((char *)&prec->ii4 - (char *)prec);
    prt->papFldDes[digitelRecordIT3]->offset = (unsigned short)((char *)&prec->it3 - (char *)prec);
    prt->papFldDes[digitelRecordITON]->offset = (unsigned short)((char *)&prec->iton - (char *)prec);
    prt->papFldDes[digitelRecordICRN]->offset = (unsigned short)((char *)&prec->icrn - (char *)prec);
    prt->papFldDes[digitelRecordIVOL]->offset = (unsigned short)((char *)&prec->ivol - (char *)prec);
    prt->papFldDes[digitelRecordCYCL]->offset = (unsigned short)((char *)&prec->cycl - (char *)prec);
    prt->papFldDes[digitelRecordERR]->offset = (unsigned short)((char *)&prec->err - (char *)prec);
    prt->papFldDes[digitelRecordIERR]->offset = (unsigned short)((char *)&prec->ierr - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(digitelRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_digitelRecord_H */
