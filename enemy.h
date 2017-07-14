#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
  // Lots of variables, but makes it easier to add more types of enemies
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


#endif
