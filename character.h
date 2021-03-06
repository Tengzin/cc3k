#ifndef CHARACTER_H
#define CHARACTER_H

#include "interactable.h"

class Character: public Interactable {
protected:
  int hp;
  int atk;
  int def;
  bool isDead;
public:
	Character();
  Character(int hp, int atk, int def);
	virtual int getHP() { return hp; }
	virtual int getAtk() { return atk; }
	virtual int getDef() {
		return def;
	}
  void damaged(int dmg);
  void setDead(bool dead);
  bool checkDead();
};

#endif
