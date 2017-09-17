#ifndef VIEWER_H
#define VIEWER_H
#include <allegro5\allegro.h>
#include <string>

using namespace std;

#define WWALKING 15
#define WJUMP 10

class viewer
{
public:
	viewer();
	~viewer();
	int init_allegro(void);
	void close_allegro(void);
	void refresh(string status, unsigned int frames, double pos_x, double pos_y);
	void update_display(void);

private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *wwalking[WWALKING];
	ALLEGRO_BITMAP *wjump[WJUMP];
};

#endif // !VIEWER_H

