#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf: public Enemy {
public:
  Dwarf();
  char whatType(Interactable *i) override;
  bool isDwarf() override;

};

#endif
