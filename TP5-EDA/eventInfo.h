#ifndef _H_EVENT_INFO

#define _H_EVENT_INFO
#include "viewer.h"
#include <allegro5\allegro.h>

#define FPS 50.0
enum  eventype { QUIT, ATM, STM, ATS, STS, REFRESH, NO_EVENT };

class eventInfo {
private:
	void ignore_ev();
	unsigned int eventData;
	unsigned int userData;
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMER *timerA = nullptr;

public:
	eventInfo(){}
	eventInfo(unsigned int eventData_, unsigned int userData_);

	void getNextEvent();
	unsigned int getEventData();
	unsigned int getUserData();
	int init_allegro_timer();
	void dispatch(viewer& view);
	void setEventData(unsigned int eventData_);
	void setUserData(unsigned int userData_);
};

#endif // !_H_EVENT_INFO

