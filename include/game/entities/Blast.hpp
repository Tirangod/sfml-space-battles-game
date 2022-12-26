#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SFML/Graphics.hpp>
#include "engine/GameObject.hpp"
#include "engine/ObjectsPool.hpp"

using namespace sf;

class Blast : public GameObject {
private:
    Clock timer;
public:
    Blast() {}
    void onInit();
    void onUpdate(float dt);
};

#endif