/* aliveRecord.h generated from aliveRecord.dbd */

#ifndef INC_aliveRecord_H
#define INC_aliveRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

#ifndef aliveHRTBT_NUM_CHOICES
typedef enum {
    aliveHRTBT_OFF                  /* Off */,
    aliveHRTBT_ON                   /* On */
} aliveHRTBT;
#define aliveHRTBT_NUM_CHOICES 2
#endif

#ifndef aliveIPSTS_NUM_CHOICES
typedef enum {
    aliveIPSTS_UNDETERMINED         /* Undetermined */,
    aliveIPSTS_OPERABLE             /* Operable */,
    aliveIPSTS_INOPERABLE           /* Inoperable */
} aliveIPSTS;
#define aliveIPSTS_NUM_CHOICES 3
#endif

#ifndef aliveISUP_NUM_CHOICES
typedef enum {
    aliveISUP_OFF                   /* Off */,
    aliveISUP_ON                    /* On */
} aliveISUP;
#define aliveISUP_NUM_CHOICES 2
#endif

#ifndef aliveITRIG_NUM_CHOICES
typedef enum {
    aliveITRIG_IDLE                 /* Idle */,
    aliveITRIG_TRIGGER              /* Trigger */
} aliveITRIG;
#define aliveITRIG_NUM_CHOICES 2
#endif

typedef struct aliveRecord {
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
    ELLLIST             bklnk;      /* Backwards link tracking */
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
    struct typed_rset   *rset;      /* Address of RSET */
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
    epicsUInt32         val;        /* Return value */
    char                rhost[40];  /* Remote host */
    epicsUInt16         rport;      /* Remote port */
    epicsEnum16         hrtbt;      /* Heartbeat state */
    epicsUInt16         hprd;       /* Heartbeat period */
    epicsUInt32         hmag;       /* Heartbeat magic number */
    epicsUInt32         msg;        /* Message Value */
    void *rpvt;                     /* Record Private */
    char                env1[40];   /* Environment variable 1 */
    char                env2[40];   /* Environment variable 2 */
    char                env3[40];   /* Environment variable 3 */
    char                env4[40];   /* Environment variable 4 */
    char                env5[40];   /* Environment variable 5 */
    char                env6[40];   /* Environment variable 6 */
    char                env7[40];   /* Environment variable 7 */
    char                env8[40];   /* Environment variable 8 */
    char                env9[40];   /* Environment variable 9 */
    char                env10[40];  /* Environment variable 10 */
    char                env11[40];  /* Environment variable 11 */
    char                env12[40];  /* Environment variable 12 */
    char                env13[40];  /* Environment variable 13 */
    char                env14[40];  /* Environment variable 14 */
    char                env15[40];  /* Environment variable 15 */
    char                env16[40];  /* Environment variable 16 */
    epicsUInt16         iport;      /* Information port */
    epicsEnum16         ipsts;      /* Information port status */
    epicsEnum16         itrig;      /* Trigger information read */
    epicsEnum16         isup;       /* Suppress information read */
    char                nmvar[40];  /* IOC name variable */
    char                iocnm[40];  /* IOC name */
    char                ver[40];    /* Record version */
} aliveRecord;

