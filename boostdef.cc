#include "boostdef.h"
#include <iostream>
#include <algorithm>
using namespace std;

int BoostDef::checked(0);

BoostAtk::BoostAtk(int def_gain, Player *pc):
PCDecorator{pc}, def_gain{def_gain} {
  if (checked == true) cout << "You gained " << def_gain "DEF points." << endl;
  checked = 1; // after using the potion, Player knows
}
int BoostDef::getDef() {
  return pc->getDef() + def_gain;
}
