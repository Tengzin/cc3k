#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Interactable {
public:


};

class Character: public Interactable {
  int hp;
  int atk;
  int def;
public:
  const int getHP();
  const int getAtk();
  const int getDef();

  void setHP(int new_hp);
  void setAtk(int new_atk);
  void setDef(int new_def);
};

class Player: public Character {
  const int def_hp;
  const int def_atk;
  const int def_def;
  int pot_multiplier; //potion multiplier, drow character has 1.5x
  bool max_hp; //if there is a hp cap, vampires have no cap
  int hp_regen;
  int gold_steal; //goblins steal 5 gold from killing enemies
public:
  Player(int hp, int atk, int def, int pot_multiplier, bool max_hp,
    int hp_regen, int gold_steal);
  const int getDefHP();
  const int getDefAtk(); //returns default value for resetting
  const int getDefDef();
  void resetStats(); //after a level is cleared, reset atk and def
};

class Enemy: public Character {
  int gold_drop;
  bool aggressive; //merchants are neutral unless global var is true
  bool allergy; //If player is a Vampire and enemy is a dwarf, player loses hp/s
  int num_atks; //Elves get 2 attacks against every race except drow
  double atk_multiplier; //orcs do 50% more against goblins
  double player_miss_chance; //default is 0, becomes 50% against a halfling
public:
  Enemy(int hp, int atk, int def, int gold_drop, bool aggressive, bool allergy,
    int num_atks, double atk_multiplier, double player_miss_chance);
  // observer method
};

// Potions
class Potion: public Interactable {
public:
  virtual const void checkEffect() = 0;
  virtual void takePotion() = 0;
};

class RHPot: public Potion {
  const int heal; //default is 10, but maybe have diff values for bonus?
public:
  RHPot(const int heal);
  const void checkEffect();
  void takePotion();
};

class BAPot: public Potion {

};



#endif
