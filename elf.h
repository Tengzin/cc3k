#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public Enemy {
public:
  Elf();
  bool isElf() override;
  char whatType(Interactable *i) override;

};

#endif
