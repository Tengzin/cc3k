#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class Goblin: public Player {
public:
  Goblin();
  void beStruckBy(Enemy *e) override;
  void autoLoot(Enemy *e) override;
};

#endif
