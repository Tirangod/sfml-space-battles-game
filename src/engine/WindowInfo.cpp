#include <engine/WindowInfo.hpp>

WindowInfo *WindowInfo::instance = nullptr;

WindowInfo& WindowInfo::Get() {
    if (instance == nullptr)
        instance = new WindowInfo;
    
    return *instance;
}

void WindowInfo::setWindowSize(Vector2u size) {
    windowSize = size;
}
bool WindowInfo::IsOutofScreen(Vector2f pos) {
    return pos.x < 0 || pos.x > Get().windowSize.x || pos.y < 0 || pos.y > Get().windowSize.y;
}
Vector2u WindowInfo::GetWindowSize() {
    return Get().windowSize;
}
