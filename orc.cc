#include "orc.h"

Orc::Orc():
	Enemy{ 180, 30, 25 } {}

bool Orc::isOrc() { return true; }

char Orc::whatType(Interactable *i) { return 'O'; }
