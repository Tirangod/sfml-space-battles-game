#include "game/Game.hpp"

Game::Game() :
    window(RenderWindow(VideoMode(1280, 720), "Super puper game"))
{
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

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                break;
            }
        }

        window.clear();

        updateObjects(0);
        drawObjects();

        window.display();
    }
}