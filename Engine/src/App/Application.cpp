#include "SdlEngine/window.h"

#include "Engine/App/Application.h"
#include "Engine/App/UI.h"
#include "Engine/utils.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace NUCTE_NS {

    Application::Application(const std::string& windowTitle, int screenWidth, int screenHeight)
        : m_Running(nullptr), m_Entitym(), m_World(m_Entitym)
        , m_Window(nullptr), m_GLContext(nullptr), m_IGH(nullptr), m_UI(nullptr) {

        m_Window = new ::Window();
        m_Window->CreateWindow(windowTitle, screenWidth, screenHeight, false, nullptr);

        m_IGH = new ImGuiHelper();
        m_IGH->initialize(m_Window);

        m_UI = new UI(m_IGH, m_Window, this);

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
        delete m_IGH;
        delete m_Window;
        delete m_UI;
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
        m_UI->Render(m_World);
    }

}
