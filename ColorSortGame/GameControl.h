#ifndef _GAMECONTROL_H_
#define _GAMECONTROL_H_

#include "PublicHead.h"
#include "game.h"

class GameControl{
	public:
		bool G_init(SDL_Renderer *render, const char *file_name, int win_width, int win_height, int box_W, int box_H);
		bool G_run(SDL_Event &e, SDL_Renderer *render);
		bool WindowRender( SDL_Renderer *render);

	private:
		iGame g;
		char f_name[32];
		FILE *fp;
};

#endif
