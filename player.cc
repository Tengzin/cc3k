#include "player.h"
#include "potion.h"
#include "woundatk.h"
#include "wounddef.h"
#include "boostatk.h"
#include "boostdef.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using std::string;

int RandomNumberP(int n) {
	srand(time(0));
	int randNum;
	randNum = 1 + (rand() % n);
	return randNum;
}

Player::Player() {}

Player::Player(int hp, int atk, int def):
Character{hp, atk, def},
def_hp{hp}, def_atk{atk}, def_def{def},
gold{0} {}

Player::~Player() {}

char Player::whatType(Interactable *i) { return '@'; }

int Player::getHP() { return hp; }
int Player::getAtk() { return atk; }
int Player::getDef() { return def; }

void Player::Strike(Enemy *e) {
  e->beStruckBy(this);
}

void Player::beStruckBy(Enemy *e) {
  const int dmg = e->getAtk();
  const int miss = RandomNumberP(2);

  if (e->isElf() == true) {
    const int miss_two = RandomNumberP(2);
    if (miss_two == 1) { damaged(dmg); }
  }
  if (miss == 1) { damaged(dmg); }
}

const int Player::getDefHP() { return def_hp; }
const int Player::getDefAtk() { return def_atk; }
const int Player::getDefDef() { return def_def; }

void Player::takePotion(Potion *p, Player *pc) {
  string pot = p->getPotType();
  if (pot == "RH") { pc->heal(10); }
  else if (pot == "WA") { pc = new WoundAtk(5, pc); }
  else if (pot == "BA") { pc = new BoostAtk(5, pc); }
  else if (pot == "WD") { pc = new WoundDef(5, pc); }
  else if (pot == "BD") { pc = new BoostDef(5, pc); }
  else {
    this->heal(-10);
    if (this->getHP() <= 0) this->setDead(true);
  }
} //generate and decorate player with potion


void Player::heal(int hp_gain) {
  const int max = this->getDefHP(); //how much the player started with
  hp = std::min(max, this->getHP() + hp_gain);
}
void Player::setAtk(int new_atk) { atk = new_atk; }
void Player::setDef(int new_def) { def = new_def; }

void Player::resetStats() {
  setAtk(this->getDefAtk());
  setDef(this->getDefDef());
}

void Player::autoLoot() {
  //use random function to generate 1 or 2
  // and add to gold immediately
  const int loot = RandomNumberP(2);
  gold += loot;
}
