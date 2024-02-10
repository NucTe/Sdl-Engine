#include "Engine/App/Application.h"
#include "Engine/utils.h"

namespace NUCTE_NS {

    Application::Application(const std::string& windowTitle, int screenWidth, int screenHeight)
        : m_Running(true), m_Renderer(nullptr), m_Entitym(nullptr), m_World(nullptr), m_ImGuiManager(nullptr) {
        InitializeSDL(windowTitle, screenWidth, screenHeight);
        InitializeOpenGL();
        InitializeExt();
    }

    Application::~Application() {
        Cleanup();
    }

    void Application::Run() {
        while (m_Running) {
            HandleEvents();
            Update();
            Render();
        }
    }

    void Application::InitializeSDL(const std::string& windowTitle, int screenWidth, int screenHeight) {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
            // Handle initialization error
            std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
            std::exit(EXIT_FAILURE);
        }

        m_Window = SDL_CreateWindow(windowTitle.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screenWidth, screenHeight,
            SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        if (!m_Window) {
            // Handle window creation error
            std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }
        
    }

    void Application::InitializeExt() {
        m_Entitym = new EntityManager();
        m_World = new GameWorld(*m_Entitym);
        m_Renderer = Renderer(m_Window);
        m_ImGuiManager = ImGuiManager(m_Window);
    }

    void Application::InitializeOpenGL() {
        // Set OpenGL attributes
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // Create OpenGL context
        m_GLContext = SDL_GL_CreateContext(m_Window);
        if (!m_GLContext) {
            // Handle context creation error
            std::cerr << "Error creating OpenGL context: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        // Initialize GLEW
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK) {
            // Handle GLEW initialization error
            std::cerr << "Error initializing GLEW: " << glewGetErrorString(glewError) << std::endl;
            SDL_GL_DeleteContext(m_GLContext);
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        // Check if OpenGL 3.3 is supported
        if (!GLEW_VERSION_3_3) {
            // Handle unsupported OpenGL version
            std::cerr << "OpenGL 3.3 is not supported!" << std::endl;
            SDL_GL_DeleteContext(m_GLContext);
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            std::exit(EXIT_FAILURE);
        }

        // Set vertical sync
        SDL_GL_SetSwapInterval(1);
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
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                m_Running = false;
                break;
                // Handle other SDL events as needed
            }
        }
    }

    void Application::Update() {
        // Perform game logic update here
    }

    void Application::Render() {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render game content using the renderer
        // Pass game world data or any other necessary parameters
        m_Renderer.Render(m_World);

        // Swap buffers
        SDL_GL_SwapWindow(m_Window);
    }

}
