#include <engine/ui/UI.hpp>

void UI::init() {
    compIndex = 0;
    onInit();
    select(0);
}

void UI::draw(RenderTarget& target) {
    for (int i = 0; i < comps.size(); i++) {
        comps[i]->_draw(target);
    }
    onDraw(target);
}
void UI::update(float dt) {
    for (int i = 0; i < comps.size(); i++) {
        if (i == compIndex)
            comps[i]->_whileSelected(dt);
        comps[i]->_update(dt);
    }
    onUpdate(dt);
}

void UI::addComp(UIComponent& comp) {
    comp._init();
    comps.push_back(&comp);
}

void UI::addCompsGroup(CompsGroup& group) {
    group.applyTransforms();
    
    auto& groupComps = group.getComponents();
    for (int i = 0; i < groupComps.size(); i++) {
        addComp(*groupComps[i]);
    }
}

void UI::select(int index) {
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

void UI::selectNext() {
    select(getIndex() + 1);
}

int UI::getIndex() {
    return compIndex;
}