#ifndef POTION_H
#define POTION_H
#include <string>
using std::string;

#include "interactable.h"
/*
#include "player.h"
#include "maplayout.h"
#include "interactable.h"
*/

class Player;

// Potions: Should Use Decorator Pattern
class Potion: public Interactable {
  string pot_type;
public:
  char whatType(Interactable *i) override;
  void notify(Player *pc);
  string getPotType();
  void takePotion(Potion *p, Player *pc) override {};
};


#endif
