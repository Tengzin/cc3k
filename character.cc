#include "character.h"
#include <cmath>

void Character::isDead(bool dead) {
  isDead = dead;
}

// does dmg to the Character
void Character::damaged(int dmg) {
  //damage calculation
  const int dmg_done = ceil((100 / (100 + this->getDef())) * dmg);
  hp = hp - dmg_done;
  if (hp <= 0) this->isDead(true);
}
