
#include "vampire.h"

Vampire::Vampire():
  Player{50, 25, 25}, lifesteal{5} {}

void Vampire::heal(int hp_gain) {
  hp = hp + hp_gain;
}

void Vampire::Strike(Enemy *e) {
  const int pre_hp = e->getHP();
  e->beStruckBy(this);
  if ((e->isDwarf() == false) && (pre_hp > e->getHP())) {
    this->heal(5);
  }
  else this->heal(-5);
}
