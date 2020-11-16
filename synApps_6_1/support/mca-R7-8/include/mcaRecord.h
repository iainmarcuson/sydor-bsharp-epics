/* mcaRecord.h generated from mcaRecord.dbd */

#ifndef INC_mcaRecord_H
#define INC_mcaRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    mcaERAS_Done                    /* Done */,
    mcaERAS_Erase                   /* Erase */
} mcaERAS;
#define mcaERAS_NUM_CHOICES 2

typedef enum {
    mcaR0IP_N                       /* N */,
    mcaR0IP_Y                       /* Y */
} mcaR0IP;
#define mcaR0IP_NUM_CHOICES 2

typedef enum {
    mcaMODE_PHA                     /* PHA */,
    mcaMODE_MCS                     /* MCS */,
    mcaMODE_List                    /* List */
} mcaMODE;
#define mcaMODE_NUM_CHOICES 3

typedef enum {
    mcaCHAS_Internal                /* Internal */,
    mcaCHAS_External                /* External */
} mcaCHAS;
#define mcaCHAS_NUM_CHOICES 2

typedef enum {
    mcaSTRT_Done                    /* Done */,
    mcaSTRT_Acquire                 /* Acquire */
} mcaSTRT;
#define mcaSTRT_NUM_CHOICES 2

typedef enum {
    mcaREAD_Done                    /* Done */,
    mcaREAD_Read                    /* Read */
} mcaREAD;
#define mcaREAD_NUM_CHOICES 2

typedef struct mcaRecord {
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
    epicsFloat64        vers;       /* Code Version */
    void *val;                      /* Value */
    void *bptr;                     /* Buffer Pointer */
    void *bg;                       /* Background */
    void *pbg;                      /* Background buffer */
    void *pstatus;                  /* Status buffer */
    epicsFloat64        hopr;       /* High Operating Range */
    epicsFloat64        lopr;       /* Low Operating Range */
    epicsInt32          nmax;       /* Max number of channels */
    epicsInt32          nord;       /* Number of channels read */
    epicsInt16          prec;       /* Display Precision */
    epicsEnum16         ftvl;       /* Field Type of Value */
    epicsEnum16         strt;       /* Start Acquire */
    epicsEnum16         erst;       /* Erase & Start Acquire */
    epicsEnum16         stop;       /* Stop Acquire */
    epicsEnum16         acqg;       /* Acquiring */
    epicsEnum16         read;       /* Read array */
    epicsEnum16         rdng;       /* Reading array */
    epicsEnum16         rdns;       /* Reading status */
    epicsEnum16         eras;       /* Erase array */
    epicsEnum16         chas;       /* Channel-advance source */
    epicsInt32          nuse;       /*  # of channels to use */
    epicsInt32          seq;        /* Time sequence # */
    epicsFloat64        dwel;       /* Dwell time per channel */
    epicsInt32          pscl;       /* Channel advance prescale */
    epicsFloat64        prtm;       /* Preset real time */
    epicsFloat64        pltm;       /* Preset live time */
    epicsFloat64        pct;        /* Preset counts */
    epicsInt32          pctl;       /* Preset count low channe */
    epicsInt32          pcth;       /* Preset count high chann */
    epicsInt32          pswp;       /* Preset number of sweeps */
    epicsEnum16         mode;       /* Mode PHA/MCS/LIST */
    epicsFloat64        calo;       /* Calibration offset */
    epicsFloat64        cals;       /* Calibration slope */
    epicsFloat64        calq;       /* Calibration quadratic */
    char                egu[16];    /* Calibration Units Name */
    epicsFloat64        tth;        /* Two-theta */
    epicsFloat64        ertm;       /* Elapsed real time */
    epicsFloat64        eltm;       /* Elapsed live time */
    epicsFloat64        dtim;       /* Average % dead time */
    epicsFloat64        idtim;      /* Instantaneous % dead time */
    char                stim[40];   /* Acquisition stop time */
    epicsFloat64        rtim;       /* Last read time */
    epicsInt32          act;        /* Actual counts in pregio */
    epicsInt16          nack;       /* Message not acknowledge */
    DBLINK              inp;        /* Input Specification */
    epicsFloat64        hihi;       /* Hihi Deviation Limit */
    epicsFloat64        lolo;       /* Lolo Deviation Limit */
    epicsFloat64        high;       /* High Deviation Limit */
    epicsFloat64        low;        /* Low Deviation Limit */
    epicsEnum16         hhsv;       /* Hihi Severity */
    epicsEnum16         llsv;       /* Lolo Severity */
    epicsEnum16         hsv;        /* High Severity */
    epicsEnum16         lsv;        /* Low Severity */
    epicsFloat64        hyst;       /* Alarm Deadband */
    epicsFloat64        lalm;       /* Last Value Alarmed */
    DBLINK              siol;       /* Sim Input Specifctn */
    DBLINK              siml;       /* Sim Mode Location */
    epicsEnum16         simm;       /* Simulation Mode */
    epicsEnum16         sims;       /* Sim mode Alarm Svrty */
    epicsUInt32         mmap;       /* Monitor map */
    epicsUInt32         rmap;       /* ROI monitor map */
    epicsUInt32         newv;       /* New Value map */
    epicsUInt32         newr;       /* New ROI Value map */
    epicsInt32          r0lo;       /* Region 0 low channel */
    epicsInt32          r0hi;       /* Region 0 high channel */
    epicsInt16          r0bg;       /* Region 0 bkgrnd chans */
    epicsEnum16         r0ip;       /* Region 0 is preset */
    epicsInt32          r1lo;       /* Region 1 low channel */
    epicsInt32          r1hi;       /* Region 1 high channel */
    epicsInt16          r1bg;       /* Region 1 bkgrnd chans */
    epicsEnum16         r1ip;       /* Region 1 is preset */
    epicsInt32          r2lo;       /* Region 2 low channel */
    epicsInt32          r2hi;       /* Region 2 high channel */
    epicsInt16          r2bg;       /* Region 2 bkgrnd chans */
    epicsEnum16         r2ip;       /* Region 2 is preset */
    epicsInt32          r3lo;       /* Region 3 low channel */
    epicsInt32          r3hi;       /* Region 3 high channel */
    epicsInt16          r3bg;       /* Region 3 bkgrnd chans */
    epicsEnum16         r3ip;       /* Region 3 is preset */
    epicsInt32          r4lo;       /* Region 4 low channel */
    epicsInt32          r4hi;       /* Region 4 high channel */
    epicsInt16          r4bg;       /* Region 4 bkgrnd chans */
    epicsEnum16         r4ip;       /* Region 4 is preset */
    epicsInt32          r5lo;       /* Region 5 low channel */
    epicsInt32          r5hi;       /* Region 5 high channel */
    epicsInt16          r5bg;       /* Region 5 bkgrnd chans */
    epicsEnum16         r5ip;       /* Region 5 is preset */
    epicsInt32          r6lo;       /* Region 6 low channel */
    epicsInt32          r6hi;       /* Region 6 high channel */
    epicsInt16          r6bg;       /* Region 6 bkgrnd chans */
    epicsEnum16         r6ip;       /* Region 6 is preset */
    epicsInt32          r7lo;       /* Region 7 low channel */
    epicsInt32          r7hi;       /* Region 7 high channel */
    epicsInt16          r7bg;       /* Region 7 bkgrnd chans */
    epicsEnum16         r7ip;       /* Region 7 is preset */
    epicsInt32          r8lo;       /* Region 8 low channel */
    epicsInt32          r8hi;       /* Region 8 high channel */
    epicsInt16          r8bg;       /* Region 8 bkgrnd chans */
    epicsEnum16         r8ip;       /* Region 8 is preset */
    epicsInt32          r9lo;       /* Region 9 low channel */
    epicsInt32          r9hi;       /* Region 9 high channel */
    epicsInt16          r9bg;       /* Region 9 bkgrnd chans */
    epicsEnum16         r9ip;       /* Region 9 is preset */
    epicsInt32          r10lo;      /* Region 10 low channel */
    epicsInt32          r10hi;      /* Region 10 high channel */
    epicsInt16          r10bg;      /* Region 10 bkgrnd chans */
    epicsEnum16         r10ip;      /* Region 10 is preset */
    epicsInt32          r11lo;      /* Region 11 low channel */
    epicsInt32          r11hi;      /* Region 11 high channel */
    epicsInt16          r11bg;      /* Region 11 bkgrnd chans */
    epicsEnum16         r11ip;      /* Region 11 is preset */
    epicsInt32          r12lo;      /* Region 12 low channel */
    epicsInt32          r12hi;      /* Region 12 high channel */
    epicsInt16          r12bg;      /* Region 12 bkgrnd chans */
    epicsEnum16         r12ip;      /* Region 12 is preset */
    epicsInt32          r13lo;      /* Region 13 low channel */
    epicsInt32          r13hi;      /* Region 13 high channel */
    epicsInt16          r13bg;      /* Region 13 bkgrnd chans */
    epicsEnum16         r13ip;      /* Region 13 is preset */
    epicsInt32          r14lo;      /* Region 14 low channel */
    epicsInt32          r14hi;      /* Region 14 high channel */
    epicsInt16          r14bg;      /* Region 14 bkgrnd chans */
    epicsEnum16         r14ip;      /* Region 14 is preset */
    epicsInt32          r15lo;      /* Region 15 low channel */
    epicsInt32          r15hi;      /* Region 15 high channel */
    epicsInt16          r15bg;      /* Region 15 bkgrnd chans */
    epicsEnum16         r15ip;      /* Region 15 is preset */
    epicsInt32          r16lo;      /* Region 16 low channel */
    epicsInt32          r16hi;      /* Region 16 high channel */
    epicsInt16          r16bg;      /* Region 16 bkgrnd chans */
    epicsEnum16         r16ip;      /* Region 16 is preset */
    epicsInt32          r17lo;      /* Region 17 low channel */
    epicsInt32          r17hi;      /* Region 17 high channel */
    epicsInt16          r17bg;      /* Region 17 bkgrnd chans */
    epicsEnum16         r17ip;      /* Region 17 is preset */
    epicsInt32          r18lo;      /* Region 18 low channel */
    epicsInt32          r18hi;      /* Region 18 high channel */
    epicsInt16          r18bg;      /* Region 18 bkgrnd chans */
    epicsEnum16         r18ip;      /* Region 18 is preset */
    epicsInt32          r19lo;      /* Region 19 low channel */
    epicsInt32          r19hi;      /* Region 19 high channel */
    epicsInt16          r19bg;      /* Region 19 bkgrnd chans */
    epicsEnum16         r19ip;      /* Region 19 is preset */
    epicsInt32          r20lo;      /* Region 20 low channel */
    epicsInt32          r20hi;      /* Region 20 high channel */
    epicsInt16          r20bg;      /* Region 20 bkgrnd chans */
    epicsEnum16         r20ip;      /* Region 20 is preset */
    epicsInt32          r21lo;      /* Region 21 low channel */
    epicsInt32          r21hi;      /* Region 21 high channel */
    epicsInt16          r21bg;      /* Region 21 bkgrnd chans */
    epicsEnum16         r21ip;      /* Region 21 is preset */
    epicsInt32          r22lo;      /* Region 22 low channel */
    epicsInt32          r22hi;      /* Region 22 high channel */
    epicsInt16          r22bg;      /* Region 22 bkgrnd chans */
    epicsEnum16         r22ip;      /* Region 22 is preset */
    epicsInt32          r23lo;      /* Region 23 low channel */
    epicsInt32          r23hi;      /* Region 23 high channel */
    epicsInt16          r23bg;      /* Region 23 bkgrnd chans */
    epicsEnum16         r23ip;      /* Region 23 is preset */
    epicsInt32          r24lo;      /* Region 24 low channel */
    epicsInt32          r24hi;      /* Region 24 high channel */
    epicsInt16          r24bg;      /* Region 24 bkgrnd chans */
    epicsEnum16         r24ip;      /* Region 24 is preset */
    epicsInt32          r25lo;      /* Region 25 low channel */
    epicsInt32          r25hi;      /* Region 25 high channel */
    epicsInt16          r25bg;      /* Region 25 bkgrnd chans */
    epicsEnum16         r25ip;      /* Region 25 is preset */
    epicsInt32          r26lo;      /* Region 26 low channel */
    epicsInt32          r26hi;      /* Region 26 high channel */
    epicsInt16          r26bg;      /* Region 26 bkgrnd chans */
    epicsEnum16         r26ip;      /* Region 26 is preset */
    epicsInt32          r27lo;      /* Region 27 low channel */
    epicsInt32          r27hi;      /* Region 27 high channel */
    epicsInt16          r27bg;      /* Region 27 bkgrnd chans */
    epicsEnum16         r27ip;      /* Region 27 is preset */
    epicsInt32          r28lo;      /* Region 28 low channel */
    epicsInt32          r28hi;      /* Region 28 high channel */
    epicsInt16          r28bg;      /* Region 28 bkgrnd chans */
    epicsEnum16         r28ip;      /* Region 28 is preset */
    epicsInt32          r29lo;      /* Region 29 low channel */
    epicsInt32          r29hi;      /* Region 29 high channel */
    epicsInt16          r29bg;      /* Region 29 bkgrnd chans */
    epicsEnum16         r29ip;      /* Region 29 is preset */
    epicsInt32          r30lo;      /* Region 30 low channel */
    epicsInt32          r30hi;      /* Region 30 high channel */
    epicsInt16          r30bg;      /* Region 30 bkgrnd chans */
    epicsEnum16         r30ip;      /* Region 30 is preset */
    epicsInt32          r31lo;      /* Region 31 low channel */
    epicsInt32          r31hi;      /* Region 31 high channel */
    epicsInt16          r31bg;      /* Region 31 bkgrnd chans */
    epicsEnum16         r31ip;      /* Region 31 is preset */
    epicsFloat64        r0;         /* Region 0 counts */
    epicsFloat64        r0n;        /* Region 0 net counts */
    epicsFloat64        r0p;        /* Region 0 preset count */
    epicsFloat64        r1;         /* Region 1 counts */
    epicsFloat64        r1n;        /* Region 1 net counts */
    epicsFloat64        r1p;        /* Region 1 preset count */
    epicsFloat64        r2;         /* Region 2 counts */
    epicsFloat64        r2n;        /* Region 2 net counts */
    epicsFloat64        r2p;        /* Region 2 preset count */
    epicsFloat64        r3;         /* Region 3 counts */
    epicsFloat64        r3n;        /* Region 3 net counts */
    epicsFloat64        r3p;        /* Region 3 preset count */
    epicsFloat64        r4;         /* Region 4 counts */
    epicsFloat64        r4n;        /* Region 4 net counts */
    epicsFloat64        r4p;        /* Region 4 preset count */
    epicsFloat64        r5;         /* Region 5 counts */
    epicsFloat64        r5n;        /* Region 5 net counts */
    epicsFloat64        r5p;        /* Region 5 preset count */
    epicsFloat64        r6;         /* Region 6 counts */
    epicsFloat64        r6n;        /* Region 6 net counts */
    epicsFloat64        r6p;        /* Region 6 preset */
    epicsFloat64        r7;         /* Region 7 counts */
    epicsFloat64        r7n;        /* Region 7 net counts */
    epicsFloat64        r7p;        /* Region 7 preset */
    epicsFloat64        r8;         /* Region 8 counts */
    epicsFloat64        r8n;        /* Region 8 net counts */
    epicsFloat64        r8p;        /* Region 8 preset */
    epicsFloat64        r9;         /* Region 9 counts */
    epicsFloat64        r9n;        /* Region 9 net counts */
    epicsFloat64        r9p;        /* Region 9 preset */
    epicsFloat64        r10;        /* Region 10 counts */
    epicsFloat64        r10n;       /* Region 10 net counts */
    epicsFloat64        r10p;       /* Region 10 preset */
    epicsFloat64        r11;        /* Region 11 counts */
    epicsFloat64        r11n;       /* Region 11 net counts */
    epicsFloat64        r11p;       /* Region 11 preset */
    epicsFloat64        r12;        /* Region 12 counts */
    epicsFloat64        r12n;       /* Region 12 net counts */
    epicsFloat64        r12p;       /* Region 12 preset */
    epicsFloat64        r13;        /* Region 13 counts */
    epicsFloat64        r13n;       /* Region 13 net counts */
    epicsFloat64        r13p;       /* Region 13 preset */
    epicsFloat64        r14;        /* Region 14 counts */
    epicsFloat64        r14n;       /* Region 14 net counts */
    epicsFloat64        r14p;       /* Region 14 preset */
    epicsFloat64        r15;        /* Region 15 counts */
    epicsFloat64        r15n;       /* Region 15 net counts */
    epicsFloat64        r15p;       /* Region 15 preset */
    epicsFloat64        r16;        /* Region 16 counts */
    epicsFloat64        r16n;       /* Region 16 net counts */
    epicsFloat64        r16p;       /* Region 16 preset */
    epicsFloat64        r17;        /* Region 17 counts */
    epicsFloat64        r17n;       /* Region 17 net counts */
    epicsFloat64        r17p;       /* Region 17 preset */
    epicsFloat64        r18;        /* Region 18 counts */
    epicsFloat64        r18n;       /* Region 18 net counts */
    epicsFloat64        r18p;       /* Region 18 preset */
    epicsFloat64        r19;        /* Region 19 counts */
    epicsFloat64        r19n;       /* Region 19 net counts */
    epicsFloat64        r19p;       /* Region 19 preset */
    epicsFloat64        r20;        /* Region 20 counts */
    epicsFloat64        r20n;       /* Region 20 net counts */
    epicsFloat64        r20p;       /* Region 20 preset */
    epicsFloat64        r21;        /* Region 21 counts */
    epicsFloat64        r21n;       /* Region 21 net counts */
    epicsFloat64        r21p;       /* Region 21 preset */
    epicsFloat64        r22;        /* Region 22 counts */
    epicsFloat64        r22n;       /* Region 22 net counts */
    epicsFloat64        r22p;       /* Region 22 preset */
    epicsFloat64        r23;        /* Region 23 counts */
    epicsFloat64        r23n;       /* Region 23 net counts */
    epicsFloat64        r23p;       /* Region 23 preset */
    epicsFloat64        r24;        /* Region 24 counts */
    epicsFloat64        r24n;       /* Region 24 net counts */
    epicsFloat64        r24p;       /* Region 24 preset */
    epicsFloat64        r25;        /* Region 25 counts */
    epicsFloat64        r25n;       /* Region 25 net counts */
    epicsFloat64        r25p;       /* Region 25 preset */
    epicsFloat64        r26;        /* Region 26 counts */
    epicsFloat64        r26n;       /* Region 26 net counts */
    epicsFloat64        r26p;       /* Region 26 preset */
    epicsFloat64        r27;        /* Region 27 counts */
    epicsFloat64        r27n;       /* Region 27 net counts */
    epicsFloat64        r27p;       /* Region 27 preset */
    epicsFloat64        r28;        /* Region 28 counts */
    epicsFloat64        r28n;       /* Region 28 net counts */
    epicsFloat64        r28p;       /* Region 28 preset */
    epicsFloat64        r29;        /* Region 29 counts */
    epicsFloat64        r29n;       /* Region 29 net counts */
    epicsFloat64        r29p;       /* Region 29 preset */
    epicsFloat64        r30;        /* Region 30 counts */
    epicsFloat64        r30n;       /* Region 30 net counts */
    epicsFloat64        r30p;       /* Region 30 preset */
    epicsFloat64        r31;        /* Region 31 counts */
    epicsFloat64        r31n;       /* Region 31 net counts */
    epicsFloat64        r31p;       /* Region 31 preset */
    char                r0nm[16];   /* Region 0 name */
    char                r1nm[16];   /* Region 1 name */
    char                r2nm[16];   /* Region 2 name */
    char                r3nm[16];   /* Region 3 name */
    char                r4nm[16];   /* Region 4 name */
    char                r5nm[16];   /* Region 5 name */
    char                r6nm[16];   /* Region 6 name */
    char                r7nm[16];   /* Region 7 name */
    char                r8nm[16];   /* Region 8 name */
    char                r9nm[16];   /* Region 9 name */
    char                r10nm[16];  /* Region 10 name */
    char                r11nm[16];  /* Region 11 name */
    char                r12nm[16];  /* Region 12 name */
    char                r13nm[16];  /* Region 13 name */
    char                r14nm[16];  /* Region 14 name */
    char                r15nm[16];  /* Region 15 name */
    char                r16nm[16];  /* Region 16 name */
    char                r17nm[16];  /* Region 17 name */
    char                r18nm[16];  /* Region 18 name */
    char                r19nm[16];  /* Region 19 name */
    char                r20nm[16];  /* Region 20 name */
    char                r21nm[16];  /* Region 21 name */
    char                r22nm[16];  /* Region 22 name */
    char                r23nm[16];  /* Region 23 name */
    char                r24nm[16];  /* Region 24 name */
    char                r25nm[16];  /* Region 25 name */
    char                r26nm[16];  /* Region 26 name */
    char                r27nm[16];  /* Region 27 name */
    char                r28nm[16];  /* Region 28 name */
    char                r29nm[16];  /* Region 29 name */
    char                r30nm[16];  /* Region 30 name */
    char                r31nm[16];  /* Region 31 name */
} mcaRecord;

