#include "SdlEngine/window.h"
#include "gameloop.h"


int main() {
	MyGame myGameLoop;
	std::string title = "Helllo";
	Window gameWindow(title, 800, 600, &myGameLoop);
	gameWindow.Run();
	
	return 0;
}
	