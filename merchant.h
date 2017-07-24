#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "interactable.h"

class Merchant: public Enemy {
public:
  Merchant();
  char whatType(Interactable *i) override;
  void Strike(Player *pc) override;
  void beStruckBy(Player *pc) override;
};

#endif
