#ifndef WOUNDATK_H
#define WOUNDATK_H
#include <algorithm>

#include "decoratePC.h"

class WoundAtk: public PCDecorator {
  int atk_loss;
public:
  WoundAtk(int atk_loss, Player *pc);
  int getAtk() override;
};

#endif
