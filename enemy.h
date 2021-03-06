#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

/*
#include "interactable.h"
#include "character.h"
#include "player.h"
*/
class Player;

class Enemy: public Character {
public:
  Enemy(int hp, int atk, int def);
  void notify(Player *pc) override;

  virtual void Strike(Player *pc);
  virtual void beStruckBy(Player *pc);
  virtual bool isOrc() { return false; }
  virtual bool isElf() { return false; }
  virtual bool isDwarf() { return false; }
  void takePotion(Potion *p, Player *pc) override {}

  bool movement() override;
};


#endif
