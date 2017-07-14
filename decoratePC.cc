#include "decoratePC.h"
#include "player.h"

PCDecorator::PCDecorator(Player *character): character{character}{}
PCDecorator::~PCDecorator() { delete character; }

class RestoreHP: public PCDecorator {
  int heal;
public:
  RestoreHP(Player *pc, int heal);
  int getHP();
}
