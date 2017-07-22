#include "vampire.h"

Vampire::Vampire(int hp, int atk, int def):
  Character{hp, atk, def},
  Player{hp, atk, def, 0}, lifesteal{5} {}

void Vampire::heal(int hp_gain) {
  // Must check for a dwarf
  hp = hp + hp_gain;
}
