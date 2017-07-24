#ifndef ENEMY_H
#define ENEMY_H

#include "interactable.h"
#include "character.h"
#include "player.h"

class Enemy: public Character {
public:
  Enemy();
  int getHP() override;
  int getAtk() override;
  int getDef() override;

  void notify(Player *pc);

  virtual void Strike(Player *pc);
  virtual void beStruckBy(Player *pc);
  virtual bool isOrc() { return false; }
  virtual bool isElf() { return false; }

  virtual void movement() override;
};


#endif
