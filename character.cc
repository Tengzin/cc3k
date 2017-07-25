#include "character.h"
#include <cmath>

Character::Character(int hp, int atk, int def):
hp{hp}, atk{atk}, def{def}, isDead{0} {}

void Character::setDead(bool dead) {
  isDead = dead;
}

bool Character::checkDead() {
  return isDead;
}

// does dmg to the Character
void Character::damaged(int dmg) {
  //damage calculation
  const int dmg_done = ceil((100 / (100 + this->getDef())) * dmg);
  hp = hp - dmg_done;
  if (hp <= 0) this->setDead(true);
}
