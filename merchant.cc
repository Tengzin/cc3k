#include "merchant.h"

Merchant::Merchant():
Character{30, 70, 5, 0}
Enemy{} {}

void Merchant::Strike(Player *pc) {
  // merchant only attacks if aggressive
  if (merch_aggressive == true) pc->beStruckBy(this);
}

void Merchant::beStruckBy(Player *pc) {
  const int dmg = pc->getAtk();
  damaged(dmg);
  if (this->isDead() == true) pc->autoLoot();
  merch_aggressive
}
