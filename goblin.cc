#include "goblin.h"

Goblin::Goblin(int hp, int atk, int def):
Player(hp, atk, def) {}

void Goblin::beStruckBy(Enemy *e) {
  const int e_atk = e->getAtk();
  float multi = 1;
  if (e->isOrc() == true) multi = 1.5;
  else if (e->isElf() == true) multi = 2;
  damaged(e_atk * multi);
}

void Goblin::autoLoot() {
  gold += 5; // additional gold from killing
}
