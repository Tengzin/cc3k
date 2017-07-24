#ifndef DRAGON_H
#define DRAGON_H

class Dragon: public Enemy {
public:
  Dragon();
  char whatType(Interactable *i) override;
};

#endif
