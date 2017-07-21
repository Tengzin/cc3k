#ifndef DROW_H
#define DROW_H

class Drow: public Player {
public:
  Drow(int hp, int atk, int def);
  void beStruckBy(Enemy *e) override;
};

#endif
