#define STB_IMAGE_IMPLEMENTATION
#include "SdlEngine/window.h"
#include "stb/stb_image.h"

Window::Window(){}

void Window::CreateWindow(const std::string& title, int width, int height, GameLoop* gameLoop) {
    {
        if (!gameLoop) {
            std::cerr << "Error: GameLoop instance not provided to Window constructor." << std::endl;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );

        if (!window) {
            std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
        }
        else {
            std::cout << "Window created successfully." << std::endl;
        }

        glContext = SDL_GL_CreateContext(window);
        if (!glContext) {
            std::cerr << "Unable to create OpenGL context: " << SDL_GetError() << std::endl;
        }
        else {
            std::cout << "OpenGL context created successfully." << std::endl;

            GLenum glewError = glewInit();
            if (glewError != GLEW_OK) {
                std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewError) << std::endl;
            }

            if (!GLEW_VERSION_3_3) {
                std::cerr << "OpenGL 3.3 is not supported!" << std::endl;
            }
        }

        SDL_GL_SetSwapInterval(1);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        gameLoop->init((Window*)this);
    }
}
void Window::Run() {
    if (gameLoop) {
        gameLoop->Run();
    }
    else {
        std::cerr << "Error: GameLoop instance not provided to Window." << std::endl;
    }
}

SDL_Window* Window::GetSDLWindow() {
    return window;
}

Window::~Window() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
