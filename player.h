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

class Potion;

class Player: public Character {
  const int def_hp;
  const int def_atk;
  const int def_def;
  int gold;
public:
  Player(int hp, int atk, int def);

  int getHP() override;
  int getAtk() override;
  int getDef() override;

  virtual void Strike(Enemy *e);
  virtual void beStruckBy(Enemy *e);

  virtual void takePotion(Potion *p);
  virtual void autoLoot();

  char whatType(Interactable *i) override;

  void resetStats(); //after a level is cleared, reset atk and def
protected:
  virtual ~Player() = 0;
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
