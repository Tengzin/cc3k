#include "elf.h"

Elf::Elf():
Character{140, 30, 10, 0}
Enemy{} {}

bool Elf::isElf() { return true; }

char Elf::whatType(Interactable *i) { return 'E'; }
