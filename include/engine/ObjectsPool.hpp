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
    Objects added;
    Objects deleted;
    vector<int> indexes;
public:
    ObjectsPool();
    static ObjectsPool& Get();
    static void AddObject(GameObject *object);
    static void RemoveObject(GameObject *object);
    static void RemoveAll();
    static void ResolveAdded();
    static void ResolveDeleted();

    static GameObject* GetObjectByIndex(size_t index);
    static Objects& GetObjects();
};

#endif