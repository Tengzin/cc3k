#ifndef RECOVERHP_H
#define RECOVERHP_H
#include <algorithm>

class RestoreHP: public PCDecorator {
  int heal;
public:
  RestoreHP(Player *pc, int heal);
  int getHP() override;
};

#endif
