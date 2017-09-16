// TP5EDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "eventInfo.h"

void dipatch(eventInfo& cevent);


int main()
{
	eventInfo cevent;

	do {
		cevent = getNextEvent();
		if (cevent.getEventData != NO_MOVE)
			dipatch(cevent);
	} while (cevent.getEventData != QUIT);

    return 0;
}


void dipatch(eventInfo& cevent) {

}



