#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc: public Enemy {
public:
  Orc();
  bool isOrc() override;
  char whatType(Interactable *i) override;
};

#endif
