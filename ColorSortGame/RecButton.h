#ifndef _RECBUTTON_H_
#define _RECBUTTON_H_
#include "PublicHead.h"

class RecButton{
	public:
		RecButton();
		~RecButton();
		RecButton( const RecButton &k);

		bool setSize( const int &w, const int &h);
		bool setPosition( const int &X, const int &Y);
		bool setColor( const int &r, const int &g, const int &b);
		bool setRender( SDL_Renderer *render);

		bool getSize(int *a, int *b);
		bool getPosition( int *a, int *b);
		bool getColor( int *a, int *b, int *c);

		bool show( SDL_Renderer *render);
	
		bool onClicked( SDL_Event &e);
		bool handleEvent( SDL_Event &e, SDL_Renderer *render);		
		bool buttonClicked(SDL_Renderer *render);

	private:
		const static int ck = 3;
		SDL_Rect rect;
		int red, green, blue;
		bool flag;
};
#endif
