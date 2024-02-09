#include "Engine/utils.h"
#include "Engine/App/Application.h"

int main(int argc, char* argv[]) {
    NUCTE_NS::Application app("Nucte-Engine", 1920, 1080);
    app.Run();

    return 0;
}
