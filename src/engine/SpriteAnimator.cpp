#include <engine/SpriteAnimator.hpp>

SpriteAnimator::SpriteAnimator(Sprite& sprite) 
: sprite(sprite)
{
   frameIndex = 0;
   timer = 0;
   dt = 0;
   speed = milliseconds(1);
   repeated = true;
   finished = false;
}

void SpriteAnimator::_update(float _dt) {
   dt = _dt;
}

/**
 * Sprite has to be aligned after animation is set
*/
void SpriteAnimator::setAnimGrid(Vector2i _grid) {
   grid = _grid;

   Vector2i cellSize{
      static_cast<int>(sprite.getTexture()->getSize().x / grid.x),
      static_cast<int>(sprite.getTexture()->getSize().y / grid.y)
   };

   for (int i = 0; i < grid.y; i++) {
      for (int j = 0; j < grid.x; j++) {
         IntRect frame(j * cellSize.x, i * cellSize.y, cellSize.x, cellSize.y);
         frames.push_back(frame);
      }
   }
   
   sprite.setTextureRect({0, 0, cellSize.x, cellSize.y});
}

void SpriteAnimator::play() {
   if (finished)
      return;

   if (timer >= speed.asSeconds()) {
      sprite.setTextureRect(frames[frameIndex]);
      frameIndex++;
      timer = 0;
   }
   
   timer += dt;

   if (frameIndex == frames.size()) {
      if (!repeated) {
         finished = true;
         return;
      }
      frameIndex = 0;
   }
}

void SpriteAnimator::setRepeated(bool flag) { repeated = flag; }
void SpriteAnimator::setSpeed(Time _speed) { speed = _speed; }

bool SpriteAnimator::isRepeated() { return repeated; }
bool SpriteAnimator::isFinished() { return finished; }
float SpriteAnimator::getSpeed() { return speed.asSeconds(); }

Time SpriteAnimator::getDuration() {
   return seconds(speed.asSeconds() * frames.size());
}