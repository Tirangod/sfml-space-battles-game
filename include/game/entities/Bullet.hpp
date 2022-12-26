#ifndef BULLET_HPP
#define BULLET_HPP

#include <typeinfo>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/GameWindow.hpp"
#include "game/entities/Blast.hpp"
#include "game/entities/Enemy.hpp"

using namespace std;
using namespace sf;

class Bullet : public GameObject {
    Clock timer;
    Vector2f moveDir;
    float speed;
public:
    Bullet() {}
    void onInit();
    void onUpdate(float dt);
    void onCollision(GameObject *object);
};

#endif