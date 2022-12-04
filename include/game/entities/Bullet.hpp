#ifndef BULLET_HPP
#define BULLET_HPP

#include <typeinfo>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/Global.hpp"

using namespace std;
using namespace sf;

class Bullet : public GameObject {
    Vector2f moveDir;
    float speed;
public:
    Bullet(Vector2f pos);
    ~Bullet();
    void onUpdate(float dt);
    void onCollisionStay(GameObject *object);
};

#endif