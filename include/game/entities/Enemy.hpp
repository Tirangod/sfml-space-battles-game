#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cmath>
#include <SFML/System.hpp>

#include "engine/effects/ShakeEffect.hpp"
#include "engine/ui/UIProgressBar.hpp"
#include "engine/GameObject.hpp"
#include "game/entities/Blast.hpp"
#include "game/entities/Bullet.hpp"
#include "game/Presets.hpp"

using namespace Presets;
using namespace std;
using namespace sf;

class Enemy : public GameObject {
private:
    EnemyInfo preset;

    Vector2f moveDir;
    float speed;
    float hp;

    ShakeEffect *shakeEffect;

    UIProgressBar healthBar;
public:
    Enemy(EnemyInfo preset) : preset(preset) {}
    void onInit();
    void onCollision(GameObject *object);
    void onUpdate(float dt);
    void onDraw(RenderTarget &target);
    void onKilled();
};

#endif