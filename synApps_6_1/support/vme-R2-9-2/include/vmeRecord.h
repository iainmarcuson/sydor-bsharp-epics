/* vmeRecord.h generated from vmeRecord.dbd */

#ifndef INC_vmeRecord_H
#define INC_vmeRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    vmeDSIZ_D8                      /* D8 */,
    vmeDSIZ_D16                     /* D16 */,
    vmeDSIZ_D32                     /* D32 */
} vmeDSIZ;
#define vmeDSIZ_NUM_CHOICES 3

typedef enum {
    vmeAMOD_A16                     /* A16 */,
    vmeAMOD_A24                     /* A24 */,
    vmeAMOD_A32                     /* A32 */
} vmeAMOD;
#define vmeAMOD_NUM_CHOICES 3

typedef enum {
    vmeRDWT_Read                    /* Read */,
    vmeRDWT_Write                   /* Write */
} vmeRDWT;
#define vmeRDWT_NUM_CHOICES 2

typedef struct vmeRecord {
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
    epicsUInt8          sarr;       /* Status array */
    void *bptr;                     /* Buffer Pointer */
    void *sptr;                     /* Status Pointer */
    epicsUInt32         addr;       /* VME address (hex) */
    epicsEnum16         amod;       /* VME address mode */
    epicsEnum16         dsiz;       /* VME data size */
    epicsEnum16         rdwt;       /* Read/write */
    epicsInt32          nmax;       /* Max. number of values */
    epicsInt32          nuse;       /* Number of values to R/W */
    epicsInt32          ainc;       /* Address increment (1-4) */
} vmeRecord;

typedef enum {
	vmeRecordNAME = 0,
	vmeRecordDESC = 1,
	vmeRecordASG = 2,
	vmeRecordSCAN = 3,
	vmeRecordPINI = 4,
	vmeRecordPHAS = 5,
	vmeRecordEVNT = 6,
	vmeRecordTSE = 7,
	vmeRecordTSEL = 8,
	vmeRecordDTYP = 9,
	vmeRecordDISV = 10,
	vmeRecordDISA = 11,
	vmeRecordSDIS = 12,
	vmeRecordMLOK = 13,
	vmeRecordMLIS = 14,
	vmeRecordDISP = 15,
	vmeRecordPROC = 16,
	vmeRecordSTAT = 17,
	vmeRecordSEVR = 18,
	vmeRecordNSTA = 19,
	vmeRecordNSEV = 20,
	vmeRecordACKS = 21,
	vmeRecordACKT = 22,
	vmeRecordDISS = 23,
	vmeRecordLCNT = 24,
	vmeRecordPACT = 25,
	vmeRecordPUTF = 26,
	vmeRecordRPRO = 27,
	vmeRecordASP = 28,
	vmeRecordPPN = 29,
	vmeRecordPPNR = 30,
	vmeRecordSPVT = 31,
	vmeRecordRSET = 32,
	vmeRecordDSET = 33,
	vmeRecordDPVT = 34,
	vmeRecordRDES = 35,
	vmeRecordLSET = 36,
	vmeRecordPRIO = 37,
	vmeRecordTPRO = 38,
	vmeRecordBKPT = 39,
	vmeRecordUDF = 40,
	vmeRecordUDFS = 41,
	vmeRecordTIME = 42,
	vmeRecordFLNK = 43,
	vmeRecordVAL = 44,
	vmeRecordSARR = 45,
	vmeRecordBPTR = 46,
	vmeRecordSPTR = 47,
	vmeRecordADDR = 48,
	vmeRecordAMOD = 49,
	vmeRecordDSIZ = 50,
	vmeRecordRDWT = 51,
	vmeRecordNMAX = 52,
	vmeRecordNUSE = 53,
	vmeRecordAINC = 54
} vmeFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int vmeRecordSizeOffset(dbRecordType *prt)
{
    vmeRecord *prec = 0;

    assert(prt->no_fields == 55);
    prt->papFldDes[vmeRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[vmeRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[vmeRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[vmeRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[vmeRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[vmeRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[vmeRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[vmeRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[vmeRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[vmeRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[vmeRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[vmeRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[vmeRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[vmeRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[vmeRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[vmeRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[vmeRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[vmeRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[vmeRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[vmeRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[vmeRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[vmeRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[vmeRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[vmeRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[vmeRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[vmeRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[vmeRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[vmeRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[vmeRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[vmeRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[vmeRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[vmeRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[vmeRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[vmeRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[vmeRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[vmeRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[vmeRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[vmeRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[vmeRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[vmeRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[vmeRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[vmeRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[vmeRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[vmeRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[vmeRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[vmeRecordSARR]->size = sizeof(prec->sarr);
    prt->papFldDes[vmeRecordBPTR]->size = sizeof(prec->bptr);
    prt->papFldDes[vmeRecordSPTR]->size = sizeof(prec->sptr);
    prt->papFldDes[vmeRecordADDR]->size = sizeof(prec->addr);
    prt->papFldDes[vmeRecordAMOD]->size = sizeof(prec->amod);
    prt->papFldDes[vmeRecordDSIZ]->size = sizeof(prec->dsiz);
    prt->papFldDes[vmeRecordRDWT]->size = sizeof(prec->rdwt);
    prt->papFldDes[vmeRecordNMAX]->size = sizeof(prec->nmax);
    prt->papFldDes[vmeRecordNUSE]->size = sizeof(prec->nuse);
    prt->papFldDes[vmeRecordAINC]->size = sizeof(prec->ainc);
    prt->papFldDes[vmeRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[vmeRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[vmeRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[vmeRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[vmeRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[vmeRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[vmeRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[vmeRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[vmeRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[vmeRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[vmeRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[vmeRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[vmeRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[vmeRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[vmeRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[vmeRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[vmeRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[vmeRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[vmeRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[vmeRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[vmeRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[vmeRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[vmeRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[vmeRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[vmeRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[vmeRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[vmeRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[vmeRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[vmeRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[vmeRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[vmeRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[vmeRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[vmeRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[vmeRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[vmeRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[vmeRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[vmeRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[vmeRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[vmeRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[vmeRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[vmeRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[vmeRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[vmeRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[vmeRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[vmeRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[vmeRecordSARR]->offset = (unsigned short)((char *)&prec->sarr - (char *)prec);
    prt->papFldDes[vmeRecordBPTR]->offset = (unsigned short)((char *)&prec->bptr - (char *)prec);
    prt->papFldDes[vmeRecordSPTR]->offset = (unsigned short)((char *)&prec->sptr - (char *)prec);
    prt->papFldDes[vmeRecordADDR]->offset = (unsigned short)((char *)&prec->addr - (char *)prec);
    prt->papFldDes[vmeRecordAMOD]->offset = (unsigned short)((char *)&prec->amod - (char *)prec);
    prt->papFldDes[vmeRecordDSIZ]->offset = (unsigned short)((char *)&prec->dsiz - (char *)prec);
    prt->papFldDes[vmeRecordRDWT]->offset = (unsigned short)((char *)&prec->rdwt - (char *)prec);
    prt->papFldDes[vmeRecordNMAX]->offset = (unsigned short)((char *)&prec->nmax - (char *)prec);
    prt->papFldDes[vmeRecordNUSE]->offset = (unsigned short)((char *)&prec->nuse - (char *)prec);
    prt->papFldDes[vmeRecordAINC]->offset = (unsigned short)((char *)&prec->ainc - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(vmeRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_vmeRecord_H */
