#include "decoratePC.h"
#include "player.h"

PCDecorator::PCDecorator(Player *pc) : pc{ pc }{}
PCDecorator::~PCDecorator() { delete pc; }
