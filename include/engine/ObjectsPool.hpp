#ifndef OBJECTSPOOL_HPP
#define OBJECTSPOOL_HPP

#include <iostream>
#include <vector>

#include "GameObject.hpp"

using namespace std;

using Objects = vector<GameObject*>;

class ObjectsPool {
private:
    static ObjectsPool* instance;
    Objects objects;
    Objects deleted;
    vector<int> indexes;
public:
    static ObjectsPool& get();

    static void addObject(GameObject *object);
    static void removeObject(GameObject *object);
    static void clearEmptySpace();

    static GameObject* getObjectAt(size_t index);
    static Objects& getObjects();
};

#endif