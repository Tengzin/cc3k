#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Interactable {
public:
  virtual bool movement();
  virtual char whatType(Interactable *i) = 0;
};
#endif
