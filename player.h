#ifndef PLAYER_H
#define PLAYER_H

class Player: public Character {
  const int def_hp;
  const int def_atk;
  const int def_def;
  int pot_multiplier; //potion multiplier, drow character has 1.5x
  bool max_hp; //if there is a hp cap, vampires have no cap
  int hp_regen;
  int lifesteal;
  int gold_steal; //goblins steal 5 gold from killing enemies
public:
  Player(int hp, int atk, int def, int pot_multiplier, bool max_hp,
    int hp_regen, int lifesteal, int gold_steal);
  void resetStats(); //after a level is cleared, reset atk and def
protected:
  virtual int getHP();
  virtual int getAtk();
  virtual int getDef();
  virtual ~Player() = 0;

  void setHP(int new_hp);
  void setAtk(int new_atk);
  void setDef(int new_def);
  const int getPotMulti();
  const int getDefHP();
  const int getDefAtk(); //returns default value for resetting
  const int getDefDef();
  void regen(); //Player could regen hp at the end of a turn if vampire
  void lifeSteal(); // Gain HP after attacking an enemy
};

#endif
