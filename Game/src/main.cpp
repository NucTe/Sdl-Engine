#include "SdlEngine/window.h"
#include "gameloop.h"

int main() {
	MyGame myGameLoop;
	Window gameWindow("GAMAMAMAMAMMAMAE", 800, 600, &myGameLoop);
	gameWindow.Run();
	
	return 0;
}
	