#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cmath>
#include <SFML/System.hpp>

#include "engine/ui/UIProgressBar.hpp"
#include "engine/GameObject.hpp"
#include "game/entities/Explosion.hpp"
#include "game/entities/Bullet.hpp"

class Enemy : public GameObject {
private:
    Vector2f moveDir;
    float speed;
    float hp;

    // Shaking effect
    Vector2f posBuffer;
    float shakeElapsedTime = 0;
    bool beginShaking = false;
    bool shaking = false;

    UIProgressBar healthBar;
public:
    Enemy() {}
    void onInit();
    void onCollisionStay(GameObject *object);
    void onUpdate(float dt);
    void onDraw(RenderTarget &target);
};

#endif