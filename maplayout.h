#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H
#include "tile.h" //Defines the tile class, analogous to cell
#include "mapdisplay.h" //the current display the player can see.
//#include "coord.h" //for storing coordinates.
//Make a coordinate coordinate structure.
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>


class mapLayout {
  std::vector<std::vector<Tile>> layout; //Stores the tiles
  mapDisplay *md;
  //Interactable *player; //pointer to the current player, not sure if we actually need it.
  //int PC_row,PC,col;
  //const int goldLimit = 10; //Check whether the number if correct or not.
  //const int potionLimit = 6; //
  //const int enemyLimit = 20; //to check whether we've created enough enemies;
  //declare the coordinate structure here
  public:
  mapLayout();
  ~mapLayout();
  void placeInteractables();
  void move (string s);
  void moveEnemies();
  friend std::ostream &operator<<(std::ostream &out, const mapDisplay &md);
};

#endif
