#ifndef INPUTMANAGER_H_DEFINED
#define INPUTMANAGER_H_DEFINED

#include <iostream>

#include "SDL2/SDL.h"

#include "./InputDefinitions.h"


namespace NUCTE_NS {

    class InputManager
    {
    public:
        static InputManager* getInstance();

        void update(float cameraX = 0, float cameraY = 0);

        bool isKeyDown(int key);

        bool isKeyUp(int key);

        bool shift();

        bool ctrl();

        bool alt();

        bool isMouseDown(MouseButton button);

        bool isMouseUp(MouseButton button);

        bool isKeyPressed(KeyboardKey key);

        bool isMousePressed(MouseButton button);

        bool quitRequested();

        int getMouseX();
        int getMouseY();

        void lock();

        void unlock();


        static bool isPrintable(SDL_Keycode key);

        bool isPrintableKeyDown();
        std::string getCurPrintableKey();

        InputManager();
        InputManager(InputManager const&) {};
        void operator=(InputManager const&) {};

    private:
        static InputManager* instance;

        const uint8_t* keyboard;

        uint32_t mouse;

        int mouseX;

        int mouseY;

        bool keyDown[KEYBOARD_SIZE];

        bool keyUp[KEYBOARD_SIZE];

        bool mouseDown[MOUSE_MAX];

        bool mouseUp[MOUSE_MAX];

        bool will_quit;

        int curPrintableKey;

        bool isLocked;
    };

}
#endif