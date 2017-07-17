#ifndef BOOSTATK_H
#define BOOSTATK_H
#include <algorithm>

#include "decoratePC.h"

class BoostAtk: public PCDecorator {
  static int checked;
  int atk_gain;
public:
  BoostAtk(int atk_gain, Player *pc);
  int getAtk() override;
};

#endif
