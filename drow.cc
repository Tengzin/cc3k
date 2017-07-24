#include "drow.h"

Drow::Drow():
  Character{150, 25, 15, 0}
  Player{150, 25, 15, 0} {}

//Drows don't get hit twice by elves
void Drow::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}

void Drow::takePotion(Potion *p) {
  string pot = p->getPotType();
  if (pot == "RH") { this->heal(15); }
  else if (pot == "WA") { *this = new WoundAtk(7, this); }
  else if (pot == "BA") { *this = new BoostAtk(7, this); }
  else if (pot == "WD") { *this = new WoundDef(7, this); }
  else if (pot == "BD") { *this = new BoostDef(7, this); }
  else {
    this->heal(-15);
    if (this->getHP() <= 0) this->setDead(true);
  }
}
