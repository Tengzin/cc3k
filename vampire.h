#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public Player {
  int lifesteal;
public:
  Vampire();
  void regen() override;
  void heal() override;
};

#endif
