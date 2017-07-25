#include "human.h"

Human::Human():
Enemy{110, 15, 20} {}

char Human::whatType(Interactable *i) { return 'H'; }
