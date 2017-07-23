#include "troll.h"

Troll::Troll():
Character{120, 25, 15, 0}
Player{120, 25, 15, 0} {}

void Troll::regen() {
  this->heal(5);
}
