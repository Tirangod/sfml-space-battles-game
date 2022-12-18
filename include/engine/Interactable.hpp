#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

class GameObject;

class Interactable {
private:
public:
    virtual bool intersects(GameObject *other) = 0;
    virtual void onCollisionStay(GameObject *other);
    virtual void onCollisionEnter(GameObject *other);
    virtual void onCollisionExit(GameObject *other);
    /*
    void setAlreadyCollided(bool flag);
    void setCollisionEnded(bool flag);

    bool isAlreadyCollided();
    bool isCollisionEnded();
    */
};

#endif 