#include "interactable.h"

// Character Class Methods
const int Character::getHealth() { return hp; }
const int Character::getAtk() { return atk; }
const int Character::getDef() { return def; }
const int Character::getDefAtk() { return def_atk; }
const int Character::getDefDef() { return def_def; }

void Character::setHP(int new_hp) { hp = new_hp; }
void Character::setAtk(int new_atk) { atk = new_atk; }
void Character::setDef(int new_def) { def = new_def; }

// Player Class Methods
Player::Player(int hp, int atk, int def, int pot_multiplier, bool max_hp,
  int hp_regen, int gold_steal):
   Character{hp, atk, def}, //must invoke superclass ctor
   def_atk {atk}, def_def {def}, pot_multiplier{pot_multiplier}, max_hp{max_hp},
   hp_regen{hp_regen}, gold_steal{gold_steal}{}

void Player::resetStats() {
  setAtk(this->getDefAtk());
  setDef(this->getDefDef());
}

// Enemy Class Methods
Enemy::Enemy(int hp, int atk, int def, int gold_drop, bool aggressive, bool allergy,
  int num_atks, double atk_multiplier, double player_miss_chance):
  Character{hp, atk, def},
  gold_drop{gold_drop}, aggressive{aggressive}, allergy{allergy},
  num_atks{num_atks}, atk_multiplier{atk_multiplier},
  player_miss_chance{player_miss_chance} {}

// Potion Class Methods
RHPot::RHPot(const int heal): heal{heal}{}

const void RHPot::checkEffect() {
  if (checked == true) {
    cout << "This potion will heal you for " << heal << " points." << endl;
  }
  else cout << "Effect unknown." << endl;
}

void RHPot::takePotion() {
  int max = heal + 
}

