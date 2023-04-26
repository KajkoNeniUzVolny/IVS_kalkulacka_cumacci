#
# Regular cron jobs for the kaukulackaprocumacky package
#
0 4	* * *	root	[ -x /usr/bin/kaukulackaprocumacky_maintenance ] && /usr/bin/kaukulackaprocumacky_maintenance
