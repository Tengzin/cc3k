#ifndef TROLL_H
#define TROLL_H

#include "enemy.h"

class Troll: public Player {
public:
  Troll();
  void regen() override; //troll specific
};

#endif
