#include <game/Game.hpp>

Game::Game() :
    window(GameWindow::Get())
{   
    window.requestFocus();
    window.clear(Color::Black);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(120);

    auto menu = new MenuScene;
    auto game = new GameScene;
    Scenes::AddScene(menu);
    Scenes::AddScene(game);
}

void Game::run() {
    
    float dt = 0;

    while (window.isOpen()) {
        KeyEvents::Get().clearKeys();

        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                break;
                case Event::Resized: {
                    window.setView(View(window.GetSizef() / 2.f, window.GetSizef()));
                break;}
                case Event::KeyPressed:
                    switch (event.key.code) {
                        case Keyboard::F11:
                            if (window.IsFullscreen())
                                window.SetFullscreen(false);
                            else 
                                window.SetFullscreen(true);
                        break;
                    }
                    

                    KeyEvents::Get().setPressedKey(event.key.code);
                break;
                case Event::KeyReleased:
                    KeyEvents::Get().setReleasedKey(event.key.code);
                break;
            }
        }
        Interactions::Update(dt);
        Scenes::Update(dt);
        Scenes::Draw(window);
        ObjectsPool::ResolveAdded();
        ObjectsPool::ResolveDeleted();
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