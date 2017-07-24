#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include <algorithm>

#include "decoratePC.h"

class WoundDef: public PCDecorator {
  int def_loss;
public:
  WoundDef(int def_loss, Player *pc);
  int getDef() override;
};

#endif
