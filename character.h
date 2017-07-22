#ifndef CHARACTER_H
#define CHARACTER_H

class Character: public Interactable {
protected:
  int hp;
  int atk;
  int def;  
  bool isDead;
public:
  virtual int getHP() = 0;
  virtual int getAtk() = 0;
  virtual int getDef() = 0;
  bool damaged();
  void isDead(bool dead);
};

#endif
