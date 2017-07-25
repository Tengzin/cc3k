#include "drow.h"
#include <string>
#include "potion.h"
#include "woundatk.h"
#include "wounddef.h"
#include "boostatk.h"
#include "boostdef.h"

using std::string;

Drow::Drow():
  Player{150, 25, 15} {}

//Drows don't get hit twice by elves
void Drow::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}

void Drow::takePotion(Potion *p, Player *pc) {
  string pot = p->getPotType();
  if (pot == "RH") { this->heal(15); }
  else if (pot == "WA") { pc = new WoundAtk(7, pc); }
  else if (pot == "BA") { pc = new BoostAtk(7, pc); }
  else if (pot == "WD") { pc = new WoundDef(7, pc); }
  else if (pot == "BD") { pc = new BoostDef(7, pc); }
  else {
    this->heal(-15);
    if (this->getHP() <= 0) this->setDead(true);
  }
}
