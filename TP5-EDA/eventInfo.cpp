#include "eventInfo.h"

eventInfo::eventInfo(unsigned int eventData_, unsigned int userData_) {
	this->eventData = eventData_;
	this->userData = userData_;
}


/********************************Getters************************************/
unsigned int eventInfo::getEventData() { return this->eventData; };
unsigned int eventInfo::getUserData() { return this->userData; };


/********************************Setters************************************/
void eventInfo::setEventData(unsigned int eventData_) { this->eventData = eventData_;  };
void eventInfo::setUserData(unsigned int userData_) { this->userData = userData_;  };