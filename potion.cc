#include "potion.h"
#include <iostream>
using namespace std;

void Potion::notify(Player *pc) {
  const int pot = RandomNumber(6);
  if (pot == 1) {
    pot_type = "RH";
    if (RH_checked) {
    cout << "There is a Healing potion here! It will heal up to 10 HP." << endl;
    }
  }
  else if (pot == 2) {
    pot_type = "BA";
    if (BA_checked) {
    cout << "There is a Boost ATK potion here! It will grant 5 ATK." << endl;
  }
  else if (pot == 3) {
    pot_type = "BD";
    if (BD_checked) {
    cout << "There is a Boost DEF potion here! It will grant 5 DEF." << endl;
    }
  }
  else if (pot == 4) {
    pot_type = "PH";
    if (PH_checked) {
    cout << "There is a Poison potion here! It will do 10 damage." << endl;
    }
  }
  else if (pot == 5)
  {
    pot_type = "WA";
    if (WA_checked) {
    cout << "There is a Wound ATK potion here! Lose 5 ATK." << endl;
    }
  }
  else {
    pot_type = "WD";
    if (WD_checked) {
    cout << "There is a Wound DEF potion here! Lose 5 DEF." << endl;
    }
}

String Potion::getPotType() { return pot_type; }
