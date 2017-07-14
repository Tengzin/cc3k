#ifndef POTION_H
#define POTION_H

// Potions: Should Use Decorator Pattern
class Potion: public Interactable {
public:
  virtual void checkEffect() = 0;
  virtual void takePotion() = 0;

  void notify(Player *character);
};


/*

class RHPot: public Potion {
  const int heal; //default is 10, but maybe have diff values for bonus?
public:
  RHPot(const int heal);
  const void checkEffect() override;
  void takePotion() override;
};

class BAPot: public Potion {
  const int atk_boost;
public:
  BAPot(const int atk_boost);


};
*/


#endif
