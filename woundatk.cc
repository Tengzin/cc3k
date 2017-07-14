#include "woundatk.h"
#include <iostream>
#include <algorithm>
using namespace std;

int WoundAtk::checked(0);
const int lowest_atk = 0; //could perhaps change in future?

WoundAtk::WoundAtk(int atk_loss, Player *pc):
  PCDecorator{pc}, atk_loss{atk_loss}  {
    if (checked == true) cout << "You lost " << atk_loss "ATK points." << endl;
    checked = 1; // after using the potion, Player knows
  }
int WoundAtk::getAtk() {
  return max((pc->getAtk() - atk_loss), lowest_atk); // can't go below lowest
}
