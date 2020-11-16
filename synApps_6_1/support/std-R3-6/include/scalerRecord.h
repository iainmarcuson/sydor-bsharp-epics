/* scalerRecord.h generated from scalerRecord.dbd */

#ifndef INC_scalerRecord_H
#define INC_scalerRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    scalerCONT_OneShot              /* OneShot */,
    scalerCONT_AutoCount            /* AutoCount */
} scalerCONT;
#define scalerCONT_NUM_CHOICES 2

typedef enum {
    scalerD1_Up                     /* Up */,
    scalerD1_Dn                     /* Dn */
} scalerD1;
#define scalerD1_NUM_CHOICES 2

typedef enum {
    scalerG1_N                      /* N */,
    scalerG1_Y                      /* Y */
} scalerG1;
#define scalerG1_NUM_CHOICES 2

typedef enum {
    scalerCNT_Done                  /* Done */,
    scalerCNT_Count                 /* Count */
} scalerCNT;
#define scalerCNT_NUM_CHOICES 2

typedef struct scalerRecord {
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
    epicsFloat32        vers;       /* Code Version */
    void *rpvt;                     /* Record Private */
    epicsFloat64        val;        /* Result */
    epicsFloat64        freq;       /* Time base freq */
    epicsEnum16         cnt;        /* Count */
    epicsEnum16         pcnt;       /* Prev Count */
    epicsInt16          ss;         /* Scaler state */
    epicsInt16          us;         /* User state */
    epicsEnum16         cont;       /* OneShot/AutoCount */
    DBLINK              out;        /* Output Specification */
    epicsFloat32        rate;       /* Display Rate (Hz.) */
    epicsFloat32        rat1;       /* Auto Display Rate (Hz.) */
    epicsFloat32        dly;        /* Delay */
    epicsFloat32        dly1;       /* Auto-mode Delay */
    epicsInt16          nch;        /* Number of Channels */
    epicsEnum16         d1;         /* Count Direction 1 */
    epicsEnum16         d2;         /* Count Direction 2 */
    epicsEnum16         d3;         /* Count Direction 3 */
    epicsEnum16         d4;         /* Count Direction 4 */
    epicsEnum16         d5;         /* Count Direction 5 */
    epicsEnum16         d6;         /* Count Direction 6 */
    epicsEnum16         d7;         /* Count Direction 7 */
    epicsEnum16         d8;         /* Count Direction 8 */
    epicsEnum16         d9;         /* Count Direction 9 */
    epicsEnum16         d10;        /* Count Direction 10 */
    epicsEnum16         d11;        /* Count Direction 11 */
    epicsEnum16         d12;        /* Count Direction 12 */
    epicsEnum16         d13;        /* Count Direction 13 */
    epicsEnum16         d14;        /* Count Direction 14 */
    epicsEnum16         d15;        /* Count Direction 15 */
    epicsEnum16         d16;        /* Count Direction 16 */
    epicsEnum16         d17;        /* Count Direction 17 */
    epicsEnum16         d18;        /* Count Direction 18 */
    epicsEnum16         d19;        /* Count Direction 19 */
    epicsEnum16         d20;        /* Count Direction 20 */
    epicsEnum16         d21;        /* Count Direction 21 */
    epicsEnum16         d22;        /* Count Direction 22 */
    epicsEnum16         d23;        /* Count Direction 23 */
    epicsEnum16         d24;        /* Count Direction 24 */
    epicsEnum16         d25;        /* Count Direction 25 */
    epicsEnum16         d26;        /* Count Direction 26 */
    epicsEnum16         d27;        /* Count Direction 27 */
    epicsEnum16         d28;        /* Count Direction 28 */
    epicsEnum16         d29;        /* Count Direction 29 */
    epicsEnum16         d30;        /* Count Direction 30 */
    epicsEnum16         d31;        /* Count Direction 31 */
    epicsEnum16         d32;        /* Count Direction 32 */
    epicsEnum16         d33;        /* Count Direction 33 */
    epicsEnum16         d34;        /* Count Direction 34 */
    epicsEnum16         d35;        /* Count Direction 35 */
    epicsEnum16         d36;        /* Count Direction 36 */
    epicsEnum16         d37;        /* Count Direction 37 */
    epicsEnum16         d38;        /* Count Direction 38 */
    epicsEnum16         d39;        /* Count Direction 39 */
    epicsEnum16         d40;        /* Count Direction 40 */
    epicsEnum16         d41;        /* Count Direction 41 */
    epicsEnum16         d42;        /* Count Direction 42 */
    epicsEnum16         d43;        /* Count Direction 43 */
    epicsEnum16         d44;        /* Count Direction 44 */
    epicsEnum16         d45;        /* Count Direction 45 */
    epicsEnum16         d46;        /* Count Direction 46 */
    epicsEnum16         d47;        /* Count Direction 47 */
    epicsEnum16         d48;        /* Count Direction 48 */
    epicsEnum16         d49;        /* Count Direction 49 */
    epicsEnum16         d50;        /* Count Direction 50 */
    epicsEnum16         d51;        /* Count Direction 51 */
    epicsEnum16         d52;        /* Count Direction 52 */
    epicsEnum16         d53;        /* Count Direction 53 */
    epicsEnum16         d54;        /* Count Direction 54 */
    epicsEnum16         d55;        /* Count Direction 55 */
    epicsEnum16         d56;        /* Count Direction 56 */
    epicsEnum16         d57;        /* Count Direction 57 */
    epicsEnum16         d58;        /* Count Direction 58 */
    epicsEnum16         d59;        /* Count Direction 59 */
    epicsEnum16         d60;        /* Count Direction 60 */
    epicsEnum16         d61;        /* Count Direction 61 */
    epicsEnum16         d62;        /* Count Direction 62 */
    epicsEnum16         d63;        /* Count Direction 63 */
    epicsEnum16         d64;        /* Count Direction 64 */
    epicsEnum16         g1;         /* Gate Control 1 */
    epicsEnum16         g2;         /* Gate Control 2 */
    epicsEnum16         g3;         /* Gate Control 3 */
    epicsEnum16         g4;         /* Gate Control 4 */
    epicsEnum16         g5;         /* Gate Control 5 */
    epicsEnum16         g6;         /* Gate Control 6 */
    epicsEnum16         g7;         /* Gate Control 7 */
    epicsEnum16         g8;         /* Gate Control 8 */
    epicsEnum16         g9;         /* Gate Control 9 */
    epicsEnum16         g10;        /* Gate Control 10 */
    epicsEnum16         g11;        /* Gate Control 11 */
    epicsEnum16         g12;        /* Gate Control 12 */
    epicsEnum16         g13;        /* Gate Control 13 */
    epicsEnum16         g14;        /* Gate Control 14 */
    epicsEnum16         g15;        /* Gate Control 15 */
    epicsEnum16         g16;        /* Gate Control 16 */
    epicsEnum16         g17;        /* Gate Control 17 */
    epicsEnum16         g18;        /* Gate Control 18 */
    epicsEnum16         g19;        /* Gate Control 19 */
    epicsEnum16         g20;        /* Gate Control 20 */
    epicsEnum16         g21;        /* Gate Control 21 */
    epicsEnum16         g22;        /* Gate Control 22 */
    epicsEnum16         g23;        /* Gate Control 23 */
    epicsEnum16         g24;        /* Gate Control 24 */
    epicsEnum16         g25;        /* Gate Control 25 */
    epicsEnum16         g26;        /* Gate Control 26 */
    epicsEnum16         g27;        /* Gate Control 27 */
    epicsEnum16         g28;        /* Gate Control 28 */
    epicsEnum16         g29;        /* Gate Control 29 */
    epicsEnum16         g30;        /* Gate Control 30 */
    epicsEnum16         g31;        /* Gate Control 31 */
    epicsEnum16         g32;        /* Gate Control 32 */
    epicsEnum16         g33;        /* Gate Control */
    epicsEnum16         g34;        /* Gate Control */
    epicsEnum16         g35;        /* Gate Control */
    epicsEnum16         g36;        /* Gate Control */
    epicsEnum16         g37;        /* Gate Control */
    epicsEnum16         g38;        /* Gate Control */
    epicsEnum16         g39;        /* Gate Control */
    epicsEnum16         g40;        /* Gate Control */
    epicsEnum16         g41;        /* Gate Control */
    epicsEnum16         g42;        /* Gate Control */
    epicsEnum16         g43;        /* Gate Control */
    epicsEnum16         g44;        /* Gate Control */
    epicsEnum16         g45;        /* Gate Control */
    epicsEnum16         g46;        /* Gate Control */
    epicsEnum16         g47;        /* Gate Control */
    epicsEnum16         g48;        /* Gate Control */
    epicsEnum16         g49;        /* Gate Control */
    epicsEnum16         g50;        /* Gate Control */
    epicsEnum16         g51;        /* Gate Control */
    epicsEnum16         g52;        /* Gate Control */
    epicsEnum16         g53;        /* Gate Control */
    epicsEnum16         g54;        /* Gate Control */
    epicsEnum16         g55;        /* Gate Control */
    epicsEnum16         g56;        /* Gate Control */
    epicsEnum16         g57;        /* Gate Control */
    epicsEnum16         g58;        /* Gate Control */
    epicsEnum16         g59;        /* Gate Control */
    epicsEnum16         g60;        /* Gate Control */
    epicsEnum16         g61;        /* Gate Control */
    epicsEnum16         g62;        /* Gate Control */
    epicsEnum16         g63;        /* Gate Control */
    epicsEnum16         g64;        /* Gate Control */
    epicsFloat64        tp;         /* Time Preset */
    epicsFloat64        tp1;        /* Time Preset */
    epicsUInt32         pr1;        /* Preset 1 */
    epicsUInt32         pr2;        /* Preset 2 */
    epicsUInt32         pr3;        /* Preset 3 */
    epicsUInt32         pr4;        /* Preset 4 */
    epicsUInt32         pr5;        /* Preset 5 */
    epicsUInt32         pr6;        /* Preset 6 */
    epicsUInt32         pr7;        /* Preset 7 */
    epicsUInt32         pr8;        /* Preset 8 */
    epicsUInt32         pr9;        /* Preset 9 */
    epicsUInt32         pr10;       /* Preset 10 */
    epicsUInt32         pr11;       /* Preset 11 */
    epicsUInt32         pr12;       /* Preset 12 */
    epicsUInt32         pr13;       /* Preset 13 */
    epicsUInt32         pr14;       /* Preset 14 */
    epicsUInt32         pr15;       /* Preset 15 */
    epicsUInt32         pr16;       /* Preset 16 */
    epicsUInt32         pr17;       /* Preset 17 */
    epicsUInt32         pr18;       /* Preset 18 */
    epicsUInt32         pr19;       /* Preset 19 */
    epicsUInt32         pr20;       /* Preset 20 */
    epicsUInt32         pr21;       /* Preset 21 */
    epicsUInt32         pr22;       /* Preset 22 */
    epicsUInt32         pr23;       /* Preset 23 */
    epicsUInt32         pr24;       /* Preset 24 */
    epicsUInt32         pr25;       /* Preset 25 */
    epicsUInt32         pr26;       /* Preset 26 */
    epicsUInt32         pr27;       /* Preset 27 */
    epicsUInt32         pr28;       /* Preset 28 */
    epicsUInt32         pr29;       /* Preset 29 */
    epicsUInt32         pr30;       /* Preset 30 */
    epicsUInt32         pr31;       /* Preset 31 */
    epicsUInt32         pr32;       /* Preset 32 */
    epicsUInt32         pr33;       /* Preset */
    epicsUInt32         pr34;       /* Preset */
    epicsUInt32         pr35;       /* Preset */
    epicsUInt32         pr36;       /* Preset */
    epicsUInt32         pr37;       /* Preset */
    epicsUInt32         pr38;       /* Preset */
    epicsUInt32         pr39;       /* Preset */
    epicsUInt32         pr40;       /* Preset */
    epicsUInt32         pr41;       /* Preset */
    epicsUInt32         pr42;       /* Preset */
    epicsUInt32         pr43;       /* Preset */
    epicsUInt32         pr44;       /* Preset */
    epicsUInt32         pr45;       /* Preset */
    epicsUInt32         pr46;       /* Preset */
    epicsUInt32         pr47;       /* Preset */
    epicsUInt32         pr48;       /* Preset */
    epicsUInt32         pr49;       /* Preset */
    epicsUInt32         pr50;       /* Preset */
    epicsUInt32         pr51;       /* Preset */
    epicsUInt32         pr52;       /* Preset */
    epicsUInt32         pr53;       /* Preset */
    epicsUInt32         pr54;       /* Preset */
    epicsUInt32         pr55;       /* Preset */
    epicsUInt32         pr56;       /* Preset */
    epicsUInt32         pr57;       /* Preset */
    epicsUInt32         pr58;       /* Preset */
    epicsUInt32         pr59;       /* Preset */
    epicsUInt32         pr60;       /* Preset */
    epicsUInt32         pr61;       /* Preset */
    epicsUInt32         pr62;       /* Preset */
    epicsUInt32         pr63;       /* Preset */
    epicsUInt32         pr64;       /* Preset */
    epicsFloat64        t;          /* Timer */
    epicsUInt32         s1;         /* Count */
    epicsUInt32         s2;         /* Count */
    epicsUInt32         s3;         /* Count */
    epicsUInt32         s4;         /* Count */
    epicsUInt32         s5;         /* Count */
    epicsUInt32         s6;         /* Count */
    epicsUInt32         s7;         /* Count */
    epicsUInt32         s8;         /* Count */
    epicsUInt32         s9;         /* Count */
    epicsUInt32         s10;        /* Count */
    epicsUInt32         s11;        /* Count */
    epicsUInt32         s12;        /* Count */
    epicsUInt32         s13;        /* Count */
    epicsUInt32         s14;        /* Count */
    epicsUInt32         s15;        /* Count */
    epicsUInt32         s16;        /* Count */
    epicsUInt32         s17;        /* Count */
    epicsUInt32         s18;        /* Count */
    epicsUInt32         s19;        /* Count */
    epicsUInt32         s20;        /* Count */
    epicsUInt32         s21;        /* Count */
    epicsUInt32         s22;        /* Count */
    epicsUInt32         s23;        /* Count */
    epicsUInt32         s24;        /* Count */
    epicsUInt32         s25;        /* Count */
    epicsUInt32         s26;        /* Count */
    epicsUInt32         s27;        /* Count */
    epicsUInt32         s28;        /* Count */
    epicsUInt32         s29;        /* Count */
    epicsUInt32         s30;        /* Count */
    epicsUInt32         s31;        /* Count */
    epicsUInt32         s32;        /* Count */
    epicsUInt32         s33;        /* Count */
    epicsUInt32         s34;        /* Count */
    epicsUInt32         s35;        /* Count */
    epicsUInt32         s36;        /* Count */
    epicsUInt32         s37;        /* Count */
    epicsUInt32         s38;        /* Count */
    epicsUInt32         s39;        /* Count */
    epicsUInt32         s40;        /* Count */
    epicsUInt32         s41;        /* Count */
    epicsUInt32         s42;        /* Count */
    epicsUInt32         s43;        /* Count */
    epicsUInt32         s44;        /* Count */
    epicsUInt32         s45;        /* Count */
    epicsUInt32         s46;        /* Count */
    epicsUInt32         s47;        /* Count */
    epicsUInt32         s48;        /* Count */
    epicsUInt32         s49;        /* Count */
    epicsUInt32         s50;        /* Count */
    epicsUInt32         s51;        /* Count */
    epicsUInt32         s52;        /* Count */
    epicsUInt32         s53;        /* Count */
    epicsUInt32         s54;        /* Count */
    epicsUInt32         s55;        /* Count */
    epicsUInt32         s56;        /* Count */
    epicsUInt32         s57;        /* Count */
    epicsUInt32         s58;        /* Count */
    epicsUInt32         s59;        /* Count */
    epicsUInt32         s60;        /* Count */
    epicsUInt32         s61;        /* Count */
    epicsUInt32         s62;        /* Count */
    epicsUInt32         s63;        /* Count */
    epicsUInt32         s64;        /* Count */
    char                nm1[16];    /* Scaler 1 name */
    char                nm2[16];    /* Scaler 2 name */
    char                nm3[16];    /* Scaler 3 name */
    char                nm4[16];    /* Scaler 4 name */
    char                nm5[16];    /* Scaler 5 name */
    char                nm6[16];    /* Scaler 6 name */
    char                nm7[16];    /* Scaler 7 name */
    char                nm8[16];    /* Scaler 8 name */
    char                nm9[16];    /* Scaler 9 name */
    char                nm10[16];   /* Scaler 10 name */
    char                nm11[16];   /* Scaler 11 name */
    char                nm12[16];   /* Scaler 12 name */
    char                nm13[16];   /* Scaler 13 name */
    char                nm14[16];   /* Scaler 14 name */
    char                nm15[16];   /* Scaler 15 name */
    char                nm16[16];   /* Scaler 16 name */
    char                nm17[16];   /* Scaler 17 name */
    char                nm18[16];   /* Scaler 18 name */
    char                nm19[16];   /* Scaler 19 name */
    char                nm20[16];   /* Scaler 20 name */
    char                nm21[16];   /* Scaler 21 name */
    char                nm22[16];   /* Scaler 22 name */
    char                nm23[16];   /* Scaler 23 name */
    char                nm24[16];   /* Scaler 24 name */
    char                nm25[16];   /* Scaler 25 name */
    char                nm26[16];   /* Scaler 26 name */
    char                nm27[16];   /* Scaler 27 name */
    char                nm28[16];   /* Scaler 28 name */
    char                nm29[16];   /* Scaler 29 name */
    char                nm30[16];   /* Scaler 30 name */
    char                nm31[16];   /* Scaler 31 name */
    char                nm32[16];   /* Scaler 32 name */
    char                nm33[16];   /* Scaler name */
    char                nm34[16];   /* Scaler name */
    char                nm35[16];   /* Scaler name */
    char                nm36[16];   /* Scaler name */
    char                nm37[16];   /* Scaler name */
    char                nm38[16];   /* Scaler name */
    char                nm39[16];   /* Scaler name */
    char                nm40[16];   /* Scaler name */
    char                nm41[16];   /* Scaler name */
    char                nm42[16];   /* Scaler name */
    char                nm43[16];   /* Scaler name */
    char                nm44[16];   /* Scaler name */
    char                nm45[16];   /* Scaler name */
    char                nm46[16];   /* Scaler name */
    char                nm47[16];   /* Scaler name */
    char                nm48[16];   /* Scaler name */
    char                nm49[16];   /* Scaler name */
    char                nm50[16];   /* Scaler name */
    char                nm51[16];   /* Scaler name */
    char                nm52[16];   /* Scaler name */
    char                nm53[16];   /* Scaler name */
    char                nm54[16];   /* Scaler name */
    char                nm55[16];   /* Scaler name */
    char                nm56[16];   /* Scaler name */
    char                nm57[16];   /* Scaler name */
    char                nm58[16];   /* Scaler name */
    char                nm59[16];   /* Scaler name */
    char                nm60[16];   /* Scaler name */
    char                nm61[16];   /* Scaler name */
    char                nm62[16];   /* Scaler name */
    char                nm63[16];   /* Scaler name */
    char                nm64[16];   /* Scaler name */
    char                egu[16];    /* Units Name */
    epicsInt16          prec;       /* Display Precision */
    DBLINK              cout;       /* CNT Output */
    DBLINK              coutp;      /* CNT Output Prompt */
} scalerRecord;

