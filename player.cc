#include "player.h"

// Player Class Methods
Player::Player(int hp, int atk, int def, int pot_multiplier, bool max_hp,
  int hp_regen, int lifesteal, int gold_steal):
  Character{hp, atk, def}, //must invoke superclass ctor
  def_hp {hp} def_atk {atk}, def_def {def}, pot_multiplier{pot_multiplier},
  max_hp{max_hp}, hp_regen{hp_regen}, lifesteal{lifesteal},
  gold_steal{gold_steal} {}

int Player::getHP() { return hp};;
int Player::getAtk() { return atk; }
int Player::getDef() { return def; }

const int Player::getDefHP() { return def_hp; }
const int Player::getDefAtk() { return def_atk; }
const int Player::getDefDef() { return def_def; }

const int Player::getPotMulti() { return pot_multiplier; }

void Character::setHP(int new_hp) { hp = new_hp; }
void Character::setAtk(int new_atk) { atk = new_atk; }
void Character::setDef(int new_def) { def = new_def; }

void Player::resetStats() {
  setAtk(this->getDefAtk());
  setDef(this->getDefDef());
}

// Only trolls have this ability
void Player::regen() {
  const int max = player->getDefHP(); //how much the player started with
  setHP(std::min(this->getHP() + hp_regen, max)); // cannot be over the max hp
}
// currently does not support bonus classes, does not account for max hp
// since only vampires regen and they have no cap
void Player::lifeSteal() {
  setHP((this->getHP() + lifesteal));
}
