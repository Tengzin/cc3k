#ifndef TROLL_H
#define TROLL_H

class Troll: public Player {
public:
  Troll();
  void regen() override; //troll specific
};

#endif
