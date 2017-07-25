#include "halfling.h"
#include "maplayout.h"
#include "player.h"

Halfling::Halfling():
Enemy{ 100, 15, 20 } {}

char Halfling::whatType(Interactable *i) { return 'L'; }

void Halfling::beStruckBy(Player *pc) {
  // 50% chance for this to happen, use random function
  const int miss = RandomNumber(2);
  if (miss == 1) {
    const int dmg = pc->getAtk();
    damaged(dmg);
    if (this->checkDead() == true) pc->autoLoot();
  }
  else { cout << "The attack missed!" << endl; }
}
