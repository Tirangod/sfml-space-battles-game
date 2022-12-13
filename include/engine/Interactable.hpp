#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

class GameObject;

class Interactable {
private:
    
public:
    virtual void onCollisionStay(GameObject *other);
    virtual void onCollisionEnter(GameObject *other);
    virtual void onCollisionExit(GameObject *other);
};

#endif 