/* vsRecord.h generated from vsRecord.dbd */

#ifndef INC_vsRecord_H
#define INC_vsRecord_H

#include "devSup.h"

/* Declare Device Support Entry Table */
struct vsRecord;
typedef struct {
    dset common;
    long (* readWrite_vs)(struct vsRecord *pr);
} vsdset;

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    vsTYPE_GP307                    /* GP307 */,
    vsTYPE_GP350                    /* GP350 */,
    vsTYPE_MM200                    /* MM200 */,
    vsTYPE_CC10                     /* CC10 */,
    vsTYPE_MX200                    /* MX200 */
} vsTYPE;
#define vsTYPE_NUM_CHOICES 5

typedef enum {
    vsOFFON_Off                     /* Off */,
    vsOFFON_On                      /* On */
} vsOFFON;
#define vsOFFON_NUM_CHOICES 2

typedef struct vsRecord {
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
    DBLINK              inp;        /* Device Specification */
    epicsEnum16         type;       /* Controller Type */
    epicsInt16          err;        /* Controller Err Cnt */
    epicsEnum16         ig1s;       /* Ion Gauge 1 Set */
    epicsEnum16         ig2s;       /* Ion Gauge 2 Set */
    epicsEnum16         dgss;       /* Degas Set */
    epicsEnum16         ig1r;       /* Ion Gauge 1 Read */
    epicsEnum16         ig2r;       /* Ion Gauge 2 Read */
    epicsEnum16         dgsr;       /* Degas Read */
    epicsEnum16         fltr;       /* Fault Read */
    epicsEnum16         sp1;        /* Set Point 1 */
    epicsEnum16         sp2;        /* Set Point 2 */
    epicsEnum16         sp3;        /* Set Point 3 */
    epicsEnum16         sp4;        /* Set Point 4 */
    epicsEnum16         sp5;        /* Set Point 5 */
    epicsEnum16         sp6;        /* Set Point 6 */
    epicsFloat64        sp1s;       /* SP 1 Setpoint Set */
    epicsFloat64        sp1r;       /* SP 1 Readback */
    epicsFloat64        sp2s;       /* SP 2 Setpoint Set */
    epicsFloat64        sp2r;       /* SP 2 Readback */
    epicsFloat64        sp3s;       /* SP 3 Setpoint Set */
    epicsFloat64        sp3r;       /* SP 3 Readback */
    epicsFloat64        sp4s;       /* SP 4 Setpoint Set */
    epicsFloat64        sp4r;       /* SP 4 Readback */
    epicsFloat64        val;        /* Gauge Pressure */
    epicsFloat64        pres;       /* Gauge Pressure */
    epicsFloat64        cgap;       /* Convectron-A Pressure */
    epicsFloat64        cgbp;       /* Convectron-B Pressure */
    epicsFloat64        lprs;       /* IG Log10 Pressure */
    epicsFloat64        lcap;       /* Conv-A Log10 Pressure */
    epicsFloat64        lcbp;       /* Conv-B Log10 Pressure */
    epicsUInt16         chgc;       /* Changed Control */
    epicsFloat32        hopr;       /* IG Pres High Display */
    epicsFloat32        lopr;       /* IG Pres Low Display */
    epicsFloat32        hlpr;       /* IG Log10 High Display */
    epicsFloat32        llpr;       /* IG Log10 Low Display */
    epicsFloat32        hapr;       /* CGA Pres High Display */
    epicsFloat32        lapr;       /* CGA Pres Low Display */
    epicsFloat32        halr;       /* CGA Log10 High Display */
    epicsFloat32        lalr;       /* CGA Log10 Low Display */
    epicsFloat32        hbpr;       /* CGB Pres High Display */
    epicsFloat32        lbpr;       /* CGB Pres Low Display */
    epicsFloat32        hblr;       /* CGB Log10 High Display */
    epicsFloat32        lblr;       /* CGB Log10 Low Display */
    epicsEnum16         pi1s;       /* prev Ion Gauge 1 */
    epicsEnum16         pi2s;       /* prev Ion Gauge 2 */
    epicsEnum16         pdss;       /* prev Degas */
    epicsEnum16         pig1;       /* prev Ion Gauge 1 */
    epicsEnum16         pig2;       /* prev Ion Gauge 2 */
    epicsEnum16         pdgs;       /* prev Degas */
    epicsEnum16         pflt;       /* prev Fault */
    epicsEnum16         psp1;       /* prev Set Point 1 */
    epicsEnum16         psp2;       /* prev Set Point 2 */
    epicsEnum16         psp3;       /* prev Set Point 3 */
    epicsEnum16         psp4;       /* prev Set Point 4 */
    epicsEnum16         psp5;       /* prev Set Point 5 */
    epicsEnum16         psp6;       /* prev Set Point 6 */
    epicsFloat64        ps1s;       /* prev SP1 Set */
    epicsFloat64        ps2s;       /* prev SP2 Set */
    epicsFloat64        ps3s;       /* prev SP3 Set */
    epicsFloat64        ps4s;       /* prev SP4 Set */
    epicsFloat64        ps1r;       /* prev SP1 Readback */
    epicsFloat64        ps2r;       /* prev SP2 Readback */
    epicsFloat64        ps3r;       /* prev SP3 Readback */
    epicsFloat64        ps4r;       /* prev SP4 Readback */
    epicsFloat64        pval;       /* prev Gauge Pres */
    epicsFloat64        ppre;       /* prev Gauge Pres */
    epicsFloat64        pcga;       /* prev Conv-A Pres */
    epicsFloat64        pcgb;       /* prev Conv-B Pres */
    epicsFloat64        plpe;       /* prev IG Log10 Pres */
    epicsFloat64        plca;       /* prev Conv-A Log10 Pres */
    epicsFloat64        plcb;       /* prev Conv-B Log10 Pres */
    epicsFloat32        hihi;       /* IG Hihi Alarm */
    epicsFloat32        lolo;       /* IG Lolo Alarm */
    epicsFloat32        high;       /* IG High Alarm */
    epicsFloat32        low;        /* IG Low Alarm */
    epicsEnum16         hhsv;       /* IG Hihi Severity */
    epicsEnum16         llsv;       /* IG Lolo Severity */
    epicsEnum16         hsv;        /* IG High Severity */
    epicsEnum16         lsv;        /* IG Low Severity */
    epicsFloat64        hyst;       /* IG Alarm Deadband */
    epicsFloat64        lalm;       /* IG Last Value Alarmed */
} vsRecord;

