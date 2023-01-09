#include <game/ui/MainMenuUI.hpp>


void MainMenuUI::onInit() {
    panel.setSize(GameWindow::Get().GetSizef());
    panel.getBackground().setFillColor(Color::Black);

    fadeIn = new RampEffect(Color::Black, Color::Transparent);
    //fadeIn->addShape(panel.getBackground());
    *fadeIn += panel.getBackground();
    fadeIn->setDuration(seconds(1.5f));
    fadeIn->start();

    fadeOut = new RampEffect(Color::Transparent, Color::Black);
    //fadeOut->addShape(panel.getBackground());
    *fadeOut += panel.getBackground();
    fadeOut->setDuration(seconds(1.f));
    fadeOut->setOnFinish([]{
        Scenes::SetNext();
    });

    play.setIcon("assets/icons/play.png");
    play.getIcon().alignCenter();
    play.getIcon().setScale(2.5f, 2.5f);
    play.setPosition({490, 310}/*{550, 500}*/);
    play.setSize({210, 85}/*{270, 100}*/);
    play.setPadding(play.getSize() / 2.f);
    play.setOnClick([&]{
        fadeOut->start();
    });

    pref.setIcon("assets/icons/list.png");
    pref.getIcon().alignCenter();
    pref.getIcon().setScale(2.5f, 2.5f);
    pref.setPosition({490, 410}/*{550, 620}*/);
    pref.setSize({210, 85}/*{270, 100}*/);
    pref.setPadding(pref.getSize() / 2.f);

    exit.setIcon("assets/icons/power_off.png");
    exit.getIcon().alignCenter();
    exit.getIcon().setScale(2.5f, 2.5f);
    exit.setPosition({490, 510}/*{550, 740}*/);
    exit.setSize({210, 85}/*{270, 100}*/);
    exit.setPadding(exit.getSize() / 2.f);
    exit.setOnClick(GameWindow::Shutdown);

    group.setPosition(GameWindow::GetSizef() / 2.f - Vector2f{80.f, 0});
    group.setMargin({0, 100});
    group.add(play);
    group.add(pref);
    group.add(exit);
    group.alignCenter();


    /*
    fullscreenBtn.setIcon("assets/icons/rect.png");
    fullscreenBtn.getIcon().alignCenter();
    fullscreenBtn.getIcon().setScale(2.5f, 2.5f);
    fullscreenBtn.setSize({80, 80});
    fullscreenBtn.setPadding(fullscreenBtn.getSize() / 2.f);

    musicVolumeBtn.setIcon("assets/icons/music_volume_0.png");
    musicVolumeBtn.getIcon().alignCenter();
    musicVolumeBtn.getIcon().setScale(2.5f, 2.5f);
    musicVolumeBtn.setSize({80, 80});
    musicVolumeBtn.setPadding(musicVolumeBtn.getSize() / 2.f);

    effectsVolumeBtn.setIcon("assets/icons/effects_volume_0.png");
    effectsVolumeBtn.getIcon().alignCenter();
    effectsVolumeBtn.getIcon().setScale(2.5f, 2.5f);
    effectsVolumeBtn.setSize({80, 80});
    effectsVolumeBtn.setPadding(effectsVolumeBtn.getSize() / 2.f);

    uiVolumeBtn.setIcon("assets/icons/ui_volume_0.png");
    uiVolumeBtn.getIcon().alignCenter();
    uiVolumeBtn.getIcon().setScale(2.5f, 2.5f);
    uiVolumeBtn.setSize({80, 80});
    uiVolumeBtn.setPadding(uiVolumeBtn.getSize() / 2.f); 

    prefGroup.setPosition({100, 100});
    prefGroup.setMargin({90, 0});
    prefGroup.add(fullscreenBtn);
    prefGroup.add(musicVolumeBtn);
    prefGroup.add(effectsVolumeBtn);
    prefGroup.add(uiVolumeBtn);
    */
    addComp(play);
    addComp(pref);
    //addCompsGroup(prefGroup);
    /*addComp(fullscreenBtn);
    addComp(musicVolumeBtn);
    addComp(effectsVolumeBtn);
    addComp(uiVolumeBtn);*/
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