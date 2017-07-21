#ifndef INFO_H
#define INFO_H

struct Info {
  int r, c;
  bool passage;
  bool isWall;
  bool isStep;
  int coin;
  Interactable *I;
};


#endif
