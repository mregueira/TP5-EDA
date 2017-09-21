#include "stdafx.h"
#include "eventInfo.h"
#include <iostream>

using namespace std;

void eventInfo::ignore_ev()
{
	// Nothing to do
}

eventInfo::eventInfo(unsigned int eventData_, unsigned int userData_) {
	this->eventData = eventData_;
	this->userData = userData_;
}

void eventInfo::getNextEvent()
{
	if ((ev.type) == ALLEGRO_EVENT_KEY_DOWN) {
		unsigned int key = ev.keyboard.keycode;
		if ((key == ALLEGRO_KEY_A) || (key == ALLEGRO_KEY_D) || (key == ALLEGRO_KEY_LEFT) || (key == ALLEGRO_KEY_RIGHT)) {
			setUserData(key);
			setEventData(ATM);
		}
		else if ((key == ALLEGRO_KEY_W) || (key == ALLEGRO_KEY_UP)) {
			setUserData(key);
			setEventData(ATS);
		}
	}
	else if ((ev.type) == ALLEGRO_EVENT_KEY_UP) {
		unsigned int key = ev.keyboard.keycode;
		if ((key == ALLEGRO_KEY_A) || (key == ALLEGRO_KEY_D) || (key == ALLEGRO_KEY_LEFT) || (key == ALLEGRO_KEY_RIGHT)) {
			setUserData(key);
			setEventData(STM);
		}
		else if ((key == ALLEGRO_KEY_W) || (key == ALLEGRO_KEY_UP)) {
			setUserData(key);
			setEventData(STS);
		}
	}
	else if ((ev.type) == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		setUserData(NULL);
		setEventData(QUIT);
	}
	else if ((ev.type) == ALLEGRO_EVENT_TIMER) {
		setUserData(NULL);
		setEventData(REFRESH);
	}
	else {
		setUserData(NULL);
		setEventData(NO_EVENT);
	}
}

void eventInfo::dispatch(viewer& view)
{
	switch (getEventData())
	{
	case QUIT:
		// No se hace nada aqui
		// Cuando sale del dispatcher termina el programa solo
		break;
	case ATM:
		// en userData esta la tecla valida apretada, se la pasa al worms
		// va a tener A, D, flecha izq o flecha der, en codigos de allegro 
		// que podes ver en el getNextEvent como se llama cada una
		break;
	case STM:
		// en userData esta la tecla valida soltada, se la pasa al worms
		// va a tener A, D, flecha izq o flecha der, en codigos de allegro 
		// que podes ver en el getNextEvent como se llama cada una
		break;
	case ATS:
		// en userData esta la tecla valida apretada, se la pasa al worms
		// va a tener W o flecha arriba, en codigos de allegro 
		// que podes ver en el getNextEvent como se llama cada una
		break;
	case STS:
		// en userData esta la tecla valida soltada, se la pasa al worms
		// va a tener W o flecha arriba, en codigos de allegro 
		// que podes ver en el getNextEvent como se llama cada una
		break;
	case REFRESH:
		// Aca llamar a refresh 2 veces, una con cada worm y luego llamar a update_display:
		// view.refresh(status, frames actuales que cuenta el worm 1, x, y)
		// view.refresh(status, frames actuales que cuenta el worm 2, x, y)
		// view.update_display(); - no recibe nada
		// done status es: "idle", "moving", "monitor_moving", "jump" 
		break;
	case NO_EVENT:
		ignore_ev();
		break;
	}
}

int eventInfo::init_allegro_timer()
{
	timerA = al_create_timer(1.0 / FPS);
	if (!timerA) {
		cout << "failed to create timer!\n" << endl;
		return 0;
	}

	al_start_timer(timerA);

	return 1;
}

// Getters //
// ------- //
unsigned int eventInfo::getEventData() { return this->eventData; }
unsigned int eventInfo::getUserData() { return this->userData; }
// ------- //

// Setters //
// ------- //
void eventInfo::setEventData(unsigned int eventData_) { this->eventData = eventData_;  }
void eventInfo::setUserData(unsigned int userData_) { this->userData = userData_;  }
// ------- //