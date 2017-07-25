#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"

/*
#include "interactable.h"
#include "character.h"
#include "player.h"
*/


class Enemy: public Character {
public:
  Enemy();
  void notify(Player *pc);

  virtual void Strike(Player *pc);
  virtual void beStruckBy(Player *pc);
  virtual bool isOrc() { return false; }
  virtual bool isElf() { return false; }
  virtual bool isDwarf() { return false; }

  bool movement() override;
};


#endif
