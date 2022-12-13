#include <game/entities/Enemy.hpp>

void Enemy::onInit() {
    setupTexture("assets/sprites/red_01.png");
    
    getSprite().alignCenter();
    getSprite().rotate(180);
    //getSprite().setPosition(450, 200);
    getSprite().setScale(1.5f, 1.5f);

    hp = 100;
    healthBar = {hp, 100};

    float yOffset = -getSprite().getLocalBounds().height;

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});
    healthBar.getForeground().setFillColor(Color::Red);
    healthBar.setPosition({
        getSprite().getPosition().x - getSprite().getLocalBounds().width, 
        getSprite().getPosition().y + yOffset * 1.5f
    });
}

void Enemy::onDraw(RenderTarget &target) {
    healthBar._draw(target);
}

void Enemy::onCollisionEnter(GameObject *object) {
    cout << "ONCE" << endl;
}

void Enemy::onCollisionStay(GameObject *object) {
    if (dynamic_cast<Bullet*>(object)) {
        healthBar.add(-10);
        if (healthBar.getValue() <= 0) {
            spawn(new Explosion).getSprite().setPosition(getSprite().getPosition());
            destroy(this);
        }
    }
}