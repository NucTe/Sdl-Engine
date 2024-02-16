#include "Engine/App/Application.h"
#include "Engine/utils.h"

#include "SdlEngine/window.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace NUCTE_NS {

    Application::Application(const std::string& windowTitle, int screenWidth, int screenHeight)
        : m_Running(nullptr), m_Renderer(nullptr), m_Entitym(), m_World(m_Entitym)
        , m_Window(nullptr), m_GLContext(nullptr), m_IGH(nullptr) {
        NE_ASSERT("TUN");

        m_Window = new Window();
        m_Window->CreateWindow(windowTitle, screenWidth, screenHeight, false, nullptr);

        m_IGH = new ImGuiHelper();
        m_IGH->initialize(m_Window);

        m_Running = true;
       
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



    void Application::Cleanup() {
        Cleanup();
        delete m_IGH;
        delete m_Window;
    }

    void Application::HandleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            m_IGH->events(&event);
            if (event.type == SDL_QUIT)
                m_Running = false;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(m_Window->GetSDLWindow()))
                m_Running = false;
        }
    }

    void Application::Update() {
    }

    void Application::Render() {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_IGH->render();

        SDL_GL_SwapWindow(m_Window->GetSDLWindow());
    }

}
