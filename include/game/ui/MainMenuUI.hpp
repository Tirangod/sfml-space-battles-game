#ifndef MAINMENUUI_HPP
#define MAINMENUUI_HPP

#include "engine/ui/KeyboardUI.hpp"
#include "engine/ui/CompsGroup.hpp"
#include "engine/ui/UIButton.hpp"
#include "engine/ui/UIText.hpp"
#include "engine/GameSettings.hpp"
#include "engine/GameWindow.hpp"
#include "engine/KeyEvents.hpp"
#include "engine/Scenes.hpp"

using namespace std;
using namespace sf;

class MainMenuUI : public KeyboardUI {
private:
    RampEffect *fadeIn;
    RampEffect *fadeOut;

    UIComponent panel;
    CompsGroup group;
    UIButton play;
    UIButton pref; //preferences
    UIButton exit;
    CompsGroup prefGroup;
    UIButton fullscreenBtn;
    UIButton musicVolumeBtn;
    UIButton effectsVolumeBtn;
    UIButton uiVolumeBtn;
public:
    void onInit();
    void onUpdate(float dt);
};

#endif