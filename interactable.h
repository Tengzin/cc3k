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
};




#endif
