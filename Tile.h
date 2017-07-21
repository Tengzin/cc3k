#ifndef TILE_H
#define TILE_H
#include "subject.h"
#include "observer.h"

class Tile {  //+this inherits from Subject
  int r;
  int c;
  bool passage;
  bool isWall;
  bool isStep;
  int coin = 0;
  Interactable *inter = nullptr;

  public:
  Info getInfo() const override;
  void change(Info target);
  Tile(bool passage, bool isWall, bool isStepable, int r, int c);
};


#endif
