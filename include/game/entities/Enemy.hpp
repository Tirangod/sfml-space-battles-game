#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "engine/ui/UIProgressBar.hpp"
#include "engine/GameObject.hpp"
#include "engine/Utils.hpp"
#include "game/entities/Bullet.hpp"

class Enemy : public GameObject {
private:
    Vector2f moveDir;
    float speed;
    float hp;

    UIProgressBar healthBar;
public:
    Enemy();
    void onCollisionStay(GameObject *object);
    void onDraw(RenderTarget &target);
};

#endif