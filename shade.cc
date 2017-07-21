#include "shade.cc"

Shade::Shade(int hp, int atk, int def):
  Character{hp, atk, def},
  Player{hp, atk, def} {}
