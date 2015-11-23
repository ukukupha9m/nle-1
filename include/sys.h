/* NetHack 3.6	sys.h	$NHDT-Date: 1448241778 2015/11/23 01:22:58 $  $NHDT-Branch: master $:$NHDT-Revision: 1.26 $ */
/* Copyright (c) Kenneth Lorber, Kensington, Maryland, 2008. */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef SYS_H
#define SYS_H

struct sysopt {
    char *support; /* local support contact */
    char *recover; /* how to run recover - may be overridden by win port */
    char *wizards; /* space-separated list of usernames */
    char *fmtd_wizard_list; /* formatted version of wizards; null or "one"
                               or "one or two" or "one, two, or three", &c */
    char *explorers;  /* like wizards, but for access to explore mode */
    char *shellers;   /* like wizards, for ! command (-DSHELL); also ^Z */
    char *debugfiles; /* files to show debugplines in. '*' is all. */
    int env_dbgfl;    /*  1: debugfiles comes from getenv("DEBUGFILES")
                       *     so sysconf's DEBUGFILES shouldn't override it;
                       *  0: getenv() hasn't been attempted yet;
                       * -1: getenv() didn't find a value for DEBUGFILES.
                       */
    int maxplayers;
    /* record file */
    int persmax;
    int pers_is_uid;
    int entrymax;
    int pointsmin;
    int tt_oname_maxrank;
#ifdef PANICTRACE
    /* panic options */
    char *gdbpath;
    char *greppath;
    int panictrace_gdb;
#ifdef PANICTRACE_LIBC
    int panictrace_libc;
#endif
#endif
    int seduce;
    int check_save_uid; /* restoring savefile checks UID? */
};

extern struct sysopt sysopt;

#define SYSOPT_SEDUCE sysopt.seduce

#endif /* SYS_H */
