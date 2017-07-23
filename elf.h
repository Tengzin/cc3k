#ifndef ELF_H
#define ELF_H

class Elf: public Enemy {
public:
  Elf();
  bool isElf() override;
};

#endif
