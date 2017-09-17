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

/* Codigo de prueba del viewer
#include "viewer.h"

#define W 1920
#define H 696

viewer view;

view.init_allegro();

for (int i = 0; i < 5; i++)
{
for (int f = 9; f <= 50; f++)
{
view.refresh("moving", f, (W / 2), ((H / 2) + 100));
view.update_display();
al_rest(0.02);
}
}
*/

