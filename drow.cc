#include "drow.h"

Drow::Drow():
  Character{150, 25, 15, 0}
  Player{150, 25, 15, 0} {}

//Drows don't get hit twice by elves
void Drow::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}
