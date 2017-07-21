#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public Player {
  int lifesteal;
public:
  Vampire(int hp, int atk, int def, int lifesteal);
  void regen() override;
  void heal() override;
};

#endif
