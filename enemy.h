#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
public:
  Enemy(int hp, int atk, int def);
  int getHP() override;
  int getAtk() override;
  int getDef() override;

  virtual void Strike(Player *pc);
  virtual void beStruckBy(Player *pc);

  virtual void movement() override;
};


#endif
