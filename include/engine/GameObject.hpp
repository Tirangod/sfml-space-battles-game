#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Interactable.hpp"
#include "ObjectsPool.hpp"
#include "GameSprite.hpp"

using namespace std;
using namespace sf;

/**
 * GameObject is interface that represents graphical object
 * in game world and its behaviour.
*/
class GameObject : public Interactable {
private:
    bool active;
    bool visible;
    
    Texture texture;
    GameSprite sprite;

    //Shader shader;
    RenderStates renderStates;

    RectangleShape boundsRect;
public:
    static GameObject *EMPTY;

    /* Internal lifecycle methods */
    void _init();
    void _update(float dt);
    void _draw(RenderTarget &target);

    /* Users events */
    virtual void onInit();
    virtual void onUpdate(float dt);
    virtual void onDraw(RenderTarget &target);
    virtual void onKilled();
    //virtual void onDeleted();
    virtual bool intersects(GameObject *other);
    
    /*
    template<class T>
    GameObject& spawn(Vector2f pos, Vector2f scale, float rot);
    */
    GameObject& spawn(GameObject *object);
    void destroy(GameObject *object);

    void move(Vector2f velocity);

    void setupTexture(string path);
    //void setupShader(string path);

    void setActive(bool flag);
    void setVisibile(bool flag);

    void enable();
    void disable();
    
    bool isActive();
    bool isVisible();
    FloatRect getBounds();
    Texture& getTexture();
    GameSprite& getSprite();
};

#endif
