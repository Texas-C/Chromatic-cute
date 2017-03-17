#include "game.h"

iGame::iGame()
{
	this->x = this->y = this->width = this->height = this->len = 0;
}

iGame::~iGame()
{
	
}

bool iGame::setPosition( const int &a, const int &b)
{
	this->x = a;
	this->y = b;
	return false;
}

bool iGame::setSize(const int &a, const int &b, const int &c)
{
	this->width = a;
	this->height = b;
	this->len = c;
	this->sum_width =this->width * (this->len + 2);
	return false;
}

bool iGame::setColor_left( const int &a, const int &b, const int &c)
{
	this->l_red = a;
	this->l_green = b;
	this->l_blue = c;	
	return false;
}
bool iGame::setColor_right( const int &a, const int &b, const int &c)
{
	this->r_red = a;
	this->r_green = b;
	this->r_blue = c;	
	return false;
}

int iGame::getSumWidth()
{
	return this->sum_width;
}



bool iGame::game_init()
{
	this->finish_flag = false;
	while( ! this->sta.empty())
		this->sta.pop();

	int vx = this->r_red - this->l_red, vy = this->r_green - this->l_green, vz = this->r_blue - this->l_blue;
	int mo = this->len + 1;
	int nx = this->x + this->width, ny = this->y;

	lib[0].setPosition( this->x, this->y);
	lib[0].setSize( this->width, this->height);
	lib[0].setColor( this->l_red, this->l_green, this->l_blue);
	
	for(int i = 1; i <= this->len; ++i)
	{
		lib[ i ].setPosition( nx , ny);
		lib[ i ].setSize( this->width , this->height);
		lib[ i ].setColor( this->l_red + (vx * i / mo), this->l_green + (vy * i / mo), this->l_blue + (vz * i / mo));

		lib[ i ]. getColor( &clib[i].a, &clib[i].b, &clib[i].c);
		nx += this->width;
	}


	lib[ mo ].setPosition( nx, this->y);
	lib[ mo ].setSize( this->width, this->height);
	lib[ mo ].setColor( this->r_red, this->r_green, this->r_blue);
	return false;
}

bool iGame::game_start()
{
	printf("Start!\n");
	srand( (unsigned int) time(NULL));
	random_shuffle( &clib[1], &clib[ this->len + 1]);

	for(int i = 1; i <= this->len; ++i)
	{
		lib[i].setColor( clib[i].a, clib[i].b, clib[i].c);
	}

	return false;
}

bool iGame::game_show(SDL_Renderer *render)
{
	if(NULL == render)
		return true;

	for(int i = 0; i <= this->len + 1; ++i)
		lib[i].show( render);
	return false;
}

bool iGame::play(SDL_Event &ievent, SDL_Renderer *render)
{
	if( NULL == render)
		return true;
	bool ans = false;
	for(register int i = 1; i <= this->len; ++i)
	{
		if(lib[i].onClicked( ievent ))
		{
			sta.push(i);
			lib[i].buttonClicked( render );
			ans = true;
			break;
		}
	}

	if(sta.size() == 2)
	{
		int a = sta.top();
		sta.pop();
		int b = sta.top();
		sta.pop();

		if(a != b)
		{
			this->ex_color( a, b );
			lib[a].buttonClicked( render );
			lib[b].buttonClicked( render );
			
			if( this->finish())
			{
				puts("Welldonw!!\n");
				this-> finish_flag = true;
				//SDL_Delay(1000);
			}
		}
	}

	return ans;
}

bool iGame::ex_color( const int &a, const int &b)
{
	int ar, ag, ab;
	int br, bg, bb;
	lib[a].getColor( &ar, &ag, &ab);
	lib[b].getColor( &br, &bg, &bb);
	lib[a].setColor( br, bg, bb);
	lib[b].setColor( ar, ag, ab);
	return false;
}


bool iGame::finish()
{
	int vx = this->r_red - this->l_red, vy = this->r_green - this->l_green, vz = this->r_blue - this->l_blue;
	int nx, ny, nz;
	int ax, ay, az, bx, by, bz;
	int mo = this->len + 1;
	bool ans = true;

	for(register int i = 1; ans && i <= this->len; ++i)
	{
		this->lib[i].getColor( &ax, &ay, &az);
		this->lib[i + 1].getColor( &bx, &by, &bz);
		nx = bx - ax;
		ny = by - ay;
		nz = bz - az;
		if( nx * vx < 0 || ny * vy < 0 || nz * vz < 0)
			ans = false;
	}
	return ans;
}

bool iGame::isPassed()
{
	return this->finish_flag;
}
