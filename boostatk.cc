#include "boostatk.h"
#include <iostream>
#include <algorithm>
using namespace std;

int BoostAtk::checked(0);

BoostAtk::BoostAtk(int atk_gain, Player *pc):
PCDecorator{pc}, atk_gain{atk_gain} {
  if (checked == true) cout << "You lost " << atk_loss "ATK points." << endl;
  checked = 1; // after using the potion, Player knows
}
int BoostAtk::getAtk() {
  return pc->getAtk() + atk_gain;
}
