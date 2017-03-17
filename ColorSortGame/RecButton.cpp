#include "RecButton.h"

RecButton::RecButton(){
	rect.x = rect.y = rect.h = rect.w = 0;
	this->flag = false;
}

RecButton::~RecButton()
{

}

RecButton::RecButton(const RecButton &k)
{
	this->rect = k.rect;
	this->red = k.red;
	this->green = k.green;
	this->blue = k.blue;
	this->flag = k.flag;
}


bool RecButton::setSize(const int &w, const int &h)
{
	this->rect.w = w;
	this->rect.h = h;
	return false;
}

bool RecButton::setPosition(const int &X, const int &Y)
{
	this->rect.x = X;
	this->rect.y = Y;
	return false;
}

bool RecButton::setColor( const int &r, const int &g, const int &b)
{
	this->red = r;
	this->green = g;
	this->blue = b;
	return false;
}

bool RecButton::setRender( SDL_Renderer *render)
{
	if(NULL == render)
		return true;
	SDL_SetRenderDrawColor( render, this->red, this->green, this->blue, 0x00);
	return false;
}


bool RecButton::getSize( int *a, int *b)
{
	if(NULL == a || NULL == b)
		return true;
	*a = this->rect.w;
	*b = this->rect.h;
	return false;
}

bool RecButton::getPosition( int *a, int *b)
{
	if(NULL == a || NULL == b)
		return true;
	*a = this->rect.x;
	*b = this->rect.y;
	return false;
}

bool RecButton::getColor(int *a, int *b, int *c)
{
	if(NULL == a || NULL == b || NULL == c)
		return true;
	*a = this->red;
	*b = this->green;
	*c = this->blue;
	return false;
}


bool RecButton::show( SDL_Renderer *render)
{
	if(NULL == render)
		return true;
	this->setRender(render);

	SDL_RenderFillRect(render, &(this->rect));
	//SDL_RenderPresent( render);
	return false;
}

bool RecButton::onClicked (SDL_Event &e)
{

	return ( e.motion.x >= this->rect.x && e.motion.x <= this->rect.x + this->rect.w && e.motion.y >= this->rect.y && e.motion.y <= this->rect.y + this->rect.h) && (e.type == SDL_MOUSEBUTTONDOWN);
}

bool RecButton::handleEvent( SDL_Event &e, SDL_Renderer *render)
{
	if(NULL == render)
		return true;
	if( this->onClicked( e ))
	{
		this->buttonClicked(render);
	}
	return false;	
}


bool RecButton::buttonClicked( SDL_Renderer *render)
{
	if(NULL == render)
		return true;

	this->flag = !this->flag;

	if(this->flag)
	{
		this->rect.y -= (RecButton::ck);
		this->rect.h += (RecButton::ck << 1);
	}
	else
	{
		SDL_SetRenderDrawColor( render, 0x00, 0x00, 0x00, 0x00);
		SDL_Rect c1, c2;
		c1.x = c2.x = this->rect.x;
		c1.h = c2.h = RecButton::ck;
		c1.w = c2.w = this->rect.w;
		c1.y = this->rect.y;
		c2.y = this->rect.y + this->rect.h - RecButton::ck;
		SDL_RenderFillRect( render, &c1);
		SDL_RenderFillRect( render, &c2);

		this->rect.y += (RecButton::ck);
		this->rect.h -= (RecButton::ck << 1);
	}
	this->show( render );
	return false;
}
