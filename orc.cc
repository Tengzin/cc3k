#include "orc.h"

Orc::Orc():
Character{180, 30, 25, 0}
Enemy{} {}

bool Orc::isOrc() { return true; }

char Orc::whatType(Interactable *i) { return 'O'; }
