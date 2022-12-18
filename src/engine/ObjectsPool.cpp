#include <engine/ObjectsPool.hpp>

ObjectsPool *ObjectsPool::instance = nullptr;

ObjectsPool::ObjectsPool() {
    objects.reserve(128);
}

ObjectsPool& ObjectsPool::Get() {
    if (instance == nullptr) {
        instance = new ObjectsPool;
    }
    return *instance;
}

void ObjectsPool::AddObject(GameObject *object) {
    object->_init();
    Get().added.push_back(object);
}

void ObjectsPool::RemoveObject(GameObject *object) {
    auto &self = Get();

    object->disable();
    object->onKilled();

    for (int i = 0; i < self.objects.size(); i++) {
        if (self.objects[i] == object) {
            self.deleted.push_back(self.objects[i]);
            self.objects[i] = GameObject::EMPTY;
            self.indexes.push_back(i);
            return;
        }
    }
}

void ObjectsPool::RemoveAll() {
    auto &self = Get();

    for (auto it = self.objects.begin(); it != self.objects.end(); ++it) {
        RemoveObject(*it);
    }
}

void ObjectsPool::ResolveAdded() {
    auto &self = Get();

    int lastIndex = 0;
    
    for (int i = 0; i < self.added.size(); i++) {
        auto object = self.added[i];

        if (self.indexes.size() > 0) {
            lastIndex = self.indexes[self.indexes.size() - 1];
            self.objects[lastIndex] = object;
            self.indexes.pop_back();
            continue;
        }
        self.objects.push_back(object);
    }
    self.added.clear();
}

void ObjectsPool::ResolveDeleted() {
    auto &self = Get();

    for (auto it = self.deleted.begin(); it != self.deleted.end(); ++it) {
        delete *it;
    }
    self.deleted.clear();
} 


GameObject* ObjectsPool::GetObjectByIndex(size_t index) {
    
    return Get().objects.at(index);
}

Objects& ObjectsPool::GetObjects() { return Get().objects; }
