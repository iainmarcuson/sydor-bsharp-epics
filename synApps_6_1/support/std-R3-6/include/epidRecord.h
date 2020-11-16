/* epidRecord.h generated from epidRecord.dbd */

#ifndef INC_epidRecord_H
#define INC_epidRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    epidFeedbackMode_PID            /* PID */,
    epidFeedbackMode_MaxMin         /* Max/Min */
} epidFeedbackMode;
#define epidFeedbackMode_NUM_CHOICES 2

typedef enum {
    epidFeedbackState_Off           /* Off */,
    epidFeedbackState_On            /* On */
} epidFeedbackState;
#define epidFeedbackState_NUM_CHOICES 2

typedef struct epidRecord {
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
    epicsFloat64        val;        /* Setpoint */
    epicsEnum16         smsl;       /* Setpoint Mode Select */
    DBLINK              stpl;       /* Setpoint Location */
    DBLINK              inp;        /* Controlled Value Loc */
    DBLINK              outl;       /* Output Location */
    DBLINK              trig;       /* Readback Trigger */
    epicsFloat64        tval;       /* Trigger Value */
    epicsFloat64        cval;       /* Controlled Value */
    epicsFloat64        cvlp;       /* Prev. Controlled Value */
    epicsFloat64        oval;       /* Output value */
    epicsFloat64        ovlp;       /* Prev output */
    epicsInt16          prec;       /* Display Precision */
    epicsFloat64        mdt;        /* Min Delta T */
    epicsEnum16         fmod;       /* Feedback Mode */
    epicsEnum16         fbon;       /* Feedback On/Off */
    epicsEnum16         fbop;       /* Prev. feedback On/Off */
    epicsFloat64        kp;         /* Proportional Gain */
    epicsFloat64        ki;         /* Intergral Gain */
    epicsFloat64        kd;         /* Derivative Gain */
    char                egu[16];    /* Engineering Units */
    epicsFloat64        hopr;       /* High Operating Range */
    epicsFloat64        lopr;       /* Low Operating Range */
    epicsFloat64        drvh;       /* High Drive Limit */
    epicsFloat64        drvl;       /* Low Drive Limit */
    epicsFloat64        hihi;       /* Hihi Deviation Limit */
    epicsFloat64        lolo;       /* Lolo Deviation Limit */
    epicsFloat64        high;       /* High Deviation Limit */
    epicsFloat64        low;        /* Low Deviation Limit */
    epicsEnum16         hhsv;       /* Hihi Severity */
    epicsEnum16         llsv;       /* Lolo Severity */
    epicsEnum16         hsv;        /* High Severity */
    epicsEnum16         lsv;        /* Low Severity */
    epicsFloat64        hyst;       /* Alarm Deadband */
    epicsFloat64        adel;       /* Archive Deadband */
    epicsFloat64        mdel;       /* Monitor Deadband */
    epicsFloat64        odel;       /* Output Deadband */
    epicsFloat64        p;          /* P component */
    epicsFloat64        pp;         /* Prev. P component */
    epicsFloat64        i;          /* I component */
    epicsFloat64        ip;         /* Prev. I component */
    epicsFloat64        d;          /* D component */
    epicsFloat64        dp;         /* Prev. D component */
    epicsTimeStamp  ct;             /* Time */
    epicsTimeStamp   ctp;           /* Previous time */
    epicsFloat64        dt;         /* Delta T */
    epicsFloat64        dtp;        /* Prev. Delta T */
    epicsFloat64        err;        /* Error */
    epicsFloat64        errp;       /* Prev. Error */
    epicsFloat64        lalm;       /* Last Value Alarmed */
    epicsFloat64        alst;       /* Last Value Archived */
    epicsFloat64        mlst;       /* Last Value Monitored */
} epidRecord;

