#include "shade.cc"

Shade::Shade(int hp, int atk, int def):
  Character{hp, atk, def},
  Player{hp, atk, def} {}

void Shade::Strike(Enemy *e) {
  e->beStruckBy(this);
}

void Shade::beStruckBy(Enemy *e) {
  damaged(e->getAtk());
}
