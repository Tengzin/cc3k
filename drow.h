#ifndef DROW_H
#define DROW_H

class Drow: public Player {
public:
  Drow();
  void beStruckBy(Enemy *e) override;
};

#endif
