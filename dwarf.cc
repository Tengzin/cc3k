#include "dwarf.h"

Dwarf::Dwarf():
Enemy{100, 20, 30} {}

char Dwarf::whatType(Interactable *i) { return 'W'; }
bool Dwarf::isDwarf() { return true; }
