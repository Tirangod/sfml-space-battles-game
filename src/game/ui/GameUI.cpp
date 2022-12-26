#include <game/ui/GameUI.hpp>

void GameUI::onInit() {
    panel.setSize(GameWindow::Get().GetSizef());
    panel.getBackground().setFillColor(Color::Black);
    //panel.setSelectable(false);
    
    fadeIn = new RampEffect(Color::Black, Color::Transparent);
    fadeIn->addShape(panel.getBackground());
    fadeIn->setDuration(seconds(1.2f));
    fadeIn->start();
    
    addComp(panel);
}
void GameUI::onUpdate(float dt) {
    fadeIn->update(dt);
}