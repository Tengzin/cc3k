#ifndef SHADE_H
#define SHADE_H

class Shade: public Player {
public:
  Shade(int hp, int atk, int def);
  void Strike(Enemy *e) override;
  void beStruckBy(Enemy *e) override;
};

#endif
