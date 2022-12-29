#ifndef BULLET_HPP
#define BULLET_HPP

#include <typeinfo>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/effects/ScaleEffect.hpp"
#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/GameWindow.hpp"
#include "game/entities/Blast.hpp"
#include "game/entities/Enemy.hpp"
#include "game/Presets.hpp"

using namespace Presets;
using namespace std;
using namespace sf;

class Bullet : public GameObject {
private:
    BulletInfo preset;
    ScaleEffect *scale;
    Clock timer;
    Vector2f moveDir;
    float speed;
public:
    Bullet(BulletInfo preset) : preset(preset) {}
    void onInit();
    void onUpdate(float dt);
    void onCollision(GameObject *object);
    float getDamage();
};

#endif