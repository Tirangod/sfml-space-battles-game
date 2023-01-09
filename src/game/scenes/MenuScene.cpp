#include <game/scenes/MenuScene.hpp>

void MenuScene::onInit() {
    getBackground().setColor(Color::Black);

    bg.loadFrom("assets/bgs/bg_21.png");

    planet0.loadFrom("assets/sprites/planets/earth_anim.png");
    planet0.setScale(2.4f, 2.4f/*3.5f, 3.5f*/);
    planet0.setPosition({990, 500}/*{1550, 700}*/);
    planet0.getAnimator().setAnimGrid({45, 45});
    planet0.getAnimator().setDuration(seconds(100.f));
    planet0.alignCenter();

    planet1.loadFrom("assets/sprites/planets/moon_anim.png");
    planet1.setScale(2.15f, 2.15f/*2.5f, 2.5f*/);
    planet1.setPosition({1140, 285}/*{1750, 350}*/);
    planet1.getAnimator().setAnimGrid({20, 20});
    planet1.getAnimator().setDuration(seconds(30.f));
    planet1.alignCenter();

    planet2.loadFrom("assets/sprites/planets/mars_anim.png");
    planet2.setScale(2.4f, 2.4f);
    planet2.setPosition({150, 290}/*{180, 210}*/);
    planet2.getAnimator().setAnimGrid({30, 30});
    planet2.getAnimator().setDuration(seconds(60.f));
    planet2.alignCenter();

    planet3.loadFrom("assets/sprites/planets/phobos_anim.png");
    planet3.setScale(1.3f, 1.3f/*1.6f, 1.6f*/);
    planet3.setPosition({270, 140}/*{290, 390}*/);
    planet3.getAnimator().setAnimGrid({15, 15});
    planet3.getAnimator().setDuration(seconds(15.f));
    planet3.alignCenter();

    planet4.loadFrom("assets/sprites/planets/ice_anim.png");
    planet4.setScale(2.f, 2.f/*1.8f, 1.8f*/);
    planet4.setPosition({185, 425}/*{160, 550}*/);
    planet4.getAnimator().setAnimGrid({15, 15});
    planet4.getAnimator().setDuration(seconds(15.f));
    planet4.alignCenter();

    gameNameCaption.loadFrom("assets/caption_en.png");
    gameNameCaption.setScale(1.75f, 1.75f/*2.5f, 2.5f*/);
    gameNameCaption.setPosition({285, 50}/*{440, 50}*/);

    getBackground().addSprite(bg, true);
    getBackground().addSprite(planet0);
    getBackground().addSprite(planet1);
    getBackground().addSprite(planet2);
    getBackground().addSprite(planet3);
    getBackground().addSprite(planet4);
    getBackground().addSprite(gameNameCaption);

    music.openFromFile("assets/audio/music/music1.wav");
    music.setVolume(20.f);
    music.play();
    GameSettings::AddMusic(music);

    /*
    scale = new ScaleEffect({900, 900});
    scale->setDuration(seconds(5));
    scale->addSprite(planet0);
    scale->start();
    */
   
    ui.init();
}

void MenuScene::onUpdate(float dt) {
    //scale->update(dt);
    ui.update(dt);

    if (KeyEvents::isKeyPressed(Keyboard::U))
        gameNameCaption.loadFrom("assets/caption.png");
    else if (KeyEvents::isKeyPressed(Keyboard::E))
        gameNameCaption.loadFrom("assets/caption_en.png");
}

void MenuScene::onDraw(RenderTarget& target) {
    ui.draw(target);
}

void MenuScene::onChanged(Scene& scene) {
    music.stop();
}