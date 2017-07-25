#include "boostdef.h"
#include <iostream>
#include <algorithm>
using namespace std;

int BoostDef::checked(0);

BoostDef::BoostDef(int def_gain, Player *pc):
PCDecorator{pc}, def_gain{def_gain} {
  cout << "You gained " << def_gain << " DEF points." << endl;  
}
int BoostDef::getDef() {
  return pc->getDef() + def_gain;
}
