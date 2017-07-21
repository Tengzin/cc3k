#include "drow.h"

Drow::Drow(int hp, int atk, int def):
  Character{hp, atk, def},
  Player{hp, atk, def} {}

//Drows don't get hit twice by elves
void Drow::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}
