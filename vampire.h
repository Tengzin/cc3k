#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public Player {
  int lifesteal;
public:
  Vampire();
  void heal(int hp_gain) override;
  void Strike(Enemy *e) override;
};

#endif
