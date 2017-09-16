#include "stdafx.h"
#include "viewer.h"
#include <iostream>
#include <string>
#include <allegro5\allegro_image.h>

#define DISP_W 1920
#define DISP_H 696

using namespace std;

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

	if (!al_init()) {
		cout << "failed to initialize allegro!\n" << endl;
		ret = 0;
	}

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
