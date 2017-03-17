#ifndef _GAME_H_
#define _GAME_H_

#include <stack>
#include "PublicHead.h"
#include "cButton.h"
using namespace std;

class node{
	public:
		int a, b, c;
};

class iGame{
	public:

		iGame();
		~iGame();
		
		bool setPosition( const int &a, const int &b);
		bool setSize(const int &a, const int &b, const int &c);
		bool setColor_left( const int &a, const int &b, const int &c);
		bool setColor_right( const int &a, const int &b, const int &c);

		int getSumWidth();

		bool game_init();
		bool game_start();
		bool game_show(SDL_Renderer *render);

		bool play(SDL_Event &ievent, SDL_Renderer *render);
		bool ex_color(const int &a, const int &b);
		bool finish();
		bool isPassed();

	//private:
		static const int length = 64;
		node clib[length];
		int len;
		cButton lib[length];
		int l_red, l_green, l_blue, r_red, r_green, r_blue;
		int x, y, width, height, sum_width;
		stack<int> sta;
		bool finish_flag;
		
};

#endif
