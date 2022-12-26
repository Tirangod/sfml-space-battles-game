#include <engine/Interactions.hpp>

void Interactions::Update(float dt) {
    GameObject *obj1, *obj2;

    size_t size = ObjectsPool::GetObjects().size();

    for (int i = 0; i < size; i++) {
        obj1 = ObjectsPool::GetObjectByIndex(i);

        for (int j = i + 1; j < size; j++) {
            obj2 = ObjectsPool::GetObjectByIndex(j);

            if (obj1->intersects(obj2) && obj2->intersects(obj1)) {
                obj1->onCollision(obj2);
                obj2->onCollision(obj1);
            }
        }
    }
}