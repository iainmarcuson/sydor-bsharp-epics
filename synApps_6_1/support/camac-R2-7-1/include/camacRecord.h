/* camacRecord.h generated from camacRecord.dbd */

#ifndef INC_camacRecord_H
#define INC_camacRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    camacCCMD_None                  /* None */,
    camacCCMD_Clear_Inhibit         /* Clear Inhibit */,
    camacCCMD_Set_Inhibit           /* Set Inhibit */,
    camacCCMD_Clear__C_             /* Clear (C) */,
    camacCCMD_Initialize__Z_        /* Initialize (Z) */
} camacCCMD;
#define camacCCMD_NUM_CHOICES 5

typedef enum {
    camacTMOD_Single                /* Single */,
    camacTMOD_Q_Stop                /* Q Stop */,
    camacTMOD_Q_Repeat              /* Q Repeat */,
    camacTMOD_Q_Scan                /* Q Scan */
} camacTMOD;
#define camacTMOD_NUM_CHOICES 4

typedef struct camacRecord {
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
    epicsInt32          val;        /* Current value */
    void *bptr;                     /* Buffer Pointer */
    epicsInt32          q;          /* Q  response */
    epicsInt32          x;          /* X  response */
    epicsInt32          inhb;       /* Inhibit status */
    epicsInt32          b;          /* Branch */
    epicsInt32          c;          /* Crate */
    epicsInt32          n;          /* Station */
    epicsInt32          a;          /* Subaddress */
    epicsInt32          f;          /* Function */
    epicsEnum16         tmod;       /* Transfer mode */
    epicsInt32          nmax;       /* Max. number of values */
    epicsInt32          nuse;       /* Number of values to R/W */
    epicsInt32          nact;       /* Actual number of values */
    epicsEnum16         ccmd;       /* Crate command */
} camacRecord;

