#include "tile.h"


void Tile::setCoords(int row, int col) {
  this->r = row;
  this->c = col;
}


Info Tile::getInfo() const {
  Info i;
  i.r = this->r;
  i.c = this->c;
  i.stairs = this->stairs;
  i.passage = this->passage;
  i.coin = this->coin;
  // Interactable *inter ???
}
