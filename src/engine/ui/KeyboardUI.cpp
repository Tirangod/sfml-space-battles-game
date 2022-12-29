#include <engine/ui/KeyboardUI.hpp>

void KeyboardUI::init() {
    compIndex = 0;
    onInit();
    select(0);
}

void KeyboardUI::draw(RenderTarget& target) {
    for (int i = 0; i < comps.size(); i++) {
        comps[i]->_draw(target);
    }
    onDraw(target);
}
void KeyboardUI::update(float dt) {
    for (int i = 0; i < comps.size(); i++) {
        if (i == compIndex)
            comps[i]->_whileSelected(dt);
        comps[i]->_update(dt);
    }
    onUpdate(dt);
}

void KeyboardUI::addComp(UIComponent& comp) {
    comp._init();
    comps.push_back(&comp);
}

void KeyboardUI::addCompsGroup(CompsGroup& group) {
    group.applyTransforms();
    
    auto& groupComps = group.getComponents();
    for (int i = 0; i < groupComps.size(); i++) {
        addComp(*groupComps[i]);
    }
}

void KeyboardUI::select(int index) {
    if (!comps.empty())
        comps[compIndex]->unselect(); //unselect prev comp

    if (index >= comps.size()) {
        /*
        cout << "cond: " << (index >= comps.size() ? "true" : "false")  << endl;
        cout << "index1: " << index << endl;
        cout << "size: " << comps.size() << endl;
        cout << "test: " << (-1 >= 3) << endl;
        */
        index = 0;
    } else if (index == -1) {
        index = comps.size() - 1;
    }
    
    //TODO: fix
    if (!comps[index]->isSelectable()) {
        select(index + 1);
        cout << "select: unselectable" << endl;
        return;
    }

    compIndex = index;
}

void KeyboardUI::selectNext() {
    select(getIndex() + 1);
}

int KeyboardUI::getIndex() {
    return compIndex;
}