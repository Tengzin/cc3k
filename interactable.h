#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "player.h"
#include "enemy.h"
#include "potion.h"

class Interactable {
public:
};

class Character: public Interactable {
protected:
  int hp;
  int atk;
  int def;
  int gold;
public:
  virtual int getHP() = 0;
  virtual int getAtk() = 0;
  virtual int getDef() = 0;
};




#endif
