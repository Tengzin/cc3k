#ifndef PLAYER_H
#define PLAYER_H

/*
#include "character.h"
#include "interactable.h"
#include "enemy.h"
#include "potion.h"
*/
#include "character.h"
#include "interactable.h"
#include "enemy.h"
#include <iostream>
using namespace std;
class Potion;

class Player: public Character {
  int def_hp;
  int def_atk;
  int def_def;  
public:
  Player();
  Player(int hp, int atk, int def);
  virtual ~Player() = 0;

  int getHP() override;
  int getAtk() override;
  int getDef() override;

  virtual void Strike(Enemy *e);
  virtual void beStruckBy(Enemy *e);

  void takePotion(Potion *p, Player *pc) override;
  virtual void autoLoot();

  char whatType(Interactable *i) override;

  void resetStats(); //after a level is cleared, reset atk and def
  friend std::ostream &operator<<(std::ostream &out, const Player &pc);
protected:
  int gold;
  virtual void heal(int hp_gain);
  void setAtk(int new_atk);
  void setDef(int new_def);
  const int getDefHP();
  const int getDefAtk(); //returns default value for resetting
  const int getDefDef();
  //Race specifics
  virtual void regen() {};
  virtual bool isDrow() { return false; }

};

#endif
