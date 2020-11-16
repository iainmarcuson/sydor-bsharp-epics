/* luascriptRecord.h generated from luascriptRecord.dbd */

#ifndef INC_luascriptRecord_H
#define INC_luascriptRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    luascriptOOPT_Every_Time        /* Every Time */,
    luascriptOOPT_On_Change         /* On Change */,
    luascriptOOPT_When_Zero         /* When Zero */,
    luascriptOOPT_When_Non_zero     /* When Non-zero */,
    luascriptOOPT_Transition_To_Zero /* Transition To Zero */,
    luascriptOOPT_Transition_To_Non_zero /* Transition To Non-zero */,
    luascriptOOPT_Never             /* Never */
} luascriptOOPT;
#define luascriptOOPT_NUM_CHOICES 7

typedef enum {
    luascriptRELO_NewFile           /* Every New File */,
    luascriptRELO_NewFunction       /* Every New Change */,
    luascriptRELO_Always            /* Every Processing */
} luascriptRELO;
#define luascriptRELO_NUM_CHOICES 3

typedef enum {
    luascriptSYNC_Synchronous       /* Sync */,
    luascriptSYNC_Asynchronous      /* Async */
} luascriptSYNC;
#define luascriptSYNC_NUM_CHOICES 2

typedef enum {
    luascriptWAIT_NoWait            /* NoWait */,
    luascriptWAIT_Wait              /* Wait */
} luascriptWAIT;
#define luascriptWAIT_NUM_CHOICES 2

typedef enum {
    luascriptINAV_EXT_NC            /* Ext PV NC */,
    luascriptINAV_EXT               /* Ext PV OK */,
    luascriptINAV_LOC               /* Local PV */,
    luascriptINAV_CON               /* Constant */
} luascriptINAV;
#define luascriptINAV_NUM_CHOICES 4

typedef struct luascriptRecord {
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
    void* state;                    /* Lua State */
    void *rpvt;                     /* Record Private */
    epicsEnum16         sync;       /* Sync/Async processing */
    epicsEnum16         relo;       /* When to reload state? */
    epicsInt16          frld;       /* Force Reload */
    char                err[200];   /* Last Error Msg */
    char                code[121];  /* LUA Code */
    char* pcode;                    /* Previous CODE */
    epicsEnum16         oopt;       /* Output Execute Opt */
    epicsEnum16         wait;       /* Wait for completion? */
    DBLINK              inpa;       /* Input A */
    DBLINK              inpb;       /* Input B */
    DBLINK              inpc;       /* Input C */
    DBLINK              inpd;       /* Input D */
    DBLINK              inpe;       /* Input E */
    DBLINK              inpf;       /* Input F */
    DBLINK              inpg;       /* Input G */
    DBLINK              inph;       /* Input H */
    DBLINK              inpi;       /* Input I */
    DBLINK              inpj;       /* Input J */
    DBLINK              inaa;       /* String input AA */
    DBLINK              inbb;       /* String input BB */
    DBLINK              incc;       /* String input CC */
    DBLINK              indd;       /* String input DD */
    DBLINK              inee;       /* String input EE */
    DBLINK              inff;       /* String input FF */
    DBLINK              ingg;       /* String input GG */
    DBLINK              inhh;       /* String input HH */
    DBLINK              inii;       /* String input II */
    DBLINK              injj;       /* String input JJ */
    epicsEnum16         inav;       /* INPA PV Status */
    epicsEnum16         inbv;       /* INPB PV Status */
    epicsEnum16         incv;       /* INPC PV Status */
    epicsEnum16         indv;       /* INPD PV Status */
    epicsEnum16         inev;       /* INPE PV Status */
    epicsEnum16         infv;       /* INPF PV Status */
    epicsEnum16         ingv;       /* INPG PV Status */
    epicsEnum16         inhv;       /* INPH PV Status */
    epicsEnum16         iniv;       /* INPI PV Status */
    epicsEnum16         injv;       /* INPJ PV Status */
    epicsEnum16         iaav;       /* INAA PV Status */
    epicsEnum16         ibbv;       /* INBB PV Status */
    epicsEnum16         iccv;       /* INCC PV Status */
    epicsEnum16         iddv;       /* INDD PV Status */
    epicsEnum16         ieev;       /* INEE PV Status */
    epicsEnum16         iffv;       /* INFF PV Status */
    epicsEnum16         iggv;       /* INGG PV Status */
    epicsEnum16         ihhv;       /* INHH PV Status */
    epicsEnum16         iiiv;       /* INII PV Status */
    epicsEnum16         ijjv;       /* INJJ PV Status */
    epicsEnum16         outv;       /* OUT PV Status */
    char                adsc[20];   /* Input A Description */
    char                bdsc[20];   /* Input B Description */
    char                cdsc[20];   /* Input C Description */
    char                ddsc[20];   /* Input D Description */
    char                edsc[20];   /* Input E Description */
    char                fdsc[20];   /* Input F Description */
    char                gdsc[20];   /* Input G Description */
    char                hdsc[20];   /* Input H Description */
    char                idsc[20];   /* Input I Description */
    char                jdsc[20];   /* Input J Description */
    char                aadn[20];   /* Input AA Description */
    char                bbdn[20];   /* Input BB Description */
    char                ccdn[20];   /* Input CC Description */
    char                dddn[20];   /* Input DD Description */
    char                eedn[20];   /* Input EE Description */
    char                ffdn[20];   /* Input FF Description */
    char                ggdn[20];   /* Input GG Description */
    char                hhdn[20];   /* Input HH Description */
    char                iidn[20];   /* Input II Description */
    char                jjdn[20];   /* Input JJ Description */
    epicsFloat64        a;          /* Value of Input A */
    epicsFloat64        b;          /* Value of Input B */
    epicsFloat64        c;          /* Value of Input C */
    epicsFloat64        d;          /* Value of Input D */
    epicsFloat64        e;          /* Value of Input E */
    epicsFloat64        f;          /* Value of Input F */
    epicsFloat64        g;          /* Value of Input G */
    epicsFloat64        h;          /* Value of Input H */
    epicsFloat64        i;          /* Value of Input I */
    epicsFloat64        j;          /* Value of Input J */
    char                aa[40];     /* Value of string input AA */
    char                bb[40];     /* Value of string input BB */
    char                cc[40];     /* Value of string input CC */
    char                dd[40];     /* Value of string input DD */
    char                ee[40];     /* Value of string input EE */
    char                ff[40];     /* Value of string input FF */
    char                gg[40];     /* Value of string input GG */
    char                hh[40];     /* Value of string input HH */
    char                ii[40];     /* Value of string input II */
    char                jj[40];     /* Value of string input JJ */
    epicsFloat64        pa;         /* Prev Value of A */
    epicsFloat64        pb;         /* Prev Value of B */
    epicsFloat64        pc;         /* Prev Value of C */
    epicsFloat64        pd;         /* Prev Value of D */
    epicsFloat64        pe;         /* Prev Value of E */
    epicsFloat64        pf;         /* Prev Value of F */
    epicsFloat64        pg;         /* Prev Value of G */
    epicsFloat64        ph;         /* Prev Value of H */
    epicsFloat64        pi;         /* Prev Value of I */
    epicsFloat64        pj;         /* Prev Value of J */
    char *paa;                      /* Prev Value of AA */
    char *pbb;                      /* Prev Value of BB */
    char *pcc;                      /* Prev Value of CC */
    char *pdd;                      /* Prev Value of DD */
    char *pee;                      /* Prev Value of EE */
    char *pff;                      /* Prev Value of FF */
    char *pgg;                      /* Prev Value of GG */
    char *phh;                      /* Prev Value of HH */
    char *pii;                      /* Prev Value of II */
    char *pjj;                      /* Prev Value of JJ */
    DBLINK              out;        /* Output Link */
    epicsFloat64        val;        /* Result */
    char                sval[40];   /* String result 1 */
    epicsFloat64        pval;       /* Previous Value */
    char                psvl[40];   /* Previous string result */
    epicsFloat64        mdel;       /* Monitor Deadband */
    epicsInt16          prec;       /* Display Precision */
} luascriptRecord;