typedef enum {
	scalerRecordNAME = 0,
	scalerRecordDESC = 1,
	scalerRecordASG = 2,
	scalerRecordSCAN = 3,
	scalerRecordPINI = 4,
	scalerRecordPHAS = 5,
	scalerRecordEVNT = 6,
	scalerRecordTSE = 7,
	scalerRecordTSEL = 8,
	scalerRecordDTYP = 9,
	scalerRecordDISV = 10,
	scalerRecordDISA = 11,
	scalerRecordSDIS = 12,
	scalerRecordMLOK = 13,
	scalerRecordMLIS = 14,
	scalerRecordDISP = 15,
	scalerRecordPROC = 16,
	scalerRecordSTAT = 17,
	scalerRecordSEVR = 18,
	scalerRecordNSTA = 19,
	scalerRecordNSEV = 20,
	scalerRecordACKS = 21,
	scalerRecordACKT = 22,
	scalerRecordDISS = 23,
	scalerRecordLCNT = 24,
	scalerRecordPACT = 25,
	scalerRecordPUTF = 26,
	scalerRecordRPRO = 27,
	scalerRecordASP = 28,
	scalerRecordPPN = 29,
	scalerRecordPPNR = 30,
	scalerRecordSPVT = 31,
	scalerRecordRSET = 32,
	scalerRecordDSET = 33,
	scalerRecordDPVT = 34,
	scalerRecordRDES = 35,
	scalerRecordLSET = 36,
	scalerRecordPRIO = 37,
	scalerRecordTPRO = 38,
	scalerRecordBKPT = 39,
	scalerRecordUDF = 40,
	scalerRecordUDFS = 41,
	scalerRecordTIME = 42,
	scalerRecordFLNK = 43,
	scalerRecordVERS = 44,
	scalerRecordRPVT = 45,
	scalerRecordVAL = 46,
	scalerRecordFREQ = 47,
	scalerRecordCNT = 48,
	scalerRecordPCNT = 49,
	scalerRecordSS = 50,
	scalerRecordUS = 51,
	scalerRecordCONT = 52,
	scalerRecordOUT = 53,
	scalerRecordRATE = 54,
	scalerRecordRAT1 = 55,
	scalerRecordDLY = 56,
	scalerRecordDLY1 = 57,
	scalerRecordNCH = 58,
	scalerRecordD1 = 59,
	scalerRecordD2 = 60,
	scalerRecordD3 = 61,
	scalerRecordD4 = 62,
	scalerRecordD5 = 63,
	scalerRecordD6 = 64,
	scalerRecordD7 = 65,
	scalerRecordD8 = 66,
	scalerRecordD9 = 67,
	scalerRecordD10 = 68,
	scalerRecordD11 = 69,
	scalerRecordD12 = 70,
	scalerRecordD13 = 71,
	scalerRecordD14 = 72,
	scalerRecordD15 = 73,
	scalerRecordD16 = 74,
	scalerRecordD17 = 75,
	scalerRecordD18 = 76,
	scalerRecordD19 = 77,
	scalerRecordD20 = 78,
	scalerRecordD21 = 79,
	scalerRecordD22 = 80,
	scalerRecordD23 = 81,
	scalerRecordD24 = 82,
	scalerRecordD25 = 83,
	scalerRecordD26 = 84,
	scalerRecordD27 = 85,
	scalerRecordD28 = 86,
	scalerRecordD29 = 87,
	scalerRecordD30 = 88,
	scalerRecordD31 = 89,
	scalerRecordD32 = 90,
	scalerRecordD33 = 91,
	scalerRecordD34 = 92,
	scalerRecordD35 = 93,
	scalerRecordD36 = 94,
	scalerRecordD37 = 95,
	scalerRecordD38 = 96,
	scalerRecordD39 = 97,
	scalerRecordD40 = 98,
	scalerRecordD41 = 99,
	scalerRecordD42 = 100,
	scalerRecordD43 = 101,
	scalerRecordD44 = 102,
	scalerRecordD45 = 103,
	scalerRecordD46 = 104,
	scalerRecordD47 = 105,
	scalerRecordD48 = 106,
	scalerRecordD49 = 107,
	scalerRecordD50 = 108,
	scalerRecordD51 = 109,
	scalerRecordD52 = 110,
	scalerRecordD53 = 111,
	scalerRecordD54 = 112,
	scalerRecordD55 = 113,
	scalerRecordD56 = 114,
	scalerRecordD57 = 115,
	scalerRecordD58 = 116,
	scalerRecordD59 = 117,
	scalerRecordD60 = 118,
	scalerRecordD61 = 119,
	scalerRecordD62 = 120,
	scalerRecordD63 = 121,
	scalerRecordD64 = 122,
	scalerRecordG1 = 123,
	scalerRecordG2 = 124,
	scalerRecordG3 = 125,
	scalerRecordG4 = 126,
	scalerRecordG5 = 127,
	scalerRecordG6 = 128,
	scalerRecordG7 = 129,
	scalerRecordG8 = 130,
	scalerRecordG9 = 131,
	scalerRecordG10 = 132,
	scalerRecordG11 = 133,
	scalerRecordG12 = 134,
	scalerRecordG13 = 135,
	scalerRecordG14 = 136,
	scalerRecordG15 = 137,
	scalerRecordG16 = 138,
	scalerRecordG17 = 139,
	scalerRecordG18 = 140,
	scalerRecordG19 = 141,
	scalerRecordG20 = 142,
	scalerRecordG21 = 143,
	scalerRecordG22 = 144,
	scalerRecordG23 = 145,
	scalerRecordG24 = 146,
	scalerRecordG25 = 147,
	scalerRecordG26 = 148,
	scalerRecordG27 = 149,
	scalerRecordG28 = 150,
	scalerRecordG29 = 151,
	scalerRecordG30 = 152,
	scalerRecordG31 = 153,
	scalerRecordG32 = 154,
	scalerRecordG33 = 155,
	scalerRecordG34 = 156,
	scalerRecordG35 = 157,
	scalerRecordG36 = 158,
	scalerRecordG37 = 159,
	scalerRecordG38 = 160,
	scalerRecordG39 = 161,
	scalerRecordG40 = 162,
	scalerRecordG41 = 163,
	scalerRecordG42 = 164,
	scalerRecordG43 = 165,
	scalerRecordG44 = 166,
	scalerRecordG45 = 167,
	scalerRecordG46 = 168,
	scalerRecordG47 = 169,
	scalerRecordG48 = 170,
	scalerRecordG49 = 171,
	scalerRecordG50 = 172,
	scalerRecordG51 = 173,
	scalerRecordG52 = 174,
	scalerRecordG53 = 175,
	scalerRecordG54 = 176,
	scalerRecordG55 = 177,
	scalerRecordG56 = 178,
	scalerRecordG57 = 179,
	scalerRecordG58 = 180,
	scalerRecordG59 = 181,
	scalerRecordG60 = 182,
	scalerRecordG61 = 183,
	scalerRecordG62 = 184,
	scalerRecordG63 = 185,
	scalerRecordG64 = 186,
	scalerRecordTP = 187,
	scalerRecordTP1 = 188,
	scalerRecordPR1 = 189,
	scalerRecordPR2 = 190,
	scalerRecordPR3 = 191,
	scalerRecordPR4 = 192,
	scalerRecordPR5 = 193,
	scalerRecordPR6 = 194,
	scalerRecordPR7 = 195,
	scalerRecordPR8 = 196,
	scalerRecordPR9 = 197,
	scalerRecordPR10 = 198,
	scalerRecordPR11 = 199,
	scalerRecordPR12 = 200,
	scalerRecordPR13 = 201,
	scalerRecordPR14 = 202,
	scalerRecordPR15 = 203,
	scalerRecordPR16 = 204,
	scalerRecordPR17 = 205,
	scalerRecordPR18 = 206,
	scalerRecordPR19 = 207,
	scalerRecordPR20 = 208,
	scalerRecordPR21 = 209,
	scalerRecordPR22 = 210,
	scalerRecordPR23 = 211,
	scalerRecordPR24 = 212,
	scalerRecordPR25 = 213,
	scalerRecordPR26 = 214,
	scalerRecordPR27 = 215,
	scalerRecordPR28 = 216,
	scalerRecordPR29 = 217,
	scalerRecordPR30 = 218,
	scalerRecordPR31 = 219,
	scalerRecordPR32 = 220,
	scalerRecordPR33 = 221,
	scalerRecordPR34 = 222,
	scalerRecordPR35 = 223,
	scalerRecordPR36 = 224,
	scalerRecordPR37 = 225,
	scalerRecordPR38 = 226,
	scalerRecordPR39 = 227,
	scalerRecordPR40 = 228,
	scalerRecordPR41 = 229,
	scalerRecordPR42 = 230,
	scalerRecordPR43 = 231,
	scalerRecordPR44 = 232,
	scalerRecordPR45 = 233,
	scalerRecordPR46 = 234,
	scalerRecordPR47 = 235,
	scalerRecordPR48 = 236,
	scalerRecordPR49 = 237,
	scalerRecordPR50 = 238,
	scalerRecordPR51 = 239,
	scalerRecordPR52 = 240,
	scalerRecordPR53 = 241,
	scalerRecordPR54 = 242,
	scalerRecordPR55 = 243,
	scalerRecordPR56 = 244,
	scalerRecordPR57 = 245,
	scalerRecordPR58 = 246,
	scalerRecordPR59 = 247,
	scalerRecordPR60 = 248,
	scalerRecordPR61 = 249,
	scalerRecordPR62 = 250,
	scalerRecordPR63 = 251,
	scalerRecordPR64 = 252,
	scalerRecordT = 253,
	scalerRecordS1 = 254,
	scalerRecordS2 = 255,
	scalerRecordS3 = 256,
	scalerRecordS4 = 257,
	scalerRecordS5 = 258,
	scalerRecordS6 = 259,
	scalerRecordS7 = 260,
	scalerRecordS8 = 261,
	scalerRecordS9 = 262,
	scalerRecordS10 = 263,
	scalerRecordS11 = 264,
	scalerRecordS12 = 265,
	scalerRecordS13 = 266,
	scalerRecordS14 = 267,
	scalerRecordS15 = 268,
	scalerRecordS16 = 269,
	scalerRecordS17 = 270,
	scalerRecordS18 = 271,
	scalerRecordS19 = 272,
	scalerRecordS20 = 273,
	scalerRecordS21 = 274,
	scalerRecordS22 = 275,
	scalerRecordS23 = 276,
	scalerRecordS24 = 277,
	scalerRecordS25 = 278,
	scalerRecordS26 = 279,
	scalerRecordS27 = 280,
	scalerRecordS28 = 281,
	scalerRecordS29 = 282,
	scalerRecordS30 = 283,
	scalerRecordS31 = 284,
	scalerRecordS32 = 285,
	scalerRecordS33 = 286,
	scalerRecordS34 = 287,
	scalerRecordS35 = 288,
	scalerRecordS36 = 289,
	scalerRecordS37 = 290,
	scalerRecordS38 = 291,
	scalerRecordS39 = 292,
	scalerRecordS40 = 293,
	scalerRecordS41 = 294,
	scalerRecordS42 = 295,
	scalerRecordS43 = 296,
	scalerRecordS44 = 297,
	scalerRecordS45 = 298,
	scalerRecordS46 = 299,
	scalerRecordS47 = 300,
	scalerRecordS48 = 301,
	scalerRecordS49 = 302,
	scalerRecordS50 = 303,
	scalerRecordS51 = 304,
	scalerRecordS52 = 305,
	scalerRecordS53 = 306,
	scalerRecordS54 = 307,
	scalerRecordS55 = 308,
	scalerRecordS56 = 309,
	scalerRecordS57 = 310,
	scalerRecordS58 = 311,
	scalerRecordS59 = 312,
	scalerRecordS60 = 313,
	scalerRecordS61 = 314,
	scalerRecordS62 = 315,
	scalerRecordS63 = 316,
	scalerRecordS64 = 317,
	scalerRecordNM1 = 318,
	scalerRecordNM2 = 319,
	scalerRecordNM3 = 320,
	scalerRecordNM4 = 321,
	scalerRecordNM5 = 322,
	scalerRecordNM6 = 323,
	scalerRecordNM7 = 324,
	scalerRecordNM8 = 325,
	scalerRecordNM9 = 326,
	scalerRecordNM10 = 327,
	scalerRecordNM11 = 328,
	scalerRecordNM12 = 329,
	scalerRecordNM13 = 330,
	scalerRecordNM14 = 331,
	scalerRecordNM15 = 332,
	scalerRecordNM16 = 333,
	scalerRecordNM17 = 334,
	scalerRecordNM18 = 335,
	scalerRecordNM19 = 336,
	scalerRecordNM20 = 337,
	scalerRecordNM21 = 338,
	scalerRecordNM22 = 339,
	scalerRecordNM23 = 340,
	scalerRecordNM24 = 341,
	scalerRecordNM25 = 342,
	scalerRecordNM26 = 343,
	scalerRecordNM27 = 344,
	scalerRecordNM28 = 345,
	scalerRecordNM29 = 346,
	scalerRecordNM30 = 347,
	scalerRecordNM31 = 348,
	scalerRecordNM32 = 349,
	scalerRecordNM33 = 350,
	scalerRecordNM34 = 351,
	scalerRecordNM35 = 352,
	scalerRecordNM36 = 353,
	scalerRecordNM37 = 354,
	scalerRecordNM38 = 355,
	scalerRecordNM39 = 356,
	scalerRecordNM40 = 357,
	scalerRecordNM41 = 358,
	scalerRecordNM42 = 359,
	scalerRecordNM43 = 360,
	scalerRecordNM44 = 361,
	scalerRecordNM45 = 362,
	scalerRecordNM46 = 363,
	scalerRecordNM47 = 364,
	scalerRecordNM48 = 365,
	scalerRecordNM49 = 366,
	scalerRecordNM50 = 367,
	scalerRecordNM51 = 368,
	scalerRecordNM52 = 369,
	scalerRecordNM53 = 370,
	scalerRecordNM54 = 371,
	scalerRecordNM55 = 372,
	scalerRecordNM56 = 373,
	scalerRecordNM57 = 374,
	scalerRecordNM58 = 375,
	scalerRecordNM59 = 376,
	scalerRecordNM60 = 377,
	scalerRecordNM61 = 378,
	scalerRecordNM62 = 379,
	scalerRecordNM63 = 380,
	scalerRecordNM64 = 381,
	scalerRecordEGU = 382,
	scalerRecordPREC = 383,
	scalerRecordCOUT = 384,
	scalerRecordCOUTP = 385
} scalerFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int scalerRecordSizeOffset(dbRecordType *prt)
{
    scalerRecord *prec = 0;

    assert(prt->no_fields == 386);
    prt->papFldDes[scalerRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[scalerRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[scalerRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[scalerRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[scalerRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[scalerRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[scalerRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[scalerRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[scalerRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[scalerRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[scalerRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[scalerRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[scalerRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[scalerRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[scalerRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[scalerRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[scalerRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[scalerRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[scalerRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[scalerRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[scalerRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[scalerRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[scalerRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[scalerRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[scalerRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[scalerRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[scalerRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[scalerRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[scalerRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[scalerRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[scalerRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[scalerRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[scalerRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[scalerRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[scalerRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[scalerRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[scalerRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[scalerRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[scalerRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[scalerRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[scalerRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[scalerRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[scalerRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[scalerRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[scalerRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[scalerRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[scalerRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[scalerRecordFREQ]->size = sizeof(prec->freq);
    prt->papFldDes[scalerRecordCNT]->size = sizeof(prec->cnt);
    prt->papFldDes[scalerRecordPCNT]->size = sizeof(prec->pcnt);
    prt->papFldDes[scalerRecordSS]->size = sizeof(prec->ss);
    prt->papFldDes[scalerRecordUS]->size = sizeof(prec->us);
    prt->papFldDes[scalerRecordCONT]->size = sizeof(prec->cont);
    prt->papFldDes[scalerRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[scalerRecordRATE]->size = sizeof(prec->rate);
    prt->papFldDes[scalerRecordRAT1]->size = sizeof(prec->rat1);
    prt->papFldDes[scalerRecordDLY]->size = sizeof(prec->dly);
    prt->papFldDes[scalerRecordDLY1]->size = sizeof(prec->dly1);
    prt->papFldDes[scalerRecordNCH]->size = sizeof(prec->nch);
    prt->papFldDes[scalerRecordD1]->size = sizeof(prec->d1);
    prt->papFldDes[scalerRecordD2]->size = sizeof(prec->d2);
    prt->papFldDes[scalerRecordD3]->size = sizeof(prec->d3);
    prt->papFldDes[scalerRecordD4]->size = sizeof(prec->d4);
    prt->papFldDes[scalerRecordD5]->size = sizeof(prec->d5);
    prt->papFldDes[scalerRecordD6]->size = sizeof(prec->d6);
    prt->papFldDes[scalerRecordD7]->size = sizeof(prec->d7);
    prt->papFldDes[scalerRecordD8]->size = sizeof(prec->d8);
    prt->papFldDes[scalerRecordD9]->size = sizeof(prec->d9);
    prt->papFldDes[scalerRecordD10]->size = sizeof(prec->d10);
    prt->papFldDes[scalerRecordD11]->size = sizeof(prec->d11);
    prt->papFldDes[scalerRecordD12]->size = sizeof(prec->d12);
    prt->papFldDes[scalerRecordD13]->size = sizeof(prec->d13);
    prt->papFldDes[scalerRecordD14]->size = sizeof(prec->d14);
    prt->papFldDes[scalerRecordD15]->size = sizeof(prec->d15);
    prt->papFldDes[scalerRecordD16]->size = sizeof(prec->d16);
    prt->papFldDes[scalerRecordD17]->size = sizeof(prec->d17);
    prt->papFldDes[scalerRecordD18]->size = sizeof(prec->d18);
    prt->papFldDes[scalerRecordD19]->size = sizeof(prec->d19);
    prt->papFldDes[scalerRecordD20]->size = sizeof(prec->d20);
    prt->papFldDes[scalerRecordD21]->size = sizeof(prec->d21);
    prt->papFldDes[scalerRecordD22]->size = sizeof(prec->d22);
    prt->papFldDes[scalerRecordD23]->size = sizeof(prec->d23);
    prt->papFldDes[scalerRecordD24]->size = sizeof(prec->d24);
    prt->papFldDes[scalerRecordD25]->size = sizeof(prec->d25);
    prt->papFldDes[scalerRecordD26]->size = sizeof(prec->d26);
    prt->papFldDes[scalerRecordD27]->size = sizeof(prec->d27);
    prt->papFldDes[scalerRecordD28]->size = sizeof(prec->d28);
    prt->papFldDes[scalerRecordD29]->size = sizeof(prec->d29);
    prt->papFldDes[scalerRecordD30]->size = sizeof(prec->d30);
    prt->papFldDes[scalerRecordD31]->size = sizeof(prec->d31);
    prt->papFldDes[scalerRecordD32]->size = sizeof(prec->d32);
    prt->papFldDes[scalerRecordD33]->size = sizeof(prec->d33);
    prt->papFldDes[scalerRecordD34]->size = sizeof(prec->d34);
    prt->papFldDes[scalerRecordD35]->size = sizeof(prec->d35);
    prt->papFldDes[scalerRecordD36]->size = sizeof(prec->d36);
    prt->papFldDes[scalerRecordD37]->size = sizeof(prec->d37);
    prt->papFldDes[scalerRecordD38]->size = sizeof(prec->d38);
    prt->papFldDes[scalerRecordD39]->size = sizeof(prec->d39);
    prt->papFldDes[scalerRecordD40]->size = sizeof(prec->d40);
    prt->papFldDes[scalerRecordD41]->size = sizeof(prec->d41);
    prt->papFldDes[scalerRecordD42]->size = sizeof(prec->d42);
    prt->papFldDes[scalerRecordD43]->size = sizeof(prec->d43);
    prt->papFldDes[scalerRecordD44]->size = sizeof(prec->d44);
    prt->papFldDes[scalerRecordD45]->size = sizeof(prec->d45);
    prt->papFldDes[scalerRecordD46]->size = sizeof(prec->d46);
    prt->papFldDes[scalerRecordD47]->size = sizeof(prec->d47);
    prt->papFldDes[scalerRecordD48]->size = sizeof(prec->d48);
    prt->papFldDes[scalerRecordD49]->size = sizeof(prec->d49);
    prt->papFldDes[scalerRecordD50]->size = sizeof(prec->d50);
    prt->papFldDes[scalerRecordD51]->size = sizeof(prec->d51);
    prt->papFldDes[scalerRecordD52]->size = sizeof(prec->d52);
    prt->papFldDes[scalerRecordD53]->size = sizeof(prec->d53);
    prt->papFldDes[scalerRecordD54]->size = sizeof(prec->d54);
    prt->papFldDes[scalerRecordD55]->size = sizeof(prec->d55);
    prt->papFldDes[scalerRecordD56]->size = sizeof(prec->d56);
    prt->papFldDes[scalerRecordD57]->size = sizeof(prec->d57);
    prt->papFldDes[scalerRecordD58]->size = sizeof(prec->d58);
    prt->papFldDes[scalerRecordD59]->size = sizeof(prec->d59);
    prt->papFldDes[scalerRecordD60]->size = sizeof(prec->d60);
    prt->papFldDes[scalerRecordD61]->size = sizeof(prec->d61);
    prt->papFldDes[scalerRecordD62]->size = sizeof(prec->d62);
    prt->papFldDes[scalerRecordD63]->size = sizeof(prec->d63);
    prt->papFldDes[scalerRecordD64]->size = sizeof(prec->d64);
    prt->papFldDes[scalerRecordG1]->size = sizeof(prec->g1);
    prt->papFldDes[scalerRecordG2]->size = sizeof(prec->g2);
    prt->papFldDes[scalerRecordG3]->size = sizeof(prec->g3);
    prt->papFldDes[scalerRecordG4]->size = sizeof(prec->g4);
    prt->papFldDes[scalerRecordG5]->size = sizeof(prec->g5);
    prt->papFldDes[scalerRecordG6]->size = sizeof(prec->g6);
    prt->papFldDes[scalerRecordG7]->size = sizeof(prec->g7);
    prt->papFldDes[scalerRecordG8]->size = sizeof(prec->g8);
    prt->papFldDes[scalerRecordG9]->size = sizeof(prec->g9);
    prt->papFldDes[scalerRecordG10]->size = sizeof(prec->g10);
    prt->papFldDes[scalerRecordG11]->size = sizeof(prec->g11);
    prt->papFldDes[scalerRecordG12]->size = sizeof(prec->g12);
    prt->papFldDes[scalerRecordG13]->size = sizeof(prec->g13);
    prt->papFldDes[scalerRecordG14]->size = sizeof(prec->g14);
    prt->papFldDes[scalerRecordG15]->size = sizeof(prec->g15);
    prt->papFldDes[scalerRecordG16]->size = sizeof(prec->g16);
    prt->papFldDes[scalerRecordG17]->size = sizeof(prec->g17);
    prt->papFldDes[scalerRecordG18]->size = sizeof(prec->g18);
    prt->papFldDes[scalerRecordG19]->size = sizeof(prec->g19);
    prt->papFldDes[scalerRecordG20]->size = sizeof(prec->g20);
    prt->papFldDes[scalerRecordG21]->size = sizeof(prec->g21);
    prt->papFldDes[scalerRecordG22]->size = sizeof(prec->g22);
    prt->papFldDes[scalerRecordG23]->size = sizeof(prec->g23);
    prt->papFldDes[scalerRecordG24]->size = sizeof(prec->g24);
    prt->papFldDes[scalerRecordG25]->size = sizeof(prec->g25);
    prt->papFldDes[scalerRecordG26]->size = sizeof(prec->g26);
    prt->papFldDes[scalerRecordG27]->size = sizeof(prec->g27);
    prt->papFldDes[scalerRecordG28]->size = sizeof(prec->g28);
    prt->papFldDes[scalerRecordG29]->size = sizeof(prec->g29);
    prt->papFldDes[scalerRecordG30]->size = sizeof(prec->g30);
    prt->papFldDes[scalerRecordG31]->size = sizeof(prec->g31);
    prt->papFldDes[scalerRecordG32]->size = sizeof(prec->g32);
    prt->papFldDes[scalerRecordG33]->size = sizeof(prec->g33);
    prt->papFldDes[scalerRecordG34]->size = sizeof(prec->g34);
    prt->papFldDes[scalerRecordG35]->size = sizeof(prec->g35);
    prt->papFldDes[scalerRecordG36]->size = sizeof(prec->g36);
    prt->papFldDes[scalerRecordG37]->size = sizeof(prec->g37);
    prt->papFldDes[scalerRecordG38]->size = sizeof(prec->g38);
    prt->papFldDes[scalerRecordG39]->size = sizeof(prec->g39);
    prt->papFldDes[scalerRecordG40]->size = sizeof(prec->g40);
    prt->papFldDes[scalerRecordG41]->size = sizeof(prec->g41);
    prt->papFldDes[scalerRecordG42]->size = sizeof(prec->g42);
    prt->papFldDes[scalerRecordG43]->size = sizeof(prec->g43);
    prt->papFldDes[scalerRecordG44]->size = sizeof(prec->g44);
    prt->papFldDes[scalerRecordG45]->size = sizeof(prec->g45);
    prt->papFldDes[scalerRecordG46]->size = sizeof(prec->g46);
    prt->papFldDes[scalerRecordG47]->size = sizeof(prec->g47);
    prt->papFldDes[scalerRecordG48]->size = sizeof(prec->g48);
    prt->papFldDes[scalerRecordG49]->size = sizeof(prec->g49);
    prt->papFldDes[scalerRecordG50]->size = sizeof(prec->g50);
    prt->papFldDes[scalerRecordG51]->size = sizeof(prec->g51);
    prt->papFldDes[scalerRecordG52]->size = sizeof(prec->g52);
    prt->papFldDes[scalerRecordG53]->size = sizeof(prec->g53);
    prt->papFldDes[scalerRecordG54]->size = sizeof(prec->g54);
    prt->papFldDes[scalerRecordG55]->size = sizeof(prec->g55);
    prt->papFldDes[scalerRecordG56]->size = sizeof(prec->g56);
    prt->papFldDes[scalerRecordG57]->size = sizeof(prec->g57);
    prt->papFldDes[scalerRecordG58]->size = sizeof(prec->g58);
    prt->papFldDes[scalerRecordG59]->size = sizeof(prec->g59);
    prt->papFldDes[scalerRecordG60]->size = sizeof(prec->g60);
    prt->papFldDes[scalerRecordG61]->size = sizeof(prec->g61);
    prt->papFldDes[scalerRecordG62]->size = sizeof(prec->g62);
    prt->papFldDes[scalerRecordG63]->size = sizeof(prec->g63);
    prt->papFldDes[scalerRecordG64]->size = sizeof(prec->g64);
    prt->papFldDes[scalerRecordTP]->size = sizeof(prec->tp);
    prt->papFldDes[scalerRecordTP1]->size = sizeof(prec->tp1);
    prt->papFldDes[scalerRecordPR1]->size = sizeof(prec->pr1);
    prt->papFldDes[scalerRecordPR2]->size = sizeof(prec->pr2);
    prt->papFldDes[scalerRecordPR3]->size = sizeof(prec->pr3);
    prt->papFldDes[scalerRecordPR4]->size = sizeof(prec->pr4);
    prt->papFldDes[scalerRecordPR5]->size = sizeof(prec->pr5);
    prt->papFldDes[scalerRecordPR6]->size = sizeof(prec->pr6);
    prt->papFldDes[scalerRecordPR7]->size = sizeof(prec->pr7);
    prt->papFldDes[scalerRecordPR8]->size = sizeof(prec->pr8);
    prt->papFldDes[scalerRecordPR9]->size = sizeof(prec->pr9);
    prt->papFldDes[scalerRecordPR10]->size = sizeof(prec->pr10);
    prt->papFldDes[scalerRecordPR11]->size = sizeof(prec->pr11);
    prt->papFldDes[scalerRecordPR12]->size = sizeof(prec->pr12);
    prt->papFldDes[scalerRecordPR13]->size = sizeof(prec->pr13);
    prt->papFldDes[scalerRecordPR14]->size = sizeof(prec->pr14);
    prt->papFldDes[scalerRecordPR15]->size = sizeof(prec->pr15);
    prt->papFldDes[scalerRecordPR16]->size = sizeof(prec->pr16);
    prt->papFldDes[scalerRecordPR17]->size = sizeof(prec->pr17);
    prt->papFldDes[scalerRecordPR18]->size = sizeof(prec->pr18);
    prt->papFldDes[scalerRecordPR19]->size = sizeof(prec->pr19);
    prt->papFldDes[scalerRecordPR20]->size = sizeof(prec->pr20);
    prt->papFldDes[scalerRecordPR21]->size = sizeof(prec->pr21);
    prt->papFldDes[scalerRecordPR22]->size = sizeof(prec->pr22);
    prt->papFldDes[scalerRecordPR23]->size = sizeof(prec->pr23);
    prt->papFldDes[scalerRecordPR24]->size = sizeof(prec->pr24);
    prt->papFldDes[scalerRecordPR25]->size = sizeof(prec->pr25);
    prt->papFldDes[scalerRecordPR26]->size = sizeof(prec->pr26);
    prt->papFldDes[scalerRecordPR27]->size = sizeof(prec->pr27);
    prt->papFldDes[scalerRecordPR28]->size = sizeof(prec->pr28);
    prt->papFldDes[scalerRecordPR29]->size = sizeof(prec->pr29);
    prt->papFldDes[scalerRecordPR30]->size = sizeof(prec->pr30);
    prt->papFldDes[scalerRecordPR31]->size = sizeof(prec->pr31);
    prt->papFldDes[scalerRecordPR32]->size = sizeof(prec->pr32);
    prt->papFldDes[scalerRecordPR33]->size = sizeof(prec->pr33);
    prt->papFldDes[scalerRecordPR34]->size = sizeof(prec->pr34);
    prt->papFldDes[scalerRecordPR35]->size = sizeof(prec->pr35);
    prt->papFldDes[scalerRecordPR36]->size = sizeof(prec->pr36);
    prt->papFldDes[scalerRecordPR37]->size = sizeof(prec->pr37);
    prt->papFldDes[scalerRecordPR38]->size = sizeof(prec->pr38);
    prt->papFldDes[scalerRecordPR39]->size = sizeof(prec->pr39);
    prt->papFldDes[scalerRecordPR40]->size = sizeof(prec->pr40);
    prt->papFldDes[scalerRecordPR41]->size = sizeof(prec->pr41);
    prt->papFldDes[scalerRecordPR42]->size = sizeof(prec->pr42);
    prt->papFldDes[scalerRecordPR43]->size = sizeof(prec->pr43);
    prt->papFldDes[scalerRecordPR44]->size = sizeof(prec->pr44);
    prt->papFldDes[scalerRecordPR45]->size = sizeof(prec->pr45);
    prt->papFldDes[scalerRecordPR46]->size = sizeof(prec->pr46);
    prt->papFldDes[scalerRecordPR47]->size = sizeof(prec->pr47);
    prt->papFldDes[scalerRecordPR48]->size = sizeof(prec->pr48);
    prt->papFldDes[scalerRecordPR49]->size = sizeof(prec->pr49);
    prt->papFldDes[scalerRecordPR50]->size = sizeof(prec->pr50);
    prt->papFldDes[scalerRecordPR51]->size = sizeof(prec->pr51);
    prt->papFldDes[scalerRecordPR52]->size = sizeof(prec->pr52);
    prt->papFldDes[scalerRecordPR53]->size = sizeof(prec->pr53);
    prt->papFldDes[scalerRecordPR54]->size = sizeof(prec->pr54);
    prt->papFldDes[scalerRecordPR55]->size = sizeof(prec->pr55);
    prt->papFldDes[scalerRecordPR56]->size = sizeof(prec->pr56);
    prt->papFldDes[scalerRecordPR57]->size = sizeof(prec->pr57);
    prt->papFldDes[scalerRecordPR58]->size = sizeof(prec->pr58);
    prt->papFldDes[scalerRecordPR59]->size = sizeof(prec->pr59);
    prt->papFldDes[scalerRecordPR60]->size = sizeof(prec->pr60);
    prt->papFldDes[scalerRecordPR61]->size = sizeof(prec->pr61);
    prt->papFldDes[scalerRecordPR62]->size = sizeof(prec->pr62);
    prt->papFldDes[scalerRecordPR63]->size = sizeof(prec->pr63);
    prt->papFldDes[scalerRecordPR64]->size = sizeof(prec->pr64);
    prt->papFldDes[scalerRecordT]->size = sizeof(prec->t);
    prt->papFldDes[scalerRecordS1]->size = sizeof(prec->s1);
    prt->papFldDes[scalerRecordS2]->size = sizeof(prec->s2);
    prt->papFldDes[scalerRecordS3]->size = sizeof(prec->s3);
    prt->papFldDes[scalerRecordS4]->size = sizeof(prec->s4);
    prt->papFldDes[scalerRecordS5]->size = sizeof(prec->s5);
    prt->papFldDes[scalerRecordS6]->size = sizeof(prec->s6);
    prt->papFldDes[scalerRecordS7]->size = sizeof(prec->s7);
    prt->papFldDes[scalerRecordS8]->size = sizeof(prec->s8);
    prt->papFldDes[scalerRecordS9]->size = sizeof(prec->s9);
    prt->papFldDes[scalerRecordS10]->size = sizeof(prec->s10);
    prt->papFldDes[scalerRecordS11]->size = sizeof(prec->s11);
    prt->papFldDes[scalerRecordS12]->size = sizeof(prec->s12);
    prt->papFldDes[scalerRecordS13]->size = sizeof(prec->s13);
    prt->papFldDes[scalerRecordS14]->size = sizeof(prec->s14);
    prt->papFldDes[scalerRecordS15]->size = sizeof(prec->s15);
    prt->papFldDes[scalerRecordS16]->size = sizeof(prec->s16);
    prt->papFldDes[scalerRecordS17]->size = sizeof(prec->s17);
    prt->papFldDes[scalerRecordS18]->size = sizeof(prec->s18);
    prt->papFldDes[scalerRecordS19]->size = sizeof(prec->s19);
    prt->papFldDes[scalerRecordS20]->size = sizeof(prec->s20);
    prt->papFldDes[scalerRecordS21]->size = sizeof(prec->s21);
    prt->papFldDes[scalerRecordS22]->size = sizeof(prec->s22);
    prt->papFldDes[scalerRecordS23]->size = sizeof(prec->s23);
    prt->papFldDes[scalerRecordS24]->size = sizeof(prec->s24);
    prt->papFldDes[scalerRecordS25]->size = sizeof(prec->s25);
    prt->papFldDes[scalerRecordS26]->size = sizeof(prec->s26);
    prt->papFldDes[scalerRecordS27]->size = sizeof(prec->s27);
    prt->papFldDes[scalerRecordS28]->size = sizeof(prec->s28);
    prt->papFldDes[scalerRecordS29]->size = sizeof(prec->s29);
    prt->papFldDes[scalerRecordS30]->size = sizeof(prec->s30);
    prt->papFldDes[scalerRecordS31]->size = sizeof(prec->s31);
    prt->papFldDes[scalerRecordS32]->size = sizeof(prec->s32);
    prt->papFldDes[scalerRecordS33]->size = sizeof(prec->s33);
    prt->papFldDes[scalerRecordS34]->size = sizeof(prec->s34);
    prt->papFldDes[scalerRecordS35]->size = sizeof(prec->s35);
    prt->papFldDes[scalerRecordS36]->size = sizeof(prec->s36);
    prt->papFldDes[scalerRecordS37]->size = sizeof(prec->s37);
    prt->papFldDes[scalerRecordS38]->size = sizeof(prec->s38);
    prt->papFldDes[scalerRecordS39]->size = sizeof(prec->s39);
    prt->papFldDes[scalerRecordS40]->size = sizeof(prec->s40);
    prt->papFldDes[scalerRecordS41]->size = sizeof(prec->s41);
    prt->papFldDes[scalerRecordS42]->size = sizeof(prec->s42);
    prt->papFldDes[scalerRecordS43]->size = sizeof(prec->s43);
    prt->papFldDes[scalerRecordS44]->size = sizeof(prec->s44);
    prt->papFldDes[scalerRecordS45]->size = sizeof(prec->s45);
    prt->papFldDes[scalerRecordS46]->size = sizeof(prec->s46);
    prt->papFldDes[scalerRecordS47]->size = sizeof(prec->s47);
    prt->papFldDes[scalerRecordS48]->size = sizeof(prec->s48);
    prt->papFldDes[scalerRecordS49]->size = sizeof(prec->s49);
    prt->papFldDes[scalerRecordS50]->size = sizeof(prec->s50);
    prt->papFldDes[scalerRecordS51]->size = sizeof(prec->s51);
    prt->papFldDes[scalerRecordS52]->size = sizeof(prec->s52);
    prt->papFldDes[scalerRecordS53]->size = sizeof(prec->s53);
    prt->papFldDes[scalerRecordS54]->size = sizeof(prec->s54);
    prt->papFldDes[scalerRecordS55]->size = sizeof(prec->s55);
    prt->papFldDes[scalerRecordS56]->size = sizeof(prec->s56);
    prt->papFldDes[scalerRecordS57]->size = sizeof(prec->s57);
    prt->papFldDes[scalerRecordS58]->size = sizeof(prec->s58);
    prt->papFldDes[scalerRecordS59]->size = sizeof(prec->s59);
    prt->papFldDes[scalerRecordS60]->size = sizeof(prec->s60);
    prt->papFldDes[scalerRecordS61]->size = sizeof(prec->s61);
    prt->papFldDes[scalerRecordS62]->size = sizeof(prec->s62);
    prt->papFldDes[scalerRecordS63]->size = sizeof(prec->s63);
    prt->papFldDes[scalerRecordS64]->size = sizeof(prec->s64);
    prt->papFldDes[scalerRecordNM1]->size = sizeof(prec->nm1);
    prt->papFldDes[scalerRecordNM2]->size = sizeof(prec->nm2);
    prt->papFldDes[scalerRecordNM3]->size = sizeof(prec->nm3);
    prt->papFldDes[scalerRecordNM4]->size = sizeof(prec->nm4);
    prt->papFldDes[scalerRecordNM5]->size = sizeof(prec->nm5);
    prt->papFldDes[scalerRecordNM6]->size = sizeof(prec->nm6);
    prt->papFldDes[scalerRecordNM7]->size = sizeof(prec->nm7);
    prt->papFldDes[scalerRecordNM8]->size = sizeof(prec->nm8);
    prt->papFldDes[scalerRecordNM9]->size = sizeof(prec->nm9);
    prt->papFldDes[scalerRecordNM10]->size = sizeof(prec->nm10);
    prt->papFldDes[scalerRecordNM11]->size = sizeof(prec->nm11);
    prt->papFldDes[scalerRecordNM12]->size = sizeof(prec->nm12);
    prt->papFldDes[scalerRecordNM13]->size = sizeof(prec->nm13);
    prt->papFldDes[scalerRecordNM14]->size = sizeof(prec->nm14);
    prt->papFldDes[scalerRecordNM15]->size = sizeof(prec->nm15);
    prt->papFldDes[scalerRecordNM16]->size = sizeof(prec->nm16);
    prt->papFldDes[scalerRecordNM17]->size = sizeof(prec->nm17);
    prt->papFldDes[scalerRecordNM18]->size = sizeof(prec->nm18);
    prt->papFldDes[scalerRecordNM19]->size = sizeof(prec->nm19);
    prt->papFldDes[scalerRecordNM20]->size = sizeof(prec->nm20);
    prt->papFldDes[scalerRecordNM21]->size = sizeof(prec->nm21);
    prt->papFldDes[scalerRecordNM22]->size = sizeof(prec->nm22);
    prt->papFldDes[scalerRecordNM23]->size = sizeof(prec->nm23);
    prt->papFldDes[scalerRecordNM24]->size = sizeof(prec->nm24);
    prt->papFldDes[scalerRecordNM25]->size = sizeof(prec->nm25);
    prt->papFldDes[scalerRecordNM26]->size = sizeof(prec->nm26);
    prt->papFldDes[scalerRecordNM27]->size = sizeof(prec->nm27);
    prt->papFldDes[scalerRecordNM28]->size = sizeof(prec->nm28);
    prt->papFldDes[scalerRecordNM29]->size = sizeof(prec->nm29);
    prt->papFldDes[scalerRecordNM30]->size = sizeof(prec->nm30);
    prt->papFldDes[scalerRecordNM31]->size = sizeof(prec->nm31);
    prt->papFldDes[scalerRecordNM32]->size = sizeof(prec->nm32);
    prt->papFldDes[scalerRecordNM33]->size = sizeof(prec->nm33);
    prt->papFldDes[scalerRecordNM34]->size = sizeof(prec->nm34);
    prt->papFldDes[scalerRecordNM35]->size = sizeof(prec->nm35);
    prt->papFldDes[scalerRecordNM36]->size = sizeof(prec->nm36);
    prt->papFldDes[scalerRecordNM37]->size = sizeof(prec->nm37);
    prt->papFldDes[scalerRecordNM38]->size = sizeof(prec->nm38);
    prt->papFldDes[scalerRecordNM39]->size = sizeof(prec->nm39);
    prt->papFldDes[scalerRecordNM40]->size = sizeof(prec->nm40);
    prt->papFldDes[scalerRecordNM41]->size = sizeof(prec->nm41);
    prt->papFldDes[scalerRecordNM42]->size = sizeof(prec->nm42);
    prt->papFldDes[scalerRecordNM43]->size = sizeof(prec->nm43);
    prt->papFldDes[scalerRecordNM44]->size = sizeof(prec->nm44);
    prt->papFldDes[scalerRecordNM45]->size = sizeof(prec->nm45);
    prt->papFldDes[scalerRecordNM46]->size = sizeof(prec->nm46);
    prt->papFldDes[scalerRecordNM47]->size = sizeof(prec->nm47);
    prt->papFldDes[scalerRecordNM48]->size = sizeof(prec->nm48);
    prt->papFldDes[scalerRecordNM49]->size = sizeof(prec->nm49);
    prt->papFldDes[scalerRecordNM50]->size = sizeof(prec->nm50);
    prt->papFldDes[scalerRecordNM51]->size = sizeof(prec->nm51);
    prt->papFldDes[scalerRecordNM52]->size = sizeof(prec->nm52);
    prt->papFldDes[scalerRecordNM53]->size = sizeof(prec->nm53);
    prt->papFldDes[scalerRecordNM54]->size = sizeof(prec->nm54);
    prt->papFldDes[scalerRecordNM55]->size = sizeof(prec->nm55);
    prt->papFldDes[scalerRecordNM56]->size = sizeof(prec->nm56);
    prt->papFldDes[scalerRecordNM57]->size = sizeof(prec->nm57);
    prt->papFldDes[scalerRecordNM58]->size = sizeof(prec->nm58);
    prt->papFldDes[scalerRecordNM59]->size = sizeof(prec->nm59);
    prt->papFldDes[scalerRecordNM60]->size = sizeof(prec->nm60);
    prt->papFldDes[scalerRecordNM61]->size = sizeof(prec->nm61);
    prt->papFldDes[scalerRecordNM62]->size = sizeof(prec->nm62);
    prt->papFldDes[scalerRecordNM63]->size = sizeof(prec->nm63);
    prt->papFldDes[scalerRecordNM64]->size = sizeof(prec->nm64);
    prt->papFldDes[scalerRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[scalerRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[scalerRecordCOUT]->size = sizeof(prec->cout);
    prt->papFldDes[scalerRecordCOUTP]->size = sizeof(prec->coutp);
    prt->papFldDes[scalerRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[scalerRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[scalerRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[scalerRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[scalerRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[scalerRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[scalerRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[scalerRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[scalerRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[scalerRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[scalerRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[scalerRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[scalerRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[scalerRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[scalerRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[scalerRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[scalerRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[scalerRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[scalerRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[scalerRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[scalerRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[scalerRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[scalerRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[scalerRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[scalerRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[scalerRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[scalerRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[scalerRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[scalerRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[scalerRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[scalerRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[scalerRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[scalerRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[scalerRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[scalerRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[scalerRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[scalerRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[scalerRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[scalerRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[scalerRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[scalerRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[scalerRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[scalerRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[scalerRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[scalerRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[scalerRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[scalerRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[scalerRecordFREQ]->offset = (unsigned short)((char *)&prec->freq - (char *)prec);
    prt->papFldDes[scalerRecordCNT]->offset = (unsigned short)((char *)&prec->cnt - (char *)prec);
    prt->papFldDes[scalerRecordPCNT]->offset = (unsigned short)((char *)&prec->pcnt - (char *)prec);
    prt->papFldDes[scalerRecordSS]->offset = (unsigned short)((char *)&prec->ss - (char *)prec);
    prt->papFldDes[scalerRecordUS]->offset = (unsigned short)((char *)&prec->us - (char *)prec);
    prt->papFldDes[scalerRecordCONT]->offset = (unsigned short)((char *)&prec->cont - (char *)prec);
    prt->papFldDes[scalerRecordOUT]->offset = (unsigned short)((char *)&prec->out - (char *)prec);
    prt->papFldDes[scalerRecordRATE]->offset = (unsigned short)((char *)&prec->rate - (char *)prec);
    prt->papFldDes[scalerRecordRAT1]->offset = (unsigned short)((char *)&prec->rat1 - (char *)prec);
    prt->papFldDes[scalerRecordDLY]->offset = (unsigned short)((char *)&prec->dly - (char *)prec);
    prt->papFldDes[scalerRecordDLY1]->offset = (unsigned short)((char *)&prec->dly1 - (char *)prec);
    prt->papFldDes[scalerRecordNCH]->offset = (unsigned short)((char *)&prec->nch - (char *)prec);
    prt->papFldDes[scalerRecordD1]->offset = (unsigned short)((char *)&prec->d1 - (char *)prec);
    prt->papFldDes[scalerRecordD2]->offset = (unsigned short)((char *)&prec->d2 - (char *)prec);
    prt->papFldDes[scalerRecordD3]->offset = (unsigned short)((char *)&prec->d3 - (char *)prec);
    prt->papFldDes[scalerRecordD4]->offset = (unsigned short)((char *)&prec->d4 - (char *)prec);
    prt->papFldDes[scalerRecordD5]->offset = (unsigned short)((char *)&prec->d5 - (char *)prec);
    prt->papFldDes[scalerRecordD6]->offset = (unsigned short)((char *)&prec->d6 - (char *)prec);
    prt->papFldDes[scalerRecordD7]->offset = (unsigned short)((char *)&prec->d7 - (char *)prec);
    prt->papFldDes[scalerRecordD8]->offset = (unsigned short)((char *)&prec->d8 - (char *)prec);
    prt->papFldDes[scalerRecordD9]->offset = (unsigned short)((char *)&prec->d9 - (char *)prec);
    prt->papFldDes[scalerRecordD10]->offset = (unsigned short)((char *)&prec->d10 - (char *)prec);
    prt->papFldDes[scalerRecordD11]->offset = (unsigned short)((char *)&prec->d11 - (char *)prec);
    prt->papFldDes[scalerRecordD12]->offset = (unsigned short)((char *)&prec->d12 - (char *)prec);
    prt->papFldDes[scalerRecordD13]->offset = (unsigned short)((char *)&prec->d13 - (char *)prec);
    prt->papFldDes[scalerRecordD14]->offset = (unsigned short)((char *)&prec->d14 - (char *)prec);
    prt->papFldDes[scalerRecordD15]->offset = (unsigned short)((char *)&prec->d15 - (char *)prec);
    prt->papFldDes[scalerRecordD16]->offset = (unsigned short)((char *)&prec->d16 - (char *)prec);
    prt->papFldDes[scalerRecordD17]->offset = (unsigned short)((char *)&prec->d17 - (char *)prec);
    prt->papFldDes[scalerRecordD18]->offset = (unsigned short)((char *)&prec->d18 - (char *)prec);
    prt->papFldDes[scalerRecordD19]->offset = (unsigned short)((char *)&prec->d19 - (char *)prec);
    prt->papFldDes[scalerRecordD20]->offset = (unsigned short)((char *)&prec->d20 - (char *)prec);
    prt->papFldDes[scalerRecordD21]->offset = (unsigned short)((char *)&prec->d21 - (char *)prec);
    prt->papFldDes[scalerRecordD22]->offset = (unsigned short)((char *)&prec->d22 - (char *)prec);
    prt->papFldDes[scalerRecordD23]->offset = (unsigned short)((char *)&prec->d23 - (char *)prec);
    prt->papFldDes[scalerRecordD24]->offset = (unsigned short)((char *)&prec->d24 - (char *)prec);
    prt->papFldDes[scalerRecordD25]->offset = (unsigned short)((char *)&prec->d25 - (char *)prec);
    prt->papFldDes[scalerRecordD26]->offset = (unsigned short)((char *)&prec->d26 - (char *)prec);
    prt->papFldDes[scalerRecordD27]->offset = (unsigned short)((char *)&prec->d27 - (char *)prec);
    prt->papFldDes[scalerRecordD28]->offset = (unsigned short)((char *)&prec->d28 - (char *)prec);
    prt->papFldDes[scalerRecordD29]->offset = (unsigned short)((char *)&prec->d29 - (char *)prec);
    prt->papFldDes[scalerRecordD30]->offset = (unsigned short)((char *)&prec->d30 - (char *)prec);
    prt->papFldDes[scalerRecordD31]->offset = (unsigned short)((char *)&prec->d31 - (char *)prec);
    prt->papFldDes[scalerRecordD32]->offset = (unsigned short)((char *)&prec->d32 - (char *)prec);
    prt->papFldDes[scalerRecordD33]->offset = (unsigned short)((char *)&prec->d33 - (char *)prec);
    prt->papFldDes[scalerRecordD34]->offset = (unsigned short)((char *)&prec->d34 - (char *)prec);
    prt->papFldDes[scalerRecordD35]->offset = (unsigned short)((char *)&prec->d35 - (char *)prec);
    prt->papFldDes[scalerRecordD36]->offset = (unsigned short)((char *)&prec->d36 - (char *)prec);
    prt->papFldDes[scalerRecordD37]->offset = (unsigned short)((char *)&prec->d37 - (char *)prec);
    prt->papFldDes[scalerRecordD38]->offset = (unsigned short)((char *)&prec->d38 - (char *)prec);
    prt->papFldDes[scalerRecordD39]->offset = (unsigned short)((char *)&prec->d39 - (char *)prec);
    prt->papFldDes[scalerRecordD40]->offset = (unsigned short)((char *)&prec->d40 - (char *)prec);
    prt->papFldDes[scalerRecordD41]->offset = (unsigned short)((char *)&prec->d41 - (char *)prec);
    prt->papFldDes[scalerRecordD42]->offset = (unsigned short)((char *)&prec->d42 - (char *)prec);
    prt->papFldDes[scalerRecordD43]->offset = (unsigned short)((char *)&prec->d43 - (char *)prec);
    prt->papFldDes[scalerRecordD44]->offset = (unsigned short)((char *)&prec->d44 - (char *)prec);
    prt->papFldDes[scalerRecordD45]->offset = (unsigned short)((char *)&prec->d45 - (char *)prec);
    prt->papFldDes[scalerRecordD46]->offset = (unsigned short)((char *)&prec->d46 - (char *)prec);
    prt->papFldDes[scalerRecordD47]->offset = (unsigned short)((char *)&prec->d47 - (char *)prec);
    prt->papFldDes[scalerRecordD48]->offset = (unsigned short)((char *)&prec->d48 - (char *)prec);
    prt->papFldDes[scalerRecordD49]->offset = (unsigned short)((char *)&prec->d49 - (char *)prec);
    prt->papFldDes[scalerRecordD50]->offset = (unsigned short)((char *)&prec->d50 - (char *)prec);
    prt->papFldDes[scalerRecordD51]->offset = (unsigned short)((char *)&prec->d51 - (char *)prec);
    prt->papFldDes[scalerRecordD52]->offset = (unsigned short)((char *)&prec->d52 - (char *)prec);
    prt->papFldDes[scalerRecordD53]->offset = (unsigned short)((char *)&prec->d53 - (char *)prec);
    prt->papFldDes[scalerRecordD54]->offset = (unsigned short)((char *)&prec->d54 - (char *)prec);
    prt->papFldDes[scalerRecordD55]->offset = (unsigned short)((char *)&prec->d55 - (char *)prec);
    prt->papFldDes[scalerRecordD56]->offset = (unsigned short)((char *)&prec->d56 - (char *)prec);
    prt->papFldDes[scalerRecordD57]->offset = (unsigned short)((char *)&prec->d57 - (char *)prec);
    prt->papFldDes[scalerRecordD58]->offset = (unsigned short)((char *)&prec->d58 - (char *)prec);
    prt->papFldDes[scalerRecordD59]->offset = (unsigned short)((char *)&prec->d59 - (char *)prec);
    prt->papFldDes[scalerRecordD60]->offset = (unsigned short)((char *)&prec->d60 - (char *)prec);
    prt->papFldDes[scalerRecordD61]->offset = (unsigned short)((char *)&prec->d61 - (char *)prec);
    prt->papFldDes[scalerRecordD62]->offset = (unsigned short)((char *)&prec->d62 - (char *)prec);
    prt->papFldDes[scalerRecordD63]->offset = (unsigned short)((char *)&prec->d63 - (char *)prec);
    prt->papFldDes[scalerRecordD64]->offset = (unsigned short)((char *)&prec->d64 - (char *)prec);
    prt->papFldDes[scalerRecordG1]->offset = (unsigned short)((char *)&prec->g1 - (char *)prec);
    prt->papFldDes[scalerRecordG2]->offset = (unsigned short)((char *)&prec->g2 - (char *)prec);
    prt->papFldDes[scalerRecordG3]->offset = (unsigned short)((char *)&prec->g3 - (char *)prec);
    prt->papFldDes[scalerRecordG4]->offset = (unsigned short)((char *)&prec->g4 - (char *)prec);
    prt->papFldDes[scalerRecordG5]->offset = (unsigned short)((char *)&prec->g5 - (char *)prec);
    prt->papFldDes[scalerRecordG6]->offset = (unsigned short)((char *)&prec->g6 - (char *)prec);
    prt->papFldDes[scalerRecordG7]->offset = (unsigned short)((char *)&prec->g7 - (char *)prec);
    prt->papFldDes[scalerRecordG8]->offset = (unsigned short)((char *)&prec->g8 - (char *)prec);
    prt->papFldDes[scalerRecordG9]->offset = (unsigned short)((char *)&prec->g9 - (char *)prec);
    prt->papFldDes[scalerRecordG10]->offset = (unsigned short)((char *)&prec->g10 - (char *)prec);
    prt->papFldDes[scalerRecordG11]->offset = (unsigned short)((char *)&prec->g11 - (char *)prec);
    prt->papFldDes[scalerRecordG12]->offset = (unsigned short)((char *)&prec->g12 - (char *)prec);
    prt->papFldDes[scalerRecordG13]->offset = (unsigned short)((char *)&prec->g13 - (char *)prec);
    prt->papFldDes[scalerRecordG14]->offset = (unsigned short)((char *)&prec->g14 - (char *)prec);
    prt->papFldDes[scalerRecordG15]->offset = (unsigned short)((char *)&prec->g15 - (char *)prec);
    prt->papFldDes[scalerRecordG16]->offset = (unsigned short)((char *)&prec->g16 - (char *)prec);
    prt->papFldDes[scalerRecordG17]->offset = (unsigned short)((char *)&prec->g17 - (char *)prec);
    prt->papFldDes[scalerRecordG18]->offset = (unsigned short)((char *)&prec->g18 - (char *)prec);
    prt->papFldDes[scalerRecordG19]->offset = (unsigned short)((char *)&prec->g19 - (char *)prec);
    prt->papFldDes[scalerRecordG20]->offset = (unsigned short)((char *)&prec->g20 - (char *)prec);
    prt->papFldDes[scalerRecordG21]->offset = (unsigned short)((char *)&prec->g21 - (char *)prec);
    prt->papFldDes[scalerRecordG22]->offset = (unsigned short)((char *)&prec->g22 - (char *)prec);
    prt->papFldDes[scalerRecordG23]->offset = (unsigned short)((char *)&prec->g23 - (char *)prec);
    prt->papFldDes[scalerRecordG24]->offset = (unsigned short)((char *)&prec->g24 - (char *)prec);
    prt->papFldDes[scalerRecordG25]->offset = (unsigned short)((char *)&prec->g25 - (char *)prec);
    prt->papFldDes[scalerRecordG26]->offset = (unsigned short)((char *)&prec->g26 - (char *)prec);
    prt->papFldDes[scalerRecordG27]->offset = (unsigned short)((char *)&prec->g27 - (char *)prec);
    prt->papFldDes[scalerRecordG28]->offset = (unsigned short)((char *)&prec->g28 - (char *)prec);
    prt->papFldDes[scalerRecordG29]->offset = (unsigned short)((char *)&prec->g29 - (char *)prec);
    prt->papFldDes[scalerRecordG30]->offset = (unsigned short)((char *)&prec->g30 - (char *)prec);
    prt->papFldDes[scalerRecordG31]->offset = (unsigned short)((char *)&prec->g31 - (char *)prec);
    prt->papFldDes[scalerRecordG32]->offset = (unsigned short)((char *)&prec->g32 - (char *)prec);
    prt->papFldDes[scalerRecordG33]->offset = (unsigned short)((char *)&prec->g33 - (char *)prec);
    prt->papFldDes[scalerRecordG34]->offset = (unsigned short)((char *)&prec->g34 - (char *)prec);
    prt->papFldDes[scalerRecordG35]->offset = (unsigned short)((char *)&prec->g35 - (char *)prec);
    prt->papFldDes[scalerRecordG36]->offset = (unsigned short)((char *)&prec->g36 - (char *)prec);
    prt->papFldDes[scalerRecordG37]->offset = (unsigned short)((char *)&prec->g37 - (char *)prec);
    prt->papFldDes[scalerRecordG38]->offset = (unsigned short)((char *)&prec->g38 - (char *)prec);
    prt->papFldDes[scalerRecordG39]->offset = (unsigned short)((char *)&prec->g39 - (char *)prec);
    prt->papFldDes[scalerRecordG40]->offset = (unsigned short)((char *)&prec->g40 - (char *)prec);
    prt->papFldDes[scalerRecordG41]->offset = (unsigned short)((char *)&prec->g41 - (char *)prec);
    prt->papFldDes[scalerRecordG42]->offset = (unsigned short)((char *)&prec->g42 - (char *)prec);
    prt->papFldDes[scalerRecordG43]->offset = (unsigned short)((char *)&prec->g43 - (char *)prec);
    prt->papFldDes[scalerRecordG44]->offset = (unsigned short)((char *)&prec->g44 - (char *)prec);
    prt->papFldDes[scalerRecordG45]->offset = (unsigned short)((char *)&prec->g45 - (char *)prec);
    prt->papFldDes[scalerRecordG46]->offset = (unsigned short)((char *)&prec->g46 - (char *)prec);
    prt->papFldDes[scalerRecordG47]->offset = (unsigned short)((char *)&prec->g47 - (char *)prec);
    prt->papFldDes[scalerRecordG48]->offset = (unsigned short)((char *)&prec->g48 - (char *)prec);
    prt->papFldDes[scalerRecordG49]->offset = (unsigned short)((char *)&prec->g49 - (char *)prec);
    prt->papFldDes[scalerRecordG50]->offset = (unsigned short)((char *)&prec->g50 - (char *)prec);
    prt->papFldDes[scalerRecordG51]->offset = (unsigned short)((char *)&prec->g51 - (char *)prec);
    prt->papFldDes[scalerRecordG52]->offset = (unsigned short)((char *)&prec->g52 - (char *)prec);
    prt->papFldDes[scalerRecordG53]->offset = (unsigned short)((char *)&prec->g53 - (char *)prec);
    prt->papFldDes[scalerRecordG54]->offset = (unsigned short)((char *)&prec->g54 - (char *)prec);
    prt->papFldDes[scalerRecordG55]->offset = (unsigned short)((char *)&prec->g55 - (char *)prec);
    prt->papFldDes[scalerRecordG56]->offset = (unsigned short)((char *)&prec->g56 - (char *)prec);
    prt->papFldDes[scalerRecordG57]->offset = (unsigned short)((char *)&prec->g57 - (char *)prec);
    prt->papFldDes[scalerRecordG58]->offset = (unsigned short)((char *)&prec->g58 - (char *)prec);
    prt->papFldDes[scalerRecordG59]->offset = (unsigned short)((char *)&prec->g59 - (char *)prec);
    prt->papFldDes[scalerRecordG60]->offset = (unsigned short)((char *)&prec->g60 - (char *)prec);
    prt->papFldDes[scalerRecordG61]->offset = (unsigned short)((char *)&prec->g61 - (char *)prec);
    prt->papFldDes[scalerRecordG62]->offset = (unsigned short)((char *)&prec->g62 - (char *)prec);
    prt->papFldDes[scalerRecordG63]->offset = (unsigned short)((char *)&prec->g63 - (char *)prec);
    prt->papFldDes[scalerRecordG64]->offset = (unsigned short)((char *)&prec->g64 - (char *)prec);
    prt->papFldDes[scalerRecordTP]->offset = (unsigned short)((char *)&prec->tp - (char *)prec);
    prt->papFldDes[scalerRecordTP1]->offset = (unsigned short)((char *)&prec->tp1 - (char *)prec);
    prt->papFldDes[scalerRecordPR1]->offset = (unsigned short)((char *)&prec->pr1 - (char *)prec);
    prt->papFldDes[scalerRecordPR2]->offset = (unsigned short)((char *)&prec->pr2 - (char *)prec);
    prt->papFldDes[scalerRecordPR3]->offset = (unsigned short)((char *)&prec->pr3 - (char *)prec);
    prt->papFldDes[scalerRecordPR4]->offset = (unsigned short)((char *)&prec->pr4 - (char *)prec);
    prt->papFldDes[scalerRecordPR5]->offset = (unsigned short)((char *)&prec->pr5 - (char *)prec);
    prt->papFldDes[scalerRecordPR6]->offset = (unsigned short)((char *)&prec->pr6 - (char *)prec);
    prt->papFldDes[scalerRecordPR7]->offset = (unsigned short)((char *)&prec->pr7 - (char *)prec);
    prt->papFldDes[scalerRecordPR8]->offset = (unsigned short)((char *)&prec->pr8 - (char *)prec);
    prt->papFldDes[scalerRecordPR9]->offset = (unsigned short)((char *)&prec->pr9 - (char *)prec);
    prt->papFldDes[scalerRecordPR10]->offset = (unsigned short)((char *)&prec->pr10 - (char *)prec);
    prt->papFldDes[scalerRecordPR11]->offset = (unsigned short)((char *)&prec->pr11 - (char *)prec);
    prt->papFldDes[scalerRecordPR12]->offset = (unsigned short)((char *)&prec->pr12 - (char *)prec);
    prt->papFldDes[scalerRecordPR13]->offset = (unsigned short)((char *)&prec->pr13 - (char *)prec);
    prt->papFldDes[scalerRecordPR14]->offset = (unsigned short)((char *)&prec->pr14 - (char *)prec);
    prt->papFldDes[scalerRecordPR15]->offset = (unsigned short)((char *)&prec->pr15 - (char *)prec);
    prt->papFldDes[scalerRecordPR16]->offset = (unsigned short)((char *)&prec->pr16 - (char *)prec);
    prt->papFldDes[scalerRecordPR17]->offset = (unsigned short)((char *)&prec->pr17 - (char *)prec);
    prt->papFldDes[scalerRecordPR18]->offset = (unsigned short)((char *)&prec->pr18 - (char *)prec);
    prt->papFldDes[scalerRecordPR19]->offset = (unsigned short)((char *)&prec->pr19 - (char *)prec);
    prt->papFldDes[scalerRecordPR20]->offset = (unsigned short)((char *)&prec->pr20 - (char *)prec);
    prt->papFldDes[scalerRecordPR21]->offset = (unsigned short)((char *)&prec->pr21 - (char *)prec);
    prt->papFldDes[scalerRecordPR22]->offset = (unsigned short)((char *)&prec->pr22 - (char *)prec);
    prt->papFldDes[scalerRecordPR23]->offset = (unsigned short)((char *)&prec->pr23 - (char *)prec);
    prt->papFldDes[scalerRecordPR24]->offset = (unsigned short)((char *)&prec->pr24 - (char *)prec);
    prt->papFldDes[scalerRecordPR25]->offset = (unsigned short)((char *)&prec->pr25 - (char *)prec);
    prt->papFldDes[scalerRecordPR26]->offset = (unsigned short)((char *)&prec->pr26 - (char *)prec);
    prt->papFldDes[scalerRecordPR27]->offset = (unsigned short)((char *)&prec->pr27 - (char *)prec);
    prt->papFldDes[scalerRecordPR28]->offset = (unsigned short)((char *)&prec->pr28 - (char *)prec);
    prt->papFldDes[scalerRecordPR29]->offset = (unsigned short)((char *)&prec->pr29 - (char *)prec);
    prt->papFldDes[scalerRecordPR30]->offset = (unsigned short)((char *)&prec->pr30 - (char *)prec);
    prt->papFldDes[scalerRecordPR31]->offset = (unsigned short)((char *)&prec->pr31 - (char *)prec);
    prt->papFldDes[scalerRecordPR32]->offset = (unsigned short)((char *)&prec->pr32 - (char *)prec);
    prt->papFldDes[scalerRecordPR33]->offset = (unsigned short)((char *)&prec->pr33 - (char *)prec);
    prt->papFldDes[scalerRecordPR34]->offset = (unsigned short)((char *)&prec->pr34 - (char *)prec);
    prt->papFldDes[scalerRecordPR35]->offset = (unsigned short)((char *)&prec->pr35 - (char *)prec);
    prt->papFldDes[scalerRecordPR36]->offset = (unsigned short)((char *)&prec->pr36 - (char *)prec);
    prt->papFldDes[scalerRecordPR37]->offset = (unsigned short)((char *)&prec->pr37 - (char *)prec);
    prt->papFldDes[scalerRecordPR38]->offset = (unsigned short)((char *)&prec->pr38 - (char *)prec);
    prt->papFldDes[scalerRecordPR39]->offset = (unsigned short)((char *)&prec->pr39 - (char *)prec);
    prt->papFldDes[scalerRecordPR40]->offset = (unsigned short)((char *)&prec->pr40 - (char *)prec);
    prt->papFldDes[scalerRecordPR41]->offset = (unsigned short)((char *)&prec->pr41 - (char *)prec);
    prt->papFldDes[scalerRecordPR42]->offset = (unsigned short)((char *)&prec->pr42 - (char *)prec);
    prt->papFldDes[scalerRecordPR43]->offset = (unsigned short)((char *)&prec->pr43 - (char *)prec);
    prt->papFldDes[scalerRecordPR44]->offset = (unsigned short)((char *)&prec->pr44 - (char *)prec);
    prt->papFldDes[scalerRecordPR45]->offset = (unsigned short)((char *)&prec->pr45 - (char *)prec);
    prt->papFldDes[scalerRecordPR46]->offset = (unsigned short)((char *)&prec->pr46 - (char *)prec);
    prt->papFldDes[scalerRecordPR47]->offset = (unsigned short)((char *)&prec->pr47 - (char *)prec);
    prt->papFldDes[scalerRecordPR48]->offset = (unsigned short)((char *)&prec->pr48 - (char *)prec);
    prt->papFldDes[scalerRecordPR49]->offset = (unsigned short)((char *)&prec->pr49 - (char *)prec);
    prt->papFldDes[scalerRecordPR50]->offset = (unsigned short)((char *)&prec->pr50 - (char *)prec);
    prt->papFldDes[scalerRecordPR51]->offset = (unsigned short)((char *)&prec->pr51 - (char *)prec);
    prt->papFldDes[scalerRecordPR52]->offset = (unsigned short)((char *)&prec->pr52 - (char *)prec);
    prt->papFldDes[scalerRecordPR53]->offset = (unsigned short)((char *)&prec->pr53 - (char *)prec);
    prt->papFldDes[scalerRecordPR54]->offset = (unsigned short)((char *)&prec->pr54 - (char *)prec);
    prt->papFldDes[scalerRecordPR55]->offset = (unsigned short)((char *)&prec->pr55 - (char *)prec);
    prt->papFldDes[scalerRecordPR56]->offset = (unsigned short)((char *)&prec->pr56 - (char *)prec);
    prt->papFldDes[scalerRecordPR57]->offset = (unsigned short)((char *)&prec->pr57 - (char *)prec);
    prt->papFldDes[scalerRecordPR58]->offset = (unsigned short)((char *)&prec->pr58 - (char *)prec);
    prt->papFldDes[scalerRecordPR59]->offset = (unsigned short)((char *)&prec->pr59 - (char *)prec);
    prt->papFldDes[scalerRecordPR60]->offset = (unsigned short)((char *)&prec->pr60 - (char *)prec);
    prt->papFldDes[scalerRecordPR61]->offset = (unsigned short)((char *)&prec->pr61 - (char *)prec);
    prt->papFldDes[scalerRecordPR62]->offset = (unsigned short)((char *)&prec->pr62 - (char *)prec);
    prt->papFldDes[scalerRecordPR63]->offset = (unsigned short)((char *)&prec->pr63 - (char *)prec);
    prt->papFldDes[scalerRecordPR64]->offset = (unsigned short)((char *)&prec->pr64 - (char *)prec);
    prt->papFldDes[scalerRecordT]->offset = (unsigned short)((char *)&prec->t - (char *)prec);
    prt->papFldDes[scalerRecordS1]->offset = (unsigned short)((char *)&prec->s1 - (char *)prec);
    prt->papFldDes[scalerRecordS2]->offset = (unsigned short)((char *)&prec->s2 - (char *)prec);
    prt->papFldDes[scalerRecordS3]->offset = (unsigned short)((char *)&prec->s3 - (char *)prec);
    prt->papFldDes[scalerRecordS4]->offset = (unsigned short)((char *)&prec->s4 - (char *)prec);
    prt->papFldDes[scalerRecordS5]->offset = (unsigned short)((char *)&prec->s5 - (char *)prec);
    prt->papFldDes[scalerRecordS6]->offset = (unsigned short)((char *)&prec->s6 - (char *)prec);
    prt->papFldDes[scalerRecordS7]->offset = (unsigned short)((char *)&prec->s7 - (char *)prec);
    prt->papFldDes[scalerRecordS8]->offset = (unsigned short)((char *)&prec->s8 - (char *)prec);
    prt->papFldDes[scalerRecordS9]->offset = (unsigned short)((char *)&prec->s9 - (char *)prec);
    prt->papFldDes[scalerRecordS10]->offset = (unsigned short)((char *)&prec->s10 - (char *)prec);
    prt->papFldDes[scalerRecordS11]->offset = (unsigned short)((char *)&prec->s11 - (char *)prec);
    prt->papFldDes[scalerRecordS12]->offset = (unsigned short)((char *)&prec->s12 - (char *)prec);
    prt->papFldDes[scalerRecordS13]->offset = (unsigned short)((char *)&prec->s13 - (char *)prec);
    prt->papFldDes[scalerRecordS14]->offset = (unsigned short)((char *)&prec->s14 - (char *)prec);
    prt->papFldDes[scalerRecordS15]->offset = (unsigned short)((char *)&prec->s15 - (char *)prec);
    prt->papFldDes[scalerRecordS16]->offset = (unsigned short)((char *)&prec->s16 - (char *)prec);
    prt->papFldDes[scalerRecordS17]->offset = (unsigned short)((char *)&prec->s17 - (char *)prec);
    prt->papFldDes[scalerRecordS18]->offset = (unsigned short)((char *)&prec->s18 - (char *)prec);
    prt->papFldDes[scalerRecordS19]->offset = (unsigned short)((char *)&prec->s19 - (char *)prec);
    prt->papFldDes[scalerRecordS20]->offset = (unsigned short)((char *)&prec->s20 - (char *)prec);
    prt->papFldDes[scalerRecordS21]->offset = (unsigned short)((char *)&prec->s21 - (char *)prec);
    prt->papFldDes[scalerRecordS22]->offset = (unsigned short)((char *)&prec->s22 - (char *)prec);
    prt->papFldDes[scalerRecordS23]->offset = (unsigned short)((char *)&prec->s23 - (char *)prec);
    prt->papFldDes[scalerRecordS24]->offset = (unsigned short)((char *)&prec->s24 - (char *)prec);
    prt->papFldDes[scalerRecordS25]->offset = (unsigned short)((char *)&prec->s25 - (char *)prec);
    prt->papFldDes[scalerRecordS26]->offset = (unsigned short)((char *)&prec->s26 - (char *)prec);
    prt->papFldDes[scalerRecordS27]->offset = (unsigned short)((char *)&prec->s27 - (char *)prec);
    prt->papFldDes[scalerRecordS28]->offset = (unsigned short)((char *)&prec->s28 - (char *)prec);
    prt->papFldDes[scalerRecordS29]->offset = (unsigned short)((char *)&prec->s29 - (char *)prec);
    prt->papFldDes[scalerRecordS30]->offset = (unsigned short)((char *)&prec->s30 - (char *)prec);
    prt->papFldDes[scalerRecordS31]->offset = (unsigned short)((char *)&prec->s31 - (char *)prec);
    prt->papFldDes[scalerRecordS32]->offset = (unsigned short)((char *)&prec->s32 - (char *)prec);
    prt->papFldDes[scalerRecordS33]->offset = (unsigned short)((char *)&prec->s33 - (char *)prec);
    prt->papFldDes[scalerRecordS34]->offset = (unsigned short)((char *)&prec->s34 - (char *)prec);
    prt->papFldDes[scalerRecordS35]->offset = (unsigned short)((char *)&prec->s35 - (char *)prec);
    prt->papFldDes[scalerRecordS36]->offset = (unsigned short)((char *)&prec->s36 - (char *)prec);
    prt->papFldDes[scalerRecordS37]->offset = (unsigned short)((char *)&prec->s37 - (char *)prec);
    prt->papFldDes[scalerRecordS38]->offset = (unsigned short)((char *)&prec->s38 - (char *)prec);
    prt->papFldDes[scalerRecordS39]->offset = (unsigned short)((char *)&prec->s39 - (char *)prec);
    prt->papFldDes[scalerRecordS40]->offset = (unsigned short)((char *)&prec->s40 - (char *)prec);
    prt->papFldDes[scalerRecordS41]->offset = (unsigned short)((char *)&prec->s41 - (char *)prec);
    prt->papFldDes[scalerRecordS42]->offset = (unsigned short)((char *)&prec->s42 - (char *)prec);
    prt->papFldDes[scalerRecordS43]->offset = (unsigned short)((char *)&prec->s43 - (char *)prec);
    prt->papFldDes[scalerRecordS44]->offset = (unsigned short)((char *)&prec->s44 - (char *)prec);
    prt->papFldDes[scalerRecordS45]->offset = (unsigned short)((char *)&prec->s45 - (char *)prec);
    prt->papFldDes[scalerRecordS46]->offset = (unsigned short)((char *)&prec->s46 - (char *)prec);
    prt->papFldDes[scalerRecordS47]->offset = (unsigned short)((char *)&prec->s47 - (char *)prec);
    prt->papFldDes[scalerRecordS48]->offset = (unsigned short)((char *)&prec->s48 - (char *)prec);
    prt->papFldDes[scalerRecordS49]->offset = (unsigned short)((char *)&prec->s49 - (char *)prec);
    prt->papFldDes[scalerRecordS50]->offset = (unsigned short)((char *)&prec->s50 - (char *)prec);
    prt->papFldDes[scalerRecordS51]->offset = (unsigned short)((char *)&prec->s51 - (char *)prec);
    prt->papFldDes[scalerRecordS52]->offset = (unsigned short)((char *)&prec->s52 - (char *)prec);
    prt->papFldDes[scalerRecordS53]->offset = (unsigned short)((char *)&prec->s53 - (char *)prec);
    prt->papFldDes[scalerRecordS54]->offset = (unsigned short)((char *)&prec->s54 - (char *)prec);
    prt->papFldDes[scalerRecordS55]->offset = (unsigned short)((char *)&prec->s55 - (char *)prec);
    prt->papFldDes[scalerRecordS56]->offset = (unsigned short)((char *)&prec->s56 - (char *)prec);
    prt->papFldDes[scalerRecordS57]->offset = (unsigned short)((char *)&prec->s57 - (char *)prec);
    prt->papFldDes[scalerRecordS58]->offset = (unsigned short)((char *)&prec->s58 - (char *)prec);
    prt->papFldDes[scalerRecordS59]->offset = (unsigned short)((char *)&prec->s59 - (char *)prec);
    prt->papFldDes[scalerRecordS60]->offset = (unsigned short)((char *)&prec->s60 - (char *)prec);
    prt->papFldDes[scalerRecordS61]->offset = (unsigned short)((char *)&prec->s61 - (char *)prec);
    prt->papFldDes[scalerRecordS62]->offset = (unsigned short)((char *)&prec->s62 - (char *)prec);
    prt->papFldDes[scalerRecordS63]->offset = (unsigned short)((char *)&prec->s63 - (char *)prec);
    prt->papFldDes[scalerRecordS64]->offset = (unsigned short)((char *)&prec->s64 - (char *)prec);
    prt->papFldDes[scalerRecordNM1]->offset = (unsigned short)((char *)&prec->nm1 - (char *)prec);
    prt->papFldDes[scalerRecordNM2]->offset = (unsigned short)((char *)&prec->nm2 - (char *)prec);
    prt->papFldDes[scalerRecordNM3]->offset = (unsigned short)((char *)&prec->nm3 - (char *)prec);
    prt->papFldDes[scalerRecordNM4]->offset = (unsigned short)((char *)&prec->nm4 - (char *)prec);
    prt->papFldDes[scalerRecordNM5]->offset = (unsigned short)((char *)&prec->nm5 - (char *)prec);
    prt->papFldDes[scalerRecordNM6]->offset = (unsigned short)((char *)&prec->nm6 - (char *)prec);
    prt->papFldDes[scalerRecordNM7]->offset = (unsigned short)((char *)&prec->nm7 - (char *)prec);
    prt->papFldDes[scalerRecordNM8]->offset = (unsigned short)((char *)&prec->nm8 - (char *)prec);
    prt->papFldDes[scalerRecordNM9]->offset = (unsigned short)((char *)&prec->nm9 - (char *)prec);
    prt->papFldDes[scalerRecordNM10]->offset = (unsigned short)((char *)&prec->nm10 - (char *)prec);
    prt->papFldDes[scalerRecordNM11]->offset = (unsigned short)((char *)&prec->nm11 - (char *)prec);
    prt->papFldDes[scalerRecordNM12]->offset = (unsigned short)((char *)&prec->nm12 - (char *)prec);
    prt->papFldDes[scalerRecordNM13]->offset = (unsigned short)((char *)&prec->nm13 - (char *)prec);
    prt->papFldDes[scalerRecordNM14]->offset = (unsigned short)((char *)&prec->nm14 - (char *)prec);
    prt->papFldDes[scalerRecordNM15]->offset = (unsigned short)((char *)&prec->nm15 - (char *)prec);
    prt->papFldDes[scalerRecordNM16]->offset = (unsigned short)((char *)&prec->nm16 - (char *)prec);
    prt->papFldDes[scalerRecordNM17]->offset = (unsigned short)((char *)&prec->nm17 - (char *)prec);
    prt->papFldDes[scalerRecordNM18]->offset = (unsigned short)((char *)&prec->nm18 - (char *)prec);
    prt->papFldDes[scalerRecordNM19]->offset = (unsigned short)((char *)&prec->nm19 - (char *)prec);
    prt->papFldDes[scalerRecordNM20]->offset = (unsigned short)((char *)&prec->nm20 - (char *)prec);
    prt->papFldDes[scalerRecordNM21]->offset = (unsigned short)((char *)&prec->nm21 - (char *)prec);
    prt->papFldDes[scalerRecordNM22]->offset = (unsigned short)((char *)&prec->nm22 - (char *)prec);
    prt->papFldDes[scalerRecordNM23]->offset = (unsigned short)((char *)&prec->nm23 - (char *)prec);
    prt->papFldDes[scalerRecordNM24]->offset = (unsigned short)((char *)&prec->nm24 - (char *)prec);
    prt->papFldDes[scalerRecordNM25]->offset = (unsigned short)((char *)&prec->nm25 - (char *)prec);
    prt->papFldDes[scalerRecordNM26]->offset = (unsigned short)((char *)&prec->nm26 - (char *)prec);
    prt->papFldDes[scalerRecordNM27]->offset = (unsigned short)((char *)&prec->nm27 - (char *)prec);
    prt->papFldDes[scalerRecordNM28]->offset = (unsigned short)((char *)&prec->nm28 - (char *)prec);
    prt->papFldDes[scalerRecordNM29]->offset = (unsigned short)((char *)&prec->nm29 - (char *)prec);
    prt->papFldDes[scalerRecordNM30]->offset = (unsigned short)((char *)&prec->nm30 - (char *)prec);
    prt->papFldDes[scalerRecordNM31]->offset = (unsigned short)((char *)&prec->nm31 - (char *)prec);
    prt->papFldDes[scalerRecordNM32]->offset = (unsigned short)((char *)&prec->nm32 - (char *)prec);
    prt->papFldDes[scalerRecordNM33]->offset = (unsigned short)((char *)&prec->nm33 - (char *)prec);
    prt->papFldDes[scalerRecordNM34]->offset = (unsigned short)((char *)&prec->nm34 - (char *)prec);
    prt->papFldDes[scalerRecordNM35]->offset = (unsigned short)((char *)&prec->nm35 - (char *)prec);
    prt->papFldDes[scalerRecordNM36]->offset = (unsigned short)((char *)&prec->nm36 - (char *)prec);
    prt->papFldDes[scalerRecordNM37]->offset = (unsigned short)((char *)&prec->nm37 - (char *)prec);
    prt->papFldDes[scalerRecordNM38]->offset = (unsigned short)((char *)&prec->nm38 - (char *)prec);
    prt->papFldDes[scalerRecordNM39]->offset = (unsigned short)((char *)&prec->nm39 - (char *)prec);
    prt->papFldDes[scalerRecordNM40]->offset = (unsigned short)((char *)&prec->nm40 - (char *)prec);
    prt->papFldDes[scalerRecordNM41]->offset = (unsigned short)((char *)&prec->nm41 - (char *)prec);
    prt->papFldDes[scalerRecordNM42]->offset = (unsigned short)((char *)&prec->nm42 - (char *)prec);
    prt->papFldDes[scalerRecordNM43]->offset = (unsigned short)((char *)&prec->nm43 - (char *)prec);
    prt->papFldDes[scalerRecordNM44]->offset = (unsigned short)((char *)&prec->nm44 - (char *)prec);
    prt->papFldDes[scalerRecordNM45]->offset = (unsigned short)((char *)&prec->nm45 - (char *)prec);
    prt->papFldDes[scalerRecordNM46]->offset = (unsigned short)((char *)&prec->nm46 - (char *)prec);
    prt->papFldDes[scalerRecordNM47]->offset = (unsigned short)((char *)&prec->nm47 - (char *)prec);
    prt->papFldDes[scalerRecordNM48]->offset = (unsigned short)((char *)&prec->nm48 - (char *)prec);
    prt->papFldDes[scalerRecordNM49]->offset = (unsigned short)((char *)&prec->nm49 - (char *)prec);
    prt->papFldDes[scalerRecordNM50]->offset = (unsigned short)((char *)&prec->nm50 - (char *)prec);
    prt->papFldDes[scalerRecordNM51]->offset = (unsigned short)((char *)&prec->nm51 - (char *)prec);
    prt->papFldDes[scalerRecordNM52]->offset = (unsigned short)((char *)&prec->nm52 - (char *)prec);
    prt->papFldDes[scalerRecordNM53]->offset = (unsigned short)((char *)&prec->nm53 - (char *)prec);
    prt->papFldDes[scalerRecordNM54]->offset = (unsigned short)((char *)&prec->nm54 - (char *)prec);
    prt->papFldDes[scalerRecordNM55]->offset = (unsigned short)((char *)&prec->nm55 - (char *)prec);
    prt->papFldDes[scalerRecordNM56]->offset = (unsigned short)((char *)&prec->nm56 - (char *)prec);
    prt->papFldDes[scalerRecordNM57]->offset = (unsigned short)((char *)&prec->nm57 - (char *)prec);
    prt->papFldDes[scalerRecordNM58]->offset = (unsigned short)((char *)&prec->nm58 - (char *)prec);
    prt->papFldDes[scalerRecordNM59]->offset = (unsigned short)((char *)&prec->nm59 - (char *)prec);
    prt->papFldDes[scalerRecordNM60]->offset = (unsigned short)((char *)&prec->nm60 - (char *)prec);
    prt->papFldDes[scalerRecordNM61]->offset = (unsigned short)((char *)&prec->nm61 - (char *)prec);
    prt->papFldDes[scalerRecordNM62]->offset = (unsigned short)((char *)&prec->nm62 - (char *)prec);
    prt->papFldDes[scalerRecordNM63]->offset = (unsigned short)((char *)&prec->nm63 - (char *)prec);
    prt->papFldDes[scalerRecordNM64]->offset = (unsigned short)((char *)&prec->nm64 - (char *)prec);
    prt->papFldDes[scalerRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[scalerRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[scalerRecordCOUT]->offset = (unsigned short)((char *)&prec->cout - (char *)prec);
    prt->papFldDes[scalerRecordCOUTP]->offset = (unsigned short)((char *)&prec->coutp - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(scalerRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_scalerRecord_H */
