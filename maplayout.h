#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H
#include "tile.h" //Defines the tile class, analogous to cell
#include "mapDisplay.h" //the current display the player can see.
#include "coord.h" //for storing coordinates.
//Make a coordinate coordinate structure.
class mapLayout {
  std::vector<tile> tileRow; //Stores the tiles
  Interactable *player; //pointer to the current player, not sure if we actually need it.
  std::vector<coord> assignedCoord //Stores the already assigned coordinates
  const int goldLimit = 10; //Check whether the number if correct or not.
  const int potionLimit = 10; //
  const int enemyLimit = 20; //to check whether we've created enough enemies;
  public:
  void init (); //initalise the tiles.
  void assignInteractables(); //Instead of having separate functions for enemy and potions and gold, this one single function.
  void move ();
}
