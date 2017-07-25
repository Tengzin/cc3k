#include "troll.h"

Troll::Troll():
Player{120, 25, 15} {}

void Troll::regen() {
  this->heal(5);
}
