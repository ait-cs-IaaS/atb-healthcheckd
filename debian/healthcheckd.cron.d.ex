#
# Regular cron jobs for the healthcheckd package.
#
0 4	* * *	root	[ -x /usr/bin/healthcheckd_maintenance ] && /usr/bin/healthcheckd_maintenance
