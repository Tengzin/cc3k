#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
public:
  Enemy();
  int getHP() override;
  int getAtk() override;
  int getDef() override;

  virtual void Strike(Player *pc);
  virtual void beStruckBy(Player *pc);
  virtual void isOrc() { return false; }
  virtual void isElf() { return false; }

  virtual void movement() override;
};


#endif
