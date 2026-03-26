#include "dolphin.h"
#include "dolphin/types.h"
#include "macros.h"
#include "sys/timer.h"

extern u8 framesThisStep;

BOOL timerTickDown(Timer timer) {
	ASSERTLINE(38, timer);
    ASSERTLINE(39, *timer >= 0);
    if(*timer != 0) {
        *timer -= framesThisStep;
        if(*timer <= 0) {
            timerReset(timer);
            return TRUE;
        }
	}
    return FALSE;
}

void timerSet(Timer timer, short initialVal) {
    ASSERTLINE(65, timer);
    ASSERTLINE(66, initialVal > 0);
    ASSERTLINE(67, *timer == 0);
	*timer = ((initialVal * 60) / 60);
}

void timerReset(Timer timer) {
    ASSERTLINE(81, timer);
    *timer = 0;
}

int timerGetTime(Timer timer) {
    ASSERTLINE(95, *timer >= 0);
	return *timer;
}
