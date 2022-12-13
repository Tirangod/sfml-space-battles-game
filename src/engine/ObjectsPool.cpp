#include <engine/ObjectsPool.hpp>

ObjectsPool *ObjectsPool::instance = nullptr;

ObjectsPool& ObjectsPool::get() {
    if (instance == nullptr) {
        instance = new ObjectsPool;
        instance->objects.reserve(256);
    }
    return *instance;
}

void ObjectsPool::addObject(GameObject *object) {
    auto &self = get();

    object->_init();

    if (self.indexes.size() > 0) {
        auto lastIndex = self.indexes[self.indexes.size()-1];
        self.objects[lastIndex] = object;
        self.indexes.pop_back();
        return;
    }

    self.objects.push_back(object);
}

void ObjectsPool::removeObject(GameObject *object) {
    auto &self = get();

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

void ObjectsPool::clearEmptySpace() {
    auto &self = get();

    for (auto it = self.deleted.begin(); it != self.deleted.end(); ++it) {
        delete *it;
    }
    self.deleted.clear();
} 


GameObject* ObjectsPool::getObjectAt(size_t index) {
    
    return get().objects.at(index);
}

Objects& ObjectsPool::getObjects() { return get().objects; }
