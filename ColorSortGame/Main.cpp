#include "PublicHead.h"
#include "Window.h"

void example()
{
	Window game1;
	if(game1.Window_Work( "Demo", 10, 50, 1200, 640, 0) == 0)
		puts("Error");
}

int main( int argc, const char *args[])
{
	example();
	return 0;
}
