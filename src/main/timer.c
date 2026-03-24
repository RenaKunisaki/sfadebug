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
