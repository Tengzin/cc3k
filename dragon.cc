#include "dragon.h"

Dragon::Dragon():
Character{150, 20, 20, 0}
Enemy{} {}

char Dragon::whatType(Interactable *i) { return 'D'; };
