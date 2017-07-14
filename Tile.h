#ifndef TILE_H
#define TILE_H


class Tile {  /// public inheritance? Struct? KSHITIJJJJJJJ
  bool stairs;
  bool passage;
  bool coin;
  int coin;
  Interactable *inter = nullptr;

  int r;  //row
  int c;  //column
  public:
  //do we need an Info class to get all the info from a given tile?
  //or do we just do a bunch of 'getInfo' functions?
  Info getInfo() override;
};


#endif
