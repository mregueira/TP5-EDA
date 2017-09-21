#include "stdafx.h"
#include "viewer.h"
#include <iostream>
#include <allegro5\allegro_image.h>

#define NORMAL_WORM 0
#define START_WORM_UP 6
#define END_WORM_UP 8
#define START_J_WORM_UP 1
#define END_J_WORM_UP 3
#define START_W_SEQ 9
#define END_W_SEQ 50
#define START_J_SEQ 4
#define END_J_SEQ 34
#define INDEX_ADJ -1

using namespace std;

#define W_SEQ 14
#define J_SEQ 31

const unsigned int w_seq[] = { 4,5,6,7,8,9,10,11,11,12,13,14,15,4 };
const unsigned int j_seq[] = { 4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10 };

viewer::viewer()
{
	display = nullptr;
	background = nullptr;
	for (int i = 0; i < WWALKING; i++)
	{
		wwalking[i] = nullptr;
	}
	for (int i = 0; i < WJUMP; i++)
	{
		wjump[i] = nullptr;
	}
}


viewer::~viewer()
{
	close_allegro();
}

int viewer::init_allegro(void)
{
	int ret = 1;

	if ((ret)&&(!al_init_image_addon())) {
		cout << "failed to initialize image addon !\n" << endl;
		ret = 0;
	}

	if (ret) {
		background = al_load_bitmap("Worms Images/Scenario.png");
		if (!background) {
			al_shutdown_image_addon();
			cout << "failed to load background" << endl;

		}
	}

	if (ret) {
		int img_load_ok = 1;
		for (int i = 0; i < WWALKING; i++)
		{
			string wwalk_num = "Worms Images/wwalking/wwalk-F";
			wwalk_num += to_string(i+1) + ".png";

			wwalking[i] = al_load_bitmap(wwalk_num.c_str());
			if (!wwalking[i]) {
				int pos = wwalk_num.find("wwalk");
				string img_failed = wwalk_num.substr(pos);
				cout << "failed to load image " << img_failed.c_str() << endl;
				img_load_ok = 0;
			}
		}

		if (!img_load_ok) {
			al_destroy_bitmap(background);
			for (int i = 0; i < WWALKING; i++) {
				if (wwalking[i] != nullptr) {
					al_destroy_bitmap(wwalking[i]);
				}
			}
			al_shutdown_image_addon();
			ret = 0;
		}
	}

	if (ret) {
		int img_load_ok = 1;
		for (int i = 0; i < WJUMP; i++)
		{
			string wjump_num = "Worms Images/wjump/wjump-F";
			wjump_num += to_string(i+1) + ".png";

			wjump[i] = al_load_bitmap(wjump_num.c_str());
			if (!wjump[i]) {
				int pos = wjump_num.find("wjump");
				string img_failed = wjump_num.substr(pos);
				cout << "failed to load image " << img_failed.c_str() << endl;
				img_load_ok = 0;
			}
		}

		if (!img_load_ok) {
			al_destroy_bitmap(background);
			for (int i = 0; i < WJUMP; i++) {
				if (wjump[i] != nullptr) {
					al_destroy_bitmap(wjump[i]);
				}
			}
			for (int i = 0; i < WWALKING; i++)
			{
				al_destroy_bitmap(wwalking[i]);
			}
			al_shutdown_image_addon();
			ret = 0;
		}
	}

	if (ret) {
		display = al_create_display(DISP_W, DISP_H);
		if (!display) {
			al_destroy_bitmap(background);
			for (int i = 0; i < WWALKING; i++)
			{
				al_destroy_bitmap(wwalking[i]);
			}
			for (int i = 0; i < WJUMP; i++)
			{
				al_destroy_bitmap(wjump[i]);
			}
			al_shutdown_image_addon();
			fprintf(stderr, "failed to create display!\n");
			ret = 0;
		}
	}

	return ret;
}

void viewer::close_allegro(void)
{
	al_destroy_bitmap(background);
	for (int i = 0; i < WWALKING; i++)
	{
		al_destroy_bitmap(wwalking[i]);
	}
	for (int i = 0; i < WJUMP; i++)
	{
		al_destroy_bitmap(wjump[i]);
	}
	al_shutdown_image_addon();
	al_destroy_display(display);
}

void viewer::refresh(string status, unsigned int frames, double pos_x, double pos_y)
{
	// funcion a corregir definicion
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(background, 0, 0, 0);

	if ((status == "idle")||(status == "monitor_moving")) {
		al_draw_bitmap(wwalking[NORMAL_WORM], pos_x, pos_y, 0);
	}
	else if (status == "moving") {
		if ((frames >= START_WORM_UP) && (frames <= END_WORM_UP)) { // Walk worm up 
			al_draw_bitmap(wwalking[frames - START_WORM_UP], pos_x, pos_y, 0);
		}
		else if ((frames >= START_W_SEQ)&&(frames <= END_W_SEQ)) { // Moving sequence
			unsigned int pic = (frames - START_W_SEQ) % W_SEQ;
			al_draw_bitmap(wwalking[w_seq[pic]], pos_x, pos_y, 0);
		}
	}
	else if (status == "jump") {
		if ((frames >= START_J_WORM_UP) && (frames <= END_J_WORM_UP)) { // Jump worm up
			al_draw_bitmap(wjump[frames - START_J_WORM_UP], pos_x, pos_y, 0);
		}
		else if ((frames >= START_J_SEQ)&&(frames <= END_J_SEQ)) { // Jumping sequence
			al_draw_bitmap(wjump[INDEX_ADJ + j_seq[frames - START_J_SEQ]], pos_x, pos_y, 0);
		}
	}
}

void viewer::update_display(void)
{
	al_flip_display();
}
