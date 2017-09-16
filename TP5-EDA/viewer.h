#pragma once
#include <allegro5\allegro.h>

#define WWALKING 15
#define WJUMP 10

class viewer
{
public:
	viewer();
	~viewer();
	int init_allegro(void);
	void close_allegro(void);

private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *wwalking[WWALKING];
	ALLEGRO_BITMAP *wjump[WJUMP];
};

