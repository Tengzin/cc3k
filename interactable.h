#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Potion;
class Player;

class Interactable {
public:
  virtual bool movement();
  virtual char whatType(Interactable *i) = 0;
  virtual void takePotion(Potion *p, Player *pc) = 0;
  virtual void notify(Player *pc) {}
  virtual ~Interactable() {}
};
#endif
