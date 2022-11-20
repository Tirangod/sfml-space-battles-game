#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * GameObject is interface that represents graphical object
 * in game world and its behaviour.
*/
class GameObject {
public:
    virtual void update(float dt) = 0;
    virtual void draw(RenderTarget &target) = 0;
    virtual void onCollision(GameObject *other) = 0;
    virtual Sprite getSprite() = 0;
    // TODO: подумати над цми методом void move(float dx, float dy);

};

#endif