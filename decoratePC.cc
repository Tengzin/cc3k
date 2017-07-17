#include "decoratePC.h"
#include "player.h"

PCDecorator::PCDecorator(Player *character): character{character}{}
PCDecorator::~PCDecorator() { delete character; }
