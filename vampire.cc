#include "vampire.h"

Vampire::Vampire():
  Character{50, 25, 25, 0},
  Player{50, 25, 25, 0}, lifesteal{5} {}

void Vampire::heal() {
  // Must check for a dwarf!!
  hp = hp + lifesteal;
}
