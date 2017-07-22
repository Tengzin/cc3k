#ifndef TROLL_H
#define TROLL_H

class Troll: public Player {
public:
  Troll(int hp, int atk, int def);  
  void regen() override; //troll specific
};

#endif
