/* tableRecord.h generated from tableRecord.dbd */

#ifndef INC_tableRecord_H
#define INC_tableRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

typedef enum {
    tableAUNIT_DEGREES              /* degrees */,
    tableAUNIT_MICRORADIANS         /* ur */
} tableAUNIT;
#define tableAUNIT_NUM_CHOICES 2

typedef enum {
    tableSET_Use                    /* Use */,
    tableSET_Set                    /* Set */
} tableSET;
#define tableSET_NUM_CHOICES 2

typedef enum {
    tableGEOM_SRI                   /* SRI */,
    tableGEOM_GEOCARS               /* GEOCARS */,
    tableGEOM_NEWPORT               /* NEWPORT */,
    tableGEOM_PNC                   /* PNC */
} tableGEOM;
#define tableGEOM_NUM_CHOICES 4

typedef struct tableRecord {
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
    epicsFloat64        val;        /* Result */
    epicsFloat64        lx;         /* wheelbase x */
    epicsFloat64        lz;         /* wheelbase z */
    epicsFloat64        sx;         /* x of fixed point */
    epicsFloat64        sy;         /* y of fixed point */
    epicsFloat64        sz;         /* z of fixed point */
    epicsFloat64        rx;         /* x of ref point */
    epicsFloat64        ry;         /* y of ref point */
    epicsFloat64        rz;         /* z of ref point */
    epicsFloat64        yang;       /* Orientation angle */
    epicsFloat64        ax;         /* x angle */
    epicsFloat64        ay;         /* y angle */
    epicsFloat64        az;         /* z angle */
    epicsFloat64        x;          /* x translation */
    epicsFloat64        y;          /* y translation */
    epicsFloat64        z;          /* z translation */
    epicsFloat64        ax0;        /* x-angle offset */
    epicsFloat64        ay0;        /* y-angle offset */
    epicsFloat64        az0;        /* z-angle offset */
    epicsFloat64        x0;         /* x offset */
    epicsFloat64        y0;         /* y offset */
    epicsFloat64        z0;         /* z offset */
    epicsFloat64        axl;        /* x angle true value */
    epicsFloat64        ayl;        /* y angle true value */
    epicsFloat64        azl;        /* z angle true value */
    epicsFloat64        xl;         /* x true value */
    epicsFloat64        yl;         /* y true value */
    epicsFloat64        zl;         /* z true value */
    epicsFloat64        axrb;       /* x angle readback */
    epicsFloat64        ayrb;       /* y angle readback */
    epicsFloat64        azrb;       /* z angle readback */
    epicsFloat64        xrb;        /* x readback value */
    epicsFloat64        yrb;        /* y readback value */
    epicsFloat64        zrb;        /* z readback value */
    epicsFloat64        eax;        /* encoder x angle */
    epicsFloat64        eay;        /* encoder y angle */
    epicsFloat64        eaz;        /* encoder z angle */
    epicsFloat64        ex;         /* encoder x */
    epicsFloat64        ey;         /* encoder y */
    epicsFloat64        ez;         /* encoder z */
    epicsFloat64        hlax;       /* x angle hi limit */
    epicsFloat64        hlay;       /* y angle hi limit */
    epicsFloat64        hlaz;       /* z angle hi limit */
    epicsFloat64        hlx;        /* x hi limit */
    epicsFloat64        hly;        /* y hi limit */
    epicsFloat64        hlz;        /* z hi limit */
    epicsFloat64        llax;       /* x angle lo limit */
    epicsFloat64        llay;       /* y angle lo limit */
    epicsFloat64        llaz;       /* z angle lo limit */
    epicsFloat64        llx;        /* x lo limit */
    epicsFloat64        lly;        /* y lo limit */
    epicsFloat64        llz;        /* z lo limit */
    epicsFloat64        uhax;       /* x angle user hi limit (absolute) */
    epicsFloat64        uhay;       /* y angle user hi limit (absolute) */
    epicsFloat64        uhaz;       /* z angle user hi limit (absolute) */
    epicsFloat64        uhx;        /* x user hi limit (absolute) */
    epicsFloat64        uhy;        /* y user hi limit (absolute) */
    epicsFloat64        uhz;        /* z user hi limit (absolute) */
    epicsFloat64        ulax;       /* x angle user lo limit (absolute) */
    epicsFloat64        ulay;       /* y angle user lo limit (absolute) */
    epicsFloat64        ulaz;       /* z angle user lo limit (absolute) */
    epicsFloat64        ulx;        /* x user lo limit (absolute) */
    epicsFloat64        uly;        /* y user lo limit (absolute) */
    epicsFloat64        ulz;        /* z user lo limit (absolute) */
    epicsFloat64        uhaxr;      /* x angle user hi limit (relative) */
    epicsFloat64        uhayr;      /* y angle user hi limit (relative) */
    epicsFloat64        uhazr;      /* z angle user hi limit (relative) */
    epicsFloat64        uhxr;       /* x user hi limit (relative) */
    epicsFloat64        uhyr;       /* y user hi limit (relative) */
    epicsFloat64        uhzr;       /* z user hi limit (relative) */
    epicsFloat64        ulaxr;      /* x angle user lo limit (relative) */
    epicsFloat64        ulayr;      /* y angle user lo limit (relative) */
    epicsFloat64        ulazr;      /* z angle user lo limit (relative) */
    epicsFloat64        ulxr;       /* x user lo limit (relative) */
    epicsFloat64        ulyr;       /* y user lo limit (relative) */
    epicsFloat64        ulzr;       /* z user lo limit (relative) */
    DBLINK              m0xl;       /* motor 0X outlink */
    DBLINK              m0yl;       /* motor 0Y outlink */
    DBLINK              m1yl;       /* motor 1Y outlink */
    DBLINK              m2xl;       /* motor 2X outlink */
    DBLINK              m2yl;       /* motor 2Y outlink */
    DBLINK              m2zl;       /* motor 2Z outlink */
    epicsFloat64        m0x;        /* motor 0X val */
    epicsFloat64        m0y;        /* motor 0Y val */
    epicsFloat64        m1y;        /* motor 1Y val */
    epicsFloat64        m2x;        /* motor 2X val */
    epicsFloat64        m2y;        /* motor 2Y val */
    epicsFloat64        m2z;        /* motor 2Z val */
    DBLINK              r0xi;       /* motor 0X RBV link */
    DBLINK              r0yi;       /* motor 0Y RBV link */
    DBLINK              r1yi;       /* motor 1Y RBV link */
    DBLINK              r2xi;       /* motor 2X RBV link */
    DBLINK              r2yi;       /* motor 2Y RBV link */
    DBLINK              r2zi;       /* motor 2Z RBV link */
    epicsFloat64        r0x;        /* motor 0X readback */
    epicsFloat64        r0y;        /* motor 0Y readback */
    epicsFloat64        r1y;        /* motor 1Y readback */
    epicsFloat64        r2x;        /* motor 2X readback */
    epicsFloat64        r2y;        /* motor 2Y readback */
    epicsFloat64        r2z;        /* motor 2Z readback */
    DBLINK              e0xi;       /* encoder 0X inlink */
    DBLINK              e0yi;       /* encoder 0Y inlink */
    DBLINK              e1yi;       /* encoder 1Y inlink */
    DBLINK              e2xi;       /* encoder 2X inlink */
    DBLINK              e2yi;       /* encoder 2Y inlink */
    DBLINK              e2zi;       /* encoder 2Z inlink */
    epicsFloat64        e0x;        /* encoder 0X val */
    epicsFloat64        e0y;        /* encoder 0Y val */
    epicsFloat64        e1y;        /* encoder 1Y val */
    epicsFloat64        e2x;        /* encoder 2X val */
    epicsFloat64        e2y;        /* encoder 2Y val */
    epicsFloat64        e2z;        /* encoder 2Z val */
    DBLINK              v0xl;       /* speed 0X outlink */
    DBLINK              v0yl;       /* speed 0Y outlink */
    DBLINK              v1yl;       /* speed 1Y outlink */
    DBLINK              v2xl;       /* speed 2X outlink */
    DBLINK              v2yl;       /* speed 2Y outlink */
    DBLINK              v2zl;       /* speed 2Z outlink */
    epicsFloat64        v0x;        /* speed 0X val */
    epicsFloat64        v0y;        /* speed 0Y val */
    epicsFloat64        v1y;        /* speed 1Y val */
    epicsFloat64        v2x;        /* speed 2X val */
    epicsFloat64        v2y;        /* speed 2Y val */
    epicsFloat64        v2z;        /* speed 2Z val */
    DBLINK              v0xi;       /* speed 0X inlink */
    DBLINK              v0yi;       /* speed 0Y inlink */
    DBLINK              v1yi;       /* speed 1Y inlink */
    DBLINK              v2xi;       /* speed 2X inlink */
    DBLINK              v2yi;       /* speed 2Y inlink */
    DBLINK              v2zi;       /* speed 2Z inlink */
    DBLINK              h0xl;       /* motor 0X HLM link */
    DBLINK              h0yl;       /* motor 0Y HLM link */
    DBLINK              h1yl;       /* motor 1Y HLM link */
    DBLINK              h2xl;       /* motor 2X HLM link */
    DBLINK              h2yl;       /* motor 2Y HLM link */
    DBLINK              h2zl;       /* motor 2Z HLM link */
    epicsFloat64        h0x;        /* motor 0X hi limit */
    epicsFloat64        h0y;        /* motor 0Y hi limit */
    epicsFloat64        h1y;        /* motor 1Y hi limit */
    epicsFloat64        h2x;        /* motor 2X hi limit */
    epicsFloat64        h2y;        /* motor 2Y hi limit */
    epicsFloat64        h2z;        /* motor 2Z hi limit */
    DBLINK              l0xl;       /* motor 0X LLM link */
    DBLINK              l0yl;       /* motor 0Y LLM link */
    DBLINK              l1yl;       /* motor 1Y LLM link */
    DBLINK              l2xl;       /* motor 2X LLM link */
    DBLINK              l2yl;       /* motor 2Y LLM link */
    DBLINK              l2zl;       /* motor 2Z LLM link */
    epicsFloat64        l0x;        /* motor 0X lo limit */
    epicsFloat64        l0y;        /* motor 0Y lo limit */
    epicsFloat64        l1y;        /* motor 1Y lo limit */
    epicsFloat64        l2x;        /* motor 2X lo limit */
    epicsFloat64        l2y;        /* motor 2Y lo limit */
    epicsFloat64        l2z;        /* motor 2Z lo limit */
    epicsInt16          init;       /* init table */
    epicsInt16          zero;       /* zero table */
    epicsInt16          sync;       /* sync with motors */
    epicsInt16          read;       /* readback motors */
    epicsEnum16         set;        /* set table */
    epicsInt16          sset;       /* Set SET Mode */
    epicsInt16          suse;       /* Set USE Mode */
    epicsInt16          lvio;       /* limit violation */
    double *	pp0;                   /* pivot pt 0 */
    double *	pp1;                   /* pivot pt 1 */
    double *	pp2;                   /* pivot pt 2 */
    double *	ppo0;                  /* pivot pt 0 orig */
    double *	ppo1;                  /* pivot pt 1 orig */
    double *	ppo2;                  /* pivot pt 2 orig */
    double **	a;                    /* x to m matrix */
    double **	b;                    /* m to x matrix */
    char                legu[16];   /* Linear Units Name */
    char                aegu[16];   /* Angular Units Name */
    epicsInt16          prec;       /* Display Precision */
    epicsUInt32         mmap;       /* Monitor Mask */
    epicsEnum16         geom;       /* Geometry */
    epicsFloat64        torad;      /* conversion to radians */
    epicsEnum16         aunit;      /* Angle units */
} tableRecord;

