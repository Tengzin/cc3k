#ifndef MERCHANT_H
#define MERCHANT_H

class Merchant: public Enemy {
public:
  Merchant();
  void Strike(Player *pc) override;
  void beStruckBy(Player *pc) override;
};

#endif
