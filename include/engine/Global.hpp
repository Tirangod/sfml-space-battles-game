#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <vector>

#include <SFML/System.hpp>
#include "GameObject.hpp"

using namespace std;
using namespace sf;

/**
 * Class for storing global information
*/
namespace Global {

class EntitiesInfo {

};

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

}

#endif