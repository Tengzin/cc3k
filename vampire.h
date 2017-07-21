#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public Player {
  int lifesteal;
public:
  Vampire(int hp, int atk, int def, int lifesteal);
  void Strike(Enemy *e) override;
  void beStruckBy(Enemy *e) override;
  void regen() override;
  void heal() override;

};

#endif
