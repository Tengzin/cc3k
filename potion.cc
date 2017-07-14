#include "potion.h"



/*
// RH (Recover Health)
RHPot::RHPot(const int heal): heal{heal}{}
const void RHPot::checkEffect() {
  if (RH_checked == true) {
    cout << "This potion will heal you for " << heal << " points." << endl;
  }
  else cout << "Effect unknown." << endl;
}
void RHPot::takePotion() {
  const int max = player->getDefHP(); //how much the player started with
  int new_hp = player->getHP() + heal;
  // if player is vampire (unlim hp) or will not hit hp cap
  if (max_hp == false || new_hp <= max) player->setHP(new_hp);
  else player->setHP(max); // bring HP to maximum
  RH_checked = true; //after taking the potion, player knows its effect
}
*/
//BA (Boost Atk)
