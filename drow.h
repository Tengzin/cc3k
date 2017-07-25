#ifndef DROW_H
#define DROW_H

#include "player.h"

class Drow: public Player {
public:
  Drow();
  void beStruckBy(Enemy *e) override;
  void takePotion(Potion *p, Player *pc) override;
};

#endif
