#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameObject.hpp"
#include "Global.hpp"

using namespace sf;
using namespace std;

class Player : public GameObject {
private:
    Texture tex;
    Sprite sprite;
    Vector2f moveDir;
    float speed;
    float hp;

    RectangleShape healthBar;

    void controll();
    void move(float dt);

public:
    Player();
    void update(float dt);
    void draw(RenderTarget &target);
    
    void onCollision(GameObject *other);
    Sprite getSprite();
};

#endif