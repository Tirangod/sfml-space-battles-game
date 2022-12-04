#include <game/Game.hpp>

Game::Game() :
    window(RenderWindow(VideoMode(1280, 720), "Super puper game")),
    winInfo(Global::WindowInfo::get())
{   
    winInfo.setWindowSize(window.getSize());
    ObjectsPool::init(100);

    Player *player = new Player;
    Enemy *enemy = new Enemy;
    ObjectsPool::addObject(player);
    ObjectsPool::addObject(enemy);
}

void Game::checkCollision() {
    GameObject *obj1, *obj2;
    FloatRect rect1, rect2;

    size_t size = ObjectsPool::getObjects().size();

    for (int i = 0; i < size; i++) {
        obj1 = ObjectsPool::getObjects().at(i);
        rect1 = obj1->getSprite().getGlobalBounds();

        for (int j = i + 1; j < size; j++) {
            obj2 = ObjectsPool::getObjects().at(j);
            rect2 = obj2->getSprite().getGlobalBounds();

            if (rect1.intersects(rect2)) {
                obj1->onCollisionStay(obj2);
                obj2->onCollisionStay(obj1);
            }
        }
    }
}

void Game::updateObjects(float dt) {
    for (auto object : ObjectsPool::getObjects())
        if (object->isActive())
            object->_update(dt);
}

void Game::drawObjects() {
    for (auto object : ObjectsPool::getObjects())
        if (object->isVisible())
            object->_draw(window);
}

void Game::run() {
    const Color DEFAULT_COLOR{123, 56, 77};
    
    float dt = 0;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                break;
                case Event::Resized:
                    int width = event.size.width;
                    int height = event.size.height;

                    window.setView(View({(float)width/2, (float)height/2}, {(float)width, (float)height}));
                    
                    winInfo.setWindowSize({(unsigned)width, (unsigned)height});
                break;
            }
        }
        //clock.restart(); // Clock starts to measure time

        window.clear(DEFAULT_COLOR);

        checkCollision();

        updateObjects(dt);
        drawObjects();

        ObjectsPool::clearRefs();
        ObjectsPool::flush();

        window.display();

        dt = clock.getElapsedTime().asSeconds();

        clock.restart(); // Clock ends to measure time
    }
}