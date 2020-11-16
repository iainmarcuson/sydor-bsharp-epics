/* timestampRecord.h generated from timestampRecord.dbd */

#ifndef INC_timestampRecord_H
#define INC_timestampRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    timestampTST_YY_MM_DD_HH_MM_SS  /* YY/MM/DD HH:MM:SS */,
    timestampTST_MM_DD_YY_HH_MM_SS  /* MM/DD/YY HH:MM:SS */,
    timestampTST_MM_DD_HH_MM_SS_YY  /* Mon DD HH:MM:SS YY */,
    timestampTST_MM_DD_HH_MM_SS     /* Mon DD HH:MM:SS */,
    timestampTST_HH_MM_SS           /* HH:MM:SS */,
    timestampTST_HH_MM              /* HH:MM */,
    timestampTST_DD_MM_YY_HH_MM_SS  /* DD/MM/YY HH:MM:SS */,
    timestampTST_DD_MM_HH_MM_SS_YY  /* DD Mon HH:MM:SS YY */,
    timestampTST_VMS                /* DD-Mon-YYYY HH:MM:SS */,
    timestampTST_MM_DD_YYYY         /* Mon DD, YYYY HH:MM:SS.ns */,
    timestampTST_MM_DD_YY           /* MM/DD/YY HH:MM:SS.ns */
} timestampTST;
#define timestampTST_NUM_CHOICES 11

typedef struct timestampRecord {
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
    char                val[40];    /* Current Value */
    char                oval[40];   /* Previous Value */
    epicsUInt32         rval;       /* Current Raw Value */
    epicsEnum16         tst;        /* Time Stamp Type */
} timestampRecord;

typedef enum {
	timestampRecordNAME = 0,
	timestampRecordDESC = 1,
	timestampRecordASG = 2,
	timestampRecordSCAN = 3,
	timestampRecordPINI = 4,
	timestampRecordPHAS = 5,
	timestampRecordEVNT = 6,
	timestampRecordTSE = 7,
	timestampRecordTSEL = 8,
	timestampRecordDTYP = 9,
	timestampRecordDISV = 10,
	timestampRecordDISA = 11,
	timestampRecordSDIS = 12,
	timestampRecordMLOK = 13,
	timestampRecordMLIS = 14,
	timestampRecordDISP = 15,
	timestampRecordPROC = 16,
	timestampRecordSTAT = 17,
	timestampRecordSEVR = 18,
	timestampRecordNSTA = 19,
	timestampRecordNSEV = 20,
	timestampRecordACKS = 21,
	timestampRecordACKT = 22,
	timestampRecordDISS = 23,
	timestampRecordLCNT = 24,
	timestampRecordPACT = 25,
	timestampRecordPUTF = 26,
	timestampRecordRPRO = 27,
	timestampRecordASP = 28,
	timestampRecordPPN = 29,
	timestampRecordPPNR = 30,
	timestampRecordSPVT = 31,
	timestampRecordRSET = 32,
	timestampRecordDSET = 33,
	timestampRecordDPVT = 34,
	timestampRecordRDES = 35,
	timestampRecordLSET = 36,
	timestampRecordPRIO = 37,
	timestampRecordTPRO = 38,
	timestampRecordBKPT = 39,
	timestampRecordUDF = 40,
	timestampRecordUDFS = 41,
	timestampRecordTIME = 42,
	timestampRecordFLNK = 43,
	timestampRecordVAL = 44,
	timestampRecordOVAL = 45,
	timestampRecordRVAL = 46,
	timestampRecordTST = 47
} timestampFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int timestampRecordSizeOffset(dbRecordType *prt)
{
    timestampRecord *prec = 0;

    assert(prt->no_fields == 48);
    prt->papFldDes[timestampRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[timestampRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[timestampRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[timestampRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[timestampRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[timestampRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[timestampRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[timestampRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[timestampRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[timestampRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[timestampRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[timestampRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[timestampRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[timestampRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[timestampRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[timestampRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[timestampRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[timestampRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[timestampRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[timestampRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[timestampRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[timestampRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[timestampRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[timestampRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[timestampRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[timestampRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[timestampRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[timestampRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[timestampRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[timestampRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[timestampRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[timestampRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[timestampRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[timestampRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[timestampRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[timestampRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[timestampRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[timestampRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[timestampRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[timestampRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[timestampRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[timestampRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[timestampRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[timestampRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[timestampRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[timestampRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[timestampRecordRVAL]->size = sizeof(prec->rval);
    prt->papFldDes[timestampRecordTST]->size = sizeof(prec->tst);
    prt->papFldDes[timestampRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[timestampRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[timestampRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[timestampRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[timestampRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[timestampRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[timestampRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[timestampRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[timestampRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[timestampRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[timestampRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[timestampRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[timestampRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[timestampRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[timestampRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[timestampRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[timestampRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[timestampRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[timestampRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[timestampRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[timestampRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[timestampRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[timestampRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[timestampRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[timestampRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[timestampRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[timestampRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[timestampRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[timestampRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[timestampRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[timestampRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[timestampRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[timestampRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[timestampRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[timestampRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[timestampRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[timestampRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[timestampRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[timestampRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[timestampRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[timestampRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[timestampRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[timestampRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[timestampRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[timestampRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[timestampRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[timestampRecordRVAL]->offset = (unsigned short)((char *)&prec->rval - (char *)prec);
    prt->papFldDes[timestampRecordTST]->offset = (unsigned short)((char *)&prec->tst - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(timestampRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_timestampRecord_H */
