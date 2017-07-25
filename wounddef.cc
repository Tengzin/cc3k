#include "wounddef.h"
#include <iostream>
#include <algorithm>
using namespace std;

const int lowest_def = 0; //could perhaps change in future?

WoundDef::WoundDef(int def_loss, Player *pc):
  PCDecorator{pc}, def_loss{def_loss}  {
    cout << "You lost " << def_loss << " DEF points." << endl;  
  }
int WoundDef::getDef() {
  return max((pc->getDef() - def_loss), lowest_def); // can't go below lowest
}
