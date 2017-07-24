#ifndef HUMAN_H
#define HUMAN_H

class Human: public Enemy {
public:
  Human();
  char whatType(Interactable *i) override;

};

#endif
