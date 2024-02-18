#define STB_IMAGE_IMPLEMENTATION
#include "SdlEngine/window.h"
#include "stb/stb_image.h"


    Window::Window() {}

    void Window::CreateWindow(const std::string& title, int width, int height, bool fullscreen, GameLoop* gameLoop) {
        this->gameLoop = gameLoop;
        screenWidth = width;
        screenHeight = height;
        isFullscreen = fullscreen;

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        }




        SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

        window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth,
            screenHeight,
            window_flags
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

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        SDL_GL_SetSwapInterval(1);
        if (gameLoop) {
            gameLoop->init((Window*)this);
        }
    }
    void Window::Run(std::string vertexShaderPath, std::string fragmentShaderPath) {
        if (gameLoop) {
            GLuint id = renderer->Initialize(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
            gameLoop->Run(id);
        }
        else {
            std::cerr << "Error: GameLoop instance not provided to Window." << std::endl;
        }
    }

    SDL_Window* Window::GetSDLWindow() {
        return window;
    }

    void Window::ToggleFullscreen() {
        isFullscreen = !isFullscreen;

        Uint32 flags = isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
        SDL_SetWindowFullscreen(window, flags);
    }

    void Window::SetWindowSize(int width, int height) {
        screenWidth = width;
        screenHeight = height;
        SDL_SetWindowSize(window, width, height);
    }

    SDL_GLContext Window::GetContext() const {
        return glContext;
    }

    int Window::GetScreenWidth() {
        return screenWidth;
    }

    int Window::GetScreenHeight() {
        return screenHeight;
    }


    Window::~Window() {
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


