#ifndef HALFLING_H
#define HALFLING_H

class Halfling: public Enemy {
public:
  Halfing();  
  void beStruckBy(Player *pc) override;
};

#endif
