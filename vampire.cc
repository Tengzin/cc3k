#include "vampire.h"

Vampire::Vampire(int hp, int atk, int def):
  Character{hp, atk, def},
  Player{hp, atk, def}, lifesteal{5} {}

void Vampire::Strike(Enemy *e) {
  e->beStruckBy(this);
}

void Vampire::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}

void Vampire::heal(int hp_gain) {
  // Must check for a dwarf
  hp = hp + hp_gain;
}
