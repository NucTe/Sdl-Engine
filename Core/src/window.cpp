#define STB_IMAGE_IMPLEMENTATION
#include "SdlEngine/window.h"
#include "stb/stb_image.h"

Window::Window(){}

void Window::CreateWindow(const std::string& title, int width, int height, bool fullscreen, GameLoop* gameLoop) {
    {
        this->gameLoop = gameLoop;
        screenWidth = width;
        screenHeight = height;
        isFullscreen = fullscreen;

        if (!gameLoop) {
            std::cerr << "Error: GameLoop instance not provided to Window constructor." << std::endl;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        DeserializeFromJson("window_settings.json");

        window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screenWidth,
            screenHeight,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );
        ToggleFullscreen();
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
        SerializeToJson("window_settings.json");
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

void Window::GetWindowSize(int& width, int& height) const {
    width = screenWidth;
    height = screenHeight;
}

std::vector<std::pair<int, int>> Window::GetAvailableResolutions() const {
    std::vector<std::pair<int, int>> resolutions;

    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    int numModes = SDL_GetNumDisplayModes(displayIndex);

    for (int i = 0; i < numModes; ++i) {
        SDL_DisplayMode mode;
        SDL_GetDisplayMode(displayIndex, i, &mode);
        resolutions.emplace_back(mode.w, mode.h);
    }

    return resolutions;
}

void Window::SerializeToJson(const std::string& filename) const {
    nlohmann::json jsonSettings;
    jsonSettings["width"] = screenWidth;
    jsonSettings["height"] = screenHeight;
    jsonSettings["fullscreen"] = isFullscreen;
    jsonSettings["resolutions"] = GetAvailableResolutions();

    std::ofstream file(filename);
    if (file.is_open()) {
        file << jsonSettings.dump(4);
        file.close();
        std::cout << "Window settings saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open file for window settings serialization." << std::endl;
    }
}
void Window::DeserializeFromJson(const nlohmann::json& jsonData) {
    if (jsonData.contains("width") && jsonData["width"].is_number()) {
        screenWidth = jsonData["width"];
    }

    if (jsonData.contains("height") && jsonData["height"].is_number()) {
        screenHeight = jsonData["height"];
    }

    if (jsonData.contains("fullscreen") && jsonData["fullscreen"].is_boolean()) {
        isFullscreen = jsonData["fullscreen"];
    }

}

void Window::UpdateWindowSettings(const nlohmann::json& settings) {
    DeserializeFromJson(settings);
    SetWindowSize(screenWidth, screenHeight);
    ToggleFullscreen();
}

Window::~Window() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
