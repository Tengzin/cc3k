#include "elf.h"

Elf::Elf():
Enemy{140, 30, 10} {}

bool Elf::isElf() { return true; }

char Elf::whatType(Interactable *i) { return 'E'; }
