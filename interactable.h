#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "character.h"


class Interactable {
public:
  virtual bool movement();
  virtual char whatType(Interactable *i) = 0;
};


#endif
