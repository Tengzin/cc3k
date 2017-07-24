#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include <algorithm>

#include "decoratePC.h"

class BoostDef: public PCDecorator {
  static int checked;
  int def_gain;
public:
  BoostDef(int def_gain, Player *pc);
  int getDef() override;
};

#endif