typedef enum {
	epidRecordNAME = 0,
	epidRecordDESC = 1,
	epidRecordASG = 2,
	epidRecordSCAN = 3,
	epidRecordPINI = 4,
	epidRecordPHAS = 5,
	epidRecordEVNT = 6,
	epidRecordTSE = 7,
	epidRecordTSEL = 8,
	epidRecordDTYP = 9,
	epidRecordDISV = 10,
	epidRecordDISA = 11,
	epidRecordSDIS = 12,
	epidRecordMLOK = 13,
	epidRecordMLIS = 14,
	epidRecordDISP = 15,
	epidRecordPROC = 16,
	epidRecordSTAT = 17,
	epidRecordSEVR = 18,
	epidRecordNSTA = 19,
	epidRecordNSEV = 20,
	epidRecordACKS = 21,
	epidRecordACKT = 22,
	epidRecordDISS = 23,
	epidRecordLCNT = 24,
	epidRecordPACT = 25,
	epidRecordPUTF = 26,
	epidRecordRPRO = 27,
	epidRecordASP = 28,
	epidRecordPPN = 29,
	epidRecordPPNR = 30,
	epidRecordSPVT = 31,
	epidRecordRSET = 32,
	epidRecordDSET = 33,
	epidRecordDPVT = 34,
	epidRecordRDES = 35,
	epidRecordLSET = 36,
	epidRecordPRIO = 37,
	epidRecordTPRO = 38,
	epidRecordBKPT = 39,
	epidRecordUDF = 40,
	epidRecordUDFS = 41,
	epidRecordTIME = 42,
	epidRecordFLNK = 43,
	epidRecordVAL = 44,
	epidRecordSMSL = 45,
	epidRecordSTPL = 46,
	epidRecordINP = 47,
	epidRecordOUTL = 48,
	epidRecordTRIG = 49,
	epidRecordTVAL = 50,
	epidRecordCVAL = 51,
	epidRecordCVLP = 52,
	epidRecordOVAL = 53,
	epidRecordOVLP = 54,
	epidRecordPREC = 55,
	epidRecordMDT = 56,
	epidRecordFMOD = 57,
	epidRecordFBON = 58,
	epidRecordFBOP = 59,
	epidRecordKP = 60,
	epidRecordKI = 61,
	epidRecordKD = 62,
	epidRecordEGU = 63,
	epidRecordHOPR = 64,
	epidRecordLOPR = 65,
	epidRecordDRVH = 66,
	epidRecordDRVL = 67,
	epidRecordHIHI = 68,
	epidRecordLOLO = 69,
	epidRecordHIGH = 70,
	epidRecordLOW = 71,
	epidRecordHHSV = 72,
	epidRecordLLSV = 73,
	epidRecordHSV = 74,
	epidRecordLSV = 75,
	epidRecordHYST = 76,
	epidRecordADEL = 77,
	epidRecordMDEL = 78,
	epidRecordODEL = 79,
	epidRecordP = 80,
	epidRecordPP = 81,
	epidRecordI = 82,
	epidRecordIP = 83,
	epidRecordD = 84,
	epidRecordDP = 85,
	epidRecordCT = 86,
	epidRecordCTP = 87,
	epidRecordDT = 88,
	epidRecordDTP = 89,
	epidRecordERR = 90,
	epidRecordERRP = 91,
	epidRecordLALM = 92,
	epidRecordALST = 93,
	epidRecordMLST = 94
} epidFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int epidRecordSizeOffset(dbRecordType *prt)
{
    epidRecord *prec = 0;

    assert(prt->no_fields == 95);
    prt->papFldDes[epidRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[epidRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[epidRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[epidRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[epidRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[epidRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[epidRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[epidRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[epidRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[epidRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[epidRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[epidRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[epidRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[epidRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[epidRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[epidRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[epidRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[epidRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[epidRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[epidRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[epidRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[epidRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[epidRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[epidRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[epidRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[epidRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[epidRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[epidRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[epidRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[epidRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[epidRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[epidRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[epidRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[epidRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[epidRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[epidRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[epidRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[epidRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[epidRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[epidRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[epidRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[epidRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[epidRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[epidRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[epidRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[epidRecordSMSL]->size = sizeof(prec->smsl);
    prt->papFldDes[epidRecordSTPL]->size = sizeof(prec->stpl);
    prt->papFldDes[epidRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[epidRecordOUTL]->size = sizeof(prec->outl);
    prt->papFldDes[epidRecordTRIG]->size = sizeof(prec->trig);
    prt->papFldDes[epidRecordTVAL]->size = sizeof(prec->tval);
    prt->papFldDes[epidRecordCVAL]->size = sizeof(prec->cval);
    prt->papFldDes[epidRecordCVLP]->size = sizeof(prec->cvlp);
    prt->papFldDes[epidRecordOVAL]->size = sizeof(prec->oval);
    prt->papFldDes[epidRecordOVLP]->size = sizeof(prec->ovlp);
    prt->papFldDes[epidRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[epidRecordMDT]->size = sizeof(prec->mdt);
    prt->papFldDes[epidRecordFMOD]->size = sizeof(prec->fmod);
    prt->papFldDes[epidRecordFBON]->size = sizeof(prec->fbon);
    prt->papFldDes[epidRecordFBOP]->size = sizeof(prec->fbop);
    prt->papFldDes[epidRecordKP]->size = sizeof(prec->kp);
    prt->papFldDes[epidRecordKI]->size = sizeof(prec->ki);
    prt->papFldDes[epidRecordKD]->size = sizeof(prec->kd);
    prt->papFldDes[epidRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[epidRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[epidRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[epidRecordDRVH]->size = sizeof(prec->drvh);
    prt->papFldDes[epidRecordDRVL]->size = sizeof(prec->drvl);
    prt->papFldDes[epidRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[epidRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[epidRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[epidRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[epidRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[epidRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[epidRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[epidRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[epidRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[epidRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[epidRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[epidRecordODEL]->size = sizeof(prec->odel);
    prt->papFldDes[epidRecordP]->size = sizeof(prec->p);
    prt->papFldDes[epidRecordPP]->size = sizeof(prec->pp);
    prt->papFldDes[epidRecordI]->size = sizeof(prec->i);
    prt->papFldDes[epidRecordIP]->size = sizeof(prec->ip);
    prt->papFldDes[epidRecordD]->size = sizeof(prec->d);
    prt->papFldDes[epidRecordDP]->size = sizeof(prec->dp);
    prt->papFldDes[epidRecordCT]->size = sizeof(prec->ct);
    prt->papFldDes[epidRecordCTP]->size = sizeof(prec->ctp);
    prt->papFldDes[epidRecordDT]->size = sizeof(prec->dt);
    prt->papFldDes[epidRecordDTP]->size = sizeof(prec->dtp);
    prt->papFldDes[epidRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[epidRecordERRP]->size = sizeof(prec->errp);
    prt->papFldDes[epidRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[epidRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[epidRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[epidRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[epidRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[epidRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[epidRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[epidRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[epidRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[epidRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[epidRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[epidRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[epidRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[epidRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[epidRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[epidRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[epidRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[epidRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[epidRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[epidRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[epidRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[epidRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[epidRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[epidRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[epidRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[epidRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[epidRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[epidRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[epidRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[epidRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[epidRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[epidRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[epidRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[epidRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[epidRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[epidRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[epidRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[epidRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[epidRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[epidRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[epidRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[epidRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[epidRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[epidRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[epidRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[epidRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[epidRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[epidRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[epidRecordSMSL]->offset = (unsigned short)((char *)&prec->smsl - (char *)prec);
    prt->papFldDes[epidRecordSTPL]->offset = (unsigned short)((char *)&prec->stpl - (char *)prec);
    prt->papFldDes[epidRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[epidRecordOUTL]->offset = (unsigned short)((char *)&prec->outl - (char *)prec);
    prt->papFldDes[epidRecordTRIG]->offset = (unsigned short)((char *)&prec->trig - (char *)prec);
    prt->papFldDes[epidRecordTVAL]->offset = (unsigned short)((char *)&prec->tval - (char *)prec);
    prt->papFldDes[epidRecordCVAL]->offset = (unsigned short)((char *)&prec->cval - (char *)prec);
    prt->papFldDes[epidRecordCVLP]->offset = (unsigned short)((char *)&prec->cvlp - (char *)prec);
    prt->papFldDes[epidRecordOVAL]->offset = (unsigned short)((char *)&prec->oval - (char *)prec);
    prt->papFldDes[epidRecordOVLP]->offset = (unsigned short)((char *)&prec->ovlp - (char *)prec);
    prt->papFldDes[epidRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[epidRecordMDT]->offset = (unsigned short)((char *)&prec->mdt - (char *)prec);
    prt->papFldDes[epidRecordFMOD]->offset = (unsigned short)((char *)&prec->fmod - (char *)prec);
    prt->papFldDes[epidRecordFBON]->offset = (unsigned short)((char *)&prec->fbon - (char *)prec);
    prt->papFldDes[epidRecordFBOP]->offset = (unsigned short)((char *)&prec->fbop - (char *)prec);
    prt->papFldDes[epidRecordKP]->offset = (unsigned short)((char *)&prec->kp - (char *)prec);
    prt->papFldDes[epidRecordKI]->offset = (unsigned short)((char *)&prec->ki - (char *)prec);
    prt->papFldDes[epidRecordKD]->offset = (unsigned short)((char *)&prec->kd - (char *)prec);
    prt->papFldDes[epidRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[epidRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[epidRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[epidRecordDRVH]->offset = (unsigned short)((char *)&prec->drvh - (char *)prec);
    prt->papFldDes[epidRecordDRVL]->offset = (unsigned short)((char *)&prec->drvl - (char *)prec);
    prt->papFldDes[epidRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[epidRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[epidRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[epidRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[epidRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[epidRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[epidRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[epidRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[epidRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[epidRecordADEL]->offset = (unsigned short)((char *)&prec->adel - (char *)prec);
    prt->papFldDes[epidRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[epidRecordODEL]->offset = (unsigned short)((char *)&prec->odel - (char *)prec);
    prt->papFldDes[epidRecordP]->offset = (unsigned short)((char *)&prec->p - (char *)prec);
    prt->papFldDes[epidRecordPP]->offset = (unsigned short)((char *)&prec->pp - (char *)prec);
    prt->papFldDes[epidRecordI]->offset = (unsigned short)((char *)&prec->i - (char *)prec);
    prt->papFldDes[epidRecordIP]->offset = (unsigned short)((char *)&prec->ip - (char *)prec);
    prt->papFldDes[epidRecordD]->offset = (unsigned short)((char *)&prec->d - (char *)prec);
    prt->papFldDes[epidRecordDP]->offset = (unsigned short)((char *)&prec->dp - (char *)prec);
    prt->papFldDes[epidRecordCT]->offset = (unsigned short)((char *)&prec->ct - (char *)prec);
    prt->papFldDes[epidRecordCTP]->offset = (unsigned short)((char *)&prec->ctp - (char *)prec);
    prt->papFldDes[epidRecordDT]->offset = (unsigned short)((char *)&prec->dt - (char *)prec);
    prt->papFldDes[epidRecordDTP]->offset = (unsigned short)((char *)&prec->dtp - (char *)prec);
    prt->papFldDes[epidRecordERR]->offset = (unsigned short)((char *)&prec->err - (char *)prec);
    prt->papFldDes[epidRecordERRP]->offset = (unsigned short)((char *)&prec->errp - (char *)prec);
    prt->papFldDes[epidRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[epidRecordALST]->offset = (unsigned short)((char *)&prec->alst - (char *)prec);
    prt->papFldDes[epidRecordMLST]->offset = (unsigned short)((char *)&prec->mlst - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(epidRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_epidRecord_H */
