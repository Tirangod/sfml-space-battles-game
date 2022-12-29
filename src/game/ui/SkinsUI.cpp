#include <game/ui/SkinsUI.hpp>

void SkinsUI::onInit() {
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

    
    skin0.setIcon(Presets::Player0.skinPath);
    skin0.getIcon().alignCenter();
    skin0.getIcon().setScale(2.5f, 2.5f);
    skin0.getBackground().setFillColor(Color::Transparent);
    skin0.setColor(Color::Transparent);
    skin0.setClickColor({3, 102, 252});
    skin0.setSize({200, 200});
    skin0.setPadding(skin0.getSize() / 2.f);
    skin0.setOnClick([&]{ 
        fadeOut->start(); 
        Player::Preset = Presets::Player0;
    });
    
    skin1.setIcon(Presets::Player1.skinPath);
    skin1.getIcon().alignCenter();
    skin1.getIcon().setScale(2.5f, 2.5f);
    skin1.getBackground().setFillColor(Color::Transparent);
    skin1.setColor(Color::Transparent);
    skin1.setClickColor({242, 101, 0});
    skin1.setSize({200, 200});
    skin1.setPadding(skin1.getSize() / 2.f);
    skin1.setOnClick([&]{ 
        fadeOut->start(); 
        Player::Preset = Presets::Player1;
    });
    
    skin2.setIcon(Presets::Player2.skinPath);
    skin2.getIcon().alignCenter();
    skin2.getIcon().setScale(2.5f, 2.5f);
    skin2.getBackground().setFillColor(Color::Transparent);
    skin2.setColor(Color::Transparent);
    skin2.setClickColor({209, 54, 42});
    skin2.setSize({200, 200});
    skin2.setPadding(skin2.getSize() / 2.f);
    skin2.setOnClick([&]{ 
        fadeOut->start(); 
        Player::Preset = Presets::Player2;
    });

    skin3.setIcon(Presets::Player3.skinPath);
    skin3.getIcon().alignCenter();
    skin3.getIcon().setScale(2.5f, 2.5f);
    skin3.getBackground().setFillColor(Color::Transparent);
    skin3.setColor(Color::Transparent);
    skin3.setClickColor({64, 173, 36});
    skin3.setSize({200, 200});
    skin3.setPadding(skin3.getSize() / 2.f);
    skin3.setOnClick([&]{ 
        fadeOut->start(); 
        Player::Preset = Presets::Player3;
    });
    /*
    text.loadFont("assets/fonts/font_bold.ttf");
    text.setString("SomeText");
    text.setFontSize(100);
    text.getText().setFillColor(Color::White);
    text.alignCenter();
    text.setPosition({GameWindow::GetSizef().x / 2.f, 80.f});
    */
    group.setMargin({220, 0});
    group.setPosition(GameWindow::GetSizef() / 2.f);
    group.add(skin0);
    group.add(skin1);
    group.add(skin2);
    group.add(skin3);
    group.alignCenter();

    addCompsGroup(group);
    //addComp(text);
    addComp(panel);
}
void SkinsUI::onUpdate(float dt) {
    fadeIn->update(dt);
    fadeOut->update(dt);

    if (KeyEvents::isKeyPressed(Keyboard::D))
        selectNext();
    else if (KeyEvents::isKeyPressed(Keyboard::A))
        select(getIndex() - 1);
}