#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <SFML/System.hpp>

using namespace sf;

class Global {
private:
    static Global *instance;

public:
    Vector2u windowSize;
    static Global& get();

    Global& operator =(Global&) = delete;
};

#endif