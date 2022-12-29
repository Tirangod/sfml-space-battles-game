#ifndef UIBUTTON_HPP
#define UIBUTTON_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "engine/effects/RampEffect.hpp"
#include "engine/SoundPlayer.hpp"
#include "engine/GameSprite.hpp"
#include "engine/KeyEvents.hpp"
#include "engine/Aliases.hpp"
#include "UIComponent.hpp"
#include "UIText.hpp"

using namespace aliases;
using namespace std;
using namespace sf;

class UIButton : public UIComponent {
private:
    SoundPlayer clickSound;
    SoundPlayer selectSound;

    RampEffect *clickEffect;

    Vector2f padding;
    GameSprite icon;
    UIText text;
    Color startColor;
    Color clickColor;
    //Color selectColor;
    //Color startOutlineColor;
    //Color selectOutlineColor;
    
    VoidCallback onClickCallback;
public:
    UIButton();
    void onInit();
    void onDraw(RenderTarget& target);
    void onUpdate(float dt);
    void onSelected();
    void onUnselected();
    void onWhileSelected(float dt);
    void onUpdateTransform();

    void alignTextCenter();

    void setColor(Color color);
    void setClickColor(Color color);
    void setOnClick(VoidCallback callback);
    //void setOnSelect(function<void(void)> callback);
    //void setOnUnselect(function<void(void)> callback);
    void setPadding(Vector2f padding);
    void setIcon(string path);
    void setString(string value);

    Vector2f getPadding();
    GameSprite& getIcon();
    UIText& getText();
    string getString();
};

#endif