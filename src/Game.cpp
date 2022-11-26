#include "game/Game.hpp"

Game::Game() :
    window(RenderWindow(VideoMode(1280, 720), "Super puper game")),
    global(Global::get())
{   
    global.windowSize.x = window.getSize().x;
    global.windowSize.y = window.getSize().y;
    
    objects.reserve(100);

    Player *player = new Player;
    objects.push_back(player);
}

void Game::checkCollision() {

}
void Game::updateObjects(float dt) {
    for (auto object : objects)
        object->update(dt);
}

void Game::drawObjects() {
    for (auto object : objects)
        object->draw(window);
}

void Game::run() {
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

                    global.windowSize.x = width;
                    global.windowSize.y = height;
                break;
            }
        }

        window.clear({123, 56, 77});

        updateObjects(dt);
        drawObjects();

        window.display();

        dt = clock.getElapsedTime().asSeconds();

        clock.restart();
    }
}