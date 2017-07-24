#include "maplayout.h"
#include "tile.h"
#include <sstream>
using namespace std;
//PC,stairway,potions,gold,enemies
int PC_r,PC_c,PC_gold;
int stair_r,stair_y;
std::vector<Tile> r1;
std::vector<Tile> r2;
std::vector<Tile> r3;
std::vector<Tile> r4;
std::vector<Tile> r5;
std::vector<vector<Tile>> room;
// Room 1 :
// (4,4) (4,29)
// (7,4) (7,29)
// Room 2 : a
// (4,40) (4,62)
// (7,40) (7,62)
// Room 2 : b //6
// (8,61) (8,77)
// (13,61) (13,77)
// Room 3 : a
// (17,66) (17,76)
// (19,66) (17,76)
// Room 3 : b //7
// (20,38) (20,76)
// (22,38) (22,76)
// Room 4
// (16,5) (16,25)
// (22,5) (22,25)
// Room 5
// (11,39) (11,50)
// (13,39) (13,50)

int RandomNumber(int n){
	srand(time(0));
	int randNum;
	randNum = 1+(rand()%n);
	return randNum;
}

mapLayout::mapLayout() {
	mapDisplay *md = new mapDisplay;
	this->md = md;
	ifstream layoutFile ("layout.txt");
	//just in case guards.
	string s;
	int height = 0;
	while(getline(layoutFile,s)) {
		istringstream iss{s};
		char c;
		int width = 0;
		vector <Tile> row;
		while (iss >> noskipws >>c) {
			if (c=='_') {
				Tile mytile(false, true, false, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c=='|') {
				Tile mytile(false, true, false, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '+') {
				Tile mytile(true, false, true, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '.') {
				Tile mytile(false, false, true, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '#') {
				Tile mytile(true, false, false, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == ' ') {
				Tile mytile(false, false, false, width, height);
				whichRoom(&mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
		}
		layout.push_back(row);
	}
	room.push_back(r1);
	room.push_back(r2);
	room.push_back(r3);
	room.push_back(r4);
	room.push_back(r5);
	for(int j = 0; j < 25; ++j) {
		for(int i = 0; i < 79; ++i) {
					// corners
			if (i - 1 >= 0 && j - 1 >= 0) {
				Tile *nt = layout[i-1][j-1];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79 && j - 1 >= 0) {
				Tile *nt = layout[i+1][j-1];
				layout[i][j].attach(nt);
			}
			if (i - 1 >= 0 && j + 1 < 25) {
				Tile *nt = layout[i-1][j+1];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79 && j + 1 < 25) {
				Tile *nt = layout[i+1][j+1];
				layout[i][j].attach(nt);
			}
					// corners
					// north, south, east, west
			if (j - 1 >= 0) {
				Tile *nt = layout[i][j-1];
				layout[i][j].attach(nt);
			}
			if (j + 1 < 25) {
				Tile *nt = layout[i][j+1];
				layout[i][j].attach(nt);
			}
			if (i - 1 >= 0) {
				Tile *nt = layout[i-1][j];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79) {
				Tile *nt = layout[i+1][j];
				layout[i][j].attach(nt);
			}
					// north, south, east, west
		}
	}
}

mapLayout::~mapLayout() {
	delete this->md;
	layout.clear();
}

void whichRoom(Subject &mytile) {
	Info myInfo = mytile.getInfo();
	int r = myInfo.r;
	int c = myInfo.c;
	if ( 4<= r && r <= 7) {
		if (4<= c && c<=29) {
			r1.push_back(mytile);
		}
		if (40<= c && c<=62) {
			r2.push_back(mytile);
		}
	}
	if ( 6<= r && r <= 7) {
		if (63<= c && c<=70) {
			r2.push_back(mytile);
		}
	}
	if (r==7) {
		if (72<=c && c <=73) {
			r2.push_back(mytile);
		}
	}
	if ( 8<= r && r <= 13) {
		if (62<= c && c<=76) {
			r2.push_back(mytile);
		}
	}
	//the box in themiddle is below
	if ( 11<= r && r <= 13) {
		if (39<= c && c<=50) {
			r3.push_back(mytile);
		}
	}
	//left and downward
	if ( 16<= r && r <= 22) {
		if (5<= c && c<=25) {
			r4.push_back(mytile);
		}
	}
	//right and downward
	if ( 17<= r && r <= 19) {
		if (66<= c && c<=76) {
			r5.push_back(mytile);
		}
	}
	if ( 20<= r && r <= 22) {
		if (38<= c && c<=76) {
			r5.push_back(mytile);
		}
	}
}

ostream &operator<<(ostream &out, const mapLayout &md) {
  out << *(l.md);
  return out;
}

void mapLayout::placeInteractables() {
  //We first generate the PC
	int char_n = RandomNumber(5);
	int x = RandomNumber(room[char_n-1].size());
	Info charloc = room[char_n-1][x-1].getInfo();
	Info playerInfo = {0,0,,,};//Create struct for PC;
	layout[charLoc.r][charLoc.c].change(playerInfo);
	//DONE WITH PC
	//Now stairs
	int stair_n = RandomNumber(5);
	while (stair_n == char_n) {
		stair_n = RandomNumber(5);
	}
	x = RandomNumber(room[stair_n-1].size());
	Info stairLoc = room[stair_n-1][x-1].getinfo();
	stair_r = stairLoc.r;
	stair_c = stairLoc.c;
	//Done with Stairs (add stair location checker in move)
	//Now make the potions.
  for (int i = 0; i < potionLimit; ++i) {				//POTIONS
		int chamb = RandomNumber(5);	//which chamber
		int loc;
		Info locInfo;
		while (true){
			loc = RandomNumber(room[chamb-1].size());		//where in the chamber
			locInfo = room[chamb-1][loc-1].getInfo();
			if (!(locInfo.r == stair_r && locInfo.c == stair_c) && !(locInfo.r == charLoc.r && locInfo.c == charLoc.c)) {
				break;
			}
		}
		int type = RandomNumber(6);		//which potion
		Info potloc = room[chamb-1][loc-1].getInfo();
		Info potInfo = {,,,};//construct the type-th potion
		layout[potloc.r][potloc.c].change(potInfo);
	}
	for (int j = 0; j < goldLimit; ++j) {					//GOLD
		int chamb = RandomNumber(5);	//which chamber
		int loc;
		Info locInfo;
		while (true){
			loc = RandomNumber(room[chamb-1].size());		//where in the chamber
			locInfo = room[chamb-1][loc-1].getInfo();
			if (!(locInfo.r == stair_r && locInfo.c == stair_c) && !(locInfo.r == charLoc.r && locInfo.c == charLoc.c)) {
				break;
			}
		}
		int gtype = RandomNumber(8);
		int gvalue;
		Info gold;
		if (gtype <= 7) {
			if (gtype <= 5) {
				gvalue = 2;		//normal
			}
			else {
				gvalue = 1;		//small
			}
			gold = {... gvalue ...};
		}
		else {
			gvalue = 6; 	//dragon
			//need to check if one of the tiles surrounding our tile is able to take a dragon
			//maybe while(true)
				//random number between 1 and 8
				//get that tile's info (need to check if it's a wall, already has PC or potion)
			//construct 2 dragons, one for the gold tile, and one for the tile next to gold
			gold = {... gvalue ... dragon1};
			Info dragon = {... ... dragon2};
			//layout[surroungind position][surrounding position].change(dragon);
		}
		layout[locInfo.r][locInfo.c].change(gold);
	}
	for (int j = 0; j < EnemiesLimit; ++j) {			//ENEMIES
		int chamb = RandomNumber(5);	//which chamber
		int loc;
		Info locInfo;
		while (true){
			loc = RandomNumber(room[chamb-1].size());		//where in the chamber
			locInfo = room[chamb-1][loc-1].getInfo();
			if (!(locInfo.r == stair_r && locInfo.c == stair_c) && !(locInfo.r == charLoc.r && locInfo.c == charLoc.c)) {
				if (locInfo.I == nullptr) {
					break;
				}
			}
		}
		etype = RandomNumber(18);
		Info enemy;
		if (etype <= 4) {					//human
			//make a human
			enemy = {...human...};
		}
		else if (etype <= 7) {		//dwarf
			//make a dwarf
			enemy = {...dwarf...};
		}
		else if (etype <= 12) {		//Halfling
			//make a halfling
			enemy = {...halfling...};
		}
		else if (etype <= 14) {		//Elf
			//make an elf
			enemy = {...elf...};
		}
		else if (etype <= 16) {		//Orc
			//make an orc
			enemy = {...orc...};
		}
		else {										//Merchant
			//make a merchant
			enemy = {...merchant...};
		}
		layout[chamb-1][loc-1].change(enemy);
	}
}

void mapLayout::move(string s) {
	int x = 0;
	int y = 0;
	if (s == "no") --r;
	if (s == "so") ++r;
	if (s == "we") --c;
	if (s == "ea") ++c;
	if (s == "ne") {
		++c; --r;
	}
	if (s == "se") {
		++c; ++r;
	}
	if (s == "sw") {
		--c; ++r;
	}
	if (s == "nw") {
		--c; --r;
	}
	Info currTile = layout[PC_r][PC_c].getInfo();
	Info nextTile = layout[PC_r+r][PC_c+c].getInfo();
	PC_gold += nextTile.coin;
	nextTile.coin = 0;
	if (nextTile.isStep) {
		layout[PC_r+r][PC_c+c].change(currTile);
		layout[PC_r][PC_c].change(nextTile);
		PC_r = PC_r+r;
		PC_c = PC_c+c;
	}
	// else throw ("DONT GO HERE, Are ye blind?")
}


void moveEnemies() {
	vector<Tile> enemies;
	for(int i = 0; i < 25; ++i) {
		for(int j = 0; j < 79; ++j) {
			Info currtile = layout[i][j].getInfo();
			if (curtile.I != nullptr) {
				if (curtile.I.movement()) enemies.push_back(layout[i][j]);
			}
		}
	}
	int vecSize = enemies.size();
	for(int i = 0; i < vecSize; ++i) {
		int move = RandomNumber(8);
		Info currTile = enemies[i].getInfo();
		int r = currTile.r;
		int c = currTile.c;
		if (move == 1) {
			--r; --c;
		}
		else if (move == 2) --r;
		else if (move ==3 ) {
			--r; ++c;
		}
		else if (move == 4) ++c;
		else if (move == 5) {
			++r; ++c;
		}
		else if (move == 6) ++r;
		else if (move == 7) {
			++r; --c;
		}
		else --c;
		Info nextTile = layout[r][c].getInfo();
		if (nextTile.isStep && !nextTile.isWall && !nextTile.passage) {
			layout[r][c].change(currTile);
			layout[currTile.r][currTile.c].change(nextTile);
		}
	}
}

void mapLayout::attack (string s) {
	int x = 0;
	int y = 0;
	if (s == "no") --r;
	if (s == "so") ++r;
	if (s == "we") --c;
	if (s == "ea") ++c;
	if (s == "ne") {
		++c; --r;
	}
	if (s == "se") {
		++c; ++r;
	}
	if (s == "sw") {
		--c; ++r;
	}
	if (s == "nw") {
		--c; --r;
	}
	Info enemyTile = layout[PC_r+r][PC_c+c].getInfo();
	Info playerTile = layout[PC_r][PC_r].getInfo();
	playerTile.I->strike(enemyTile.I);
}
