/* NetHack 3.6	mhinput.h	$NHDT-Date$  $NHDT-Branch$:$NHDT-Revision$ */
/* NetHack 3.6	mhinput.h	$Date: 2009/05/06 10:59:49 $  $Revision: 1.6 $ */
/*	SCCS Id: @(#)mhinput.h	3.5	2005/01/23	*/
/* Copyright (C) 2001 by Alex Kompel 	 */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef MSWINInput_h
#define MSWINInput_h

/* nethack input queue - store/extract input events */
#include "winMS.h"

#define NHEVENT_CHAR	1
#define NHEVENT_MOUSE	2
typedef struct mswin_event {
	int type;
	union {
		struct {
			int  ch;
		} kbd;

		struct {
			int mod;
			int x, y;
		} ms;
	};
} MSNHEvent, *PMSNHEvent;

#define NHEVENT_KBD(c) { MSNHEvent e; e.type=NHEVENT_CHAR; e.kbd.ch=(c); mswin_input_push(&e); }
#define NHEVENT_MS(_mod, _x, _y) { MSNHEvent e; e.type=NHEVENT_MOUSE; e.ms.mod = (_mod); e.ms.x=(_x); e.ms.y=(_y); mswin_input_push(&e); }

void		mswin_nh_input_init(void);
int			mswin_have_input(void);
void		mswin_input_push(PMSNHEvent event);
PMSNHEvent	mswin_input_pop(void);
PMSNHEvent	mswin_input_peek(void);

#endif /* MSWINInput_h */

