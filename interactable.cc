#include "interactable.h"

//Character Class Methods
const int Character::getHealth() { return hp; }
const int Character::getAtk() { return atk; }
const int Character::getDef() { return def; }
const int Character::getDefAtk() { return def_atk; }
const int Character::getDefDef() { return def_def; }

void Character::setHP(int new_hp) { hp = new_hp; }
void Character::setAtk(int new_atk) { atk = new_atk; }
void Character::setDef(int new_def) { def = new_def; }
Character::~Character() { delete this };

//Player Class Methods
Player::Player(int hp, int atk, const int def_atk, int def, const int def_def,
  int pot_multiplier, bool max_hp, int hp_regen, int gold_steal):
   Character{hp, atk, def_atk, def, def_def}, //must invoke superclass ctor
   pot_multiplier{pot_multiplier}, max_hp{max_hp}, hp_regen{hp_regen},
   gold_steal{gold_steal}{}

void Player::resetStats() {
  setAtk(this->getDefAtk());
  setDef(this->getDefDef());
}

