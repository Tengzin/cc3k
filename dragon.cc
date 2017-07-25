#include "dragon.h"

Dragon::Dragon():
Enemy{150, 20, 20} {}

char Dragon::whatType(Interactable *i) { return 'D'; };
