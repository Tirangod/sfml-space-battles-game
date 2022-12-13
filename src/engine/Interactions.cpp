#include <engine/Interactions.hpp>

void Interactions::update(float dt) {
    GameObject *obj1, *obj2;
    FloatRect rect1, rect2;

    size_t size = ObjectsPool::getObjects().size();

    for (int i = 0; i < size; i++) {
        obj1 = ObjectsPool::getObjectAt(i);

        rect1 = obj1->getSprite().getGlobalBounds();

        for (int j = i + 1; j < size; j++) {
            obj2 = ObjectsPool::getObjectAt(j);
            rect2 = obj2->getSprite().getGlobalBounds();

            if (rect1.intersects(rect2)) {
                obj1->onCollisionStay(obj2);
                obj2->onCollisionStay(obj1);
            }
        }
    }
}