typedef enum {
	camacRecordNAME = 0,
	camacRecordDESC = 1,
	camacRecordASG = 2,
	camacRecordSCAN = 3,
	camacRecordPINI = 4,
	camacRecordPHAS = 5,
	camacRecordEVNT = 6,
	camacRecordTSE = 7,
	camacRecordTSEL = 8,
	camacRecordDTYP = 9,
	camacRecordDISV = 10,
	camacRecordDISA = 11,
	camacRecordSDIS = 12,
	camacRecordMLOK = 13,
	camacRecordMLIS = 14,
	camacRecordDISP = 15,
	camacRecordPROC = 16,
	camacRecordSTAT = 17,
	camacRecordSEVR = 18,
	camacRecordNSTA = 19,
	camacRecordNSEV = 20,
	camacRecordACKS = 21,
	camacRecordACKT = 22,
	camacRecordDISS = 23,
	camacRecordLCNT = 24,
	camacRecordPACT = 25,
	camacRecordPUTF = 26,
	camacRecordRPRO = 27,
	camacRecordASP = 28,
	camacRecordPPN = 29,
	camacRecordPPNR = 30,
	camacRecordSPVT = 31,
	camacRecordRSET = 32,
	camacRecordDSET = 33,
	camacRecordDPVT = 34,
	camacRecordRDES = 35,
	camacRecordLSET = 36,
	camacRecordPRIO = 37,
	camacRecordTPRO = 38,
	camacRecordBKPT = 39,
	camacRecordUDF = 40,
	camacRecordUDFS = 41,
	camacRecordTIME = 42,
	camacRecordFLNK = 43,
	camacRecordVAL = 44,
	camacRecordBPTR = 45,
	camacRecordQ = 46,
	camacRecordX = 47,
	camacRecordINHB = 48,
	camacRecordB = 49,
	camacRecordC = 50,
	camacRecordN = 51,
	camacRecordA = 52,
	camacRecordF = 53,
	camacRecordTMOD = 54,
	camacRecordNMAX = 55,
	camacRecordNUSE = 56,
	camacRecordNACT = 57,
	camacRecordCCMD = 58
} camacFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int camacRecordSizeOffset(dbRecordType *prt)
{
    camacRecord *prec = 0;

    assert(prt->no_fields == 59);
    prt->papFldDes[camacRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[camacRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[camacRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[camacRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[camacRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[camacRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[camacRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[camacRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[camacRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[camacRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[camacRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[camacRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[camacRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[camacRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[camacRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[camacRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[camacRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[camacRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[camacRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[camacRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[camacRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[camacRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[camacRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[camacRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[camacRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[camacRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[camacRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[camacRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[camacRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[camacRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[camacRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[camacRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[camacRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[camacRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[camacRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[camacRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[camacRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[camacRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[camacRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[camacRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[camacRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[camacRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[camacRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[camacRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[camacRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[camacRecordBPTR]->size = sizeof(prec->bptr);
    prt->papFldDes[camacRecordQ]->size = sizeof(prec->q);
    prt->papFldDes[camacRecordX]->size = sizeof(prec->x);
    prt->papFldDes[camacRecordINHB]->size = sizeof(prec->inhb);
    prt->papFldDes[camacRecordB]->size = sizeof(prec->b);
    prt->papFldDes[camacRecordC]->size = sizeof(prec->c);
    prt->papFldDes[camacRecordN]->size = sizeof(prec->n);
    prt->papFldDes[camacRecordA]->size = sizeof(prec->a);
    prt->papFldDes[camacRecordF]->size = sizeof(prec->f);
    prt->papFldDes[camacRecordTMOD]->size = sizeof(prec->tmod);
    prt->papFldDes[camacRecordNMAX]->size = sizeof(prec->nmax);
    prt->papFldDes[camacRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[camacRecordNACT]->size = sizeof(prec->nact);
    prt->papFldDes[camacRecordCCMD]->size = sizeof(prec->ccmd);
    prt->papFldDes[camacRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[camacRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[camacRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[camacRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[camacRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[camacRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[camacRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[camacRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[camacRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[camacRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[camacRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[camacRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[camacRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[camacRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[camacRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[camacRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[camacRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[camacRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[camacRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[camacRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[camacRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[camacRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[camacRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[camacRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[camacRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[camacRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[camacRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[camacRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[camacRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[camacRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[camacRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[camacRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[camacRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[camacRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[camacRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[camacRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[camacRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[camacRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[camacRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[camacRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[camacRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[camacRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[camacRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[camacRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[camacRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[camacRecordBPTR]->offset = (unsigned short)((char *)&prec->bptr - (char *)prec);
    prt->papFldDes[camacRecordQ]->offset = (unsigned short)((char *)&prec->q - (char *)prec);
    prt->papFldDes[camacRecordX]->offset = (unsigned short)((char *)&prec->x - (char *)prec);
    prt->papFldDes[camacRecordINHB]->offset = (unsigned short)((char *)&prec->inhb - (char *)prec);
    prt->papFldDes[camacRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[camacRecordC]->offset = (unsigned short)((char *)&prec->c - (char *)prec);
    prt->papFldDes[camacRecordN]->offset = (unsigned short)((char *)&prec->n - (char *)prec);
    prt->papFldDes[camacRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[camacRecordF]->offset = (unsigned short)((char *)&prec->f - (char *)prec);
    prt->papFldDes[camacRecordTMOD]->offset = (unsigned short)((char *)&prec->tmod - (char *)prec);
    prt->papFldDes[camacRecordNMAX]->offset = (unsigned short)((char *)&prec->nmax - (char *)prec);
    prt->papFldDes[camacRecordNUSE]->offset = (unsigned short)((char *)&prec->nuse - (char *)prec);
    prt->papFldDes[camacRecordNACT]->offset = (unsigned short)((char *)&prec->nact - (char *)prec);
    prt->papFldDes[camacRecordCCMD]->offset = (unsigned short)((char *)&prec->ccmd - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(camacRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_camacRecord_H */
