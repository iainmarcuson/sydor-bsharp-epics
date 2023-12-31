/* devLiAbDcm.c */
/*
 *      Author:  Marty Kraimer
 *      Date:   June 9, 1995
 *	Major revision July 22, 1996
 */
/*************************************************************************
* Copyright (c) 2003 The University of Chicago, as Operator of Argonne
* National Laboratory, the Regents of the University of California, as
* Operator of Los Alamos National Laboratory, and Leland Stanford Junior
* University, as the Operator of Stanford Linear Accelerator.
* This code is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
*************************************************************************/
#include <vxWorks.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <logLib.h>

#include "dbDefs.h"
#include "epicsDynLink.h"
#include "errlog.h"
#include "dbScan.h"
#include "alarm.h"
#include "dbDefs.h"
#include "dbStaticLib.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "errMdef.h"
#include "recSup.h"
#include "devSup.h"
#include "link.h"
#include "abDcm.h"
#include "longinRecord.h"
#include <epicsExport.h>

/*DSET for longin records*/
static long li_init();
static long li_init_record();
static long li_get_ioint_info();
static long li_read();
struct {
	long		number;
	DEVSUPFUN	dev_report;
	DEVSUPFUN	dev_init;
	DEVSUPFUN	dev_init_record;
	DEVSUPFUN	li_get_ioint_info;
	DEVSUPFUN	li_read;
}devLiAbDcm={
	5,
	NULL,
	li_init,
	li_init_record,
	li_get_ioint_info,
	li_read};
epicsExportAddress(dset,devLiAbDcm);
static abDcm *pabDcm=NULL;

static long li_init(int after)
{
    if(!after) {
	STATUS		rtn;
	SYM_TYPE	type;

	rtn = symFindByNameEPICS(sysSymTbl,"_abDcmTable",(void *)&pabDcm,&type);
	if(rtn!=OK) errlogPrintf("devLiAbDcm: cant locate abDcmTable\n");
    }
    return(0);
}

static long li_init_record(struct longinRecord *precord)
{
    struct link 	*plink = &precord->inp;
    char		*parm=NULL;
    unsigned short	table,word;
    char		*period;
    abDcmStatus		dcmStatus;
    char                parmSmall[80];
    int                 parmSize=0;

    if(!pabDcm) {
	precord->pact = TRUE; goto done;
    }
    parmSize = strlen(plink->value.instio.string)+1;
    parm = ((parmSize<=80) ? &parmSmall[0] : (char *)malloc(parmSize));
    strcpy(parm,plink->value.instio.string);
    /*parm has the form pvname.Tx[word]*/
    period = strchr(parm,'.');
    if(!period) {
	errlogPrintf("record %s INP %s is illegal\n",precord->name,period+1);
	precord->pact = TRUE; goto done;
    }
    if(sscanf(period+1,"T%hu[%hu]",&table,&word)!=2) {
	errlogPrintf("record %s INP %s is illegal\n",precord->name,period+1);
	precord->pact = TRUE; goto done;
    }
    *period = 0;
    dcmStatus = (*pabDcm->connect)(&precord->dpvt,parm,table,word,1);
    if(dcmStatus!=abDcmOK) {
	errlogPrintf("record %s abDcm.connect error %s\n",
	    precord->name,pabDcm->abDcmStatusMessage[dcmStatus]);
	precord->pact = TRUE; goto done;
    }
done:
    if(parmSize>80) free((void *)parm);
    return(0);
}

static long li_get_ioint_info(int cmd,struct longinRecord *precord,
    IOSCANPVT *ppvt)
{
    if(!pabDcm) return(0);
    if(!precord->dpvt) return(0);
    (*pabDcm->get_ioint_info)(precord->dpvt,cmd,ppvt);
    return(0);
}

static long li_read( struct longinRecord *precord)
{
    short	svalue;
    abDcmStatus dcmStatus;

    if(!pabDcm) {
	recGblSetSevr(precord,READ_ALARM,INVALID_ALARM);
	return(0);
    }
    dcmStatus = (*pabDcm->get_short)(precord->dpvt,&svalue);
    if(dcmStatus!=abDcmOK) {
	recGblSetSevr(precord,READ_ALARM,INVALID_ALARM);
	return(0);
    }
    precord->val = (long)svalue;
    precord->udf = FALSE;
    return(0);
}
