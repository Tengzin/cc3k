#include "player.h"

// Player Class Methods
Player::Player(int hp, int atk, int def):
  Character{hp, atk, def}, //must invoke superclass ctor
  def_hp {hp} def_atk {atk}, def_def {def} {}

int Player::getHP() { return hp; }
int Player::getAtk() { return atk; }
int Player::getDef() { return def; }

const int Player::getDefHP() { return def_hp; }
const int Player::getDefAtk() { return def_atk; }
const int Player::getDefDef() { return def_def; }

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
