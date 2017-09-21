// TP5EDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "eventInfo.h"
#include "viewer.h"

using namespace std;

int main()
{
	if (!al_init()) {
		cout << "failed to initialize allegro!\n" << endl;
		return -1;
	}

	viewer view;

	int is_ok_v = view.init_allegro();
	if (!is_ok_v) {
		return -1; // No se inicio bien alguna cosa
	}

	eventInfo cevent;
	int is_ok = cevent.init_allegro_timer();
	if (!is_ok) {
		return -1; // No se pudo inicializar el timer
	}

	do {
		cevent.getNextEvent();
		cevent.dispatch(view);
	} while (cevent.getEventData() != QUIT);

    return 0;
}


/* Codigo de prueba del viewer
#include "viewer.h"


viewer view;

int is_ok_v = view.init_allegro();
if(!is_ok_v){
	return -1; // No se inicio bien alguna cosa
}

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

