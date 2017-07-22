#include "troll.h"

Troll::Troll(int hp, int atk, int def):
  Player(hp, atk, def) {}

void Troll::regen() {
  this->heal(5);
}
