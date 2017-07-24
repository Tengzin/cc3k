#ifndef POTION_H
#define POTION_H
#include <string>

#include "interactable.h"
/*
#include "player.h"
#include "maplayout.h"
#include "interactable.h"
*/

// Potions: Should Use Decorator Pattern
class Potion: public Interactable {
  string pot_type;
public:
  char whatType(Interactable *i) override;
  void notify(Player *pc);
  string getPotType();
};


/*

class RHPot: public Potion {
  const int heal; //default is 10, but maybe have diff values for bonus?
public:
  RHPot(const int heal);
  const void checkEffect() override;
  void takePotion() override;
};

class BAPot: public Potion {
  const int atk_boost;
public:
  BAPot(const int atk_boost);


};
*/


#endif
