TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

#----------------------------------------------------
# Create and install (or just install)
# databases, templates, substitutions like this
DB += AH401B.template
DB += AH501.template
DB += APS_EM.template
DB += NSLS_EM.template
DB += NSLS2_EM.template
DB += NSLS2_DAC.template
DB += TetrAMM.template
DB += BS_EM_PID.template
DB += quadEM.template
DB += quadEM_TimeSeries.template
DB += fdbk_send.db

#----------------------------------------------------
# If <anyname>.db template is not named <anyname>*.template add
# <anyname>_template = <templatename>

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