typedef enum {
	luascriptRecordNAME = 0,
	luascriptRecordDESC = 1,
	luascriptRecordASG = 2,
	luascriptRecordSCAN = 3,
	luascriptRecordPINI = 4,
	luascriptRecordPHAS = 5,
	luascriptRecordEVNT = 6,
	luascriptRecordTSE = 7,
	luascriptRecordTSEL = 8,
	luascriptRecordDTYP = 9,
	luascriptRecordDISV = 10,
	luascriptRecordDISA = 11,
	luascriptRecordSDIS = 12,
	luascriptRecordMLOK = 13,
	luascriptRecordMLIS = 14,
	luascriptRecordDISP = 15,
	luascriptRecordPROC = 16,
	luascriptRecordSTAT = 17,
	luascriptRecordSEVR = 18,
	luascriptRecordNSTA = 19,
	luascriptRecordNSEV = 20,
	luascriptRecordACKS = 21,
	luascriptRecordACKT = 22,
	luascriptRecordDISS = 23,
	luascriptRecordLCNT = 24,
	luascriptRecordPACT = 25,
	luascriptRecordPUTF = 26,
	luascriptRecordRPRO = 27,
	luascriptRecordASP = 28,
	luascriptRecordPPN = 29,
	luascriptRecordPPNR = 30,
	luascriptRecordSPVT = 31,
	luascriptRecordRSET = 32,
	luascriptRecordDSET = 33,
	luascriptRecordDPVT = 34,
	luascriptRecordRDES = 35,
	luascriptRecordLSET = 36,
	luascriptRecordPRIO = 37,
	luascriptRecordTPRO = 38,
	luascriptRecordBKPT = 39,
	luascriptRecordUDF = 40,
	luascriptRecordUDFS = 41,
	luascriptRecordTIME = 42,
	luascriptRecordFLNK = 43,
	luascriptRecordSTATE = 44,
	luascriptRecordRPVT = 45,
	luascriptRecordSYNC = 46,
	luascriptRecordRELO = 47,
	luascriptRecordFRLD = 48,
	luascriptRecordERR = 49,
	luascriptRecordCODE = 50,
	luascriptRecordPCODE = 51,
	luascriptRecordOOPT = 52,
	luascriptRecordWAIT = 53,
	luascriptRecordINPA = 54,
	luascriptRecordINPB = 55,
	luascriptRecordINPC = 56,
	luascriptRecordINPD = 57,
	luascriptRecordINPE = 58,
	luascriptRecordINPF = 59,
	luascriptRecordINPG = 60,
	luascriptRecordINPH = 61,
	luascriptRecordINPI = 62,
	luascriptRecordINPJ = 63,
	luascriptRecordINAA = 64,
	luascriptRecordINBB = 65,
	luascriptRecordINCC = 66,
	luascriptRecordINDD = 67,
	luascriptRecordINEE = 68,
	luascriptRecordINFF = 69,
	luascriptRecordINGG = 70,
	luascriptRecordINHH = 71,
	luascriptRecordINII = 72,
	luascriptRecordINJJ = 73,
	luascriptRecordINAV = 74,
	luascriptRecordINBV = 75,
	luascriptRecordINCV = 76,
	luascriptRecordINDV = 77,
	luascriptRecordINEV = 78,
	luascriptRecordINFV = 79,
	luascriptRecordINGV = 80,
	luascriptRecordINHV = 81,
	luascriptRecordINIV = 82,
	luascriptRecordINJV = 83,
	luascriptRecordIAAV = 84,
	luascriptRecordIBBV = 85,
	luascriptRecordICCV = 86,
	luascriptRecordIDDV = 87,
	luascriptRecordIEEV = 88,
	luascriptRecordIFFV = 89,
	luascriptRecordIGGV = 90,
	luascriptRecordIHHV = 91,
	luascriptRecordIIIV = 92,
	luascriptRecordIJJV = 93,
	luascriptRecordOUTV = 94,
	luascriptRecordADSC = 95,
	luascriptRecordBDSC = 96,
	luascriptRecordCDSC = 97,
	luascriptRecordDDSC = 98,
	luascriptRecordEDSC = 99,
	luascriptRecordFDSC = 100,
	luascriptRecordGDSC = 101,
	luascriptRecordHDSC = 102,
	luascriptRecordIDSC = 103,
	luascriptRecordJDSC = 104,
	luascriptRecordAADN = 105,
	luascriptRecordBBDN = 106,
	luascriptRecordCCDN = 107,
	luascriptRecordDDDN = 108,
	luascriptRecordEEDN = 109,
	luascriptRecordFFDN = 110,
	luascriptRecordGGDN = 111,
	luascriptRecordHHDN = 112,
	luascriptRecordIIDN = 113,
	luascriptRecordJJDN = 114,
	luascriptRecordA = 115,
	luascriptRecordB = 116,
	luascriptRecordC = 117,
	luascriptRecordD = 118,
	luascriptRecordE = 119,
	luascriptRecordF = 120,
	luascriptRecordG = 121,
	luascriptRecordH = 122,
	luascriptRecordI = 123,
	luascriptRecordJ = 124,
	luascriptRecordAA = 125,
	luascriptRecordBB = 126,
	luascriptRecordCC = 127,
	luascriptRecordDD = 128,
	luascriptRecordEE = 129,
	luascriptRecordFF = 130,
	luascriptRecordGG = 131,
	luascriptRecordHH = 132,
	luascriptRecordII = 133,
	luascriptRecordJJ = 134,
	luascriptRecordPA = 135,
	luascriptRecordPB = 136,
	luascriptRecordPC = 137,
	luascriptRecordPD = 138,
	luascriptRecordPE = 139,
	luascriptRecordPF = 140,
	luascriptRecordPG = 141,
	luascriptRecordPH = 142,
	luascriptRecordPI = 143,
	luascriptRecordPJ = 144,
	luascriptRecordPAA = 145,
	luascriptRecordPBB = 146,
	luascriptRecordPCC = 147,
	luascriptRecordPDD = 148,
	luascriptRecordPEE = 149,
	luascriptRecordPFF = 150,
	luascriptRecordPGG = 151,
	luascriptRecordPHH = 152,
	luascriptRecordPII = 153,
	luascriptRecordPJJ = 154,
	luascriptRecordOUT = 155,
	luascriptRecordVAL = 156,
	luascriptRecordSVAL = 157,
	luascriptRecordPVAL = 158,
	luascriptRecordPSVL = 159,
	luascriptRecordMDEL = 160,
	luascriptRecordPREC = 161
} luascriptFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int luascriptRecordSizeOffset(dbRecordType *prt)
{
    luascriptRecord *prec = 0;

    assert(prt->no_fields == 162);
    prt->papFldDes[luascriptRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[luascriptRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[luascriptRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[luascriptRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[luascriptRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[luascriptRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[luascriptRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[luascriptRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[luascriptRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[luascriptRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[luascriptRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[luascriptRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[luascriptRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[luascriptRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[luascriptRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[luascriptRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[luascriptRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[luascriptRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[luascriptRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[luascriptRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[luascriptRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[luascriptRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[luascriptRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[luascriptRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[luascriptRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[luascriptRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[luascriptRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[luascriptRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[luascriptRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[luascriptRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[luascriptRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[luascriptRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[luascriptRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[luascriptRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[luascriptRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[luascriptRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[luascriptRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[luascriptRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[luascriptRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[luascriptRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[luascriptRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[luascriptRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[luascriptRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[luascriptRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[luascriptRecordSTATE]->size = sizeof(prec->state);
    prt->papFldDes[luascriptRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[luascriptRecordSYNC]->size = sizeof(prec->sync);
    prt->papFldDes[luascriptRecordRELO]->size = sizeof(prec->relo);
    prt->papFldDes[luascriptRecordFRLD]->size = sizeof(prec->frld);
    prt->papFldDes[luascriptRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[luascriptRecordCODE]->size = sizeof(prec->code);
    prt->papFldDes[luascriptRecordPCODE]->size = sizeof(prec->pcode);
    prt->papFldDes[luascriptRecordOOPT]->size = sizeof(prec->oopt);
    prt->papFldDes[luascriptRecordWAIT]->size = sizeof(prec->wait);
    prt->papFldDes[luascriptRecordINPA]->size = sizeof(prec->inpa);
    prt->papFldDes[luascriptRecordINPB]->size = sizeof(prec->inpb);
    prt->papFldDes[luascriptRecordINPC]->size = sizeof(prec->inpc);
    prt->papFldDes[luascriptRecordINPD]->size = sizeof(prec->inpd);
    prt->papFldDes[luascriptRecordINPE]->size = sizeof(prec->inpe);
    prt->papFldDes[luascriptRecordINPF]->size = sizeof(prec->inpf);
    prt->papFldDes[luascriptRecordINPG]->size = sizeof(prec->inpg);
    prt->papFldDes[luascriptRecordINPH]->size = sizeof(prec->inph);
    prt->papFldDes[luascriptRecordINPI]->size = sizeof(prec->inpi);
    prt->papFldDes[luascriptRecordINPJ]->size = sizeof(prec->inpj);
    prt->papFldDes[luascriptRecordINAA]->size = sizeof(prec->inaa);
    prt->papFldDes[luascriptRecordINBB]->size = sizeof(prec->inbb);
    prt->papFldDes[luascriptRecordINCC]->size = sizeof(prec->incc);
    prt->papFldDes[luascriptRecordINDD]->size = sizeof(prec->indd);
    prt->papFldDes[luascriptRecordINEE]->size = sizeof(prec->inee);
    prt->papFldDes[luascriptRecordINFF]->size = sizeof(prec->inff);
    prt->papFldDes[luascriptRecordINGG]->size = sizeof(prec->ingg);
    prt->papFldDes[luascriptRecordINHH]->size = sizeof(prec->inhh);
    prt->papFldDes[luascriptRecordINII]->size = sizeof(prec->inii);
    prt->papFldDes[luascriptRecordINJJ]->size = sizeof(prec->injj);
    prt->papFldDes[luascriptRecordINAV]->size = sizeof(prec->inav);
    prt->papFldDes[luascriptRecordINBV]->size = sizeof(prec->inbv);
    prt->papFldDes[luascriptRecordINCV]->size = sizeof(prec->incv);
    prt->papFldDes[luascriptRecordINDV]->size = sizeof(prec->indv);
    prt->papFldDes[luascriptRecordINEV]->size = sizeof(prec->inev);
    prt->papFldDes[luascriptRecordINFV]->size = sizeof(prec->infv);
    prt->papFldDes[luascriptRecordINGV]->size = sizeof(prec->ingv);
    prt->papFldDes[luascriptRecordINHV]->size = sizeof(prec->inhv);
    prt->papFldDes[luascriptRecordINIV]->size = sizeof(prec->iniv);
    prt->papFldDes[luascriptRecordINJV]->size = sizeof(prec->injv);
    prt->papFldDes[luascriptRecordIAAV]->size = sizeof(prec->iaav);
    prt->papFldDes[luascriptRecordIBBV]->size = sizeof(prec->ibbv);
    prt->papFldDes[luascriptRecordICCV]->size = sizeof(prec->iccv);
    prt->papFldDes[luascriptRecordIDDV]->size = sizeof(prec->iddv);
    prt->papFldDes[luascriptRecordIEEV]->size = sizeof(prec->ieev);
    prt->papFldDes[luascriptRecordIFFV]->size = sizeof(prec->iffv);
    prt->papFldDes[luascriptRecordIGGV]->size = sizeof(prec->iggv);
    prt->papFldDes[luascriptRecordIHHV]->size = sizeof(prec->ihhv);
    prt->papFldDes[luascriptRecordIIIV]->size = sizeof(prec->iiiv);
    prt->papFldDes[luascriptRecordIJJV]->size = sizeof(prec->ijjv);
    prt->papFldDes[luascriptRecordOUTV]->size = sizeof(prec->outv);
    prt->papFldDes[luascriptRecordADSC]->size = sizeof(prec->adsc);
    prt->papFldDes[luascriptRecordBDSC]->size = sizeof(prec->bdsc);
    prt->papFldDes[luascriptRecordCDSC]->size = sizeof(prec->cdsc);
    prt->papFldDes[luascriptRecordDDSC]->size = sizeof(prec->ddsc);
    prt->papFldDes[luascriptRecordEDSC]->size = sizeof(prec->edsc);
    prt->papFldDes[luascriptRecordFDSC]->size = sizeof(prec->fdsc);
    prt->papFldDes[luascriptRecordGDSC]->size = sizeof(prec->gdsc);
    prt->papFldDes[luascriptRecordHDSC]->size = sizeof(prec->hdsc);
    prt->papFldDes[luascriptRecordIDSC]->size = sizeof(prec->idsc);
    prt->papFldDes[luascriptRecordJDSC]->size = sizeof(prec->jdsc);
    prt->papFldDes[luascriptRecordAADN]->size = sizeof(prec->aadn);
    prt->papFldDes[luascriptRecordBBDN]->size = sizeof(prec->bbdn);
    prt->papFldDes[luascriptRecordCCDN]->size = sizeof(prec->ccdn);
    prt->papFldDes[luascriptRecordDDDN]->size = sizeof(prec->dddn);
    prt->papFldDes[luascriptRecordEEDN]->size = sizeof(prec->eedn);
    prt->papFldDes[luascriptRecordFFDN]->size = sizeof(prec->ffdn);
    prt->papFldDes[luascriptRecordGGDN]->size = sizeof(prec->ggdn);
    prt->papFldDes[luascriptRecordHHDN]->size = sizeof(prec->hhdn);
    prt->papFldDes[luascriptRecordIIDN]->size = sizeof(prec->iidn);
    prt->papFldDes[luascriptRecordJJDN]->size = sizeof(prec->jjdn);
    prt->papFldDes[luascriptRecordA]->size = sizeof(prec->a);
    prt->papFldDes[luascriptRecordB]->size = sizeof(prec->b);
    prt->papFldDes[luascriptRecordC]->size = sizeof(prec->c);
    prt->papFldDes[luascriptRecordD]->size = sizeof(prec->d);
    prt->papFldDes[luascriptRecordE]->size = sizeof(prec->e);
    prt->papFldDes[luascriptRecordF]->size = sizeof(prec->f);
    prt->papFldDes[luascriptRecordG]->size = sizeof(prec->g);
    prt->papFldDes[luascriptRecordH]->size = sizeof(prec->h);
    prt->papFldDes[luascriptRecordI]->size = sizeof(prec->i);
    prt->papFldDes[luascriptRecordJ]->size = sizeof(prec->j);
    prt->papFldDes[luascriptRecordAA]->size = sizeof(prec->aa);
    prt->papFldDes[luascriptRecordBB]->size = sizeof(prec->bb);
    prt->papFldDes[luascriptRecordCC]->size = sizeof(prec->cc);
    prt->papFldDes[luascriptRecordDD]->size = sizeof(prec->dd);
    prt->papFldDes[luascriptRecordEE]->size = sizeof(prec->ee);
    prt->papFldDes[luascriptRecordFF]->size = sizeof(prec->ff);
    prt->papFldDes[luascriptRecordGG]->size = sizeof(prec->gg);
    prt->papFldDes[luascriptRecordHH]->size = sizeof(prec->hh);
    prt->papFldDes[luascriptRecordII]->size = sizeof(prec->ii);
    prt->papFldDes[luascriptRecordJJ]->size = sizeof(prec->jj);
    prt->papFldDes[luascriptRecordPA]->size = sizeof(prec->pa);
    prt->papFldDes[luascriptRecordPB]->size = sizeof(prec->pb);
    prt->papFldDes[luascriptRecordPC]->size = sizeof(prec->pc);
    prt->papFldDes[luascriptRecordPD]->size = sizeof(prec->pd);
    prt->papFldDes[luascriptRecordPE]->size = sizeof(prec->pe);
    prt->papFldDes[luascriptRecordPF]->size = sizeof(prec->pf);
    prt->papFldDes[luascriptRecordPG]->size = sizeof(prec->pg);
    prt->papFldDes[luascriptRecordPH]->size = sizeof(prec->ph);
    prt->papFldDes[luascriptRecordPI]->size = sizeof(prec->pi);
    prt->papFldDes[luascriptRecordPJ]->size = sizeof(prec->pj);
    prt->papFldDes[luascriptRecordPAA]->size = sizeof(prec->paa);
    prt->papFldDes[luascriptRecordPBB]->size = sizeof(prec->pbb);
    prt->papFldDes[luascriptRecordPCC]->size = sizeof(prec->pcc);
    prt->papFldDes[luascriptRecordPDD]->size = sizeof(prec->pdd);
    prt->papFldDes[luascriptRecordPEE]->size = sizeof(prec->pee);
    prt->papFldDes[luascriptRecordPFF]->size = sizeof(prec->pff);
    prt->papFldDes[luascriptRecordPGG]->size = sizeof(prec->pgg);
    prt->papFldDes[luascriptRecordPHH]->size = sizeof(prec->phh);
    prt->papFldDes[luascriptRecordPII]->size = sizeof(prec->pii);
    prt->papFldDes[luascriptRecordPJJ]->size = sizeof(prec->pjj);
    prt->papFldDes[luascriptRecordOUT]->size = sizeof(prec->out);
    prt->papFldDes[luascriptRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[luascriptRecordSVAL]->size = sizeof(prec->sval);
    prt->papFldDes[luascriptRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[luascriptRecordPSVL]->size = sizeof(prec->psvl);
    prt->papFldDes[luascriptRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[luascriptRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[luascriptRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[luascriptRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[luascriptRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[luascriptRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[luascriptRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[luascriptRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[luascriptRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[luascriptRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[luascriptRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[luascriptRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[luascriptRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[luascriptRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[luascriptRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[luascriptRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[luascriptRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[luascriptRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[luascriptRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[luascriptRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[luascriptRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[luascriptRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[luascriptRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[luascriptRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[luascriptRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[luascriptRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[luascriptRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[luascriptRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[luascriptRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[luascriptRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[luascriptRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[luascriptRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[luascriptRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[luascriptRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[luascriptRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[luascriptRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[luascriptRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[luascriptRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[luascriptRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[luascriptRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[luascriptRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[luascriptRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[luascriptRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[luascriptRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[luascriptRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[luascriptRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[luascriptRecordSTATE]->offset = (unsigned short)((char *)&prec->state - (char *)prec);
    prt->papFldDes[luascriptRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[luascriptRecordSYNC]->offset = (unsigned short)((char *)&prec->sync - (char *)prec);
    prt->papFldDes[luascriptRecordRELO]->offset = (unsigned short)((char *)&prec->relo - (char *)prec);
    prt->papFldDes[luascriptRecordFRLD]->offset = (unsigned short)((char *)&prec->frld - (char *)prec);
    prt->papFldDes[luascriptRecordERR]->offset = (unsigned short)((char *)&prec->err - (char *)prec);
    prt->papFldDes[luascriptRecordCODE]->offset = (unsigned short)((char *)&prec->code - (char *)prec);
    prt->papFldDes[luascriptRecordPCODE]->offset = (unsigned short)((char *)&prec->pcode - (char *)prec);
    prt->papFldDes[luascriptRecordOOPT]->offset = (unsigned short)((char *)&prec->oopt - (char *)prec);
    prt->papFldDes[luascriptRecordWAIT]->offset = (unsigned short)((char *)&prec->wait - (char *)prec);
    prt->papFldDes[luascriptRecordINPA]->offset = (unsigned short)((char *)&prec->inpa - (char *)prec);
    prt->papFldDes[luascriptRecordINPB]->offset = (unsigned short)((char *)&prec->inpb - (char *)prec);
    prt->papFldDes[luascriptRecordINPC]->offset = (unsigned short)((char *)&prec->inpc - (char *)prec);
    prt->papFldDes[luascriptRecordINPD]->offset = (unsigned short)((char *)&prec->inpd - (char *)prec);
    prt->papFldDes[luascriptRecordINPE]->offset = (unsigned short)((char *)&prec->inpe - (char *)prec);
    prt->papFldDes[luascriptRecordINPF]->offset = (unsigned short)((char *)&prec->inpf - (char *)prec);
    prt->papFldDes[luascriptRecordINPG]->offset = (unsigned short)((char *)&prec->inpg - (char *)prec);
    prt->papFldDes[luascriptRecordINPH]->offset = (unsigned short)((char *)&prec->inph - (char *)prec);
    prt->papFldDes[luascriptRecordINPI]->offset = (unsigned short)((char *)&prec->inpi - (char *)prec);
    prt->papFldDes[luascriptRecordINPJ]->offset = (unsigned short)((char *)&prec->inpj - (char *)prec);
    prt->papFldDes[luascriptRecordINAA]->offset = (unsigned short)((char *)&prec->inaa - (char *)prec);
    prt->papFldDes[luascriptRecordINBB]->offset = (unsigned short)((char *)&prec->inbb - (char *)prec);
    prt->papFldDes[luascriptRecordINCC]->offset = (unsigned short)((char *)&prec->incc - (char *)prec);
    prt->papFldDes[luascriptRecordINDD]->offset = (unsigned short)((char *)&prec->indd - (char *)prec);
    prt->papFldDes[luascriptRecordINEE]->offset = (unsigned short)((char *)&prec->inee - (char *)prec);
    prt->papFldDes[luascriptRecordINFF]->offset = (unsigned short)((char *)&prec->inff - (char *)prec);
    prt->papFldDes[luascriptRecordINGG]->offset = (unsigned short)((char *)&prec->ingg - (char *)prec);
    prt->papFldDes[luascriptRecordINHH]->offset = (unsigned short)((char *)&prec->inhh - (char *)prec);
    prt->papFldDes[luascriptRecordINII]->offset = (unsigned short)((char *)&prec->inii - (char *)prec);
    prt->papFldDes[luascriptRecordINJJ]->offset = (unsigned short)((char *)&prec->injj - (char *)prec);
    prt->papFldDes[luascriptRecordINAV]->offset = (unsigned short)((char *)&prec->inav - (char *)prec);
    prt->papFldDes[luascriptRecordINBV]->offset = (unsigned short)((char *)&prec->inbv - (char *)prec);
    prt->papFldDes[luascriptRecordINCV]->offset = (unsigned short)((char *)&prec->incv - (char *)prec);
    prt->papFldDes[luascriptRecordINDV]->offset = (unsigned short)((char *)&prec->indv - (char *)prec);
    prt->papFldDes[luascriptRecordINEV]->offset = (unsigned short)((char *)&prec->inev - (char *)prec);
    prt->papFldDes[luascriptRecordINFV]->offset = (unsigned short)((char *)&prec->infv - (char *)prec);
    prt->papFldDes[luascriptRecordINGV]->offset = (unsigned short)((char *)&prec->ingv - (char *)prec);
    prt->papFldDes[luascriptRecordINHV]->offset = (unsigned short)((char *)&prec->inhv - (char *)prec);
    prt->papFldDes[luascriptRecordINIV]->offset = (unsigned short)((char *)&prec->iniv - (char *)prec);
    prt->papFldDes[luascriptRecordINJV]->offset = (unsigned short)((char *)&prec->injv - (char *)prec);
    prt->papFldDes[luascriptRecordIAAV]->offset = (unsigned short)((char *)&prec->iaav - (char *)prec);
    prt->papFldDes[luascriptRecordIBBV]->offset = (unsigned short)((char *)&prec->ibbv - (char *)prec);
    prt->papFldDes[luascriptRecordICCV]->offset = (unsigned short)((char *)&prec->iccv - (char *)prec);
    prt->papFldDes[luascriptRecordIDDV]->offset = (unsigned short)((char *)&prec->iddv - (char *)prec);
    prt->papFldDes[luascriptRecordIEEV]->offset = (unsigned short)((char *)&prec->ieev - (char *)prec);
    prt->papFldDes[luascriptRecordIFFV]->offset = (unsigned short)((char *)&prec->iffv - (char *)prec);
    prt->papFldDes[luascriptRecordIGGV]->offset = (unsigned short)((char *)&prec->iggv - (char *)prec);
    prt->papFldDes[luascriptRecordIHHV]->offset = (unsigned short)((char *)&prec->ihhv - (char *)prec);
    prt->papFldDes[luascriptRecordIIIV]->offset = (unsigned short)((char *)&prec->iiiv - (char *)prec);
    prt->papFldDes[luascriptRecordIJJV]->offset = (unsigned short)((char *)&prec->ijjv - (char *)prec);
    prt->papFldDes[luascriptRecordOUTV]->offset = (unsigned short)((char *)&prec->outv - (char *)prec);
    prt->papFldDes[luascriptRecordADSC]->offset = (unsigned short)((char *)&prec->adsc - (char *)prec);
    prt->papFldDes[luascriptRecordBDSC]->offset = (unsigned short)((char *)&prec->bdsc - (char *)prec);
    prt->papFldDes[luascriptRecordCDSC]->offset = (unsigned short)((char *)&prec->cdsc - (char *)prec);
    prt->papFldDes[luascriptRecordDDSC]->offset = (unsigned short)((char *)&prec->ddsc - (char *)prec);
    prt->papFldDes[luascriptRecordEDSC]->offset = (unsigned short)((char *)&prec->edsc - (char *)prec);
    prt->papFldDes[luascriptRecordFDSC]->offset = (unsigned short)((char *)&prec->fdsc - (char *)prec);
    prt->papFldDes[luascriptRecordGDSC]->offset = (unsigned short)((char *)&prec->gdsc - (char *)prec);
    prt->papFldDes[luascriptRecordHDSC]->offset = (unsigned short)((char *)&prec->hdsc - (char *)prec);
    prt->papFldDes[luascriptRecordIDSC]->offset = (unsigned short)((char *)&prec->idsc - (char *)prec);
    prt->papFldDes[luascriptRecordJDSC]->offset = (unsigned short)((char *)&prec->jdsc - (char *)prec);
    prt->papFldDes[luascriptRecordAADN]->offset = (unsigned short)((char *)&prec->aadn - (char *)prec);
    prt->papFldDes[luascriptRecordBBDN]->offset = (unsigned short)((char *)&prec->bbdn - (char *)prec);
    prt->papFldDes[luascriptRecordCCDN]->offset = (unsigned short)((char *)&prec->ccdn - (char *)prec);
    prt->papFldDes[luascriptRecordDDDN]->offset = (unsigned short)((char *)&prec->dddn - (char *)prec);
    prt->papFldDes[luascriptRecordEEDN]->offset = (unsigned short)((char *)&prec->eedn - (char *)prec);
    prt->papFldDes[luascriptRecordFFDN]->offset = (unsigned short)((char *)&prec->ffdn - (char *)prec);
    prt->papFldDes[luascriptRecordGGDN]->offset = (unsigned short)((char *)&prec->ggdn - (char *)prec);
    prt->papFldDes[luascriptRecordHHDN]->offset = (unsigned short)((char *)&prec->hhdn - (char *)prec);
    prt->papFldDes[luascriptRecordIIDN]->offset = (unsigned short)((char *)&prec->iidn - (char *)prec);
    prt->papFldDes[luascriptRecordJJDN]->offset = (unsigned short)((char *)&prec->jjdn - (char *)prec);
    prt->papFldDes[luascriptRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[luascriptRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[luascriptRecordC]->offset = (unsigned short)((char *)&prec->c - (char *)prec);
    prt->papFldDes[luascriptRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[luascriptRecordE]->offset = (unsigned short)((char *)&prec->e - (char *)prec);
    prt->papFldDes[luascriptRecordF]->offset = (unsigned short)((char *)&prec->f - (char *)prec);
    prt->papFldDes[luascriptRecordG]->offset = (unsigned short)((char *)&prec->g - (char *)prec);
    prt->papFldDes[luascriptRecordH]->offset = (unsigned short)((char *)&prec->h - (char *)prec);
    prt->papFldDes[luascriptRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[luascriptRecordJ]->offset = (unsigned short)((char *)&prec->j - (char *)prec);
    prt->papFldDes[luascriptRecordAA]->offset = (unsigned short)((char *)&prec->aa - (char *)prec);
    prt->papFldDes[luascriptRecordBB]->offset = (unsigned short)((char *)&prec->bb - (char *)prec);
    prt->papFldDes[luascriptRecordCC]->offset = (unsigned short)((char *)&prec->cc - (char *)prec);
    prt->papFldDes[luascriptRecordDD]->offset = (unsigned short)((char *)&prec->dd - (char *)prec);
    prt->papFldDes[luascriptRecordEE]->offset = (unsigned short)((char *)&prec->ee - (char *)prec);
    prt->papFldDes[luascriptRecordFF]->offset = (unsigned short)((char *)&prec->ff - (char *)prec);
    prt->papFldDes[luascriptRecordGG]->offset = (unsigned short)((char *)&prec->gg - (char *)prec);
    prt->papFldDes[luascriptRecordHH]->offset = (unsigned short)((char *)&prec->hh - (char *)prec);
    prt->papFldDes[luascriptRecordII]->offset = (unsigned short)((char *)&prec->ii - (char *)prec);
    prt->papFldDes[luascriptRecordJJ]->offset = (unsigned short)((char *)&prec->jj - (char *)prec);
    prt->papFldDes[luascriptRecordPA]->offset = (unsigned short)((char *)&prec->pa - (char *)prec);
    prt->papFldDes[luascriptRecordPB]->offset = (unsigned short)((char *)&prec->pb - (char *)prec);
    prt->papFldDes[luascriptRecordPC]->offset = (unsigned short)((char *)&prec->pc - (char *)prec);
    prt->papFldDes[luascriptRecordPD]->offset = (unsigned short)((char *)&prec->pd - (char *)prec);
    prt->papFldDes[luascriptRecordPE]->offset = (unsigned short)((char *)&prec->pe - (char *)prec);
    prt->papFldDes[luascriptRecordPF]->offset = (unsigned short)((char *)&prec->pf - (char *)prec);
    prt->papFldDes[luascriptRecordPG]->offset = (unsigned short)((char *)&prec->pg - (char *)prec);
    prt->papFldDes[luascriptRecordPH]->offset = (unsigned short)((char *)&prec->ph - (char *)prec);
    prt->papFldDes[luascriptRecordPI]->offset = (unsigned short)((char *)&prec->pi - (char *)prec);
    prt->papFldDes[luascriptRecordPJ]->offset = (unsigned short)((char *)&prec->pj - (char *)prec);
    prt->papFldDes[luascriptRecordPAA]->offset = (unsigned short)((char *)&prec->paa - (char *)prec);
    prt->papFldDes[luascriptRecordPBB]->offset = (unsigned short)((char *)&prec->pbb - (char *)prec);
    prt->papFldDes[luascriptRecordPCC]->offset = (unsigned short)((char *)&prec->pcc - (char *)prec);
    prt->papFldDes[luascriptRecordPDD]->offset = (unsigned short)((char *)&prec->pdd - (char *)prec);
    prt->papFldDes[luascriptRecordPEE]->offset = (unsigned short)((char *)&prec->pee - (char *)prec);
    prt->papFldDes[luascriptRecordPFF]->offset = (unsigned short)((char *)&prec->pff - (char *)prec);
    prt->papFldDes[luascriptRecordPGG]->offset = (unsigned short)((char *)&prec->pgg - (char *)prec);
    prt->papFldDes[luascriptRecordPHH]->offset = (unsigned short)((char *)&prec->phh - (char *)prec);
    prt->papFldDes[luascriptRecordPII]->offset = (unsigned short)((char *)&prec->pii - (char *)prec);
    prt->papFldDes[luascriptRecordPJJ]->offset = (unsigned short)((char *)&prec->pjj - (char *)prec);
    prt->papFldDes[luascriptRecordOUT]->offset = (unsigned short)((char *)&prec->out - (char *)prec);
    prt->papFldDes[luascriptRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[luascriptRecordSVAL]->offset = (unsigned short)((char *)&prec->sval - (char *)prec);
    prt->papFldDes[luascriptRecordPVAL]->offset = (unsigned short)((char *)&prec->pval - (char *)prec);
    prt->papFldDes[luascriptRecordPSVL]->offset = (unsigned short)((char *)&prec->psvl - (char *)prec);
    prt->papFldDes[luascriptRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[luascriptRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(luascriptRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_luascriptRecord_H */