typedef enum {
	tableRecordNAME = 0,
	tableRecordDESC = 1,
	tableRecordASG = 2,
	tableRecordSCAN = 3,
	tableRecordPINI = 4,
	tableRecordPHAS = 5,
	tableRecordEVNT = 6,
	tableRecordTSE = 7,
	tableRecordTSEL = 8,
	tableRecordDTYP = 9,
	tableRecordDISV = 10,
	tableRecordDISA = 11,
	tableRecordSDIS = 12,
	tableRecordMLOK = 13,
	tableRecordMLIS = 14,
	tableRecordDISP = 15,
	tableRecordPROC = 16,
	tableRecordSTAT = 17,
	tableRecordSEVR = 18,
	tableRecordNSTA = 19,
	tableRecordNSEV = 20,
	tableRecordACKS = 21,
	tableRecordACKT = 22,
	tableRecordDISS = 23,
	tableRecordLCNT = 24,
	tableRecordPACT = 25,
	tableRecordPUTF = 26,
	tableRecordRPRO = 27,
	tableRecordASP = 28,
	tableRecordPPN = 29,
	tableRecordPPNR = 30,
	tableRecordSPVT = 31,
	tableRecordRSET = 32,
	tableRecordDSET = 33,
	tableRecordDPVT = 34,
	tableRecordRDES = 35,
	tableRecordLSET = 36,
	tableRecordPRIO = 37,
	tableRecordTPRO = 38,
	tableRecordBKPT = 39,
	tableRecordUDF = 40,
	tableRecordUDFS = 41,
	tableRecordTIME = 42,
	tableRecordFLNK = 43,
	tableRecordVERS = 44,
	tableRecordVAL = 45,
	tableRecordLX = 46,
	tableRecordLZ = 47,
	tableRecordSX = 48,
	tableRecordSY = 49,
	tableRecordSZ = 50,
	tableRecordRX = 51,
	tableRecordRY = 52,
	tableRecordRZ = 53,
	tableRecordYANG = 54,
	tableRecordAX = 55,
	tableRecordAY = 56,
	tableRecordAZ = 57,
	tableRecordX = 58,
	tableRecordY = 59,
	tableRecordZ = 60,
	tableRecordAX0 = 61,
	tableRecordAY0 = 62,
	tableRecordAZ0 = 63,
	tableRecordX0 = 64,
	tableRecordY0 = 65,
	tableRecordZ0 = 66,
	tableRecordAXL = 67,
	tableRecordAYL = 68,
	tableRecordAZL = 69,
	tableRecordXL = 70,
	tableRecordYL = 71,
	tableRecordZL = 72,
	tableRecordAXRB = 73,
	tableRecordAYRB = 74,
	tableRecordAZRB = 75,
	tableRecordXRB = 76,
	tableRecordYRB = 77,
	tableRecordZRB = 78,
	tableRecordEAX = 79,
	tableRecordEAY = 80,
	tableRecordEAZ = 81,
	tableRecordEX = 82,
	tableRecordEY = 83,
	tableRecordEZ = 84,
	tableRecordHLAX = 85,
	tableRecordHLAY = 86,
	tableRecordHLAZ = 87,
	tableRecordHLX = 88,
	tableRecordHLY = 89,
	tableRecordHLZ = 90,
	tableRecordLLAX = 91,
	tableRecordLLAY = 92,
	tableRecordLLAZ = 93,
	tableRecordLLX = 94,
	tableRecordLLY = 95,
	tableRecordLLZ = 96,
	tableRecordUHAX = 97,
	tableRecordUHAY = 98,
	tableRecordUHAZ = 99,
	tableRecordUHX = 100,
	tableRecordUHY = 101,
	tableRecordUHZ = 102,
	tableRecordULAX = 103,
	tableRecordULAY = 104,
	tableRecordULAZ = 105,
	tableRecordULX = 106,
	tableRecordULY = 107,
	tableRecordULZ = 108,
	tableRecordUHAXR = 109,
	tableRecordUHAYR = 110,
	tableRecordUHAZR = 111,
	tableRecordUHXR = 112,
	tableRecordUHYR = 113,
	tableRecordUHZR = 114,
	tableRecordULAXR = 115,
	tableRecordULAYR = 116,
	tableRecordULAZR = 117,
	tableRecordULXR = 118,
	tableRecordULYR = 119,
	tableRecordULZR = 120,
	tableRecordM0XL = 121,
	tableRecordM0YL = 122,
	tableRecordM1YL = 123,
	tableRecordM2XL = 124,
	tableRecordM2YL = 125,
	tableRecordM2ZL = 126,
	tableRecordM0X = 127,
	tableRecordM0Y = 128,
	tableRecordM1Y = 129,
	tableRecordM2X = 130,
	tableRecordM2Y = 131,
	tableRecordM2Z = 132,
	tableRecordR0XI = 133,
	tableRecordR0YI = 134,
	tableRecordR1YI = 135,
	tableRecordR2XI = 136,
	tableRecordR2YI = 137,
	tableRecordR2ZI = 138,
	tableRecordR0X = 139,
	tableRecordR0Y = 140,
	tableRecordR1Y = 141,
	tableRecordR2X = 142,
	tableRecordR2Y = 143,
	tableRecordR2Z = 144,
	tableRecordE0XI = 145,
	tableRecordE0YI = 146,
	tableRecordE1YI = 147,
	tableRecordE2XI = 148,
	tableRecordE2YI = 149,
	tableRecordE2ZI = 150,
	tableRecordE0X = 151,
	tableRecordE0Y = 152,
	tableRecordE1Y = 153,
	tableRecordE2X = 154,
	tableRecordE2Y = 155,
	tableRecordE2Z = 156,
	tableRecordV0XL = 157,
	tableRecordV0YL = 158,
	tableRecordV1YL = 159,
	tableRecordV2XL = 160,
	tableRecordV2YL = 161,
	tableRecordV2ZL = 162,
	tableRecordV0X = 163,
	tableRecordV0Y = 164,
	tableRecordV1Y = 165,
	tableRecordV2X = 166,
	tableRecordV2Y = 167,
	tableRecordV2Z = 168,
	tableRecordV0XI = 169,
	tableRecordV0YI = 170,
	tableRecordV1YI = 171,
	tableRecordV2XI = 172,
	tableRecordV2YI = 173,
	tableRecordV2ZI = 174,
	tableRecordH0XL = 175,
	tableRecordH0YL = 176,
	tableRecordH1YL = 177,
	tableRecordH2XL = 178,
	tableRecordH2YL = 179,
	tableRecordH2ZL = 180,
	tableRecordH0X = 181,
	tableRecordH0Y = 182,
	tableRecordH1Y = 183,
	tableRecordH2X = 184,
	tableRecordH2Y = 185,
	tableRecordH2Z = 186,
	tableRecordL0XL = 187,
	tableRecordL0YL = 188,
	tableRecordL1YL = 189,
	tableRecordL2XL = 190,
	tableRecordL2YL = 191,
	tableRecordL2ZL = 192,
	tableRecordL0X = 193,
	tableRecordL0Y = 194,
	tableRecordL1Y = 195,
	tableRecordL2X = 196,
	tableRecordL2Y = 197,
	tableRecordL2Z = 198,
	tableRecordINIT = 199,
	tableRecordZERO = 200,
	tableRecordSYNC = 201,
	tableRecordREAD = 202,
	tableRecordSET = 203,
	tableRecordSSET = 204,
	tableRecordSUSE = 205,
	tableRecordLVIO = 206,
	tableRecordPP0 = 207,
	tableRecordPP1 = 208,
	tableRecordPP2 = 209,
	tableRecordPPO0 = 210,
	tableRecordPPO1 = 211,
	tableRecordPPO2 = 212,
	tableRecordA = 213,
	tableRecordB = 214,
	tableRecordLEGU = 215,
	tableRecordAEGU = 216,
	tableRecordPREC = 217,
	tableRecordMMAP = 218,
	tableRecordGEOM = 219,
	tableRecordTORAD = 220,
	tableRecordAUNIT = 221
} tableFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsAssert.h>
#include <epicsExport.h>
#ifdef __cplusplus
extern "C" {
#endif
static int tableRecordSizeOffset(dbRecordType *prt)
{
    tableRecord *prec = 0;

    assert(prt->no_fields == 222);
    prt->papFldDes[tableRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[tableRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[tableRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[tableRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[tableRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[tableRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[tableRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[tableRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[tableRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[tableRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[tableRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[tableRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[tableRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[tableRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[tableRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[tableRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[tableRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[tableRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[tableRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[tableRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[tableRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[tableRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[tableRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[tableRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[tableRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[tableRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[tableRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[tableRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[tableRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[tableRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[tableRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[tableRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[tableRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[tableRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[tableRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[tableRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[tableRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[tableRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[tableRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[tableRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[tableRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[tableRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[tableRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[tableRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[tableRecordVERS]->size = sizeof(prec->vers);
    prt->papFldDes[tableRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[tableRecordLX]->size = sizeof(prec->lx);
    prt->papFldDes[tableRecordLZ]->size = sizeof(prec->lz);
    prt->papFldDes[tableRecordSX]->size = sizeof(prec->sx);
    prt->papFldDes[tableRecordSY]->size = sizeof(prec->sy);
    prt->papFldDes[tableRecordSZ]->size = sizeof(prec->sz);
    prt->papFldDes[tableRecordRX]->size = sizeof(prec->rx);
    prt->papFldDes[tableRecordRY]->size = sizeof(prec->ry);
    prt->papFldDes[tableRecordRZ]->size = sizeof(prec->rz);
    prt->papFldDes[tableRecordYANG]->size = sizeof(prec->yang);
    prt->papFldDes[tableRecordAX]->size = sizeof(prec->ax);
    prt->papFldDes[tableRecordAY]->size = sizeof(prec->ay);
    prt->papFldDes[tableRecordAZ]->size = sizeof(prec->az);
    prt->papFldDes[tableRecordX]->size = sizeof(prec->x);
    prt->papFldDes[tableRecordY]->size = sizeof(prec->y);
    prt->papFldDes[tableRecordZ]->size = sizeof(prec->z);
    prt->papFldDes[tableRecordAX0]->size = sizeof(prec->ax0);
    prt->papFldDes[tableRecordAY0]->size = sizeof(prec->ay0);
    prt->papFldDes[tableRecordAZ0]->size = sizeof(prec->az0);
    prt->papFldDes[tableRecordX0]->size = sizeof(prec->x0);
    prt->papFldDes[tableRecordY0]->size = sizeof(prec->y0);
    prt->papFldDes[tableRecordZ0]->size = sizeof(prec->z0);
    prt->papFldDes[tableRecordAXL]->size = sizeof(prec->axl);
    prt->papFldDes[tableRecordAYL]->size = sizeof(prec->ayl);
    prt->papFldDes[tableRecordAZL]->size = sizeof(prec->azl);
    prt->papFldDes[tableRecordXL]->size = sizeof(prec->xl);
    prt->papFldDes[tableRecordYL]->size = sizeof(prec->yl);
    prt->papFldDes[tableRecordZL]->size = sizeof(prec->zl);
    prt->papFldDes[tableRecordAXRB]->size = sizeof(prec->axrb);
    prt->papFldDes[tableRecordAYRB]->size = sizeof(prec->ayrb);
    prt->papFldDes[tableRecordAZRB]->size = sizeof(prec->azrb);
    prt->papFldDes[tableRecordXRB]->size = sizeof(prec->xrb);
    prt->papFldDes[tableRecordYRB]->size = sizeof(prec->yrb);
    prt->papFldDes[tableRecordZRB]->size = sizeof(prec->zrb);
    prt->papFldDes[tableRecordEAX]->size = sizeof(prec->eax);
    prt->papFldDes[tableRecordEAY]->size = sizeof(prec->eay);
    prt->papFldDes[tableRecordEAZ]->size = sizeof(prec->eaz);
    prt->papFldDes[tableRecordEX]->size = sizeof(prec->ex);
    prt->papFldDes[tableRecordEY]->size = sizeof(prec->ey);
    prt->papFldDes[tableRecordEZ]->size = sizeof(prec->ez);
    prt->papFldDes[tableRecordHLAX]->size = sizeof(prec->hlax);
    prt->papFldDes[tableRecordHLAY]->size = sizeof(prec->hlay);
    prt->papFldDes[tableRecordHLAZ]->size = sizeof(prec->hlaz);
    prt->papFldDes[tableRecordHLX]->size = sizeof(prec->hlx);
    prt->papFldDes[tableRecordHLY]->size = sizeof(prec->hly);
    prt->papFldDes[tableRecordHLZ]->size = sizeof(prec->hlz);
    prt->papFldDes[tableRecordLLAX]->size = sizeof(prec->llax);
    prt->papFldDes[tableRecordLLAY]->size = sizeof(prec->llay);
    prt->papFldDes[tableRecordLLAZ]->size = sizeof(prec->llaz);
    prt->papFldDes[tableRecordLLX]->size = sizeof(prec->llx);
    prt->papFldDes[tableRecordLLY]->size = sizeof(prec->lly);
    prt->papFldDes[tableRecordLLZ]->size = sizeof(prec->llz);
    prt->papFldDes[tableRecordUHAX]->size = sizeof(prec->uhax);
    prt->papFldDes[tableRecordUHAY]->size = sizeof(prec->uhay);
    prt->papFldDes[tableRecordUHAZ]->size = sizeof(prec->uhaz);
    prt->papFldDes[tableRecordUHX]->size = sizeof(prec->uhx);
    prt->papFldDes[tableRecordUHY]->size = sizeof(prec->uhy);
    prt->papFldDes[tableRecordUHZ]->size = sizeof(prec->uhz);
    prt->papFldDes[tableRecordULAX]->size = sizeof(prec->ulax);
    prt->papFldDes[tableRecordULAY]->size = sizeof(prec->ulay);
    prt->papFldDes[tableRecordULAZ]->size = sizeof(prec->ulaz);
    prt->papFldDes[tableRecordULX]->size = sizeof(prec->ulx);
    prt->papFldDes[tableRecordULY]->size = sizeof(prec->uly);
    prt->papFldDes[tableRecordULZ]->size = sizeof(prec->ulz);
    prt->papFldDes[tableRecordUHAXR]->size = sizeof(prec->uhaxr);
    prt->papFldDes[tableRecordUHAYR]->size = sizeof(prec->uhayr);
    prt->papFldDes[tableRecordUHAZR]->size = sizeof(prec->uhazr);
    prt->papFldDes[tableRecordUHXR]->size = sizeof(prec->uhxr);
    prt->papFldDes[tableRecordUHYR]->size = sizeof(prec->uhyr);
    prt->papFldDes[tableRecordUHZR]->size = sizeof(prec->uhzr);
    prt->papFldDes[tableRecordULAXR]->size = sizeof(prec->ulaxr);
    prt->papFldDes[tableRecordULAYR]->size = sizeof(prec->ulayr);
    prt->papFldDes[tableRecordULAZR]->size = sizeof(prec->ulazr);
    prt->papFldDes[tableRecordULXR]->size = sizeof(prec->ulxr);
    prt->papFldDes[tableRecordULYR]->size = sizeof(prec->ulyr);
    prt->papFldDes[tableRecordULZR]->size = sizeof(prec->ulzr);
    prt->papFldDes[tableRecordM0XL]->size = sizeof(prec->m0xl);
    prt->papFldDes[tableRecordM0YL]->size = sizeof(prec->m0yl);
    prt->papFldDes[tableRecordM1YL]->size = sizeof(prec->m1yl);
    prt->papFldDes[tableRecordM2XL]->size = sizeof(prec->m2xl);
    prt->papFldDes[tableRecordM2YL]->size = sizeof(prec->m2yl);
    prt->papFldDes[tableRecordM2ZL]->size = sizeof(prec->m2zl);
    prt->papFldDes[tableRecordM0X]->size = sizeof(prec->m0x);
    prt->papFldDes[tableRecordM0Y]->size = sizeof(prec->m0y);
    prt->papFldDes[tableRecordM1Y]->size = sizeof(prec->m1y);
    prt->papFldDes[tableRecordM2X]->size = sizeof(prec->m2x);
    prt->papFldDes[tableRecordM2Y]->size = sizeof(prec->m2y);
    prt->papFldDes[tableRecordM2Z]->size = sizeof(prec->m2z);
    prt->papFldDes[tableRecordR0XI]->size = sizeof(prec->r0xi);
    prt->papFldDes[tableRecordR0YI]->size = sizeof(prec->r0yi);
    prt->papFldDes[tableRecordR1YI]->size = sizeof(prec->r1yi);
    prt->papFldDes[tableRecordR2XI]->size = sizeof(prec->r2xi);
    prt->papFldDes[tableRecordR2YI]->size = sizeof(prec->r2yi);
    prt->papFldDes[tableRecordR2ZI]->size = sizeof(prec->r2zi);
    prt->papFldDes[tableRecordR0X]->size = sizeof(prec->r0x);
    prt->papFldDes[tableRecordR0Y]->size = sizeof(prec->r0y);
    prt->papFldDes[tableRecordR1Y]->size = sizeof(prec->r1y);
    prt->papFldDes[tableRecordR2X]->size = sizeof(prec->r2x);
    prt->papFldDes[tableRecordR2Y]->size = sizeof(prec->r2y);
    prt->papFldDes[tableRecordR2Z]->size = sizeof(prec->r2z);
    prt->papFldDes[tableRecordE0XI]->size = sizeof(prec->e0xi);
    prt->papFldDes[tableRecordE0YI]->size = sizeof(prec->e0yi);
    prt->papFldDes[tableRecordE1YI]->size = sizeof(prec->e1yi);
    prt->papFldDes[tableRecordE2XI]->size = sizeof(prec->e2xi);
    prt->papFldDes[tableRecordE2YI]->size = sizeof(prec->e2yi);
    prt->papFldDes[tableRecordE2ZI]->size = sizeof(prec->e2zi);
    prt->papFldDes[tableRecordE0X]->size = sizeof(prec->e0x);
    prt->papFldDes[tableRecordE0Y]->size = sizeof(prec->e0y);
    prt->papFldDes[tableRecordE1Y]->size = sizeof(prec->e1y);
    prt->papFldDes[tableRecordE2X]->size = sizeof(prec->e2x);
    prt->papFldDes[tableRecordE2Y]->size = sizeof(prec->e2y);
    prt->papFldDes[tableRecordE2Z]->size = sizeof(prec->e2z);
    prt->papFldDes[tableRecordV0XL]->size = sizeof(prec->v0xl);
    prt->papFldDes[tableRecordV0YL]->size = sizeof(prec->v0yl);
    prt->papFldDes[tableRecordV1YL]->size = sizeof(prec->v1yl);
    prt->papFldDes[tableRecordV2XL]->size = sizeof(prec->v2xl);
    prt->papFldDes[tableRecordV2YL]->size = sizeof(prec->v2yl);
    prt->papFldDes[tableRecordV2ZL]->size = sizeof(prec->v2zl);
    prt->papFldDes[tableRecordV0X]->size = sizeof(prec->v0x);
    prt->papFldDes[tableRecordV0Y]->size = sizeof(prec->v0y);
    prt->papFldDes[tableRecordV1Y]->size = sizeof(prec->v1y);
    prt->papFldDes[tableRecordV2X]->size = sizeof(prec->v2x);
    prt->papFldDes[tableRecordV2Y]->size = sizeof(prec->v2y);
    prt->papFldDes[tableRecordV2Z]->size = sizeof(prec->v2z);
    prt->papFldDes[tableRecordV0XI]->size = sizeof(prec->v0xi);
    prt->papFldDes[tableRecordV0YI]->size = sizeof(prec->v0yi);
    prt->papFldDes[tableRecordV1YI]->size = sizeof(prec->v1yi);
    prt->papFldDes[tableRecordV2XI]->size = sizeof(prec->v2xi);
    prt->papFldDes[tableRecordV2YI]->size = sizeof(prec->v2yi);
    prt->papFldDes[tableRecordV2ZI]->size = sizeof(prec->v2zi);
    prt->papFldDes[tableRecordH0XL]->size = sizeof(prec->h0xl);
    prt->papFldDes[tableRecordH0YL]->size = sizeof(prec->h0yl);
    prt->papFldDes[tableRecordH1YL]->size = sizeof(prec->h1yl);
    prt->papFldDes[tableRecordH2XL]->size = sizeof(prec->h2xl);
    prt->papFldDes[tableRecordH2YL]->size = sizeof(prec->h2yl);
    prt->papFldDes[tableRecordH2ZL]->size = sizeof(prec->h2zl);
    prt->papFldDes[tableRecordH0X]->size = sizeof(prec->h0x);
    prt->papFldDes[tableRecordH0Y]->size = sizeof(prec->h0y);
    prt->papFldDes[tableRecordH1Y]->size = sizeof(prec->h1y);
    prt->papFldDes[tableRecordH2X]->size = sizeof(prec->h2x);
    prt->papFldDes[tableRecordH2Y]->size = sizeof(prec->h2y);
    prt->papFldDes[tableRecordH2Z]->size = sizeof(prec->h2z);
    prt->papFldDes[tableRecordL0XL]->size = sizeof(prec->l0xl);
    prt->papFldDes[tableRecordL0YL]->size = sizeof(prec->l0yl);
    prt->papFldDes[tableRecordL1YL]->size = sizeof(prec->l1yl);
    prt->papFldDes[tableRecordL2XL]->size = sizeof(prec->l2xl);
    prt->papFldDes[tableRecordL2YL]->size = sizeof(prec->l2yl);
    prt->papFldDes[tableRecordL2ZL]->size = sizeof(prec->l2zl);
    prt->papFldDes[tableRecordL0X]->size = sizeof(prec->l0x);
    prt->papFldDes[tableRecordL0Y]->size = sizeof(prec->l0y);
    prt->papFldDes[tableRecordL1Y]->size = sizeof(prec->l1y);
    prt->papFldDes[tableRecordL2X]->size = sizeof(prec->l2x);
    prt->papFldDes[tableRecordL2Y]->size = sizeof(prec->l2y);
    prt->papFldDes[tableRecordL2Z]->size = sizeof(prec->l2z);
    prt->papFldDes[tableRecordINIT]->size = sizeof(prec->init);
    prt->papFldDes[tableRecordZERO]->size = sizeof(prec->zero);
    prt->papFldDes[tableRecordSYNC]->size = sizeof(prec->sync);
    prt->papFldDes[tableRecordREAD]->size = sizeof(prec->read);
    prt->papFldDes[tableRecordSET]->size = sizeof(prec->set);
    prt->papFldDes[tableRecordSSET]->size = sizeof(prec->sset);
    prt->papFldDes[tableRecordSUSE]->size = sizeof(prec->suse);
    prt->papFldDes[tableRecordLVIO]->size = sizeof(prec->lvio);
    prt->papFldDes[tableRecordPP0]->size = sizeof(prec->pp0);
    prt->papFldDes[tableRecordPP1]->size = sizeof(prec->pp1);
    prt->papFldDes[tableRecordPP2]->size = sizeof(prec->pp2);
    prt->papFldDes[tableRecordPPO0]->size = sizeof(prec->ppo0);
    prt->papFldDes[tableRecordPPO1]->size = sizeof(prec->ppo1);
    prt->papFldDes[tableRecordPPO2]->size = sizeof(prec->ppo2);
    prt->papFldDes[tableRecordA]->size = sizeof(prec->a);
    prt->papFldDes[tableRecordB]->size = sizeof(prec->b);
    prt->papFldDes[tableRecordLEGU]->size = sizeof(prec->legu);
    prt->papFldDes[tableRecordAEGU]->size = sizeof(prec->aegu);
    prt->papFldDes[tableRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[tableRecordMMAP]->size = sizeof(prec->mmap);
    prt->papFldDes[tableRecordGEOM]->size = sizeof(prec->geom);
    prt->papFldDes[tableRecordTORAD]->size = sizeof(prec->torad);
    prt->papFldDes[tableRecordAUNIT]->size = sizeof(prec->aunit);
    prt->papFldDes[tableRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[tableRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[tableRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[tableRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[tableRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[tableRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[tableRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[tableRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[tableRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[tableRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[tableRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[tableRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[tableRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[tableRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[tableRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[tableRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[tableRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[tableRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[tableRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[tableRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[tableRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[tableRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[tableRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[tableRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[tableRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[tableRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[tableRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[tableRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[tableRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[tableRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[tableRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[tableRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[tableRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[tableRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[tableRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[tableRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[tableRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[tableRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[tableRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[tableRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[tableRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[tableRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[tableRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[tableRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[tableRecordVERS]->offset = (unsigned short)((char *)&prec->vers - (char *)prec);
    prt->papFldDes[tableRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[tableRecordLX]->offset = (unsigned short)((char *)&prec->lx - (char *)prec);
    prt->papFldDes[tableRecordLZ]->offset = (unsigned short)((char *)&prec->lz - (char *)prec);
    prt->papFldDes[tableRecordSX]->offset = (unsigned short)((char *)&prec->sx - (char *)prec);
    prt->papFldDes[tableRecordSY]->offset = (unsigned short)((char *)&prec->sy - (char *)prec);
    prt->papFldDes[tableRecordSZ]->offset = (unsigned short)((char *)&prec->sz - (char *)prec);
    prt->papFldDes[tableRecordRX]->offset = (unsigned short)((char *)&prec->rx - (char *)prec);
    prt->papFldDes[tableRecordRY]->offset = (unsigned short)((char *)&prec->ry - (char *)prec);
    prt->papFldDes[tableRecordRZ]->offset = (unsigned short)((char *)&prec->rz - (char *)prec);
    prt->papFldDes[tableRecordYANG]->offset = (unsigned short)((char *)&prec->yang - (char *)prec);
    prt->papFldDes[tableRecordAX]->offset = (unsigned short)((char *)&prec->ax - (char *)prec);
    prt->papFldDes[tableRecordAY]->offset = (unsigned short)((char *)&prec->ay - (char *)prec);
    prt->papFldDes[tableRecordAZ]->offset = (unsigned short)((char *)&prec->az - (char *)prec);
    prt->papFldDes[tableRecordX]->offset = (unsigned short)((char *)&prec->x - (char *)prec);
    prt->papFldDes[tableRecordY]->offset = (unsigned short)((char *)&prec->y - (char *)prec);
    prt->papFldDes[tableRecordZ]->offset = (unsigned short)((char *)&prec->z - (char *)prec);
    prt->papFldDes[tableRecordAX0]->offset = (unsigned short)((char *)&prec->ax0 - (char *)prec);
    prt->papFldDes[tableRecordAY0]->offset = (unsigned short)((char *)&prec->ay0 - (char *)prec);
    prt->papFldDes[tableRecordAZ0]->offset = (unsigned short)((char *)&prec->az0 - (char *)prec);
    prt->papFldDes[tableRecordX0]->offset = (unsigned short)((char *)&prec->x0 - (char *)prec);
    prt->papFldDes[tableRecordY0]->offset = (unsigned short)((char *)&prec->y0 - (char *)prec);
    prt->papFldDes[tableRecordZ0]->offset = (unsigned short)((char *)&prec->z0 - (char *)prec);
    prt->papFldDes[tableRecordAXL]->offset = (unsigned short)((char *)&prec->axl - (char *)prec);
    prt->papFldDes[tableRecordAYL]->offset = (unsigned short)((char *)&prec->ayl - (char *)prec);
    prt->papFldDes[tableRecordAZL]->offset = (unsigned short)((char *)&prec->azl - (char *)prec);
    prt->papFldDes[tableRecordXL]->offset = (unsigned short)((char *)&prec->xl - (char *)prec);
    prt->papFldDes[tableRecordYL]->offset = (unsigned short)((char *)&prec->yl - (char *)prec);
    prt->papFldDes[tableRecordZL]->offset = (unsigned short)((char *)&prec->zl - (char *)prec);
    prt->papFldDes[tableRecordAXRB]->offset = (unsigned short)((char *)&prec->axrb - (char *)prec);
    prt->papFldDes[tableRecordAYRB]->offset = (unsigned short)((char *)&prec->ayrb - (char *)prec);
    prt->papFldDes[tableRecordAZRB]->offset = (unsigned short)((char *)&prec->azrb - (char *)prec);
    prt->papFldDes[tableRecordXRB]->offset = (unsigned short)((char *)&prec->xrb - (char *)prec);
    prt->papFldDes[tableRecordYRB]->offset = (unsigned short)((char *)&prec->yrb - (char *)prec);
    prt->papFldDes[tableRecordZRB]->offset = (unsigned short)((char *)&prec->zrb - (char *)prec);
    prt->papFldDes[tableRecordEAX]->offset = (unsigned short)((char *)&prec->eax - (char *)prec);
    prt->papFldDes[tableRecordEAY]->offset = (unsigned short)((char *)&prec->eay - (char *)prec);
    prt->papFldDes[tableRecordEAZ]->offset = (unsigned short)((char *)&prec->eaz - (char *)prec);
    prt->papFldDes[tableRecordEX]->offset = (unsigned short)((char *)&prec->ex - (char *)prec);
    prt->papFldDes[tableRecordEY]->offset = (unsigned short)((char *)&prec->ey - (char *)prec);
    prt->papFldDes[tableRecordEZ]->offset = (unsigned short)((char *)&prec->ez - (char *)prec);
    prt->papFldDes[tableRecordHLAX]->offset = (unsigned short)((char *)&prec->hlax - (char *)prec);
    prt->papFldDes[tableRecordHLAY]->offset = (unsigned short)((char *)&prec->hlay - (char *)prec);
    prt->papFldDes[tableRecordHLAZ]->offset = (unsigned short)((char *)&prec->hlaz - (char *)prec);
    prt->papFldDes[tableRecordHLX]->offset = (unsigned short)((char *)&prec->hlx - (char *)prec);
    prt->papFldDes[tableRecordHLY]->offset = (unsigned short)((char *)&prec->hly - (char *)prec);
    prt->papFldDes[tableRecordHLZ]->offset = (unsigned short)((char *)&prec->hlz - (char *)prec);
    prt->papFldDes[tableRecordLLAX]->offset = (unsigned short)((char *)&prec->llax - (char *)prec);
    prt->papFldDes[tableRecordLLAY]->offset = (unsigned short)((char *)&prec->llay - (char *)prec);
    prt->papFldDes[tableRecordLLAZ]->offset = (unsigned short)((char *)&prec->llaz - (char *)prec);
    prt->papFldDes[tableRecordLLX]->offset = (unsigned short)((char *)&prec->llx - (char *)prec);
    prt->papFldDes[tableRecordLLY]->offset = (unsigned short)((char *)&prec->lly - (char *)prec);
    prt->papFldDes[tableRecordLLZ]->offset = (unsigned short)((char *)&prec->llz - (char *)prec);
    prt->papFldDes[tableRecordUHAX]->offset = (unsigned short)((char *)&prec->uhax - (char *)prec);
    prt->papFldDes[tableRecordUHAY]->offset = (unsigned short)((char *)&prec->uhay - (char *)prec);
    prt->papFldDes[tableRecordUHAZ]->offset = (unsigned short)((char *)&prec->uhaz - (char *)prec);
    prt->papFldDes[tableRecordUHX]->offset = (unsigned short)((char *)&prec->uhx - (char *)prec);
    prt->papFldDes[tableRecordUHY]->offset = (unsigned short)((char *)&prec->uhy - (char *)prec);
    prt->papFldDes[tableRecordUHZ]->offset = (unsigned short)((char *)&prec->uhz - (char *)prec);
    prt->papFldDes[tableRecordULAX]->offset = (unsigned short)((char *)&prec->ulax - (char *)prec);
    prt->papFldDes[tableRecordULAY]->offset = (unsigned short)((char *)&prec->ulay - (char *)prec);
    prt->papFldDes[tableRecordULAZ]->offset = (unsigned short)((char *)&prec->ulaz - (char *)prec);
    prt->papFldDes[tableRecordULX]->offset = (unsigned short)((char *)&prec->ulx - (char *)prec);
    prt->papFldDes[tableRecordULY]->offset = (unsigned short)((char *)&prec->uly - (char *)prec);
    prt->papFldDes[tableRecordULZ]->offset = (unsigned short)((char *)&prec->ulz - (char *)prec);
    prt->papFldDes[tableRecordUHAXR]->offset = (unsigned short)((char *)&prec->uhaxr - (char *)prec);
    prt->papFldDes[tableRecordUHAYR]->offset = (unsigned short)((char *)&prec->uhayr - (char *)prec);
    prt->papFldDes[tableRecordUHAZR]->offset = (unsigned short)((char *)&prec->uhazr - (char *)prec);
    prt->papFldDes[tableRecordUHXR]->offset = (unsigned short)((char *)&prec->uhxr - (char *)prec);
    prt->papFldDes[tableRecordUHYR]->offset = (unsigned short)((char *)&prec->uhyr - (char *)prec);
    prt->papFldDes[tableRecordUHZR]->offset = (unsigned short)((char *)&prec->uhzr - (char *)prec);
    prt->papFldDes[tableRecordULAXR]->offset = (unsigned short)((char *)&prec->ulaxr - (char *)prec);
    prt->papFldDes[tableRecordULAYR]->offset = (unsigned short)((char *)&prec->ulayr - (char *)prec);
    prt->papFldDes[tableRecordULAZR]->offset = (unsigned short)((char *)&prec->ulazr - (char *)prec);
    prt->papFldDes[tableRecordULXR]->offset = (unsigned short)((char *)&prec->ulxr - (char *)prec);
    prt->papFldDes[tableRecordULYR]->offset = (unsigned short)((char *)&prec->ulyr - (char *)prec);
    prt->papFldDes[tableRecordULZR]->offset = (unsigned short)((char *)&prec->ulzr - (char *)prec);
    prt->papFldDes[tableRecordM0XL]->offset = (unsigned short)((char *)&prec->m0xl - (char *)prec);
    prt->papFldDes[tableRecordM0YL]->offset = (unsigned short)((char *)&prec->m0yl - (char *)prec);
    prt->papFldDes[tableRecordM1YL]->offset = (unsigned short)((char *)&prec->m1yl - (char *)prec);
    prt->papFldDes[tableRecordM2XL]->offset = (unsigned short)((char *)&prec->m2xl - (char *)prec);
    prt->papFldDes[tableRecordM2YL]->offset = (unsigned short)((char *)&prec->m2yl - (char *)prec);
    prt->papFldDes[tableRecordM2ZL]->offset = (unsigned short)((char *)&prec->m2zl - (char *)prec);
    prt->papFldDes[tableRecordM0X]->offset = (unsigned short)((char *)&prec->m0x - (char *)prec);
    prt->papFldDes[tableRecordM0Y]->offset = (unsigned short)((char *)&prec->m0y - (char *)prec);
    prt->papFldDes[tableRecordM1Y]->offset = (unsigned short)((char *)&prec->m1y - (char *)prec);
    prt->papFldDes[tableRecordM2X]->offset = (unsigned short)((char *)&prec->m2x - (char *)prec);
    prt->papFldDes[tableRecordM2Y]->offset = (unsigned short)((char *)&prec->m2y - (char *)prec);
    prt->papFldDes[tableRecordM2Z]->offset = (unsigned short)((char *)&prec->m2z - (char *)prec);
    prt->papFldDes[tableRecordR0XI]->offset = (unsigned short)((char *)&prec->r0xi - (char *)prec);
    prt->papFldDes[tableRecordR0YI]->offset = (unsigned short)((char *)&prec->r0yi - (char *)prec);
    prt->papFldDes[tableRecordR1YI]->offset = (unsigned short)((char *)&prec->r1yi - (char *)prec);
    prt->papFldDes[tableRecordR2XI]->offset = (unsigned short)((char *)&prec->r2xi - (char *)prec);
    prt->papFldDes[tableRecordR2YI]->offset = (unsigned short)((char *)&prec->r2yi - (char *)prec);
    prt->papFldDes[tableRecordR2ZI]->offset = (unsigned short)((char *)&prec->r2zi - (char *)prec);
    prt->papFldDes[tableRecordR0X]->offset = (unsigned short)((char *)&prec->r0x - (char *)prec);
    prt->papFldDes[tableRecordR0Y]->offset = (unsigned short)((char *)&prec->r0y - (char *)prec);
    prt->papFldDes[tableRecordR1Y]->offset = (unsigned short)((char *)&prec->r1y - (char *)prec);
    prt->papFldDes[tableRecordR2X]->offset = (unsigned short)((char *)&prec->r2x - (char *)prec);
    prt->papFldDes[tableRecordR2Y]->offset = (unsigned short)((char *)&prec->r2y - (char *)prec);
    prt->papFldDes[tableRecordR2Z]->offset = (unsigned short)((char *)&prec->r2z - (char *)prec);
    prt->papFldDes[tableRecordE0XI]->offset = (unsigned short)((char *)&prec->e0xi - (char *)prec);
    prt->papFldDes[tableRecordE0YI]->offset = (unsigned short)((char *)&prec->e0yi - (char *)prec);
    prt->papFldDes[tableRecordE1YI]->offset = (unsigned short)((char *)&prec->e1yi - (char *)prec);
    prt->papFldDes[tableRecordE2XI]->offset = (unsigned short)((char *)&prec->e2xi - (char *)prec);
    prt->papFldDes[tableRecordE2YI]->offset = (unsigned short)((char *)&prec->e2yi - (char *)prec);
    prt->papFldDes[tableRecordE2ZI]->offset = (unsigned short)((char *)&prec->e2zi - (char *)prec);
    prt->papFldDes[tableRecordE0X]->offset = (unsigned short)((char *)&prec->e0x - (char *)prec);
    prt->papFldDes[tableRecordE0Y]->offset = (unsigned short)((char *)&prec->e0y - (char *)prec);
    prt->papFldDes[tableRecordE1Y]->offset = (unsigned short)((char *)&prec->e1y - (char *)prec);
    prt->papFldDes[tableRecordE2X]->offset = (unsigned short)((char *)&prec->e2x - (char *)prec);
    prt->papFldDes[tableRecordE2Y]->offset = (unsigned short)((char *)&prec->e2y - (char *)prec);
    prt->papFldDes[tableRecordE2Z]->offset = (unsigned short)((char *)&prec->e2z - (char *)prec);
    prt->papFldDes[tableRecordV0XL]->offset = (unsigned short)((char *)&prec->v0xl - (char *)prec);
    prt->papFldDes[tableRecordV0YL]->offset = (unsigned short)((char *)&prec->v0yl - (char *)prec);
    prt->papFldDes[tableRecordV1YL]->offset = (unsigned short)((char *)&prec->v1yl - (char *)prec);
    prt->papFldDes[tableRecordV2XL]->offset = (unsigned short)((char *)&prec->v2xl - (char *)prec);
    prt->papFldDes[tableRecordV2YL]->offset = (unsigned short)((char *)&prec->v2yl - (char *)prec);
    prt->papFldDes[tableRecordV2ZL]->offset = (unsigned short)((char *)&prec->v2zl - (char *)prec);
    prt->papFldDes[tableRecordV0X]->offset = (unsigned short)((char *)&prec->v0x - (char *)prec);
    prt->papFldDes[tableRecordV0Y]->offset = (unsigned short)((char *)&prec->v0y - (char *)prec);
    prt->papFldDes[tableRecordV1Y]->offset = (unsigned short)((char *)&prec->v1y - (char *)prec);
    prt->papFldDes[tableRecordV2X]->offset = (unsigned short)((char *)&prec->v2x - (char *)prec);
    prt->papFldDes[tableRecordV2Y]->offset = (unsigned short)((char *)&prec->v2y - (char *)prec);
    prt->papFldDes[tableRecordV2Z]->offset = (unsigned short)((char *)&prec->v2z - (char *)prec);
    prt->papFldDes[tableRecordV0XI]->offset = (unsigned short)((char *)&prec->v0xi - (char *)prec);
    prt->papFldDes[tableRecordV0YI]->offset = (unsigned short)((char *)&prec->v0yi - (char *)prec);
    prt->papFldDes[tableRecordV1YI]->offset = (unsigned short)((char *)&prec->v1yi - (char *)prec);
    prt->papFldDes[tableRecordV2XI]->offset = (unsigned short)((char *)&prec->v2xi - (char *)prec);
    prt->papFldDes[tableRecordV2YI]->offset = (unsigned short)((char *)&prec->v2yi - (char *)prec);
    prt->papFldDes[tableRecordV2ZI]->offset = (unsigned short)((char *)&prec->v2zi - (char *)prec);
    prt->papFldDes[tableRecordH0XL]->offset = (unsigned short)((char *)&prec->h0xl - (char *)prec);
    prt->papFldDes[tableRecordH0YL]->offset = (unsigned short)((char *)&prec->h0yl - (char *)prec);
    prt->papFldDes[tableRecordH1YL]->offset = (unsigned short)((char *)&prec->h1yl - (char *)prec);
    prt->papFldDes[tableRecordH2XL]->offset = (unsigned short)((char *)&prec->h2xl - (char *)prec);
    prt->papFldDes[tableRecordH2YL]->offset = (unsigned short)((char *)&prec->h2yl - (char *)prec);
    prt->papFldDes[tableRecordH2ZL]->offset = (unsigned short)((char *)&prec->h2zl - (char *)prec);
    prt->papFldDes[tableRecordH0X]->offset = (unsigned short)((char *)&prec->h0x - (char *)prec);
    prt->papFldDes[tableRecordH0Y]->offset = (unsigned short)((char *)&prec->h0y - (char *)prec);
    prt->papFldDes[tableRecordH1Y]->offset = (unsigned short)((char *)&prec->h1y - (char *)prec);
    prt->papFldDes[tableRecordH2X]->offset = (unsigned short)((char *)&prec->h2x - (char *)prec);
    prt->papFldDes[tableRecordH2Y]->offset = (unsigned short)((char *)&prec->h2y - (char *)prec);
    prt->papFldDes[tableRecordH2Z]->offset = (unsigned short)((char *)&prec->h2z - (char *)prec);
    prt->papFldDes[tableRecordL0XL]->offset = (unsigned short)((char *)&prec->l0xl - (char *)prec);
    prt->papFldDes[tableRecordL0YL]->offset = (unsigned short)((char *)&prec->l0yl - (char *)prec);
    prt->papFldDes[tableRecordL1YL]->offset = (unsigned short)((char *)&prec->l1yl - (char *)prec);
    prt->papFldDes[tableRecordL2XL]->offset = (unsigned short)((char *)&prec->l2xl - (char *)prec);
    prt->papFldDes[tableRecordL2YL]->offset = (unsigned short)((char *)&prec->l2yl - (char *)prec);
    prt->papFldDes[tableRecordL2ZL]->offset = (unsigned short)((char *)&prec->l2zl - (char *)prec);
    prt->papFldDes[tableRecordL0X]->offset = (unsigned short)((char *)&prec->l0x - (char *)prec);
    prt->papFldDes[tableRecordL0Y]->offset = (unsigned short)((char *)&prec->l0y - (char *)prec);
    prt->papFldDes[tableRecordL1Y]->offset = (unsigned short)((char *)&prec->l1y - (char *)prec);
    prt->papFldDes[tableRecordL2X]->offset = (unsigned short)((char *)&prec->l2x - (char *)prec);
    prt->papFldDes[tableRecordL2Y]->offset = (unsigned short)((char *)&prec->l2y - (char *)prec);
    prt->papFldDes[tableRecordL2Z]->offset = (unsigned short)((char *)&prec->l2z - (char *)prec);
    prt->papFldDes[tableRecordINIT]->offset = (unsigned short)((char *)&prec->init - (char *)prec);
    prt->papFldDes[tableRecordZERO]->offset = (unsigned short)((char *)&prec->zero - (char *)prec);
    prt->papFldDes[tableRecordSYNC]->offset = (unsigned short)((char *)&prec->sync - (char *)prec);
    prt->papFldDes[tableRecordREAD]->offset = (unsigned short)((char *)&prec->read - (char *)prec);
    prt->papFldDes[tableRecordSET]->offset = (unsigned short)((char *)&prec->set - (char *)prec);
    prt->papFldDes[tableRecordSSET]->offset = (unsigned short)((char *)&prec->sset - (char *)prec);
    prt->papFldDes[tableRecordSUSE]->offset = (unsigned short)((char *)&prec->suse - (char *)prec);
    prt->papFldDes[tableRecordLVIO]->offset = (unsigned short)((char *)&prec->lvio - (char *)prec);
    prt->papFldDes[tableRecordPP0]->offset = (unsigned short)((char *)&prec->pp0 - (char *)prec);
    prt->papFldDes[tableRecordPP1]->offset = (unsigned short)((char *)&prec->pp1 - (char *)prec);
    prt->papFldDes[tableRecordPP2]->offset = (unsigned short)((char *)&prec->pp2 - (char *)prec);
    prt->papFldDes[tableRecordPPO0]->offset = (unsigned short)((char *)&prec->ppo0 - (char *)prec);
    prt->papFldDes[tableRecordPPO1]->offset = (unsigned short)((char *)&prec->ppo1 - (char *)prec);
    prt->papFldDes[tableRecordPPO2]->offset = (unsigned short)((char *)&prec->ppo2 - (char *)prec);
    prt->papFldDes[tableRecordA]->offset = (unsigned short)((char *)&prec->a - (char *)prec);
    prt->papFldDes[tableRecordB]->offset = (unsigned short)((char *)&prec->b - (char *)prec);
    prt->papFldDes[tableRecordLEGU]->offset = (unsigned short)((char *)&prec->legu - (char *)prec);
    prt->papFldDes[tableRecordAEGU]->offset = (unsigned short)((char *)&prec->aegu - (char *)prec);
    prt->papFldDes[tableRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[tableRecordMMAP]->offset = (unsigned short)((char *)&prec->mmap - (char *)prec);
    prt->papFldDes[tableRecordGEOM]->offset = (unsigned short)((char *)&prec->geom - (char *)prec);
    prt->papFldDes[tableRecordTORAD]->offset = (unsigned short)((char *)&prec->torad - (char *)prec);
    prt->papFldDes[tableRecordAUNIT]->offset = (unsigned short)((char *)&prec->aunit - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(tableRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_tableRecord_H */
