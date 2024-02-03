#include "SdlEngine/window.h"
#include "gameloop.h"


int main() {
	MyGame myGameLoop;
	std::string title = "Helllo";
	Window window;
	window.CreateWindow(title, 800, 600, &myGameLoop);
	
	return 0;
}
	