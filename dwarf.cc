#include "dwarf.h"

Dwarf::Dwarf():
Character{100, 20, 30, 0}
Enemy{} {}

char Dwarf::whatType(Interactable *i) { return 'W'; }
