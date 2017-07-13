#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Interactable {
public:
  virtual ~Interactable() = 0;

};

class Character: public Interactable {
  int hp;
  int atk;
  const int def_atk;
  int def;
  const int def_def;
public:
  ~Character() override;
protected:
  const int getHealth();
  const int getAtk();
  const int getDef();
  const int getDefAtk(); //returns default value for resetting
  const int getDefDef();

  void setHP(int new_hp);
  void setAtk(int new_atk);
  void setDef(int new_def);
};

class Player: public Character {
  int pot_multiplier; //potion multiplier, drow character has 1.5x
  bool max_hp; //if there is a hp cap, vampires have no cap
  int hp_regen;
  int gold_steal; //goblins steal 5 gold from killing enemies
public:
  Player(int hp, int atk, const int def_atk, int def, const int def_def,
    int pot_multiplier, bool max_hp, int hp_regen, int gold_steal);
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


};

#endif

