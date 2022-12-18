#ifndef WINDOWINFO_HPP
#define WINDOWINFO_HPP

#include <SFML/System.hpp>

using namespace sf;

class WindowInfo {
    static WindowInfo *instance;
    Vector2u windowSize;

public:
    void setWindowSize(Vector2u size);

    static WindowInfo& Get();
    static Vector2u GetWindowSize();
    static bool IsOutofScreen(Vector2f pos);
};

#endif