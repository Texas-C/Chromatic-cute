#include "Window.h"

bool set_DefaultRender( SDL_Renderer *render)
{
	if(NULL == render)
		return true;

	SDL_SetRenderDrawColor( render, 0x00, 0x00, 0x00, 0x00);
	return false;
}


Window::Window(){
	this->Window_flag = true;
}


bool Window::Window_Init(const char *WindowName, const int &x, const int &y, const int &width, const int &height, const int &flags)
{
	this->width = width;
	this->height = height;
	if( 0 > ( SDL_Init( SDL_INIT_EVERYTHING ) ) )
	{
		return 1;
	}

	this->win = SDL_CreateWindow( WindowName, x, y, width, height, flags);	
	if(0 == this->win)
	{
		SDL_Quit();
		return 1;
	}
	
	this->ren = SDL_CreateRenderer( this->win , -1, 0);
	if( 0 == this->ren )
	{
		SDL_DestroyWindow( this->win );
		SDL_Quit();
		return 1;
	}

	//SDL_SetRenderDrawColor( this->ren, 0xff, 0xff, 0xff, 0xff);
	set_DefaultRender( this->ren);
	SDL_RenderClear( this->ren );
	SDL_RenderPresent( this->ren );

	this->Window_flag = true;

	return 0;
}

void Window::Window_Clear()
{
	SDL_DestroyRenderer( this->ren );
	SDL_DestroyWindow( this->win );
	SDL_Quit();
}


bool Window::Window_Event()
{
	SDL_Event event;

	while( 0 != SDL_PollEvent( &event))
	{
		switch( event.type )
		{
			case SDL_QUIT:
				this->Window_flag = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(gnow.G_run( event, this->ren))
					this->Window_flag = false;;
				break;
			default: break;
		}
	}	
	return false;
}


bool Window::Window_Render()
{
	set_DefaultRender( this->ren );
	SDL_RenderClear( this->ren );
	SDL_RenderPresent( this->ren);
	return false;
}

bool Window::Window_Update()
{
	return false;
}


bool Window::Window_Work(const char *WindowName, const int &x, const int &y, const int &width, const int &height, const int &flags)
{

	if(this->Window_Init(WindowName, x, y, width, height, flags))
		return false;

	gnow.G_init(this->ren, "XD.txt", width, height, 30, 50);

	while( true == this->Window_flag )
	{
		this->Window_Event();
	}

	this->Window_Clear();
}
