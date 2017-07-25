#include "merchant.h"
#include "player.h"
#include "character.h"

extern bool merch_aggressive;

Merchant::Merchant():
Enemy{ 30, 70, 5 } {}

char Merchant::whatType(Interactable *i) { return 'M'; }

void Merchant::Strike(Player *pc) {
  // merchant only attacks if aggressive
  if (merch_aggressive == true) pc->beStruckBy(this);
}

void Merchant::beStruckBy(Player *pc) {
  const int dmg = pc->getAtk();
  this->damaged(dmg);
  merch_aggressive = true;
  if (this->checkDead() == true) pc->autoLoot();
}
