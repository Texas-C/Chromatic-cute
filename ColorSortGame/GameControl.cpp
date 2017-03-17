#include "GameControl.h"

bool GameControl::G_init( SDL_Renderer *render, const char *file_name, int win_width, int win_height, int box_W, int box_H)
{
	strcpy( this->f_name, file_name);
	fp = fopen( file_name, "r");
	int lg, xr, xg, xb, yr, yg, yb;
	fscanf(fp, "%d%d%d", &xr, &xg, &xb);
	fscanf(fp, "%d%d%d", &yr, &yg, &yb);
	fscanf(fp, "%d", &lg);

	this->g.setSize(box_W, box_H, lg);
	printf("%d %d\n", win_width, g.getSumWidth());
	this->g.setPosition( (win_width - g.getSumWidth()) / 2, (win_height  - box_H) / 2);
	this->g.setColor_left(xr, xg, xb);
	this->g.setColor_right(yr, yg, yb);

	this->g.game_init();
	free(fp);

	SDL_Rect rc;
	rc.w = 300;
	rc.h = 10;
	rc.x = (win_width - (rc.w)) / 2;
	rc.y = (win_height - box_H) / 2 - 60;


	for(int i = 1; i <= 3; ++i)
	{
		SDL_SetRenderDrawColor( render, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear( render );
		SDL_SetRenderDrawColor( render, 0x00, 0xff, 0x00, 0x00);
		SDL_RenderFillRect( render, &rc);
		this->g.game_show(render);
		SDL_RenderPresent( render );

		rc.w -= 100;
		rc.x += 50;
		cout << i << endl;
		SDL_Delay(1000);
	}

	this->g.game_start();
	this->WindowRender( render );

	return false;
}


void dialog()
{
	//MessageBox(0, 0, "Acepted", 0);

	SDL_Window *dia = SDL_CreateWindow("Acepted!  (Session will close in 3 seconds)", 100, 100, 500, 1, 0);
	SDL_Delay(3000);
	//SDL_WindowDestroy( dia );
}

bool GameControl::G_run( SDL_Event &e, SDL_Renderer *render)
{
	if(this->g.play( e, render))
	{
		this->WindowRender( render );
		if( this->g.isPassed() )
		{
			cout << "Passed" << endl;
			dialog();
			return true;
		}
	}
	return false;
}

bool GameControl::WindowRender( SDL_Renderer *render)
{
	SDL_SetRenderDrawColor( render, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear( render);
	this->g.game_show( render );
	SDL_RenderPresent( render );
	return false;
}

