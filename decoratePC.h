#ifndef DECORATEPC_H
#define DECORATEPC_H

#include "player.h"

class PCDecorator: public Player {
protected: Player *pc;
public:
  PCDecorator(Player *pc);
  virtual ~PCDecorator();
};


#endif
