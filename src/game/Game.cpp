#include <game/Game.hpp>

Game::Game() :
    window(RenderWindow(VideoMode(1280, 720), "Super puper game"))
{   
    WindowInfo::get().setWindowSize(window.getSize());

    window.setFramerateLimit(120);

    Player *player = new Player;
    Enemy *enemy = new Enemy;
    ObjectsPool::addObject(player);
    ObjectsPool::addObject(enemy);
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
                    WindowInfo::get().setWindowSize({(unsigned)width, (unsigned)height});
                break;
            }
        }
        window.clear(DEFAULT_COLOR);
        Interactions::update(dt);
        updateObjects(dt);
        drawObjects();
        ObjectsPool::clearEmptySpace();
        window.display();

        dt = clock.getElapsedTime().asSeconds();
        if (time >= 1.f) {
            window.setTitle("FPS: " + to_string(frames));
            frames = 0;
            time = 0;
        }
        time += dt;
        frames++;
        clock.restart(); // resets Clock time counter
    }
}