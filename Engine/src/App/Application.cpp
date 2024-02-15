#include "Engine/App/Application.h"
#include "Engine/utils.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace NUCTE_NS {

    Application::Application(const std::string& windowTitle, int screenWidth, int screenHeight)
        : m_Running(true), m_Renderer(nullptr), m_Entitym(), m_World(m_Entitym)
        , m_Window(nullptr), m_GLContext(nullptr), m_UI(nullptr) {
        InitializeSDL(windowTitle, screenWidth, screenHeight);
        InitializeOpenGL();
        m_UI = new UI(this);
    }

    Application::~Application() {
        Cleanup();
        delete m_UI;
    }

    void Application::Run() {
        while (m_Running) {
            HandleEvents();
            Update();
            Render();
        }
    }

    void Application::InitializeSDL(const std::string& windowTitle, int screenWidth, int screenHeight) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
            std::exit(EXIT_FAILURE);
        }

        m_Window = SDL_CreateWindow(windowTitle.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth, screenHeight,
            SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        if (!m_Window) {
            std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        if (m_Window == nullptr) {
            std::cerr << "Failed to create SDL window." << std::endl;
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        SDL_GLContext glContext = SDL_GL_CreateContext(m_Window);
        SDL_GL_MakeCurrent(m_Window, glContext);
        SDL_GL_SetSwapInterval(1);
    }

    void Application::InitializeOpenGL() {
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK) {
            std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewError) << std::endl;
            SDL_GL_DeleteContext(m_GLContext);
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        if (!GLEW_VERSION_3_3) {
            std::cerr << "OpenGL 3.3 is not supported!" << std::endl;
            SDL_GL_DeleteContext(m_GLContext);
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    }

    SDL_Window* Application::GetWindow() const {
        return m_Window;
    }

    void Application::Cleanup() {
        if (m_Window) {
            SDL_DestroyWindow(m_Window);
            m_Window = nullptr;
        }
        SDL_Quit();
    }

    void Application::HandleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            m_UI->Events(event);
            if (event.type == SDL_QUIT)
                m_Running = false;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(m_Window))
                m_Running = false;
        }
    }

    void Application::Update() {
    }

    void Application::Render() {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_UI->Render();
    }

}
