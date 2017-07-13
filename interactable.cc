#include "interactable.h"
#include <algorithm>

// Character Class Methods
const int Character::getHP() { return hp; }
const int Character::getDefHP() { return def_hp; }
const int Character::getAtk() { return atk; }
const int Character::getDef() { return def; }
const int Character::getDefAtk() { return def_atk; }
const int Character::getDefDef() { return def_def; }

void Character::setHP(int new_hp) { hp = new_hp; }
void Character::setAtk(int new_atk) { atk = new_atk; }
void Character::setDef(int new_def) { def = new_def; }

// Player Class Methods
Player::Player(int hp, int atk, int def, int pot_multiplier, bool max_hp,
  int hp_regen, int lifesteal, int gold_steal):
  Character{hp, atk, def}, //must invoke superclass ctor
  def_hp {hp} def_atk {atk}, def_def {def}, pot_multiplier{pot_multiplier},
  max_hp{max_hp}, hp_regen{hp_regen}, lifesteal{lifesteal},
  gold_steal{gold_steal} {}

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


// Enemy Class Methods
Enemy::Enemy(int hp, int atk, int def, int gold_drop, bool aggressive, bool allergy,
  int num_atks, double atk_multiplier, double player_miss_chance):
  Character{hp, atk, def},
  gold_drop{gold_drop}, aggressive{aggressive}, allergy{allergy},
  num_atks{num_atks}, atk_multiplier{atk_multiplier},
  player_miss_chance{player_miss_chance} {}

// Potion Class Methods

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
