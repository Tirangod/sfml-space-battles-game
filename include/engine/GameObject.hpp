#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/**
 * GameObject is interface that represents graphical object
 * in game world and its behaviour.
*/
class GameObject {
private:
    long typeHash; 
    bool active;
    bool visible;
    Texture texture;
    Sprite sprite;

    RectangleShape boundsRect;
public:
    /* Internal lifecycle methods */
    void _init();
    void _update(float dt);
    void _draw(RenderTarget &target);

    /* Users events */
    virtual void onInit() {}
    virtual void onUpdate(float dt) {}
    virtual void onDraw(RenderTarget &target) {}
    virtual void onCollisionStay(GameObject *other) {}
    //virtual void onCollisionEnter(GameObject *other) {}
    //virtual void onCollisionExit(GameObject *other) {}
    virtual void onKilled() {}
    //virtual void onDeleted() {}

    void loadTexture(string path);
    void centerSprite();

    void setActive(bool flag);
    void setVisibile(bool flag);
    void setTypeHash(long hash);
    
    bool isActive();
    bool isVisible();
    RectangleShape& getBounds();
    Texture& getTexture();
    Sprite& getSprite();
    //Utils::TypeHash getTypeHash();

};

#endif