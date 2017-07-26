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
	std::vector<Tile> r1;
	std::vector<Tile> r2;
	std::vector<Tile> r3;
	std::vector<Tile> r4;
	std::vector<Tile> r5;
	std::vector<vector<Tile>> room;

	std::vector<std::vector<Tile>> layout; //Stores the tiles
	mapDisplay *md;
	//Interactable *player; //pointer to the current player, not sure if we actually need it.
	//int PC_row,PC,col;
	const int goldLimit = 10; //Check whether the number if correct or not.
	const int potionLimit = 10; //
	const int enemyLimit = 20; //to check whether we've created enough enemies;
	//declare the coordinate structure here
public:
	void whichRoom(Tile mytile);
	mapLayout();
	~mapLayout();
	  void placeInteractables(string charType);
	void move(string s);
	//  void moveEnemies();
	//  void attack(string s);
	void take (string s);
	friend  std::ostream &operator<<(std::ostream &out, const mapLayout &l);
};
//friend std::ostream &operator<<(std::ostream &out, const mapDisplay &md);

#endif
