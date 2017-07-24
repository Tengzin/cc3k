#include "player.h"
#include "maplayout.h"

// Player Class Methods
/*
Player::Player():
  Character{hp, atk, def, 0}, //must invoke superclass ctor
  def_hp {hp} def_atk {atk}, def_def {def}, gold{0} {}
*/
int Player::getHP() { return hp; }
int Player::getAtk() { return atk; }
int Player::getDef() { return def; }

void Player::Strike(Enemy *e) {
  e->beStruckBy(this);
}

void Player::beStruckBy(Enemy *e) {
  const int dmg = e->getAtk();
  const int miss = RandomNumber(2);
  
  if (e->isElf() == true) {
    const int miss_two = RandomNumber(2);
    if (miss_two == 1) { damaged(dmg); }
  }
  if (miss == 1) { damaged(dmg); }
}

const int Player::getDefHP() { return def_hp; }
const int Player::getDefAtk() { return def_atk; }
const int Player::getDefDef() { return def_def; }

void takePotion(Potion *p) {
  String pot = p->getPotType();
  if (pot == "RH") { this->heal(10); }
  else if (pot == "WA") { this = new WoundAtk(5, this); }
  else if (pot == "BA") { this = new BoostAtk(5, this); }
  else if (pot == "WD") { this = new WoundDef(5, this); }
  else if (pot == "BD") { this = new BoostDef(5, this); }
  else {
    this->heal(-10);
    if (this->getHP() <= 0) this->setDead(true);
  }
} //generate and decorate player with potion

void Player::heal(int hp_gain) {
  const int max = this->getDefHP(); //how much the player started with
  hp = std::min(max, this->getHP() + hp_gain)
}
void Player::setAtk(int new_atk) { atk = new_atk; }
void Player::setDef(int new_def) { def = new_def; }

void Player::resetStats() {
  setAtk(this->getDefAtk());
  setDef(this->getDefDef());
}

void autoLoot() {
  //use random functoin to generate 1 or 2
  // and add to gold immediately
}
