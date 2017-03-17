cc = g++
objects = Main.o Window.o RecButton.o cButton.o game.o GameControl.o
MainWin : $(objects)
	$(cc) -o MainWin $(objects) -lSDL2 -g;
Main.cpp: PublicHead.h Window.h
RecButton.cpp: PublicHead.h RecButton.h
cButton.cpp: cButton.h RecButton.h
game.cpp: game.h PublicHead.h cButton.h
GameControl.cpp: GameControl.h PublicHead.h game.h
Window.cpp: Window.h PublicHead.h GameControl.h
.PHONY: clean
clean:
	rm $(objects);
