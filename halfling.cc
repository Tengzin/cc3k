#include "halfling.h"

Halfling::Halfling():
Character{100, 15, 20, 0}
Enemy{} {}

void Halfling::beStruckBy(Player *pc) {
  // 50% chance for this to happen, use random function  
  const int dmg = pc->getAtk();
  damaged(dmg);
  if (this->isDead() == true) pc->autoLoot();
}
