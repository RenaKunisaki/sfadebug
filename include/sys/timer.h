#include "dolphin/types.h"

typedef short* Timer;

BOOL timerTickDown(Timer timer);
void timerSet(Timer timer, short initialVal);
void timerReset(Timer timer);
int timerGetTime(Timer timer);