typedef enum {
	aliveRecordNAME = 0,
	aliveRecordDESC = 1,
	aliveRecordASG = 2,
	aliveRecordSCAN = 3,
	aliveRecordPINI = 4,
	aliveRecordPHAS = 5,
	aliveRecordEVNT = 6,
	aliveRecordTSE = 7,
	aliveRecordTSEL = 8,
	aliveRecordDTYP = 9,
	aliveRecordDISV = 10,
	aliveRecordDISA = 11,
	aliveRecordSDIS = 12,
	aliveRecordMLOK = 13,
	aliveRecordMLIS = 14,
	aliveRecordBKLNK = 15,
	aliveRecordDISP = 16,
	aliveRecordPROC = 17,
	aliveRecordSTAT = 18,
	aliveRecordSEVR = 19,
	aliveRecordNSTA = 20,
	aliveRecordNSEV = 21,
	aliveRecordACKS = 22,
	aliveRecordACKT = 23,
	aliveRecordDISS = 24,
	aliveRecordLCNT = 25,
	aliveRecordPACT = 26,
	aliveRecordPUTF = 27,
	aliveRecordRPRO = 28,
	aliveRecordASP = 29,
	aliveRecordPPN = 30,
	aliveRecordPPNR = 31,
	aliveRecordSPVT = 32,
	aliveRecordRSET = 33,
	aliveRecordDSET = 34,
	aliveRecordDPVT = 35,
	aliveRecordRDES = 36,
	aliveRecordLSET = 37,
	aliveRecordPRIO = 38,
	aliveRecordTPRO = 39,
	aliveRecordBKPT = 40,
	aliveRecordUDF = 41,
	aliveRecordUDFS = 42,
	aliveRecordTIME = 43,
	aliveRecordFLNK = 44,
	aliveRecordVAL = 45,
	aliveRecordRHOST = 46,
	aliveRecordRPORT = 47,
	aliveRecordHRTBT = 48,
	aliveRecordHPRD = 49,
	aliveRecordHMAG = 50,
	aliveRecordMSG = 51,
	aliveRecordRPVT = 52,
	aliveRecordENV1 = 53,
	aliveRecordENV2 = 54,
	aliveRecordENV3 = 55,
	aliveRecordENV4 = 56,
	aliveRecordENV5 = 57,
	aliveRecordENV6 = 58,
	aliveRecordENV7 = 59,
	aliveRecordENV8 = 60,
	aliveRecordENV9 = 61,
	aliveRecordENV10 = 62,
	aliveRecordENV11 = 63,
	aliveRecordENV12 = 64,
	aliveRecordENV13 = 65,
	aliveRecordENV14 = 66,
	aliveRecordENV15 = 67,
	aliveRecordENV16 = 68,
	aliveRecordIPORT = 69,
	aliveRecordIPSTS = 70,
	aliveRecordITRIG = 71,
	aliveRecordISUP = 72,
	aliveRecordNMVAR = 73,
	aliveRecordIOCNM = 74,
	aliveRecordVER = 75
} aliveFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int aliveRecordSizeOffset(dbRecordType *prt)
{
    aliveRecord *prec = 0;

    assert(prt->no_fields == 76);
    prt->papFldDes[aliveRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[aliveRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[aliveRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[aliveRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[aliveRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[aliveRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[aliveRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[aliveRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[aliveRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[aliveRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[aliveRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[aliveRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[aliveRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[aliveRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[aliveRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[aliveRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[aliveRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[aliveRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[aliveRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[aliveRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[aliveRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[aliveRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[aliveRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[aliveRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[aliveRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[aliveRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[aliveRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[aliveRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[aliveRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[aliveRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[aliveRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[aliveRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[aliveRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[aliveRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[aliveRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[aliveRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[aliveRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[aliveRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[aliveRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[aliveRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[aliveRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[aliveRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[aliveRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[aliveRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[aliveRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[aliveRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[aliveRecordRHOST]->size = sizeof(prec->rhost);
    prt->papFldDes[aliveRecordRPORT]->size = sizeof(prec->rport);
    prt->papFldDes[aliveRecordHRTBT]->size = sizeof(prec->hrtbt);
    prt->papFldDes[aliveRecordHPRD]->size = sizeof(prec->hprd);
    prt->papFldDes[aliveRecordHMAG]->size = sizeof(prec->hmag);
    prt->papFldDes[aliveRecordMSG]->size = sizeof(prec->msg);
    prt->papFldDes[aliveRecordRPVT]->size = sizeof(prec->rpvt);
    prt->papFldDes[aliveRecordENV1]->size = sizeof(prec->env1);
    prt->papFldDes[aliveRecordENV2]->size = sizeof(prec->env2);
    prt->papFldDes[aliveRecordENV3]->size = sizeof(prec->env3);
    prt->papFldDes[aliveRecordENV4]->size = sizeof(prec->env4);
    prt->papFldDes[aliveRecordENV5]->size = sizeof(prec->env5);
    prt->papFldDes[aliveRecordENV6]->size = sizeof(prec->env6);
    prt->papFldDes[aliveRecordENV7]->size = sizeof(prec->env7);
    prt->papFldDes[aliveRecordENV8]->size = sizeof(prec->env8);
    prt->papFldDes[aliveRecordENV9]->size = sizeof(prec->env9);
    prt->papFldDes[aliveRecordENV10]->size = sizeof(prec->env10);
    prt->papFldDes[aliveRecordENV11]->size = sizeof(prec->env11);
    prt->papFldDes[aliveRecordENV12]->size = sizeof(prec->env12);
    prt->papFldDes[aliveRecordENV13]->size = sizeof(prec->env13);
    prt->papFldDes[aliveRecordENV14]->size = sizeof(prec->env14);
    prt->papFldDes[aliveRecordENV15]->size = sizeof(prec->env15);
    prt->papFldDes[aliveRecordENV16]->size = sizeof(prec->env16);
    prt->papFldDes[aliveRecordIPORT]->size = sizeof(prec->iport);
    prt->papFldDes[aliveRecordIPSTS]->size = sizeof(prec->ipsts);
    prt->papFldDes[aliveRecordITRIG]->size = sizeof(prec->itrig);
    prt->papFldDes[aliveRecordISUP]->size = sizeof(prec->isup);
    prt->papFldDes[aliveRecordNMVAR]->size = sizeof(prec->nmvar);
    prt->papFldDes[aliveRecordIOCNM]->size = sizeof(prec->iocnm);
    prt->papFldDes[aliveRecordVER]->size = sizeof(prec->ver);
    prt->papFldDes[aliveRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[aliveRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[aliveRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[aliveRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[aliveRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[aliveRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[aliveRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[aliveRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[aliveRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[aliveRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[aliveRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[aliveRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[aliveRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[aliveRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[aliveRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[aliveRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[aliveRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[aliveRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[aliveRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[aliveRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[aliveRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[aliveRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[aliveRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[aliveRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[aliveRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[aliveRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[aliveRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[aliveRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[aliveRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[aliveRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[aliveRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[aliveRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[aliveRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[aliveRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[aliveRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[aliveRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[aliveRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[aliveRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[aliveRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[aliveRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[aliveRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[aliveRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[aliveRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[aliveRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[aliveRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[aliveRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[aliveRecordRHOST]->offset = (unsigned short)((char *)&prec->rhost - (char *)prec);
    prt->papFldDes[aliveRecordRPORT]->offset = (unsigned short)((char *)&prec->rport - (char *)prec);
    prt->papFldDes[aliveRecordHRTBT]->offset = (unsigned short)((char *)&prec->hrtbt - (char *)prec);
    prt->papFldDes[aliveRecordHPRD]->offset = (unsigned short)((char *)&prec->hprd - (char *)prec);
    prt->papFldDes[aliveRecordHMAG]->offset = (unsigned short)((char *)&prec->hmag - (char *)prec);
    prt->papFldDes[aliveRecordMSG]->offset = (unsigned short)((char *)&prec->msg - (char *)prec);
    prt->papFldDes[aliveRecordRPVT]->offset = (unsigned short)((char *)&prec->rpvt - (char *)prec);
    prt->papFldDes[aliveRecordENV1]->offset = (unsigned short)((char *)&prec->env1 - (char *)prec);
    prt->papFldDes[aliveRecordENV2]->offset = (unsigned short)((char *)&prec->env2 - (char *)prec);
    prt->papFldDes[aliveRecordENV3]->offset = (unsigned short)((char *)&prec->env3 - (char *)prec);
    prt->papFldDes[aliveRecordENV4]->offset = (unsigned short)((char *)&prec->env4 - (char *)prec);
    prt->papFldDes[aliveRecordENV5]->offset = (unsigned short)((char *)&prec->env5 - (char *)prec);
    prt->papFldDes[aliveRecordENV6]->offset = (unsigned short)((char *)&prec->env6 - (char *)prec);
    prt->papFldDes[aliveRecordENV7]->offset = (unsigned short)((char *)&prec->env7 - (char *)prec);
    prt->papFldDes[aliveRecordENV8]->offset = (unsigned short)((char *)&prec->env8 - (char *)prec);
    prt->papFldDes[aliveRecordENV9]->offset = (unsigned short)((char *)&prec->env9 - (char *)prec);
    prt->papFldDes[aliveRecordENV10]->offset = (unsigned short)((char *)&prec->env10 - (char *)prec);
    prt->papFldDes[aliveRecordENV11]->offset = (unsigned short)((char *)&prec->env11 - (char *)prec);
    prt->papFldDes[aliveRecordENV12]->offset = (unsigned short)((char *)&prec->env12 - (char *)prec);
    prt->papFldDes[aliveRecordENV13]->offset = (unsigned short)((char *)&prec->env13 - (char *)prec);
    prt->papFldDes[aliveRecordENV14]->offset = (unsigned short)((char *)&prec->env14 - (char *)prec);
    prt->papFldDes[aliveRecordENV15]->offset = (unsigned short)((char *)&prec->env15 - (char *)prec);
    prt->papFldDes[aliveRecordENV16]->offset = (unsigned short)((char *)&prec->env16 - (char *)prec);
    prt->papFldDes[aliveRecordIPORT]->offset = (unsigned short)((char *)&prec->iport - (char *)prec);
    prt->papFldDes[aliveRecordIPSTS]->offset = (unsigned short)((char *)&prec->ipsts - (char *)prec);
    prt->papFldDes[aliveRecordITRIG]->offset = (unsigned short)((char *)&prec->itrig - (char *)prec);
    prt->papFldDes[aliveRecordISUP]->offset = (unsigned short)((char *)&prec->isup - (char *)prec);
    prt->papFldDes[aliveRecordNMVAR]->offset = (unsigned short)((char *)&prec->nmvar - (char *)prec);
    prt->papFldDes[aliveRecordIOCNM]->offset = (unsigned short)((char *)&prec->iocnm - (char *)prec);
    prt->papFldDes[aliveRecordVER]->offset = (unsigned short)((char *)&prec->ver - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(aliveRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_aliveRecord_H */
