#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "PublicHead.h"
#include "GameControl.h"

class Window
{
	public:
	Window();
	~Window(){}

	bool Window_Init(const char * WindowName, const int &x, const int &y, const int &width, const int &height, const int &flags);
	void Window_Clear();

	bool Window_Event();
	bool Window_Render();
	bool Window_Update();

	bool Window_Work();
	bool Window_Work(const char *WindowName, const int &x, const int &y, const int &width, const int &height, const int &flags);

	private:
		SDL_Window *win;
		SDL_Renderer *ren;
		bool Window_flag;
		int x, y, width, height;

		GameControl gnow;
};

#endif
