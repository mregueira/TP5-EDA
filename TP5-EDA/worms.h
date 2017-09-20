#pragma once
#include <cmath>
#include "possition.h"
enum stateType{ idle, monitorMov, monitorJmp, moving, jumping, end_mov, end_jmp };
enum keyType{ move_left, move_right, jump};
enum direction {left, right};

class Physics
{
	const double gravity = 0.24;
	const double speedX=27;
	const double speedY = 4.5*sin(lngjmpAngle);
	const double lngjmpAngle = 60/3.141592;
	public:
	double getGrav();
	double getVx();
	double getVy();
	double getAng();
};

class worms
{
	stateType state = idle;
	unsigned int framecnt=0;
	unsigned int auxcnt = 0;
	direction dir;
	position pos;
	static Physics wormPhs;
	char Keys[3];
	
	
public:
	worms();
	~worms();
	bool Update();
	bool startMov(char);
	bool stopMov(char);
	bool startJum(char);
	bool stopJum(char);
	unsigned int getFrame();
	unsigned int getState();
	position getPos();
	int getDir();
	static double getPhys(char);

	bool setKeys(char left, char right, char jmp);
};