typedef enum {
	mcaRecordNAME = 0,
	mcaRecordDESC = 1,
	mcaRecordASG = 2,
	mcaRecordSCAN = 3,
	mcaRecordPINI = 4,
	mcaRecordPHAS = 5,
	mcaRecordEVNT = 6,
	mcaRecordTSE = 7,
	mcaRecordTSEL = 8,
	mcaRecordDTYP = 9,
	mcaRecordDISV = 10,
	mcaRecordDISA = 11,
	mcaRecordSDIS = 12,
	mcaRecordMLOK = 13,
	mcaRecordMLIS = 14,
	mcaRecordDISP = 15,
	mcaRecordPROC = 16,
	mcaRecordSTAT = 17,
	mcaRecordSEVR = 18,
	mcaRecordNSTA = 19,
	mcaRecordNSEV = 20,
	mcaRecordACKS = 21,
	mcaRecordACKT = 22,
	mcaRecordDISS = 23,
	mcaRecordLCNT = 24,
	mcaRecordPACT = 25,
	mcaRecordPUTF = 26,
	mcaRecordRPRO = 27,
	mcaRecordASP = 28,
	mcaRecordPPN = 29,
	mcaRecordPPNR = 30,
	mcaRecordSPVT = 31,
	mcaRecordRSET = 32,
	mcaRecordDSET = 33,
	mcaRecordDPVT = 34,
	mcaRecordRDES = 35,
	mcaRecordLSET = 36,
	mcaRecordPRIO = 37,
	mcaRecordTPRO = 38,
	mcaRecordBKPT = 39,
	mcaRecordUDF = 40,
	mcaRecordUDFS = 41,
	mcaRecordTIME = 42,
	mcaRecordFLNK = 43,
	mcaRecordVERS = 44,
	mcaRecordVAL = 45,
	mcaRecordBPTR = 46,
	mcaRecordBG = 47,
	mcaRecordPBG = 48,
	mcaRecordPSTATUS = 49,
	mcaRecordHOPR = 50,
	mcaRecordLOPR = 51,
	mcaRecordNMAX = 52,
	mcaRecordNORD = 53,
	mcaRecordPREC = 54,
	mcaRecordFTVL = 55,
	mcaRecordSTRT = 56,
	mcaRecordERST = 57,
	mcaRecordSTOP = 58,
	mcaRecordACQG = 59,
	mcaRecordREAD = 60,
	mcaRecordRDNG = 61,
	mcaRecordRDNS = 62,
	mcaRecordERAS = 63,
	mcaRecordCHAS = 64,
	mcaRecordNUSE = 65,
	mcaRecordSEQ = 66,
	mcaRecordDWEL = 67,
	mcaRecordPSCL = 68,
	mcaRecordPRTM = 69,
	mcaRecordPLTM = 70,
	mcaRecordPCT = 71,
	mcaRecordPCTL = 72,
	mcaRecordPCTH = 73,
	mcaRecordPSWP = 74,
	mcaRecordMODE = 75,
	mcaRecordCALO = 76,
	mcaRecordCALS = 77,
	mcaRecordCALQ = 78,
	mcaRecordEGU = 79,
	mcaRecordTTH = 80,
	mcaRecordERTM = 81,
	mcaRecordELTM = 82,
	mcaRecordDTIM = 83,
	mcaRecordIDTIM = 84,
	mcaRecordSTIM = 85,
	mcaRecordRTIM = 86,
	mcaRecordACT = 87,
	mcaRecordNACK = 88,
	mcaRecordINP = 89,
	mcaRecordHIHI = 90,
	mcaRecordLOLO = 91,
	mcaRecordHIGH = 92,
	mcaRecordLOW = 93,
	mcaRecordHHSV = 94,
	mcaRecordLLSV = 95,
	mcaRecordHSV = 96,
	mcaRecordLSV = 97,
	mcaRecordHYST = 98,
	mcaRecordLALM = 99,
	mcaRecordSIOL = 100,
	mcaRecordSIML = 101,
	mcaRecordSIMM = 102,
	mcaRecordSIMS = 103,
	mcaRecordMMAP = 104,
	mcaRecordRMAP = 105,
	mcaRecordNEWV = 106,
	mcaRecordNEWR = 107,
	mcaRecordR0LO = 108,
	mcaRecordR0HI = 109,
	mcaRecordR0BG = 110,
	mcaRecordR0IP = 111,
	mcaRecordR1LO = 112,
	mcaRecordR1HI = 113,
	mcaRecordR1BG = 114,
	mcaRecordR1IP = 115,
	mcaRecordR2LO = 116,
	mcaRecordR2HI = 117,
	mcaRecordR2BG = 118,
	mcaRecordR2IP = 119,
	mcaRecordR3LO = 120,
	mcaRecordR3HI = 121,
	mcaRecordR3BG = 122,
	mcaRecordR3IP = 123,
	mcaRecordR4LO = 124,
	mcaRecordR4HI = 125,
	mcaRecordR4BG = 126,
	mcaRecordR4IP = 127,
	mcaRecordR5LO = 128,
	mcaRecordR5HI = 129,
	mcaRecordR5BG = 130,
	mcaRecordR5IP = 131,
	mcaRecordR6LO = 132,
	mcaRecordR6HI = 133,
	mcaRecordR6BG = 134,
	mcaRecordR6IP = 135,
	mcaRecordR7LO = 136,
	mcaRecordR7HI = 137,
	mcaRecordR7BG = 138,
	mcaRecordR7IP = 139,
	mcaRecordR8LO = 140,
	mcaRecordR8HI = 141,
	mcaRecordR8BG = 142,
	mcaRecordR8IP = 143,
	mcaRecordR9LO = 144,
	mcaRecordR9HI = 145,
	mcaRecordR9BG = 146,
	mcaRecordR9IP = 147,
	mcaRecordR10LO = 148,
	mcaRecordR10HI = 149,
	mcaRecordR10BG = 150,
	mcaRecordR10IP = 151,
	mcaRecordR11LO = 152,
	mcaRecordR11HI = 153,
	mcaRecordR11BG = 154,
	mcaRecordR11IP = 155,
	mcaRecordR12LO = 156,
	mcaRecordR12HI = 157,
	mcaRecordR12BG = 158,
	mcaRecordR12IP = 159,
	mcaRecordR13LO = 160,
	mcaRecordR13HI = 161,
	mcaRecordR13BG = 162,
	mcaRecordR13IP = 163,
	mcaRecordR14LO = 164,
	mcaRecordR14HI = 165,
	mcaRecordR14BG = 166,
	mcaRecordR14IP = 167,
	mcaRecordR15LO = 168,
	mcaRecordR15HI = 169,
	mcaRecordR15BG = 170,
	mcaRecordR15IP = 171,
	mcaRecordR16LO = 172,
	mcaRecordR16HI = 173,
	mcaRecordR16BG = 174,
	mcaRecordR16IP = 175,
	mcaRecordR17LO = 176,
	mcaRecordR17HI = 177,
	mcaRecordR17BG = 178,
	mcaRecordR17IP = 179,
	mcaRecordR18LO = 180,
	mcaRecordR18HI = 181,
	mcaRecordR18BG = 182,
	mcaRecordR18IP = 183,
	mcaRecordR19LO = 184,
	mcaRecordR19HI = 185,
	mcaRecordR19BG = 186,
	mcaRecordR19IP = 187,
	mcaRecordR20LO = 188,
	mcaRecordR20HI = 189,
	mcaRecordR20BG = 190,
	mcaRecordR20IP = 191,
	mcaRecordR21LO = 192,
	mcaRecordR21HI = 193,
	mcaRecordR21BG = 194,
	mcaRecordR21IP = 195,
	mcaRecordR22LO = 196,
	mcaRecordR22HI = 197,
	mcaRecordR22BG = 198,
	mcaRecordR22IP = 199,
	mcaRecordR23LO = 200,
	mcaRecordR23HI = 201,
	mcaRecordR23BG = 202,
	mcaRecordR23IP = 203,
	mcaRecordR24LO = 204,
	mcaRecordR24HI = 205,
	mcaRecordR24BG = 206,
	mcaRecordR24IP = 207,
	mcaRecordR25LO = 208,
	mcaRecordR25HI = 209,
	mcaRecordR25BG = 210,
	mcaRecordR25IP = 211,
	mcaRecordR26LO = 212,
	mcaRecordR26HI = 213,
	mcaRecordR26BG = 214,
	mcaRecordR26IP = 215,
	mcaRecordR27LO = 216,
	mcaRecordR27HI = 217,
	mcaRecordR27BG = 218,
	mcaRecordR27IP = 219,
	mcaRecordR28LO = 220,
	mcaRecordR28HI = 221,
	mcaRecordR28BG = 222,
	mcaRecordR28IP = 223,
	mcaRecordR29LO = 224,
	mcaRecordR29HI = 225,
	mcaRecordR29BG = 226,
	mcaRecordR29IP = 227,
	mcaRecordR30LO = 228,
	mcaRecordR30HI = 229,
	mcaRecordR30BG = 230,
	mcaRecordR30IP = 231,
	mcaRecordR31LO = 232,
	mcaRecordR31HI = 233,
	mcaRecordR31BG = 234,
	mcaRecordR31IP = 235,
	mcaRecordR0 = 236,
	mcaRecordR0N = 237,
	mcaRecordR0P = 238,
	mcaRecordR1 = 239,
	mcaRecordR1N = 240,
	mcaRecordR1P = 241,
	mcaRecordR2 = 242,
	mcaRecordR2N = 243,
	mcaRecordR2P = 244,
	mcaRecordR3 = 245,
	mcaRecordR3N = 246,
	mcaRecordR3P = 247,
	mcaRecordR4 = 248,
	mcaRecordR4N = 249,
	mcaRecordR4P = 250,
	mcaRecordR5 = 251,
	mcaRecordR5N = 252,
	mcaRecordR5P = 253,
	mcaRecordR6 = 254,
	mcaRecordR6N = 255,
	mcaRecordR6P = 256,
	mcaRecordR7 = 257,
	mcaRecordR7N = 258,
	mcaRecordR7P = 259,
	mcaRecordR8 = 260,
	mcaRecordR8N = 261,
	mcaRecordR8P = 262,
	mcaRecordR9 = 263,
	mcaRecordR9N = 264,
	mcaRecordR9P = 265,
	mcaRecordR10 = 266,
	mcaRecordR10N = 267,
	mcaRecordR10P = 268,
	mcaRecordR11 = 269,
	mcaRecordR11N = 270,
	mcaRecordR11P = 271,
	mcaRecordR12 = 272,
	mcaRecordR12N = 273,
	mcaRecordR12P = 274,
	mcaRecordR13 = 275,
	mcaRecordR13N = 276,
	mcaRecordR13P = 277,
	mcaRecordR14 = 278,
	mcaRecordR14N = 279,
	mcaRecordR14P = 280,
	mcaRecordR15 = 281,
	mcaRecordR15N = 282,
	mcaRecordR15P = 283,
	mcaRecordR16 = 284,
	mcaRecordR16N = 285,
	mcaRecordR16P = 286,
	mcaRecordR17 = 287,
	mcaRecordR17N = 288,
	mcaRecordR17P = 289,
	mcaRecordR18 = 290,
	mcaRecordR18N = 291,
	mcaRecordR18P = 292,
	mcaRecordR19 = 293,
	mcaRecordR19N = 294,
	mcaRecordR19P = 295,
	mcaRecordR20 = 296,
	mcaRecordR20N = 297,
	mcaRecordR20P = 298,
	mcaRecordR21 = 299,
	mcaRecordR21N = 300,
	mcaRecordR21P = 301,
	mcaRecordR22 = 302,
	mcaRecordR22N = 303,
	mcaRecordR22P = 304,
	mcaRecordR23 = 305,
	mcaRecordR23N = 306,
	mcaRecordR23P = 307,
	mcaRecordR24 = 308,
	mcaRecordR24N = 309,
	mcaRecordR24P = 310,
	mcaRecordR25 = 311,
	mcaRecordR25N = 312,
	mcaRecordR25P = 313,
	mcaRecordR26 = 314,
	mcaRecordR26N = 315,
	mcaRecordR26P = 316,
	mcaRecordR27 = 317,
	mcaRecordR27N = 318,
	mcaRecordR27P = 319,
	mcaRecordR28 = 320,
	mcaRecordR28N = 321,
	mcaRecordR28P = 322,
	mcaRecordR29 = 323,
	mcaRecordR29N = 324,
	mcaRecordR29P = 325,
	mcaRecordR30 = 326,
	mcaRecordR30N = 327,
	mcaRecordR30P = 328,
	mcaRecordR31 = 329,
	mcaRecordR31N = 330,
	mcaRecordR31P = 331,
	mcaRecordR0NM = 332,
	mcaRecordR1NM = 333,
	mcaRecordR2NM = 334,
	mcaRecordR3NM = 335,
	mcaRecordR4NM = 336,
	mcaRecordR5NM = 337,
	mcaRecordR6NM = 338,
	mcaRecordR7NM = 339,
	mcaRecordR8NM = 340,
	mcaRecordR9NM = 341,
	mcaRecordR10NM = 342,
	mcaRecordR11NM = 343,
	mcaRecordR12NM = 344,
	mcaRecordR13NM = 345,
	mcaRecordR14NM = 346,
	mcaRecordR15NM = 347,
	mcaRecordR16NM = 348,
	mcaRecordR17NM = 349,
	mcaRecordR18NM = 350,
	mcaRecordR19NM = 351,
	mcaRecordR20NM = 352,
	mcaRecordR21NM = 353,
	mcaRecordR22NM = 354,
	mcaRecordR23NM = 355,
	mcaRecordR24NM = 356,
	mcaRecordR25NM = 357,
	mcaRecordR26NM = 358,
	mcaRecordR27NM = 359,
	mcaRecordR28NM = 360,
	mcaRecordR29NM = 361,
	mcaRecordR30NM = 362,
	mcaRecordR31NM = 363
} mcaFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int mcaRecordSizeOffset(dbRecordType *prt)
{
    mcaRecord *prec = 0;

    assert(prt->no_fields == 364);
    prt->papFldDes[mcaRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[mcaRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[mcaRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[mcaRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[mcaRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[mcaRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[mcaRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[mcaRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[mcaRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[mcaRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[mcaRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[mcaRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[mcaRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[mcaRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[mcaRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[mcaRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[mcaRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[mcaRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[mcaRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[mcaRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[mcaRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[mcaRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[mcaRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[mcaRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[mcaRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[mcaRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[mcaRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[mcaRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[mcaRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[mcaRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[mcaRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[mcaRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[mcaRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[mcaRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[mcaRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[mcaRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[mcaRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[mcaRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[mcaRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[mcaRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[mcaRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[mcaRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[mcaRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[mcaRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[mcaRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[mcaRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[mcaRecordBPTR]->size = sizeof(prec->bptr);
    prt->papFldDes[mcaRecordBG]->size = sizeof(prec->bg);
    prt->papFldDes[mcaRecordPBG]->size = sizeof(prec->pbg);
    prt->papFldDes[mcaRecordPSTATUS]->size = sizeof(prec->pstatus);
    prt->papFldDes[mcaRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[mcaRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[mcaRecordNMAX]->size = sizeof(prec->nmax);
    prt->papFldDes[mcaRecordNORD]->size = sizeof(prec->nord);
    prt->papFldDes[mcaRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[mcaRecordFTVL]->size = sizeof(prec->ftvl);
    prt->papFldDes[mcaRecordSTRT]->size = sizeof(prec->strt);
    prt->papFldDes[mcaRecordERST]->size = sizeof(prec->erst);
    prt->papFldDes[mcaRecordSTOP]->size = sizeof(prec->stop);
    prt->papFldDes[mcaRecordACQG]->size = sizeof(prec->acqg);
    prt->papFldDes[mcaRecordREAD]->size = sizeof(prec->read);
    prt->papFldDes[mcaRecordRDNG]->size = sizeof(prec->rdng);
    prt->papFldDes[mcaRecordRDNS]->size = sizeof(prec->rdns);
    prt->papFldDes[mcaRecordERAS]->size = sizeof(prec->eras);
    prt->papFldDes[mcaRecordCHAS]->size = sizeof(prec->chas);
    prt->papFldDes[mcaRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[mcaRecordSEQ]->size = sizeof(prec->seq);
    prt->papFldDes[mcaRecordDWEL]->size = sizeof(prec->dwel);
    prt->papFldDes[mcaRecordPSCL]->size = sizeof(prec->pscl);
    prt->papFldDes[mcaRecordPRTM]->size = sizeof(prec->prtm);
    prt->papFldDes[mcaRecordPLTM]->size = sizeof(prec->pltm);
    prt->papFldDes[mcaRecordPCT]->size = sizeof(prec->pct);
    prt->papFldDes[mcaRecordPCTL]->size = sizeof(prec->pctl);
    prt->papFldDes[mcaRecordPCTH]->size = sizeof(prec->pcth);
    prt->papFldDes[mcaRecordPSWP]->size = sizeof(prec->pswp);
    prt->papFldDes[mcaRecordMODE]->size = sizeof(prec->mode);
    prt->papFldDes[mcaRecordCALO]->size = sizeof(prec->calo);
    prt->papFldDes[mcaRecordCALS]->size = sizeof(prec->cals);
    prt->papFldDes[mcaRecordCALQ]->size = sizeof(prec->calq);
    prt->papFldDes[mcaRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[mcaRecordTTH]->size = sizeof(prec->tth);
    prt->papFldDes[mcaRecordERTM]->size = sizeof(prec->ertm);
    prt->papFldDes[mcaRecordELTM]->size = sizeof(prec->eltm);
    prt->papFldDes[mcaRecordDTIM]->size = sizeof(prec->dtim);
    prt->papFldDes[mcaRecordIDTIM]->size = sizeof(prec->idtim);
    prt->papFldDes[mcaRecordSTIM]->size = sizeof(prec->stim);
    prt->papFldDes[mcaRecordRTIM]->size = sizeof(prec->rtim);
    prt->papFldDes[mcaRecordACT]->size = sizeof(prec->act);
    prt->papFldDes[mcaRecordNACK]->size = sizeof(prec->nack);
    prt->papFldDes[mcaRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[mcaRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[mcaRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[mcaRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[mcaRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[mcaRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[mcaRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[mcaRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[mcaRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[mcaRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[mcaRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[mcaRecordSIOL]->size = sizeof(prec->siol);
    prt->papFldDes[mcaRecordSIML]->size = sizeof(prec->siml);
    prt->papFldDes[mcaRecordSIMM]->size = sizeof(prec->simm);
    prt->papFldDes[mcaRecordSIMS]->size = sizeof(prec->sims);
    prt->papFldDes[mcaRecordMMAP]->size = sizeof(prec->mmap);
    prt->papFldDes[mcaRecordRMAP]->size = sizeof(prec->rmap);
    prt->papFldDes[mcaRecordNEWV]->size = sizeof(prec->newv);
    prt->papFldDes[mcaRecordNEWR]->size = sizeof(prec->newr);
    prt->papFldDes[mcaRecordR0LO]->size = sizeof(prec->r0lo);
    prt->papFldDes[mcaRecordR0HI]->size = sizeof(prec->r0hi);
    prt->papFldDes[mcaRecordR0BG]->size = sizeof(prec->r0bg);
    prt->papFldDes[mcaRecordR0IP]->size = sizeof(prec->r0ip);
    prt->papFldDes[mcaRecordR1LO]->size = sizeof(prec->r1lo);
    prt->papFldDes[mcaRecordR1HI]->size = sizeof(prec->r1hi);
    prt->papFldDes[mcaRecordR1BG]->size = sizeof(prec->r1bg);
    prt->papFldDes[mcaRecordR1IP]->size = sizeof(prec->r1ip);
    prt->papFldDes[mcaRecordR2LO]->size = sizeof(prec->r2lo);
    prt->papFldDes[mcaRecordR2HI]->size = sizeof(prec->r2hi);
    prt->papFldDes[mcaRecordR2BG]->size = sizeof(prec->r2bg);
    prt->papFldDes[mcaRecordR2IP]->size = sizeof(prec->r2ip);
    prt->papFldDes[mcaRecordR3LO]->size = sizeof(prec->r3lo);
    prt->papFldDes[mcaRecordR3HI]->size = sizeof(prec->r3hi);
    prt->papFldDes[mcaRecordR3BG]->size = sizeof(prec->r3bg);
    prt->papFldDes[mcaRecordR3IP]->size = sizeof(prec->r3ip);
    prt->papFldDes[mcaRecordR4LO]->size = sizeof(prec->r4lo);
    prt->papFldDes[mcaRecordR4HI]->size = sizeof(prec->r4hi);
    prt->papFldDes[mcaRecordR4BG]->size = sizeof(prec->r4bg);
    prt->papFldDes[mcaRecordR4IP]->size = sizeof(prec->r4ip);
    prt->papFldDes[mcaRecordR5LO]->size = sizeof(prec->r5lo);
    prt->papFldDes[mcaRecordR5HI]->size = sizeof(prec->r5hi);
    prt->papFldDes[mcaRecordR5BG]->size = sizeof(prec->r5bg);
    prt->papFldDes[mcaRecordR5IP]->size = sizeof(prec->r5ip);
    prt->papFldDes[mcaRecordR6LO]->size = sizeof(prec->r6lo);
    prt->papFldDes[mcaRecordR6HI]->size = sizeof(prec->r6hi);
    prt->papFldDes[mcaRecordR6BG]->size = sizeof(prec->r6bg);
    prt->papFldDes[mcaRecordR6IP]->size = sizeof(prec->r6ip);
    prt->papFldDes[mcaRecordR7LO]->size = sizeof(prec->r7lo);
    prt->papFldDes[mcaRecordR7HI]->size = sizeof(prec->r7hi);
    prt->papFldDes[mcaRecordR7BG]->size = sizeof(prec->r7bg);
    prt->papFldDes[mcaRecordR7IP]->size = sizeof(prec->r7ip);
    prt->papFldDes[mcaRecordR8LO]->size = sizeof(prec->r8lo);
    prt->papFldDes[mcaRecordR8HI]->size = sizeof(prec->r8hi);
    prt->papFldDes[mcaRecordR8BG]->size = sizeof(prec->r8bg);
    prt->papFldDes[mcaRecordR8IP]->size = sizeof(prec->r8ip);
    prt->papFldDes[mcaRecordR9LO]->size = sizeof(prec->r9lo);
    prt->papFldDes[mcaRecordR9HI]->size = sizeof(prec->r9hi);
    prt->papFldDes[mcaRecordR9BG]->size = sizeof(prec->r9bg);
    prt->papFldDes[mcaRecordR9IP]->size = sizeof(prec->r9ip);
    prt->papFldDes[mcaRecordR10LO]->size = sizeof(prec->r10lo);
    prt->papFldDes[mcaRecordR10HI]->size = sizeof(prec->r10hi);
    prt->papFldDes[mcaRecordR10BG]->size = sizeof(prec->r10bg);
    prt->papFldDes[mcaRecordR10IP]->size = sizeof(prec->r10ip);
    prt->papFldDes[mcaRecordR11LO]->size = sizeof(prec->r11lo);
    prt->papFldDes[mcaRecordR11HI]->size = sizeof(prec->r11hi);
    prt->papFldDes[mcaRecordR11BG]->size = sizeof(prec->r11bg);
    prt->papFldDes[mcaRecordR11IP]->size = sizeof(prec->r11ip);
    prt->papFldDes[mcaRecordR12LO]->size = sizeof(prec->r12lo);
    prt->papFldDes[mcaRecordR12HI]->size = sizeof(prec->r12hi);
    prt->papFldDes[mcaRecordR12BG]->size = sizeof(prec->r12bg);
    prt->papFldDes[mcaRecordR12IP]->size = sizeof(prec->r12ip);
    prt->papFldDes[mcaRecordR13LO]->size = sizeof(prec->r13lo);
    prt->papFldDes[mcaRecordR13HI]->size = sizeof(prec->r13hi);
    prt->papFldDes[mcaRecordR13BG]->size = sizeof(prec->r13bg);
    prt->papFldDes[mcaRecordR13IP]->size = sizeof(prec->r13ip);
    prt->papFldDes[mcaRecordR14LO]->size = sizeof(prec->r14lo);
    prt->papFldDes[mcaRecordR14HI]->size = sizeof(prec->r14hi);
    prt->papFldDes[mcaRecordR14BG]->size = sizeof(prec->r14bg);
    prt->papFldDes[mcaRecordR14IP]->size = sizeof(prec->r14ip);
    prt->papFldDes[mcaRecordR15LO]->size = sizeof(prec->r15lo);
    prt->papFldDes[mcaRecordR15HI]->size = sizeof(prec->r15hi);
    prt->papFldDes[mcaRecordR15BG]->size = sizeof(prec->r15bg);
    prt->papFldDes[mcaRecordR15IP]->size = sizeof(prec->r15ip);
    prt->papFldDes[mcaRecordR16LO]->size = sizeof(prec->r16lo);
    prt->papFldDes[mcaRecordR16HI]->size = sizeof(prec->r16hi);
    prt->papFldDes[mcaRecordR16BG]->size = sizeof(prec->r16bg);
    prt->papFldDes[mcaRecordR16IP]->size = sizeof(prec->r16ip);
    prt->papFldDes[mcaRecordR17LO]->size = sizeof(prec->r17lo);
    prt->papFldDes[mcaRecordR17HI]->size = sizeof(prec->r17hi);
    prt->papFldDes[mcaRecordR17BG]->size = sizeof(prec->r17bg);
    prt->papFldDes[mcaRecordR17IP]->size = sizeof(prec->r17ip);
    prt->papFldDes[mcaRecordR18LO]->size = sizeof(prec->r18lo);
    prt->papFldDes[mcaRecordR18HI]->size = sizeof(prec->r18hi);
    prt->papFldDes[mcaRecordR18BG]->size = sizeof(prec->r18bg);
    prt->papFldDes[mcaRecordR18IP]->size = sizeof(prec->r18ip);
    prt->papFldDes[mcaRecordR19LO]->size = sizeof(prec->r19lo);
    prt->papFldDes[mcaRecordR19HI]->size = sizeof(prec->r19hi);
    prt->papFldDes[mcaRecordR19BG]->size = sizeof(prec->r19bg);
    prt->papFldDes[mcaRecordR19IP]->size = sizeof(prec->r19ip);
    prt->papFldDes[mcaRecordR20LO]->size = sizeof(prec->r20lo);
    prt->papFldDes[mcaRecordR20HI]->size = sizeof(prec->r20hi);
    prt->papFldDes[mcaRecordR20BG]->size = sizeof(prec->r20bg);
    prt->papFldDes[mcaRecordR20IP]->size = sizeof(prec->r20ip);
    prt->papFldDes[mcaRecordR21LO]->size = sizeof(prec->r21lo);
    prt->papFldDes[mcaRecordR21HI]->size = sizeof(prec->r21hi);
    prt->papFldDes[mcaRecordR21BG]->size = sizeof(prec->r21bg);
    prt->papFldDes[mcaRecordR21IP]->size = sizeof(prec->r21ip);
    prt->papFldDes[mcaRecordR22LO]->size = sizeof(prec->r22lo);
    prt->papFldDes[mcaRecordR22HI]->size = sizeof(prec->r22hi);
    prt->papFldDes[mcaRecordR22BG]->size = sizeof(prec->r22bg);
    prt->papFldDes[mcaRecordR22IP]->size = sizeof(prec->r22ip);
    prt->papFldDes[mcaRecordR23LO]->size = sizeof(prec->r23lo);
    prt->papFldDes[mcaRecordR23HI]->size = sizeof(prec->r23hi);
    prt->papFldDes[mcaRecordR23BG]->size = sizeof(prec->r23bg);
    prt->papFldDes[mcaRecordR23IP]->size = sizeof(prec->r23ip);
    prt->papFldDes[mcaRecordR24LO]->size = sizeof(prec->r24lo);
    prt->papFldDes[mcaRecordR24HI]->size = sizeof(prec->r24hi);
    prt->papFldDes[mcaRecordR24BG]->size = sizeof(prec->r24bg);
    prt->papFldDes[mcaRecordR24IP]->size = sizeof(prec->r24ip);
    prt->papFldDes[mcaRecordR25LO]->size = sizeof(prec->r25lo);
    prt->papFldDes[mcaRecordR25HI]->size = sizeof(prec->r25hi);
    prt->papFldDes[mcaRecordR25BG]->size = sizeof(prec->r25bg);
    prt->papFldDes[mcaRecordR25IP]->size = sizeof(prec->r25ip);
    prt->papFldDes[mcaRecordR26LO]->size = sizeof(prec->r26lo);
    prt->papFldDes[mcaRecordR26HI]->size = sizeof(prec->r26hi);
    prt->papFldDes[mcaRecordR26BG]->size = sizeof(prec->r26bg);
    prt->papFldDes[mcaRecordR26IP]->size = sizeof(prec->r26ip);
    prt->papFldDes[mcaRecordR27LO]->size = sizeof(prec->r27lo);
    prt->papFldDes[mcaRecordR27HI]->size = sizeof(prec->r27hi);
    prt->papFldDes[mcaRecordR27BG]->size = sizeof(prec->r27bg);
    prt->papFldDes[mcaRecordR27IP]->size = sizeof(prec->r27ip);
    prt->papFldDes[mcaRecordR28LO]->size = sizeof(prec->r28lo);
    prt->papFldDes[mcaRecordR28HI]->size = sizeof(prec->r28hi);
    prt->papFldDes[mcaRecordR28BG]->size = sizeof(prec->r28bg);
    prt->papFldDes[mcaRecordR28IP]->size = sizeof(prec->r28ip);
    prt->papFldDes[mcaRecordR29LO]->size = sizeof(prec->r29lo);
    prt->papFldDes[mcaRecordR29HI]->size = sizeof(prec->r29hi);
    prt->papFldDes[mcaRecordR29BG]->size = sizeof(prec->r29bg);
    prt->papFldDes[mcaRecordR29IP]->size = sizeof(prec->r29ip);
    prt->papFldDes[mcaRecordR30LO]->size = sizeof(prec->r30lo);
    prt->papFldDes[mcaRecordR30HI]->size = sizeof(prec->r30hi);
    prt->papFldDes[mcaRecordR30BG]->size = sizeof(prec->r30bg);
    prt->papFldDes[mcaRecordR30IP]->size = sizeof(prec->r30ip);
    prt->papFldDes[mcaRecordR31LO]->size = sizeof(prec->r31lo);
    prt->papFldDes[mcaRecordR31HI]->size = sizeof(prec->r31hi);
    prt->papFldDes[mcaRecordR31BG]->size = sizeof(prec->r31bg);
    prt->papFldDes[mcaRecordR31IP]->size = sizeof(prec->r31ip);
    prt->papFldDes[mcaRecordR0]->size = sizeof(prec->r0);
    prt->papFldDes[mcaRecordR0N]->size = sizeof(prec->r0n);
    prt->papFldDes[mcaRecordR0P]->size = sizeof(prec->r0p);
    prt->papFldDes[mcaRecordR1]->size = sizeof(prec->r1);
    prt->papFldDes[mcaRecordR1N]->size = sizeof(prec->r1n);
    prt->papFldDes[mcaRecordR1P]->size = sizeof(prec->r1p);
    prt->papFldDes[mcaRecordR2]->size = sizeof(prec->r2);
    prt->papFldDes[mcaRecordR2N]->size = sizeof(prec->r2n);
    prt->papFldDes[mcaRecordR2P]->size = sizeof(prec->r2p);
    prt->papFldDes[mcaRecordR3]->size = sizeof(prec->r3);
    prt->papFldDes[mcaRecordR3N]->size = sizeof(prec->r3n);
    prt->papFldDes[mcaRecordR3P]->size = sizeof(prec->r3p);
    prt->papFldDes[mcaRecordR4]->size = sizeof(prec->r4);
    prt->papFldDes[mcaRecordR4N]->size = sizeof(prec->r4n);
    prt->papFldDes[mcaRecordR4P]->size = sizeof(prec->r4p);
    prt->papFldDes[mcaRecordR5]->size = sizeof(prec->r5);
    prt->papFldDes[mcaRecordR5N]->size = sizeof(prec->r5n);
    prt->papFldDes[mcaRecordR5P]->size = sizeof(prec->r5p);
    prt->papFldDes[mcaRecordR6]->size = sizeof(prec->r6);
    prt->papFldDes[mcaRecordR6N]->size = sizeof(prec->r6n);
    prt->papFldDes[mcaRecordR6P]->size = sizeof(prec->r6p);
    prt->papFldDes[mcaRecordR7]->size = sizeof(prec->r7);
    prt->papFldDes[mcaRecordR7N]->size = sizeof(prec->r7n);
    prt->papFldDes[mcaRecordR7P]->size = sizeof(prec->r7p);
    prt->papFldDes[mcaRecordR8]->size = sizeof(prec->r8);
    prt->papFldDes[mcaRecordR8N]->size = sizeof(prec->r8n);
    prt->papFldDes[mcaRecordR8P]->size = sizeof(prec->r8p);
    prt->papFldDes[mcaRecordR9]->size = sizeof(prec->r9);
    prt->papFldDes[mcaRecordR9N]->size = sizeof(prec->r9n);
    prt->papFldDes[mcaRecordR9P]->size = sizeof(prec->r9p);
    prt->papFldDes[mcaRecordR10]->size = sizeof(prec->r10);
    prt->papFldDes[mcaRecordR10N]->size = sizeof(prec->r10n);
    prt->papFldDes[mcaRecordR10P]->size = sizeof(prec->r10p);
    prt->papFldDes[mcaRecordR11]->size = sizeof(prec->r11);
    prt->papFldDes[mcaRecordR11N]->size = sizeof(prec->r11n);
    prt->papFldDes[mcaRecordR11P]->size = sizeof(prec->r11p);
    prt->papFldDes[mcaRecordR12]->size = sizeof(prec->r12);
    prt->papFldDes[mcaRecordR12N]->size = sizeof(prec->r12n);
    prt->papFldDes[mcaRecordR12P]->size = sizeof(prec->r12p);
    prt->papFldDes[mcaRecordR13]->size = sizeof(prec->r13);
    prt->papFldDes[mcaRecordR13N]->size = sizeof(prec->r13n);
    prt->papFldDes[mcaRecordR13P]->size = sizeof(prec->r13p);
    prt->papFldDes[mcaRecordR14]->size = sizeof(prec->r14);
    prt->papFldDes[mcaRecordR14N]->size = sizeof(prec->r14n);
    prt->papFldDes[mcaRecordR14P]->size = sizeof(prec->r14p);
    prt->papFldDes[mcaRecordR15]->size = sizeof(prec->r15);
    prt->papFldDes[mcaRecordR15N]->size = sizeof(prec->r15n);
    prt->papFldDes[mcaRecordR15P]->size = sizeof(prec->r15p);
    prt->papFldDes[mcaRecordR16]->size = sizeof(prec->r16);
    prt->papFldDes[mcaRecordR16N]->size = sizeof(prec->r16n);
    prt->papFldDes[mcaRecordR16P]->size = sizeof(prec->r16p);
    prt->papFldDes[mcaRecordR17]->size = sizeof(prec->r17);
    prt->papFldDes[mcaRecordR17N]->size = sizeof(prec->r17n);
    prt->papFldDes[mcaRecordR17P]->size = sizeof(prec->r17p);
    prt->papFldDes[mcaRecordR18]->size = sizeof(prec->r18);
    prt->papFldDes[mcaRecordR18N]->size = sizeof(prec->r18n);
    prt->papFldDes[mcaRecordR18P]->size = sizeof(prec->r18p);
    prt->papFldDes[mcaRecordR19]->size = sizeof(prec->r19);
    prt->papFldDes[mcaRecordR19N]->size = sizeof(prec->r19n);
    prt->papFldDes[mcaRecordR19P]->size = sizeof(prec->r19p);
    prt->papFldDes[mcaRecordR20]->size = sizeof(prec->r20);
    prt->papFldDes[mcaRecordR20N]->size = sizeof(prec->r20n);
    prt->papFldDes[mcaRecordR20P]->size = sizeof(prec->r20p);
    prt->papFldDes[mcaRecordR21]->size = sizeof(prec->r21);
    prt->papFldDes[mcaRecordR21N]->size = sizeof(prec->r21n);
    prt->papFldDes[mcaRecordR21P]->size = sizeof(prec->r21p);
    prt->papFldDes[mcaRecordR22]->size = sizeof(prec->r22);
    prt->papFldDes[mcaRecordR22N]->size = sizeof(prec->r22n);
    prt->papFldDes[mcaRecordR22P]->size = sizeof(prec->r22p);
    prt->papFldDes[mcaRecordR23]->size = sizeof(prec->r23);
    prt->papFldDes[mcaRecordR23N]->size = sizeof(prec->r23n);
    prt->papFldDes[mcaRecordR23P]->size = sizeof(prec->r23p);
    prt->papFldDes[mcaRecordR24]->size = sizeof(prec->r24);
    prt->papFldDes[mcaRecordR24N]->size = sizeof(prec->r24n);
    prt->papFldDes[mcaRecordR24P]->size = sizeof(prec->r24p);
    prt->papFldDes[mcaRecordR25]->size = sizeof(prec->r25);
    prt->papFldDes[mcaRecordR25N]->size = sizeof(prec->r25n);
    prt->papFldDes[mcaRecordR25P]->size = sizeof(prec->r25p);
    prt->papFldDes[mcaRecordR26]->size = sizeof(prec->r26);
    prt->papFldDes[mcaRecordR26N]->size = sizeof(prec->r26n);
    prt->papFldDes[mcaRecordR26P]->size = sizeof(prec->r26p);
    prt->papFldDes[mcaRecordR27]->size = sizeof(prec->r27);
    prt->papFldDes[mcaRecordR27N]->size = sizeof(prec->r27n);
    prt->papFldDes[mcaRecordR27P]->size = sizeof(prec->r27p);
    prt->papFldDes[mcaRecordR28]->size = sizeof(prec->r28);
    prt->papFldDes[mcaRecordR28N]->size = sizeof(prec->r28n);
    prt->papFldDes[mcaRecordR28P]->size = sizeof(prec->r28p);
    prt->papFldDes[mcaRecordR29]->size = sizeof(prec->r29);
    prt->papFldDes[mcaRecordR29N]->size = sizeof(prec->r29n);
    prt->papFldDes[mcaRecordR29P]->size = sizeof(prec->r29p);
    prt->papFldDes[mcaRecordR30]->size = sizeof(prec->r30);
    prt->papFldDes[mcaRecordR30N]->size = sizeof(prec->r30n);
    prt->papFldDes[mcaRecordR30P]->size = sizeof(prec->r30p);
    prt->papFldDes[mcaRecordR31]->size = sizeof(prec->r31);
    prt->papFldDes[mcaRecordR31N]->size = sizeof(prec->r31n);
    prt->papFldDes[mcaRecordR31P]->size = sizeof(prec->r31p);
    prt->papFldDes[mcaRecordR0NM]->size = sizeof(prec->r0nm);
    prt->papFldDes[mcaRecordR1NM]->size = sizeof(prec->r1nm);
    prt->papFldDes[mcaRecordR2NM]->size = sizeof(prec->r2nm);
    prt->papFldDes[mcaRecordR3NM]->size = sizeof(prec->r3nm);
    prt->papFldDes[mcaRecordR4NM]->size = sizeof(prec->r4nm);
    prt->papFldDes[mcaRecordR5NM]->size = sizeof(prec->r5nm);
    prt->papFldDes[mcaRecordR6NM]->size = sizeof(prec->r6nm);
    prt->papFldDes[mcaRecordR7NM]->size = sizeof(prec->r7nm);
    prt->papFldDes[mcaRecordR8NM]->size = sizeof(prec->r8nm);
    prt->papFldDes[mcaRecordR9NM]->size = sizeof(prec->r9nm);
    prt->papFldDes[mcaRecordR10NM]->size = sizeof(prec->r10nm);
    prt->papFldDes[mcaRecordR11NM]->size = sizeof(prec->r11nm);
    prt->papFldDes[mcaRecordR12NM]->size = sizeof(prec->r12nm);
    prt->papFldDes[mcaRecordR13NM]->size = sizeof(prec->r13nm);
    prt->papFldDes[mcaRecordR14NM]->size = sizeof(prec->r14nm);
    prt->papFldDes[mcaRecordR15NM]->size = sizeof(prec->r15nm);
    prt->papFldDes[mcaRecordR16NM]->size = sizeof(prec->r16nm);
    prt->papFldDes[mcaRecordR17NM]->size = sizeof(prec->r17nm);
    prt->papFldDes[mcaRecordR18NM]->size = sizeof(prec->r18nm);
    prt->papFldDes[mcaRecordR19NM]->size = sizeof(prec->r19nm);
    prt->papFldDes[mcaRecordR20NM]->size = sizeof(prec->r20nm);
    prt->papFldDes[mcaRecordR21NM]->size = sizeof(prec->r21nm);
    prt->papFldDes[mcaRecordR22NM]->size = sizeof(prec->r22nm);
    prt->papFldDes[mcaRecordR23NM]->size = sizeof(prec->r23nm);
    prt->papFldDes[mcaRecordR24NM]->size = sizeof(prec->r24nm);
    prt->papFldDes[mcaRecordR25NM]->size = sizeof(prec->r25nm);
    prt->papFldDes[mcaRecordR26NM]->size = sizeof(prec->r26nm);
    prt->papFldDes[mcaRecordR27NM]->size = sizeof(prec->r27nm);
    prt->papFldDes[mcaRecordR28NM]->size = sizeof(prec->r28nm);
    prt->papFldDes[mcaRecordR29NM]->size = sizeof(prec->r29nm);
    prt->papFldDes[mcaRecordR30NM]->size = sizeof(prec->r30nm);
    prt->papFldDes[mcaRecordR31NM]->size = sizeof(prec->r31nm);
    prt->papFldDes[mcaRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[mcaRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[mcaRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[mcaRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[mcaRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[mcaRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[mcaRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[mcaRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[mcaRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[mcaRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[mcaRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[mcaRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[mcaRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[mcaRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[mcaRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[mcaRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[mcaRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[mcaRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[mcaRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[mcaRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[mcaRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[mcaRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[mcaRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[mcaRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[mcaRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[mcaRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[mcaRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[mcaRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[mcaRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[mcaRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[mcaRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[mcaRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[mcaRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[mcaRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[mcaRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[mcaRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[mcaRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[mcaRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[mcaRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[mcaRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[mcaRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[mcaRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[mcaRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[mcaRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[mcaRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[mcaRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[mcaRecordBPTR]->offset = (unsigned short)((char *)&prec->bptr - (char *)prec);
    prt->papFldDes[mcaRecordBG]->offset = (unsigned short)((char *)&prec->bg - (char *)prec);
    prt->papFldDes[mcaRecordPBG]->offset = (unsigned short)((char *)&prec->pbg - (char *)prec);
    prt->papFldDes[mcaRecordPSTATUS]->offset = (unsigned short)((char *)&prec->pstatus - (char *)prec);
    prt->papFldDes[mcaRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[mcaRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[mcaRecordNMAX]->offset = (unsigned short)((char *)&prec->nmax - (char *)prec);
    prt->papFldDes[mcaRecordNORD]->offset = (unsigned short)((char *)&prec->nord - (char *)prec);
    prt->papFldDes[mcaRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[mcaRecordFTVL]->offset = (unsigned short)((char *)&prec->ftvl - (char *)prec);
    prt->papFldDes[mcaRecordSTRT]->offset = (unsigned short)((char *)&prec->strt - (char *)prec);
    prt->papFldDes[mcaRecordERST]->offset = (unsigned short)((char *)&prec->erst - (char *)prec);
    prt->papFldDes[mcaRecordSTOP]->offset = (unsigned short)((char *)&prec->stop - (char *)prec);
    prt->papFldDes[mcaRecordACQG]->offset = (unsigned short)((char *)&prec->acqg - (char *)prec);
    prt->papFldDes[mcaRecordREAD]->offset = (unsigned short)((char *)&prec->read - (char *)prec);
    prt->papFldDes[mcaRecordRDNG]->offset = (unsigned short)((char *)&prec->rdng - (char *)prec);
    prt->papFldDes[mcaRecordRDNS]->offset = (unsigned short)((char *)&prec->rdns - (char *)prec);
    prt->papFldDes[mcaRecordERAS]->offset = (unsigned short)((char *)&prec->eras - (char *)prec);
    prt->papFldDes[mcaRecordCHAS]->offset = (unsigned short)((char *)&prec->chas - (char *)prec);
    prt->papFldDes[mcaRecordNUSE]->offset = (unsigned short)((char *)&prec->nuse - (char *)prec);
    prt->papFldDes[mcaRecordSEQ]->offset = (unsigned short)((char *)&prec->seq - (char *)prec);
    prt->papFldDes[mcaRecordDWEL]->offset = (unsigned short)((char *)&prec->dwel - (char *)prec);
    prt->papFldDes[mcaRecordPSCL]->offset = (unsigned short)((char *)&prec->pscl - (char *)prec);
    prt->papFldDes[mcaRecordPRTM]->offset = (unsigned short)((char *)&prec->prtm - (char *)prec);
    prt->papFldDes[mcaRecordPLTM]->offset = (unsigned short)((char *)&prec->pltm - (char *)prec);
    prt->papFldDes[mcaRecordPCT]->offset = (unsigned short)((char *)&prec->pct - (char *)prec);
    prt->papFldDes[mcaRecordPCTL]->offset = (unsigned short)((char *)&prec->pctl - (char *)prec);
    prt->papFldDes[mcaRecordPCTH]->offset = (unsigned short)((char *)&prec->pcth - (char *)prec);
    prt->papFldDes[mcaRecordPSWP]->offset = (unsigned short)((char *)&prec->pswp - (char *)prec);
    prt->papFldDes[mcaRecordMODE]->offset = (unsigned short)((char *)&prec->mode - (char *)prec);
    prt->papFldDes[mcaRecordCALO]->offset = (unsigned short)((char *)&prec->calo - (char *)prec);
    prt->papFldDes[mcaRecordCALS]->offset = (unsigned short)((char *)&prec->cals - (char *)prec);
    prt->papFldDes[mcaRecordCALQ]->offset = (unsigned short)((char *)&prec->calq - (char *)prec);
    prt->papFldDes[mcaRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[mcaRecordTTH]->offset = (unsigned short)((char *)&prec->tth - (char *)prec);
    prt->papFldDes[mcaRecordERTM]->offset = (unsigned short)((char *)&prec->ertm - (char *)prec);
    prt->papFldDes[mcaRecordELTM]->offset = (unsigned short)((char *)&prec->eltm - (char *)prec);
    prt->papFldDes[mcaRecordDTIM]->offset = (unsigned short)((char *)&prec->dtim - (char *)prec);
    prt->papFldDes[mcaRecordIDTIM]->offset = (unsigned short)((char *)&prec->idtim - (char *)prec);
    prt->papFldDes[mcaRecordSTIM]->offset = (unsigned short)((char *)&prec->stim - (char *)prec);
    prt->papFldDes[mcaRecordRTIM]->offset = (unsigned short)((char *)&prec->rtim - (char *)prec);
    prt->papFldDes[mcaRecordACT]->offset = (unsigned short)((char *)&prec->act - (char *)prec);
    prt->papFldDes[mcaRecordNACK]->offset = (unsigned short)((char *)&prec->nack - (char *)prec);
    prt->papFldDes[mcaRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[mcaRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[mcaRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[mcaRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[mcaRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[mcaRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[mcaRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[mcaRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[mcaRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[mcaRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[mcaRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[mcaRecordSIOL]->offset = (unsigned short)((char *)&prec->siol - (char *)prec);
    prt->papFldDes[mcaRecordSIML]->offset = (unsigned short)((char *)&prec->siml - (char *)prec);
    prt->papFldDes[mcaRecordSIMM]->offset = (unsigned short)((char *)&prec->simm - (char *)prec);
    prt->papFldDes[mcaRecordSIMS]->offset = (unsigned short)((char *)&prec->sims - (char *)prec);
    prt->papFldDes[mcaRecordMMAP]->offset = (unsigned short)((char *)&prec->mmap - (char *)prec);
    prt->papFldDes[mcaRecordRMAP]->offset = (unsigned short)((char *)&prec->rmap - (char *)prec);
    prt->papFldDes[mcaRecordNEWV]->offset = (unsigned short)((char *)&prec->newv - (char *)prec);
    prt->papFldDes[mcaRecordNEWR]->offset = (unsigned short)((char *)&prec->newr - (char *)prec);
    prt->papFldDes[mcaRecordR0LO]->offset = (unsigned short)((char *)&prec->r0lo - (char *)prec);
    prt->papFldDes[mcaRecordR0HI]->offset = (unsigned short)((char *)&prec->r0hi - (char *)prec);
    prt->papFldDes[mcaRecordR0BG]->offset = (unsigned short)((char *)&prec->r0bg - (char *)prec);
    prt->papFldDes[mcaRecordR0IP]->offset = (unsigned short)((char *)&prec->r0ip - (char *)prec);
    prt->papFldDes[mcaRecordR1LO]->offset = (unsigned short)((char *)&prec->r1lo - (char *)prec);
    prt->papFldDes[mcaRecordR1HI]->offset = (unsigned short)((char *)&prec->r1hi - (char *)prec);
    prt->papFldDes[mcaRecordR1BG]->offset = (unsigned short)((char *)&prec->r1bg - (char *)prec);
    prt->papFldDes[mcaRecordR1IP]->offset = (unsigned short)((char *)&prec->r1ip - (char *)prec);
    prt->papFldDes[mcaRecordR2LO]->offset = (unsigned short)((char *)&prec->r2lo - (char *)prec);
    prt->papFldDes[mcaRecordR2HI]->offset = (unsigned short)((char *)&prec->r2hi - (char *)prec);
    prt->papFldDes[mcaRecordR2BG]->offset = (unsigned short)((char *)&prec->r2bg - (char *)prec);
    prt->papFldDes[mcaRecordR2IP]->offset = (unsigned short)((char *)&prec->r2ip - (char *)prec);
    prt->papFldDes[mcaRecordR3LO]->offset = (unsigned short)((char *)&prec->r3lo - (char *)prec);
    prt->papFldDes[mcaRecordR3HI]->offset = (unsigned short)((char *)&prec->r3hi - (char *)prec);
    prt->papFldDes[mcaRecordR3BG]->offset = (unsigned short)((char *)&prec->r3bg - (char *)prec);
    prt->papFldDes[mcaRecordR3IP]->offset = (unsigned short)((char *)&prec->r3ip - (char *)prec);
    prt->papFldDes[mcaRecordR4LO]->offset = (unsigned short)((char *)&prec->r4lo - (char *)prec);
    prt->papFldDes[mcaRecordR4HI]->offset = (unsigned short)((char *)&prec->r4hi - (char *)prec);
    prt->papFldDes[mcaRecordR4BG]->offset = (unsigned short)((char *)&prec->r4bg - (char *)prec);
    prt->papFldDes[mcaRecordR4IP]->offset = (unsigned short)((char *)&prec->r4ip - (char *)prec);
    prt->papFldDes[mcaRecordR5LO]->offset = (unsigned short)((char *)&prec->r5lo - (char *)prec);
    prt->papFldDes[mcaRecordR5HI]->offset = (unsigned short)((char *)&prec->r5hi - (char *)prec);
    prt->papFldDes[mcaRecordR5BG]->offset = (unsigned short)((char *)&prec->r5bg - (char *)prec);
    prt->papFldDes[mcaRecordR5IP]->offset = (unsigned short)((char *)&prec->r5ip - (char *)prec);
    prt->papFldDes[mcaRecordR6LO]->offset = (unsigned short)((char *)&prec->r6lo - (char *)prec);
    prt->papFldDes[mcaRecordR6HI]->offset = (unsigned short)((char *)&prec->r6hi - (char *)prec);
    prt->papFldDes[mcaRecordR6BG]->offset = (unsigned short)((char *)&prec->r6bg - (char *)prec);
    prt->papFldDes[mcaRecordR6IP]->offset = (unsigned short)((char *)&prec->r6ip - (char *)prec);
    prt->papFldDes[mcaRecordR7LO]->offset = (unsigned short)((char *)&prec->r7lo - (char *)prec);
    prt->papFldDes[mcaRecordR7HI]->offset = (unsigned short)((char *)&prec->r7hi - (char *)prec);
    prt->papFldDes[mcaRecordR7BG]->offset = (unsigned short)((char *)&prec->r7bg - (char *)prec);
    prt->papFldDes[mcaRecordR7IP]->offset = (unsigned short)((char *)&prec->r7ip - (char *)prec);
    prt->papFldDes[mcaRecordR8LO]->offset = (unsigned short)((char *)&prec->r8lo - (char *)prec);
    prt->papFldDes[mcaRecordR8HI]->offset = (unsigned short)((char *)&prec->r8hi - (char *)prec);
    prt->papFldDes[mcaRecordR8BG]->offset = (unsigned short)((char *)&prec->r8bg - (char *)prec);
    prt->papFldDes[mcaRecordR8IP]->offset = (unsigned short)((char *)&prec->r8ip - (char *)prec);
    prt->papFldDes[mcaRecordR9LO]->offset = (unsigned short)((char *)&prec->r9lo - (char *)prec);
    prt->papFldDes[mcaRecordR9HI]->offset = (unsigned short)((char *)&prec->r9hi - (char *)prec);
    prt->papFldDes[mcaRecordR9BG]->offset = (unsigned short)((char *)&prec->r9bg - (char *)prec);
    prt->papFldDes[mcaRecordR9IP]->offset = (unsigned short)((char *)&prec->r9ip - (char *)prec);
    prt->papFldDes[mcaRecordR10LO]->offset = (unsigned short)((char *)&prec->r10lo - (char *)prec);
    prt->papFldDes[mcaRecordR10HI]->offset = (unsigned short)((char *)&prec->r10hi - (char *)prec);
    prt->papFldDes[mcaRecordR10BG]->offset = (unsigned short)((char *)&prec->r10bg - (char *)prec);
    prt->papFldDes[mcaRecordR10IP]->offset = (unsigned short)((char *)&prec->r10ip - (char *)prec);
    prt->papFldDes[mcaRecordR11LO]->offset = (unsigned short)((char *)&prec->r11lo - (char *)prec);
    prt->papFldDes[mcaRecordR11HI]->offset = (unsigned short)((char *)&prec->r11hi - (char *)prec);
    prt->papFldDes[mcaRecordR11BG]->offset = (unsigned short)((char *)&prec->r11bg - (char *)prec);
    prt->papFldDes[mcaRecordR11IP]->offset = (unsigned short)((char *)&prec->r11ip - (char *)prec);
    prt->papFldDes[mcaRecordR12LO]->offset = (unsigned short)((char *)&prec->r12lo - (char *)prec);
    prt->papFldDes[mcaRecordR12HI]->offset = (unsigned short)((char *)&prec->r12hi - (char *)prec);
    prt->papFldDes[mcaRecordR12BG]->offset = (unsigned short)((char *)&prec->r12bg - (char *)prec);
    prt->papFldDes[mcaRecordR12IP]->offset = (unsigned short)((char *)&prec->r12ip - (char *)prec);
    prt->papFldDes[mcaRecordR13LO]->offset = (unsigned short)((char *)&prec->r13lo - (char *)prec);
    prt->papFldDes[mcaRecordR13HI]->offset = (unsigned short)((char *)&prec->r13hi - (char *)prec);
    prt->papFldDes[mcaRecordR13BG]->offset = (unsigned short)((char *)&prec->r13bg - (char *)prec);
    prt->papFldDes[mcaRecordR13IP]->offset = (unsigned short)((char *)&prec->r13ip - (char *)prec);
    prt->papFldDes[mcaRecordR14LO]->offset = (unsigned short)((char *)&prec->r14lo - (char *)prec);
    prt->papFldDes[mcaRecordR14HI]->offset = (unsigned short)((char *)&prec->r14hi - (char *)prec);
    prt->papFldDes[mcaRecordR14BG]->offset = (unsigned short)((char *)&prec->r14bg - (char *)prec);
    prt->papFldDes[mcaRecordR14IP]->offset = (unsigned short)((char *)&prec->r14ip - (char *)prec);
    prt->papFldDes[mcaRecordR15LO]->offset = (unsigned short)((char *)&prec->r15lo - (char *)prec);
    prt->papFldDes[mcaRecordR15HI]->offset = (unsigned short)((char *)&prec->r15hi - (char *)prec);
    prt->papFldDes[mcaRecordR15BG]->offset = (unsigned short)((char *)&prec->r15bg - (char *)prec);
    prt->papFldDes[mcaRecordR15IP]->offset = (unsigned short)((char *)&prec->r15ip - (char *)prec);
    prt->papFldDes[mcaRecordR16LO]->offset = (unsigned short)((char *)&prec->r16lo - (char *)prec);
    prt->papFldDes[mcaRecordR16HI]->offset = (unsigned short)((char *)&prec->r16hi - (char *)prec);
    prt->papFldDes[mcaRecordR16BG]->offset = (unsigned short)((char *)&prec->r16bg - (char *)prec);
    prt->papFldDes[mcaRecordR16IP]->offset = (unsigned short)((char *)&prec->r16ip - (char *)prec);
    prt->papFldDes[mcaRecordR17LO]->offset = (unsigned short)((char *)&prec->r17lo - (char *)prec);
    prt->papFldDes[mcaRecordR17HI]->offset = (unsigned short)((char *)&prec->r17hi - (char *)prec);
    prt->papFldDes[mcaRecordR17BG]->offset = (unsigned short)((char *)&prec->r17bg - (char *)prec);
    prt->papFldDes[mcaRecordR17IP]->offset = (unsigned short)((char *)&prec->r17ip - (char *)prec);
    prt->papFldDes[mcaRecordR18LO]->offset = (unsigned short)((char *)&prec->r18lo - (char *)prec);
    prt->papFldDes[mcaRecordR18HI]->offset = (unsigned short)((char *)&prec->r18hi - (char *)prec);
    prt->papFldDes[mcaRecordR18BG]->offset = (unsigned short)((char *)&prec->r18bg - (char *)prec);
    prt->papFldDes[mcaRecordR18IP]->offset = (unsigned short)((char *)&prec->r18ip - (char *)prec);
    prt->papFldDes[mcaRecordR19LO]->offset = (unsigned short)((char *)&prec->r19lo - (char *)prec);
    prt->papFldDes[mcaRecordR19HI]->offset = (unsigned short)((char *)&prec->r19hi - (char *)prec);
    prt->papFldDes[mcaRecordR19BG]->offset = (unsigned short)((char *)&prec->r19bg - (char *)prec);
    prt->papFldDes[mcaRecordR19IP]->offset = (unsigned short)((char *)&prec->r19ip - (char *)prec);
    prt->papFldDes[mcaRecordR20LO]->offset = (unsigned short)((char *)&prec->r20lo - (char *)prec);
    prt->papFldDes[mcaRecordR20HI]->offset = (unsigned short)((char *)&prec->r20hi - (char *)prec);
    prt->papFldDes[mcaRecordR20BG]->offset = (unsigned short)((char *)&prec->r20bg - (char *)prec);
    prt->papFldDes[mcaRecordR20IP]->offset = (unsigned short)((char *)&prec->r20ip - (char *)prec);
    prt->papFldDes[mcaRecordR21LO]->offset = (unsigned short)((char *)&prec->r21lo - (char *)prec);
    prt->papFldDes[mcaRecordR21HI]->offset = (unsigned short)((char *)&prec->r21hi - (char *)prec);
    prt->papFldDes[mcaRecordR21BG]->offset = (unsigned short)((char *)&prec->r21bg - (char *)prec);
    prt->papFldDes[mcaRecordR21IP]->offset = (unsigned short)((char *)&prec->r21ip - (char *)prec);
    prt->papFldDes[mcaRecordR22LO]->offset = (unsigned short)((char *)&prec->r22lo - (char *)prec);
    prt->papFldDes[mcaRecordR22HI]->offset = (unsigned short)((char *)&prec->r22hi - (char *)prec);
    prt->papFldDes[mcaRecordR22BG]->offset = (unsigned short)((char *)&prec->r22bg - (char *)prec);
    prt->papFldDes[mcaRecordR22IP]->offset = (unsigned short)((char *)&prec->r22ip - (char *)prec);
    prt->papFldDes[mcaRecordR23LO]->offset = (unsigned short)((char *)&prec->r23lo - (char *)prec);
    prt->papFldDes[mcaRecordR23HI]->offset = (unsigned short)((char *)&prec->r23hi - (char *)prec);
    prt->papFldDes[mcaRecordR23BG]->offset = (unsigned short)((char *)&prec->r23bg - (char *)prec);
    prt->papFldDes[mcaRecordR23IP]->offset = (unsigned short)((char *)&prec->r23ip - (char *)prec);
    prt->papFldDes[mcaRecordR24LO]->offset = (unsigned short)((char *)&prec->r24lo - (char *)prec);
    prt->papFldDes[mcaRecordR24HI]->offset = (unsigned short)((char *)&prec->r24hi - (char *)prec);
    prt->papFldDes[mcaRecordR24BG]->offset = (unsigned short)((char *)&prec->r24bg - (char *)prec);
    prt->papFldDes[mcaRecordR24IP]->offset = (unsigned short)((char *)&prec->r24ip - (char *)prec);
    prt->papFldDes[mcaRecordR25LO]->offset = (unsigned short)((char *)&prec->r25lo - (char *)prec);
    prt->papFldDes[mcaRecordR25HI]->offset = (unsigned short)((char *)&prec->r25hi - (char *)prec);
    prt->papFldDes[mcaRecordR25BG]->offset = (unsigned short)((char *)&prec->r25bg - (char *)prec);
    prt->papFldDes[mcaRecordR25IP]->offset = (unsigned short)((char *)&prec->r25ip - (char *)prec);
    prt->papFldDes[mcaRecordR26LO]->offset = (unsigned short)((char *)&prec->r26lo - (char *)prec);
    prt->papFldDes[mcaRecordR26HI]->offset = (unsigned short)((char *)&prec->r26hi - (char *)prec);
    prt->papFldDes[mcaRecordR26BG]->offset = (unsigned short)((char *)&prec->r26bg - (char *)prec);
    prt->papFldDes[mcaRecordR26IP]->offset = (unsigned short)((char *)&prec->r26ip - (char *)prec);
    prt->papFldDes[mcaRecordR27LO]->offset = (unsigned short)((char *)&prec->r27lo - (char *)prec);
    prt->papFldDes[mcaRecordR27HI]->offset = (unsigned short)((char *)&prec->r27hi - (char *)prec);
    prt->papFldDes[mcaRecordR27BG]->offset = (unsigned short)((char *)&prec->r27bg - (char *)prec);
    prt->papFldDes[mcaRecordR27IP]->offset = (unsigned short)((char *)&prec->r27ip - (char *)prec);
    prt->papFldDes[mcaRecordR28LO]->offset = (unsigned short)((char *)&prec->r28lo - (char *)prec);
    prt->papFldDes[mcaRecordR28HI]->offset = (unsigned short)((char *)&prec->r28hi - (char *)prec);
    prt->papFldDes[mcaRecordR28BG]->offset = (unsigned short)((char *)&prec->r28bg - (char *)prec);
    prt->papFldDes[mcaRecordR28IP]->offset = (unsigned short)((char *)&prec->r28ip - (char *)prec);
    prt->papFldDes[mcaRecordR29LO]->offset = (unsigned short)((char *)&prec->r29lo - (char *)prec);
    prt->papFldDes[mcaRecordR29HI]->offset = (unsigned short)((char *)&prec->r29hi - (char *)prec);
    prt->papFldDes[mcaRecordR29BG]->offset = (unsigned short)((char *)&prec->r29bg - (char *)prec);
    prt->papFldDes[mcaRecordR29IP]->offset = (unsigned short)((char *)&prec->r29ip - (char *)prec);
    prt->papFldDes[mcaRecordR30LO]->offset = (unsigned short)((char *)&prec->r30lo - (char *)prec);
    prt->papFldDes[mcaRecordR30HI]->offset = (unsigned short)((char *)&prec->r30hi - (char *)prec);
    prt->papFldDes[mcaRecordR30BG]->offset = (unsigned short)((char *)&prec->r30bg - (char *)prec);
    prt->papFldDes[mcaRecordR30IP]->offset = (unsigned short)((char *)&prec->r30ip - (char *)prec);
    prt->papFldDes[mcaRecordR31LO]->offset = (unsigned short)((char *)&prec->r31lo - (char *)prec);
    prt->papFldDes[mcaRecordR31HI]->offset = (unsigned short)((char *)&prec->r31hi - (char *)prec);
    prt->papFldDes[mcaRecordR31BG]->offset = (unsigned short)((char *)&prec->r31bg - (char *)prec);
    prt->papFldDes[mcaRecordR31IP]->offset = (unsigned short)((char *)&prec->r31ip - (char *)prec);
    prt->papFldDes[mcaRecordR0]->offset = (unsigned short)((char *)&prec->r0 - (char *)prec);
    prt->papFldDes[mcaRecordR0N]->offset = (unsigned short)((char *)&prec->r0n - (char *)prec);
    prt->papFldDes[mcaRecordR0P]->offset = (unsigned short)((char *)&prec->r0p - (char *)prec);
    prt->papFldDes[mcaRecordR1]->offset = (unsigned short)((char *)&prec->r1 - (char *)prec);
    prt->papFldDes[mcaRecordR1N]->offset = (unsigned short)((char *)&prec->r1n - (char *)prec);
    prt->papFldDes[mcaRecordR1P]->offset = (unsigned short)((char *)&prec->r1p - (char *)prec);
    prt->papFldDes[mcaRecordR2]->offset = (unsigned short)((char *)&prec->r2 - (char *)prec);
    prt->papFldDes[mcaRecordR2N]->offset = (unsigned short)((char *)&prec->r2n - (char *)prec);
    prt->papFldDes[mcaRecordR2P]->offset = (unsigned short)((char *)&prec->r2p - (char *)prec);
    prt->papFldDes[mcaRecordR3]->offset = (unsigned short)((char *)&prec->r3 - (char *)prec);
    prt->papFldDes[mcaRecordR3N]->offset = (unsigned short)((char *)&prec->r3n - (char *)prec);
    prt->papFldDes[mcaRecordR3P]->offset = (unsigned short)((char *)&prec->r3p - (char *)prec);
    prt->papFldDes[mcaRecordR4]->offset = (unsigned short)((char *)&prec->r4 - (char *)prec);
    prt->papFldDes[mcaRecordR4N]->offset = (unsigned short)((char *)&prec->r4n - (char *)prec);
    prt->papFldDes[mcaRecordR4P]->offset = (unsigned short)((char *)&prec->r4p - (char *)prec);
    prt->papFldDes[mcaRecordR5]->offset = (unsigned short)((char *)&prec->r5 - (char *)prec);
    prt->papFldDes[mcaRecordR5N]->offset = (unsigned short)((char *)&prec->r5n - (char *)prec);
    prt->papFldDes[mcaRecordR5P]->offset = (unsigned short)((char *)&prec->r5p - (char *)prec);
    prt->papFldDes[mcaRecordR6]->offset = (unsigned short)((char *)&prec->r6 - (char *)prec);
    prt->papFldDes[mcaRecordR6N]->offset = (unsigned short)((char *)&prec->r6n - (char *)prec);
    prt->papFldDes[mcaRecordR6P]->offset = (unsigned short)((char *)&prec->r6p - (char *)prec);
    prt->papFldDes[mcaRecordR7]->offset = (unsigned short)((char *)&prec->r7 - (char *)prec);
    prt->papFldDes[mcaRecordR7N]->offset = (unsigned short)((char *)&prec->r7n - (char *)prec);
    prt->papFldDes[mcaRecordR7P]->offset = (unsigned short)((char *)&prec->r7p - (char *)prec);
    prt->papFldDes[mcaRecordR8]->offset = (unsigned short)((char *)&prec->r8 - (char *)prec);
    prt->papFldDes[mcaRecordR8N]->offset = (unsigned short)((char *)&prec->r8n - (char *)prec);
    prt->papFldDes[mcaRecordR8P]->offset = (unsigned short)((char *)&prec->r8p - (char *)prec);
    prt->papFldDes[mcaRecordR9]->offset = (unsigned short)((char *)&prec->r9 - (char *)prec);
    prt->papFldDes[mcaRecordR9N]->offset = (unsigned short)((char *)&prec->r9n - (char *)prec);
    prt->papFldDes[mcaRecordR9P]->offset = (unsigned short)((char *)&prec->r9p - (char *)prec);
    prt->papFldDes[mcaRecordR10]->offset = (unsigned short)((char *)&prec->r10 - (char *)prec);
    prt->papFldDes[mcaRecordR10N]->offset = (unsigned short)((char *)&prec->r10n - (char *)prec);
    prt->papFldDes[mcaRecordR10P]->offset = (unsigned short)((char *)&prec->r10p - (char *)prec);
    prt->papFldDes[mcaRecordR11]->offset = (unsigned short)((char *)&prec->r11 - (char *)prec);
    prt->papFldDes[mcaRecordR11N]->offset = (unsigned short)((char *)&prec->r11n - (char *)prec);
    prt->papFldDes[mcaRecordR11P]->offset = (unsigned short)((char *)&prec->r11p - (char *)prec);
    prt->papFldDes[mcaRecordR12]->offset = (unsigned short)((char *)&prec->r12 - (char *)prec);
    prt->papFldDes[mcaRecordR12N]->offset = (unsigned short)((char *)&prec->r12n - (char *)prec);
    prt->papFldDes[mcaRecordR12P]->offset = (unsigned short)((char *)&prec->r12p - (char *)prec);
    prt->papFldDes[mcaRecordR13]->offset = (unsigned short)((char *)&prec->r13 - (char *)prec);
    prt->papFldDes[mcaRecordR13N]->offset = (unsigned short)((char *)&prec->r13n - (char *)prec);
    prt->papFldDes[mcaRecordR13P]->offset = (unsigned short)((char *)&prec->r13p - (char *)prec);
    prt->papFldDes[mcaRecordR14]->offset = (unsigned short)((char *)&prec->r14 - (char *)prec);
    prt->papFldDes[mcaRecordR14N]->offset = (unsigned short)((char *)&prec->r14n - (char *)prec);
    prt->papFldDes[mcaRecordR14P]->offset = (unsigned short)((char *)&prec->r14p - (char *)prec);
    prt->papFldDes[mcaRecordR15]->offset = (unsigned short)((char *)&prec->r15 - (char *)prec);
    prt->papFldDes[mcaRecordR15N]->offset = (unsigned short)((char *)&prec->r15n - (char *)prec);
    prt->papFldDes[mcaRecordR15P]->offset = (unsigned short)((char *)&prec->r15p - (char *)prec);
    prt->papFldDes[mcaRecordR16]->offset = (unsigned short)((char *)&prec->r16 - (char *)prec);
    prt->papFldDes[mcaRecordR16N]->offset = (unsigned short)((char *)&prec->r16n - (char *)prec);
    prt->papFldDes[mcaRecordR16P]->offset = (unsigned short)((char *)&prec->r16p - (char *)prec);
    prt->papFldDes[mcaRecordR17]->offset = (unsigned short)((char *)&prec->r17 - (char *)prec);
    prt->papFldDes[mcaRecordR17N]->offset = (unsigned short)((char *)&prec->r17n - (char *)prec);
    prt->papFldDes[mcaRecordR17P]->offset = (unsigned short)((char *)&prec->r17p - (char *)prec);
    prt->papFldDes[mcaRecordR18]->offset = (unsigned short)((char *)&prec->r18 - (char *)prec);
    prt->papFldDes[mcaRecordR18N]->offset = (unsigned short)((char *)&prec->r18n - (char *)prec);
    prt->papFldDes[mcaRecordR18P]->offset = (unsigned short)((char *)&prec->r18p - (char *)prec);
    prt->papFldDes[mcaRecordR19]->offset = (unsigned short)((char *)&prec->r19 - (char *)prec);
    prt->papFldDes[mcaRecordR19N]->offset = (unsigned short)((char *)&prec->r19n - (char *)prec);
    prt->papFldDes[mcaRecordR19P]->offset = (unsigned short)((char *)&prec->r19p - (char *)prec);
    prt->papFldDes[mcaRecordR20]->offset = (unsigned short)((char *)&prec->r20 - (char *)prec);
    prt->papFldDes[mcaRecordR20N]->offset = (unsigned short)((char *)&prec->r20n - (char *)prec);
    prt->papFldDes[mcaRecordR20P]->offset = (unsigned short)((char *)&prec->r20p - (char *)prec);
    prt->papFldDes[mcaRecordR21]->offset = (unsigned short)((char *)&prec->r21 - (char *)prec);
    prt->papFldDes[mcaRecordR21N]->offset = (unsigned short)((char *)&prec->r21n - (char *)prec);
    prt->papFldDes[mcaRecordR21P]->offset = (unsigned short)((char *)&prec->r21p - (char *)prec);
    prt->papFldDes[mcaRecordR22]->offset = (unsigned short)((char *)&prec->r22 - (char *)prec);
    prt->papFldDes[mcaRecordR22N]->offset = (unsigned short)((char *)&prec->r22n - (char *)prec);
    prt->papFldDes[mcaRecordR22P]->offset = (unsigned short)((char *)&prec->r22p - (char *)prec);
    prt->papFldDes[mcaRecordR23]->offset = (unsigned short)((char *)&prec->r23 - (char *)prec);
    prt->papFldDes[mcaRecordR23N]->offset = (unsigned short)((char *)&prec->r23n - (char *)prec);
    prt->papFldDes[mcaRecordR23P]->offset = (unsigned short)((char *)&prec->r23p - (char *)prec);
    prt->papFldDes[mcaRecordR24]->offset = (unsigned short)((char *)&prec->r24 - (char *)prec);
    prt->papFldDes[mcaRecordR24N]->offset = (unsigned short)((char *)&prec->r24n - (char *)prec);
    prt->papFldDes[mcaRecordR24P]->offset = (unsigned short)((char *)&prec->r24p - (char *)prec);
    prt->papFldDes[mcaRecordR25]->offset = (unsigned short)((char *)&prec->r25 - (char *)prec);
    prt->papFldDes[mcaRecordR25N]->offset = (unsigned short)((char *)&prec->r25n - (char *)prec);
    prt->papFldDes[mcaRecordR25P]->offset = (unsigned short)((char *)&prec->r25p - (char *)prec);
    prt->papFldDes[mcaRecordR26]->offset = (unsigned short)((char *)&prec->r26 - (char *)prec);
    prt->papFldDes[mcaRecordR26N]->offset = (unsigned short)((char *)&prec->r26n - (char *)prec);
    prt->papFldDes[mcaRecordR26P]->offset = (unsigned short)((char *)&prec->r26p - (char *)prec);
    prt->papFldDes[mcaRecordR27]->offset = (unsigned short)((char *)&prec->r27 - (char *)prec);
    prt->papFldDes[mcaRecordR27N]->offset = (unsigned short)((char *)&prec->r27n - (char *)prec);
    prt->papFldDes[mcaRecordR27P]->offset = (unsigned short)((char *)&prec->r27p - (char *)prec);
    prt->papFldDes[mcaRecordR28]->offset = (unsigned short)((char *)&prec->r28 - (char *)prec);
    prt->papFldDes[mcaRecordR28N]->offset = (unsigned short)((char *)&prec->r28n - (char *)prec);
    prt->papFldDes[mcaRecordR28P]->offset = (unsigned short)((char *)&prec->r28p - (char *)prec);
    prt->papFldDes[mcaRecordR29]->offset = (unsigned short)((char *)&prec->r29 - (char *)prec);
    prt->papFldDes[mcaRecordR29N]->offset = (unsigned short)((char *)&prec->r29n - (char *)prec);
    prt->papFldDes[mcaRecordR29P]->offset = (unsigned short)((char *)&prec->r29p - (char *)prec);
    prt->papFldDes[mcaRecordR30]->offset = (unsigned short)((char *)&prec->r30 - (char *)prec);
    prt->papFldDes[mcaRecordR30N]->offset = (unsigned short)((char *)&prec->r30n - (char *)prec);
    prt->papFldDes[mcaRecordR30P]->offset = (unsigned short)((char *)&prec->r30p - (char *)prec);
    prt->papFldDes[mcaRecordR31]->offset = (unsigned short)((char *)&prec->r31 - (char *)prec);
    prt->papFldDes[mcaRecordR31N]->offset = (unsigned short)((char *)&prec->r31n - (char *)prec);
    prt->papFldDes[mcaRecordR31P]->offset = (unsigned short)((char *)&prec->r31p - (char *)prec);
    prt->papFldDes[mcaRecordR0NM]->offset = (unsigned short)((char *)&prec->r0nm - (char *)prec);
    prt->papFldDes[mcaRecordR1NM]->offset = (unsigned short)((char *)&prec->r1nm - (char *)prec);
    prt->papFldDes[mcaRecordR2NM]->offset = (unsigned short)((char *)&prec->r2nm - (char *)prec);
    prt->papFldDes[mcaRecordR3NM]->offset = (unsigned short)((char *)&prec->r3nm - (char *)prec);
    prt->papFldDes[mcaRecordR4NM]->offset = (unsigned short)((char *)&prec->r4nm - (char *)prec);
    prt->papFldDes[mcaRecordR5NM]->offset = (unsigned short)((char *)&prec->r5nm - (char *)prec);
    prt->papFldDes[mcaRecordR6NM]->offset = (unsigned short)((char *)&prec->r6nm - (char *)prec);
    prt->papFldDes[mcaRecordR7NM]->offset = (unsigned short)((char *)&prec->r7nm - (char *)prec);
    prt->papFldDes[mcaRecordR8NM]->offset = (unsigned short)((char *)&prec->r8nm - (char *)prec);
    prt->papFldDes[mcaRecordR9NM]->offset = (unsigned short)((char *)&prec->r9nm - (char *)prec);
    prt->papFldDes[mcaRecordR10NM]->offset = (unsigned short)((char *)&prec->r10nm - (char *)prec);
    prt->papFldDes[mcaRecordR11NM]->offset = (unsigned short)((char *)&prec->r11nm - (char *)prec);
    prt->papFldDes[mcaRecordR12NM]->offset = (unsigned short)((char *)&prec->r12nm - (char *)prec);
    prt->papFldDes[mcaRecordR13NM]->offset = (unsigned short)((char *)&prec->r13nm - (char *)prec);
    prt->papFldDes[mcaRecordR14NM]->offset = (unsigned short)((char *)&prec->r14nm - (char *)prec);
    prt->papFldDes[mcaRecordR15NM]->offset = (unsigned short)((char *)&prec->r15nm - (char *)prec);
    prt->papFldDes[mcaRecordR16NM]->offset = (unsigned short)((char *)&prec->r16nm - (char *)prec);
    prt->papFldDes[mcaRecordR17NM]->offset = (unsigned short)((char *)&prec->r17nm - (char *)prec);
    prt->papFldDes[mcaRecordR18NM]->offset = (unsigned short)((char *)&prec->r18nm - (char *)prec);
    prt->papFldDes[mcaRecordR19NM]->offset = (unsigned short)((char *)&prec->r19nm - (char *)prec);
    prt->papFldDes[mcaRecordR20NM]->offset = (unsigned short)((char *)&prec->r20nm - (char *)prec);
    prt->papFldDes[mcaRecordR21NM]->offset = (unsigned short)((char *)&prec->r21nm - (char *)prec);
    prt->papFldDes[mcaRecordR22NM]->offset = (unsigned short)((char *)&prec->r22nm - (char *)prec);
    prt->papFldDes[mcaRecordR23NM]->offset = (unsigned short)((char *)&prec->r23nm - (char *)prec);
    prt->papFldDes[mcaRecordR24NM]->offset = (unsigned short)((char *)&prec->r24nm - (char *)prec);
    prt->papFldDes[mcaRecordR25NM]->offset = (unsigned short)((char *)&prec->r25nm - (char *)prec);
    prt->papFldDes[mcaRecordR26NM]->offset = (unsigned short)((char *)&prec->r26nm - (char *)prec);
    prt->papFldDes[mcaRecordR27NM]->offset = (unsigned short)((char *)&prec->r27nm - (char *)prec);
    prt->papFldDes[mcaRecordR28NM]->offset = (unsigned short)((char *)&prec->r28nm - (char *)prec);
    prt->papFldDes[mcaRecordR29NM]->offset = (unsigned short)((char *)&prec->r29nm - (char *)prec);
    prt->papFldDes[mcaRecordR30NM]->offset = (unsigned short)((char *)&prec->r30nm - (char *)prec);
    prt->papFldDes[mcaRecordR31NM]->offset = (unsigned short)((char *)&prec->r31nm - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(mcaRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_mcaRecord_H */
