#ifndef WINDOWINFO_HPP
#define WINDOWINFO_HPP

#include <SFML/System.hpp>

using namespace sf;

class WindowInfo {
    static WindowInfo *instance;
    Vector2u windowSize;

public:
    void setWindowSize(Vector2u size);

    static WindowInfo& get();
    static Vector2u getWindowSize();
    static bool isOutofScreen(Vector2f pos);

    WindowInfo& operator =(WindowInfo&) = delete;
};

#endif