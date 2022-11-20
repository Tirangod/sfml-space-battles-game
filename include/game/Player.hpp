#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameObject.hpp"

using namespace sf;

class Player : public GameObject {
private:
    Sprite sprite;
    Vector2f moveDir;
    float speed;
    float hp;

public:
    Player();
    void update(float dt);
    void draw(RenderTarget &target);
    
    void onCollision(GameObject *other);
    Sprite getSprite();
};

#endif