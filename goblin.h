#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"
#include "enemy.h"
#include "character.h"

class Goblin: public Player {
public:
  Goblin();
  void beStruckBy(Enemy *e) override;
  void autoLoot(Enemy *e) override;
};

#endif
