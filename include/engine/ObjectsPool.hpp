#ifndef OBJECTSPOOL_HPP
#define OBJECTSPOOL_HPP

#include <iostream>
#include <vector>

#include "GameObject.hpp"

using namespace std;

using ObjectsVector = vector<GameObject*>;

class ObjectsPool {
private:
    static ObjectsPool *instance;
    ObjectsVector objects;
    ObjectsVector buffer;
    vector<int> indexes; // Mutate indexes
public:
    static ObjectsPool& init(int reserveNumber);
    static ObjectsPool& get();

    static void addObject(GameObject *object);
    static void killObject(GameObject *object);
    static void clearRefs();
    static void flush();

    static ObjectsVector getObjects();
};

#endif