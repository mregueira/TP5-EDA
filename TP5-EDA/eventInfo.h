#ifndef _H_EVENT_INFO

#define _H_EVENT_INFO

enum { QUIT, NO_MOVE, START_MOVE, STOP_MOVE, START_JUMP, STOP_JUMP } eventype;

class eventInfo {
private:
	unsigned int eventData;
	unsigned int userData;

public:
	eventInfo(){}
	eventInfo(unsigned int eventData_, unsigned int userData_);

	unsigned int getEventData();
	unsigned int getUserData();
	void setEventData(unsigned int eventData_);
	void setUserData(unsigned int userData_);
};

#endif // !_H_EVENT_INFO

