#include <engine/Global.hpp>

using namespace Global;

WindowInfo *WindowInfo::instance = nullptr;

WindowInfo& WindowInfo::get() {
    if (instance == nullptr)
        instance = new WindowInfo;
    
    return *instance;
}
void WindowInfo::setWindowSize(Vector2u size) {
    windowSize = size;
}
bool WindowInfo::isOutofScreen(Vector2f pos) {
    return pos.x < 0 || pos.x > get().windowSize.x || pos.y < 0 || pos.y > get().windowSize.y;
}
Vector2u WindowInfo::getWindowSize() {
    return get().windowSize;
}

