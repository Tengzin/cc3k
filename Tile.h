#ifndef TILE_H
#define TILE_H


class Tile {  /// public inheritance? Struct? KSHITIJJJJJJJ
  bool stairs = false;
  bool passage = false;
//  bool coin = false; //necessary? if (tile.coin > 0) .... instead of if (tile.coin) ....
  int coin = 0;
  Interactable *inter = nullptr;    //enemy, PC, or potion
  int r;  //row
  int c;  //column

  public:
  void setCoords(int row, int col);
  Info getInfo() const override;

  //void notify   KSHITIJJJJJJ
};


#endif
