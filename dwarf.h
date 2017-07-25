#ifndef DWARF_H
#define DWARF_H

class Dwarf: public Enemy {
public:
  Dwarf();
  char whatType(Interactable *i) override;
  bool isDwarf() override;

};

#endif
