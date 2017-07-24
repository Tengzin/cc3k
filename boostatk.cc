#include "boostatk.h"
#include <iostream>
#include <algorithm>
using namespace std;

BoostAtk::BoostAtk(int atk_gain, Player *pc):
PCDecorator{pc}, atk_gain{atk_gain} {
  cout << "You gained " << atk_loss "ATK points." << endl;  
}
int BoostAtk::getAtk() {
  return pc->getAtk() + atk_gain;
}
