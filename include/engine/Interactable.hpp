#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

class GameObject;

class Interactable {
private:
public:
    virtual bool intersects(GameObject *other) = 0;
    virtual void onCollision(GameObject *other) {}
};

#endif 