#include <game/Game.hpp>

Game::Game() :
    window(RenderWindow(VideoMode(1280, 720), "Super puper game"))
{   
    WindowInfo::Get().setWindowSize(window.getSize());

    //window.setFramerateLimit(120);

    auto menu = new MenuScene;
    auto game = new GameScene;
    Scenes::AddScene(menu);
    Scenes::AddScene(game);
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
                    WindowInfo::Get().setWindowSize({(unsigned)width, (unsigned)height});
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
            window.setTitle("FPS: " + to_string(frames) + " Objects: " + to_string(ObjectsPool::GetObjects().size()));
            frames = 0;
            time = 0;
        }
        time += dt;
        frames++;

        clock.restart(); // resets Clock time counter
    }
}