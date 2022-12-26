#include <engine/GameWindow.hpp>

GameWindow *GameWindow::instance = nullptr;

GameWindow::GameWindow() {
    windowStyle = Style::Default;
    fullscreen = false;
    videoMode = VideoMode(1280, 720);

    createWindow();
}

GameWindow& GameWindow::Get() {
    if (instance == nullptr)
        instance = new GameWindow();
    return *instance;
}

void GameWindow::createWindow() {
    if (fullscreen)
        windowStyle = Style::Fullscreen;
    else
        windowStyle = Style::Default;

    create(videoMode, "", windowStyle);
}

void GameWindow::Shutdown() {
    Get().close();
}

void GameWindow::SetFullscreen(bool flag) {
    Get().fullscreen = flag;
    Get().createWindow();
}

Vector2f GameWindow::GetSizef() {
    return {
        static_cast<float>(Get().getSize().x),
        static_cast<float>(Get().getSize().y)
    };
}

bool GameWindow::IsOutofScreen(Vector2f pos) {
    return pos.x < 0 || pos.x > Get().getSize().x || pos.y < 0 || pos.y > Get().getSize().y;
}

bool GameWindow::IsFullscreen() {
    return Get().fullscreen;
}