#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cmath>
#include <SFML/System.hpp>

#include "engine/effects/ShakeEffect.hpp"
#include "engine/ui/UIProgressBar.hpp"
#include "engine/GameObject.hpp"
#include "game/entities/Blast.hpp"
#include "game/entities/Bullet.hpp"

class Enemy : public GameObject {
private:
    Vector2f moveDir;
    float speed;
    float hp;

    ShakeEffect *shakeEffect;

    UIProgressBar healthBar;
public:
    Enemy() {}
    void onInit();
    void onCollision(GameObject *object);
    void onUpdate(float dt);
    void onDraw(RenderTarget &target);
    void onKilled();
};

#endif