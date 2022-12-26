#include <game/ui/MainMenuUI.hpp>


void MainMenuUI::onInit() {
    panel.setSize(GameWindow::Get().GetSizef());
    panel.getBackground().setFillColor(Color::Black);

    fadeIn = new RampEffect(Color::Black, Color::Transparent);
    fadeIn->addShape(panel.getBackground());
    fadeIn->setDuration(seconds(1.5f));
    fadeIn->start();

    fadeOut = new RampEffect(Color::Transparent, Color::Black);
    fadeOut->addShape(panel.getBackground());
    fadeOut->setDuration(seconds(1.f));
    fadeOut->setOnFinish([]{
        Scenes::SetNext();
    });

    play.setIcon("assets/icons/play.png");
    play.getIcon().alignCenter();
    play.getIcon().setScale(2.5f, 2.5f);
    play.setPosition({500, 310}/*{550, 500}*/);
    play.setSize({190, 85}/*{270, 100}*/);
    play.setPadding(play.getSize() / 2.f);
    play.setOnClick([&]{
        fadeOut->start();
    });

    skin.setIcon("assets/icons/list.png");
    skin.getIcon().alignCenter();
    skin.getIcon().setScale(2.5f, 2.5f);
    skin.setPosition({500, 410}/*{550, 620}*/);
    skin.setSize({190, 85}/*{270, 100}*/);
    skin.setPadding(play.getSize() / 2.f);

    exit.setIcon("assets/icons/power_off.png");
    exit.getIcon().alignCenter();
    exit.getIcon().setScale(2.5f, 2.5f);
    exit.setPosition({500, 510}/*{550, 740}*/);
    exit.setSize({190, 85}/*{270, 100}*/);
    exit.setPadding(play.getSize() / 2.f);
    exit.setOnClick(GameWindow::Shutdown);

    addComp(play);
    addComp(skin);
    addComp(exit);
    addComp(panel);
}

void MainMenuUI::onUpdate(float dt) {
    fadeIn->update(dt);
    fadeOut->update(dt);

    if (KeyEvents::isKeyPressed(Keyboard::S))
        selectNext();
    else if (KeyEvents::isKeyPressed(Keyboard::W))
        select(getIndex() - 1);
}