typedef enum {
	vsRecordNAME = 0,
	vsRecordDESC = 1,
	vsRecordASG = 2,
	vsRecordSCAN = 3,
	vsRecordPINI = 4,
	vsRecordPHAS = 5,
	vsRecordEVNT = 6,
	vsRecordTSE = 7,
	vsRecordTSEL = 8,
	vsRecordDTYP = 9,
	vsRecordDISV = 10,
	vsRecordDISA = 11,
	vsRecordSDIS = 12,
	vsRecordMLOK = 13,
	vsRecordMLIS = 14,
	vsRecordDISP = 15,
	vsRecordPROC = 16,
	vsRecordSTAT = 17,
	vsRecordSEVR = 18,
	vsRecordNSTA = 19,
	vsRecordNSEV = 20,
	vsRecordACKS = 21,
	vsRecordACKT = 22,
	vsRecordDISS = 23,
	vsRecordLCNT = 24,
	vsRecordPACT = 25,
	vsRecordPUTF = 26,
	vsRecordRPRO = 27,
	vsRecordASP = 28,
	vsRecordPPN = 29,
	vsRecordPPNR = 30,
	vsRecordSPVT = 31,
	vsRecordRSET = 32,
	vsRecordDSET = 33,
	vsRecordDPVT = 34,
	vsRecordRDES = 35,
	vsRecordLSET = 36,
	vsRecordPRIO = 37,
	vsRecordTPRO = 38,
	vsRecordBKPT = 39,
	vsRecordUDF = 40,
	vsRecordUDFS = 41,
	vsRecordTIME = 42,
	vsRecordFLNK = 43,
	vsRecordINP = 44,
	vsRecordTYPE = 45,
	vsRecordERR = 46,
	vsRecordIG1S = 47,
	vsRecordIG2S = 48,
	vsRecordDGSS = 49,
	vsRecordIG1R = 50,
	vsRecordIG2R = 51,
	vsRecordDGSR = 52,
	vsRecordFLTR = 53,
	vsRecordSP1 = 54,
	vsRecordSP2 = 55,
	vsRecordSP3 = 56,
	vsRecordSP4 = 57,
	vsRecordSP5 = 58,
	vsRecordSP6 = 59,
	vsRecordSP1S = 60,
	vsRecordSP1R = 61,
	vsRecordSP2S = 62,
	vsRecordSP2R = 63,
	vsRecordSP3S = 64,
	vsRecordSP3R = 65,
	vsRecordSP4S = 66,
	vsRecordSP4R = 67,
	vsRecordVAL = 68,
	vsRecordPRES = 69,
	vsRecordCGAP = 70,
	vsRecordCGBP = 71,
	vsRecordLPRS = 72,
	vsRecordLCAP = 73,
	vsRecordLCBP = 74,
	vsRecordCHGC = 75,
	vsRecordHOPR = 76,
	vsRecordLOPR = 77,
	vsRecordHLPR = 78,
	vsRecordLLPR = 79,
	vsRecordHAPR = 80,
	vsRecordLAPR = 81,
	vsRecordHALR = 82,
	vsRecordLALR = 83,
	vsRecordHBPR = 84,
	vsRecordLBPR = 85,
	vsRecordHBLR = 86,
	vsRecordLBLR = 87,
	vsRecordPI1S = 88,
	vsRecordPI2S = 89,
	vsRecordPDSS = 90,
	vsRecordPIG1 = 91,
	vsRecordPIG2 = 92,
	vsRecordPDGS = 93,
	vsRecordPFLT = 94,
	vsRecordPSP1 = 95,
	vsRecordPSP2 = 96,
	vsRecordPSP3 = 97,
	vsRecordPSP4 = 98,
	vsRecordPSP5 = 99,
	vsRecordPSP6 = 100,
	vsRecordPS1S = 101,
	vsRecordPS2S = 102,
	vsRecordPS3S = 103,
	vsRecordPS4S = 104,
	vsRecordPS1R = 105,
	vsRecordPS2R = 106,
	vsRecordPS3R = 107,
	vsRecordPS4R = 108,
	vsRecordPVAL = 109,
	vsRecordPPRE = 110,
	vsRecordPCGA = 111,
	vsRecordPCGB = 112,
	vsRecordPLPE = 113,
	vsRecordPLCA = 114,
	vsRecordPLCB = 115,
	vsRecordHIHI = 116,
	vsRecordLOLO = 117,
	vsRecordHIGH = 118,
	vsRecordLOW = 119,
	vsRecordHHSV = 120,
	vsRecordLLSV = 121,
	vsRecordHSV = 122,
	vsRecordLSV = 123,
	vsRecordHYST = 124,
	vsRecordLALM = 125
} vsFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int vsRecordSizeOffset(dbRecordType *prt)
{
    vsRecord *prec = 0;

    assert(prt->no_fields == 126);
    prt->papFldDes[vsRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[vsRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[vsRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[vsRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[vsRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[vsRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[vsRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[vsRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[vsRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[vsRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[vsRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[vsRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[vsRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[vsRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[vsRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[vsRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[vsRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[vsRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[vsRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[vsRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[vsRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[vsRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[vsRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[vsRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[vsRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[vsRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[vsRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[vsRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[vsRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[vsRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[vsRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[vsRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[vsRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[vsRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[vsRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[vsRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[vsRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[vsRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[vsRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[vsRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[vsRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[vsRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[vsRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[vsRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[vsRecordINP]->size = sizeof(prec->inp);
    prt->papFldDes[vsRecordTYPE]->size = sizeof(prec->type);
    prt->papFldDes[vsRecordERR]->size = sizeof(prec->err);
    prt->papFldDes[vsRecordIG1S]->size = sizeof(prec->ig1s);
    prt->papFldDes[vsRecordIG2S]->size = sizeof(prec->ig2s);
    prt->papFldDes[vsRecordDGSS]->size = sizeof(prec->dgss);
    prt->papFldDes[vsRecordIG1R]->size = sizeof(prec->ig1r);
    prt->papFldDes[vsRecordIG2R]->size = sizeof(prec->ig2r);
    prt->papFldDes[vsRecordDGSR]->size = sizeof(prec->dgsr);
    prt->papFldDes[vsRecordFLTR]->size = sizeof(prec->fltr);
    prt->papFldDes[vsRecordSP1]->size = sizeof(prec->sp1);
    prt->papFldDes[vsRecordSP2]->size = sizeof(prec->sp2);
    prt->papFldDes[vsRecordSP3]->size = sizeof(prec->sp3);
    prt->papFldDes[vsRecordSP4]->size = sizeof(prec->sp4);
    prt->papFldDes[vsRecordSP5]->size = sizeof(prec->sp5);
    prt->papFldDes[vsRecordSP6]->size = sizeof(prec->sp6);
    prt->papFldDes[vsRecordSP1S]->size = sizeof(prec->sp1s);
    prt->papFldDes[vsRecordSP1R]->size = sizeof(prec->sp1r);
    prt->papFldDes[vsRecordSP2S]->size = sizeof(prec->sp2s);
    prt->papFldDes[vsRecordSP2R]->size = sizeof(prec->sp2r);
    prt->papFldDes[vsRecordSP3S]->size = sizeof(prec->sp3s);
    prt->papFldDes[vsRecordSP3R]->size = sizeof(prec->sp3r);
    prt->papFldDes[vsRecordSP4S]->size = sizeof(prec->sp4s);
    prt->papFldDes[vsRecordSP4R]->size = sizeof(prec->sp4r);
    prt->papFldDes[vsRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[vsRecordPRES]->size = sizeof(prec->pres);
    prt->papFldDes[vsRecordCGAP]->size = sizeof(prec->cgap);
    prt->papFldDes[vsRecordCGBP]->size = sizeof(prec->cgbp);
    prt->papFldDes[vsRecordLPRS]->size = sizeof(prec->lprs);
    prt->papFldDes[vsRecordLCAP]->size = sizeof(prec->lcap);
    prt->papFldDes[vsRecordLCBP]->size = sizeof(prec->lcbp);
    prt->papFldDes[vsRecordCHGC]->size = sizeof(prec->chgc);
    prt->papFldDes[vsRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[vsRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[vsRecordHLPR]->size = sizeof(prec->hlpr);
    prt->papFldDes[vsRecordLLPR]->size = sizeof(prec->llpr);
    prt->papFldDes[vsRecordHAPR]->size = sizeof(prec->hapr);
    prt->papFldDes[vsRecordLAPR]->size = sizeof(prec->lapr);
    prt->papFldDes[vsRecordHALR]->size = sizeof(prec->halr);
    prt->papFldDes[vsRecordLALR]->size = sizeof(prec->lalr);
    prt->papFldDes[vsRecordHBPR]->size = sizeof(prec->hbpr);
    prt->papFldDes[vsRecordLBPR]->size = sizeof(prec->lbpr);
    prt->papFldDes[vsRecordHBLR]->size = sizeof(prec->hblr);
    prt->papFldDes[vsRecordLBLR]->size = sizeof(prec->lblr);
    prt->papFldDes[vsRecordPI1S]->size = sizeof(prec->pi1s);
    prt->papFldDes[vsRecordPI2S]->size = sizeof(prec->pi2s);
    prt->papFldDes[vsRecordPDSS]->size = sizeof(prec->pdss);
    prt->papFldDes[vsRecordPIG1]->size = sizeof(prec->pig1);
    prt->papFldDes[vsRecordPIG2]->size = sizeof(prec->pig2);
    prt->papFldDes[vsRecordPDGS]->size = sizeof(prec->pdgs);
    prt->papFldDes[vsRecordPFLT]->size = sizeof(prec->pflt);
    prt->papFldDes[vsRecordPSP1]->size = sizeof(prec->psp1);
    prt->papFldDes[vsRecordPSP2]->size = sizeof(prec->psp2);
    prt->papFldDes[vsRecordPSP3]->size = sizeof(prec->psp3);
    prt->papFldDes[vsRecordPSP4]->size = sizeof(prec->psp4);
    prt->papFldDes[vsRecordPSP5]->size = sizeof(prec->psp5);
    prt->papFldDes[vsRecordPSP6]->size = sizeof(prec->psp6);
    prt->papFldDes[vsRecordPS1S]->size = sizeof(prec->ps1s);
    prt->papFldDes[vsRecordPS2S]->size = sizeof(prec->ps2s);
    prt->papFldDes[vsRecordPS3S]->size = sizeof(prec->ps3s);
    prt->papFldDes[vsRecordPS4S]->size = sizeof(prec->ps4s);
    prt->papFldDes[vsRecordPS1R]->size = sizeof(prec->ps1r);
    prt->papFldDes[vsRecordPS2R]->size = sizeof(prec->ps2r);
    prt->papFldDes[vsRecordPS3R]->size = sizeof(prec->ps3r);
    prt->papFldDes[vsRecordPS4R]->size = sizeof(prec->ps4r);
    prt->papFldDes[vsRecordPVAL]->size = sizeof(prec->pval);
    prt->papFldDes[vsRecordPPRE]->size = sizeof(prec->ppre);
    prt->papFldDes[vsRecordPCGA]->size = sizeof(prec->pcga);
    prt->papFldDes[vsRecordPCGB]->size = sizeof(prec->pcgb);
    prt->papFldDes[vsRecordPLPE]->size = sizeof(prec->plpe);
    prt->papFldDes[vsRecordPLCA]->size = sizeof(prec->plca);
    prt->papFldDes[vsRecordPLCB]->size = sizeof(prec->plcb);
    prt->papFldDes[vsRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[vsRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[vsRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[vsRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[vsRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[vsRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[vsRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[vsRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[vsRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[vsRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[vsRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[vsRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[vsRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[vsRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[vsRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[vsRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[vsRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[vsRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[vsRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[vsRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[vsRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[vsRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[vsRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[vsRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[vsRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[vsRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[vsRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[vsRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[vsRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[vsRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[vsRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[vsRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[vsRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[vsRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[vsRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[vsRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[vsRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[vsRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[vsRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[vsRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[vsRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[vsRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[vsRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[vsRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[vsRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[vsRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[vsRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[vsRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[vsRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[vsRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[vsRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[vsRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[vsRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[vsRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[vsRecordINP]->offset = (unsigned short)((char *)&prec->inp - (char *)prec);
    prt->papFldDes[vsRecordTYPE]->offset = (unsigned short)((char *)&prec->type - (char *)prec);
    prt->papFldDes[vsRecordERR]->offset = (unsigned short)((char *)&prec->err - (char *)prec);
    prt->papFldDes[vsRecordIG1S]->offset = (unsigned short)((char *)&prec->ig1s - (char *)prec);
    prt->papFldDes[vsRecordIG2S]->offset = (unsigned short)((char *)&prec->ig2s - (char *)prec);
    prt->papFldDes[vsRecordDGSS]->offset = (unsigned short)((char *)&prec->dgss - (char *)prec);
    prt->papFldDes[vsRecordIG1R]->offset = (unsigned short)((char *)&prec->ig1r - (char *)prec);
    prt->papFldDes[vsRecordIG2R]->offset = (unsigned short)((char *)&prec->ig2r - (char *)prec);
    prt->papFldDes[vsRecordDGSR]->offset = (unsigned short)((char *)&prec->dgsr - (char *)prec);
    prt->papFldDes[vsRecordFLTR]->offset = (unsigned short)((char *)&prec->fltr - (char *)prec);
    prt->papFldDes[vsRecordSP1]->offset = (unsigned short)((char *)&prec->sp1 - (char *)prec);
    prt->papFldDes[vsRecordSP2]->offset = (unsigned short)((char *)&prec->sp2 - (char *)prec);
    prt->papFldDes[vsRecordSP3]->offset = (unsigned short)((char *)&prec->sp3 - (char *)prec);
    prt->papFldDes[vsRecordSP4]->offset = (unsigned short)((char *)&prec->sp4 - (char *)prec);
    prt->papFldDes[vsRecordSP5]->offset = (unsigned short)((char *)&prec->sp5 - (char *)prec);
    prt->papFldDes[vsRecordSP6]->offset = (unsigned short)((char *)&prec->sp6 - (char *)prec);
    prt->papFldDes[vsRecordSP1S]->offset = (unsigned short)((char *)&prec->sp1s - (char *)prec);
    prt->papFldDes[vsRecordSP1R]->offset = (unsigned short)((char *)&prec->sp1r - (char *)prec);
    prt->papFldDes[vsRecordSP2S]->offset = (unsigned short)((char *)&prec->sp2s - (char *)prec);
    prt->papFldDes[vsRecordSP2R]->offset = (unsigned short)((char *)&prec->sp2r - (char *)prec);
    prt->papFldDes[vsRecordSP3S]->offset = (unsigned short)((char *)&prec->sp3s - (char *)prec);
    prt->papFldDes[vsRecordSP3R]->offset = (unsigned short)((char *)&prec->sp3r - (char *)prec);
    prt->papFldDes[vsRecordSP4S]->offset = (unsigned short)((char *)&prec->sp4s - (char *)prec);
    prt->papFldDes[vsRecordSP4R]->offset = (unsigned short)((char *)&prec->sp4r - (char *)prec);
    prt->papFldDes[vsRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[vsRecordPRES]->offset = (unsigned short)((char *)&prec->pres - (char *)prec);
    prt->papFldDes[vsRecordCGAP]->offset = (unsigned short)((char *)&prec->cgap - (char *)prec);
    prt->papFldDes[vsRecordCGBP]->offset = (unsigned short)((char *)&prec->cgbp - (char *)prec);
    prt->papFldDes[vsRecordLPRS]->offset = (unsigned short)((char *)&prec->lprs - (char *)prec);
    prt->papFldDes[vsRecordLCAP]->offset = (unsigned short)((char *)&prec->lcap - (char *)prec);
    prt->papFldDes[vsRecordLCBP]->offset = (unsigned short)((char *)&prec->lcbp - (char *)prec);
    prt->papFldDes[vsRecordCHGC]->offset = (unsigned short)((char *)&prec->chgc - (char *)prec);
    prt->papFldDes[vsRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[vsRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[vsRecordHLPR]->offset = (unsigned short)((char *)&prec->hlpr - (char *)prec);
    prt->papFldDes[vsRecordLLPR]->offset = (unsigned short)((char *)&prec->llpr - (char *)prec);
    prt->papFldDes[vsRecordHAPR]->offset = (unsigned short)((char *)&prec->hapr - (char *)prec);
    prt->papFldDes[vsRecordLAPR]->offset = (unsigned short)((char *)&prec->lapr - (char *)prec);
    prt->papFldDes[vsRecordHALR]->offset = (unsigned short)((char *)&prec->halr - (char *)prec);
    prt->papFldDes[vsRecordLALR]->offset = (unsigned short)((char *)&prec->lalr - (char *)prec);
    prt->papFldDes[vsRecordHBPR]->offset = (unsigned short)((char *)&prec->hbpr - (char *)prec);
    prt->papFldDes[vsRecordLBPR]->offset = (unsigned short)((char *)&prec->lbpr - (char *)prec);
    prt->papFldDes[vsRecordHBLR]->offset = (unsigned short)((char *)&prec->hblr - (char *)prec);
    prt->papFldDes[vsRecordLBLR]->offset = (unsigned short)((char *)&prec->lblr - (char *)prec);
    prt->papFldDes[vsRecordPI1S]->offset = (unsigned short)((char *)&prec->pi1s - (char *)prec);
    prt->papFldDes[vsRecordPI2S]->offset = (unsigned short)((char *)&prec->pi2s - (char *)prec);
    prt->papFldDes[vsRecordPDSS]->offset = (unsigned short)((char *)&prec->pdss - (char *)prec);
    prt->papFldDes[vsRecordPIG1]->offset = (unsigned short)((char *)&prec->pig1 - (char *)prec);
    prt->papFldDes[vsRecordPIG2]->offset = (unsigned short)((char *)&prec->pig2 - (char *)prec);
    prt->papFldDes[vsRecordPDGS]->offset = (unsigned short)((char *)&prec->pdgs - (char *)prec);
    prt->papFldDes[vsRecordPFLT]->offset = (unsigned short)((char *)&prec->pflt - (char *)prec);
    prt->papFldDes[vsRecordPSP1]->offset = (unsigned short)((char *)&prec->psp1 - (char *)prec);
    prt->papFldDes[vsRecordPSP2]->offset = (unsigned short)((char *)&prec->psp2 - (char *)prec);
    prt->papFldDes[vsRecordPSP3]->offset = (unsigned short)((char *)&prec->psp3 - (char *)prec);
    prt->papFldDes[vsRecordPSP4]->offset = (unsigned short)((char *)&prec->psp4 - (char *)prec);
    prt->papFldDes[vsRecordPSP5]->offset = (unsigned short)((char *)&prec->psp5 - (char *)prec);
    prt->papFldDes[vsRecordPSP6]->offset = (unsigned short)((char *)&prec->psp6 - (char *)prec);
    prt->papFldDes[vsRecordPS1S]->offset = (unsigned short)((char *)&prec->ps1s - (char *)prec);
    prt->papFldDes[vsRecordPS2S]->offset = (unsigned short)((char *)&prec->ps2s - (char *)prec);
    prt->papFldDes[vsRecordPS3S]->offset = (unsigned short)((char *)&prec->ps3s - (char *)prec);
    prt->papFldDes[vsRecordPS4S]->offset = (unsigned short)((char *)&prec->ps4s - (char *)prec);
    prt->papFldDes[vsRecordPS1R]->offset = (unsigned short)((char *)&prec->ps1r - (char *)prec);
    prt->papFldDes[vsRecordPS2R]->offset = (unsigned short)((char *)&prec->ps2r - (char *)prec);
    prt->papFldDes[vsRecordPS3R]->offset = (unsigned short)((char *)&prec->ps3r - (char *)prec);
    prt->papFldDes[vsRecordPS4R]->offset = (unsigned short)((char *)&prec->ps4r - (char *)prec);
    prt->papFldDes[vsRecordPVAL]->offset = (unsigned short)((char *)&prec->pval - (char *)prec);
    prt->papFldDes[vsRecordPPRE]->offset = (unsigned short)((char *)&prec->ppre - (char *)prec);
    prt->papFldDes[vsRecordPCGA]->offset = (unsigned short)((char *)&prec->pcga - (char *)prec);
    prt->papFldDes[vsRecordPCGB]->offset = (unsigned short)((char *)&prec->pcgb - (char *)prec);
    prt->papFldDes[vsRecordPLPE]->offset = (unsigned short)((char *)&prec->plpe - (char *)prec);
    prt->papFldDes[vsRecordPLCA]->offset = (unsigned short)((char *)&prec->plca - (char *)prec);
    prt->papFldDes[vsRecordPLCB]->offset = (unsigned short)((char *)&prec->plcb - (char *)prec);
    prt->papFldDes[vsRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[vsRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[vsRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[vsRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[vsRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[vsRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[vsRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[vsRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[vsRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[vsRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(vsRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_vsRecord_H */
