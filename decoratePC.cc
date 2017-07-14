#include "decoratePC.h"
#include "player.h"

PCDecorator::PCDecorator(Player *character): character{character}{}
PCDecorator::~PCDecorator() { delete character; }

int PCDecorator::getHP() { return hp; }
int PCDecorator::getAtk() { return atk; }
int PCDecorator::getDef() { return def; }

class RestoreHP: public PCDecorator {
  int heal;
public:
  RestoreHP(Player *pc, int heal);
  int getHP();
}
