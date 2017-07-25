#include "maplayout.h"
#include "tile.h"
#include "potion.h"
#include "dragon.h"
#include "drow.h"
#include "elf.h"
#include "dwarf.h"
#include "goblin.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orc.h"
#include "shade.h"
#include "troll.h"
#include "vampire.h"
#include "potion.h"

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

int RandomNumber(int n){
	srand(time(0));
	int randNum;
	randNum = 1+(rand()%n);
	return randNum;
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

mapLayout::mapLayout() {
	mapDisplay *md = new mapDisplay;
	this->md = md;
	ifstream layoutFile ("layout.txt");
	//just in case guards.
	string s;
	//int height = 0;
	while(getline(layoutFile,s)) {
		istringstream iss{s};
		char c;
		//int width = 0;
		vector <Tile> row;
		while (iss >> noskipws >>c) {
			if (c=='-') {
				Tile mytile(false, true, false, layout.size(), row.size());
				whichRoom(mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c=='|') {
				Tile mytile(false, true, false, layout.size(), row.size());
				whichRoom(mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '+') {
				Tile mytile(true, false, true, layout.size(), row.size());
				whichRoom(mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '.') {
				Tile mytile(false, false, true, layout.size(), row.size());
				whichRoom(mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == '#') {
				Tile mytile(true, false, false, layout.size(), row.size());
				whichRoom(mytile);
				mytile.attach(md);
				row.push_back(mytile);
			}
			if (c == ' ') {
				Tile mytile(false, false, false, layout.size(), row.size());
				whichRoom(mytile);
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
	for(int i = 0; i < 25; ++i) {
		for(int j = 0; j < 79; ++j) {
					// corners
			if (i - 1 >= 0 && j - 1 >= 0) {
				Tile *nt = &layout[i-1][j-1];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79 && j - 1 >= 0) {
				Tile *nt = &layout[i+1][j-1];
				layout[i][j].attach(nt);
			}
			if (i - 1 >= 0 && j + 1 < 25) {
				Tile *nt = &layout[i-1][j+1];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79 && j + 1 < 25) {
				Tile *nt = &layout[i+1][j+1];
				layout[i][j].attach(nt);
			}
					// corners
					// north, south, east, west
			if (j - 1 >= 0) {
				Tile *nt = &layout[i][j-1];
				layout[i][j].attach(nt);
			}
			if (j + 1 < 25) {
				Tile *nt = &layout[i][j+1];
				layout[i][j].attach(nt);
			}
			if (i - 1 >= 0) {
				Tile *nt = &layout[i-1][j];
				layout[i][j].attach(nt);
			}
			if (i + 1 < 79) {
				Tile *nt = &layout[i+1][j];
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



ostream &operator<<(ostream &out, const mapLayout &l) {
  out << *(l.md);
  return out;
}


void mapLayout::placeInteractables(string charType) {
  //We first generate the PC
	int char_n = RandomNumber(5);
	int x = RandomNumber(room[char_n-1].size());
	Info charloc = room[char_n-1][x-1].getInfo();
	PC_r = charloc.r;
	PC_c = charloc.c;
	//make the character
	Interactable *inter;
	if (charType == "s") {
		Shade *s = new Shade();
		inter = s;
	}
	else if (charType == "d") {
		Drow *d = new Drow();
		inter = d;
	}
	else if (charType == "v") {
		Vampire *v = new Vampire();
		inter = v;
	}
	else if (charType == "g") {
		Goblin *g = new Goblin();
		inter = g;
	}
	else {
		Troll *t = new Troll();
		inter = t;
	}
	Info playerInfo = {0,0,false,false,false,0,inter};//Create struct for PC;
	layout[charLoc.r][charLoc.c].change(playerInfo);
	//DONE WITH PC
	//Now stairs
	int stair_n = RandomNumber(5);
	while (stair_n == char_n) {
		stair_n = RandomNumber(5);
	}
	x = RandomNumber(room[stair_n-1].size());
	Info stairLoc = room[stair_n-1][x-1].getInfo();
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
			if (!(locInfo.r == stair_r && locInfo.c == stair_c) && locInfo.I == nullptr) {
				break;
			}
		}
		Potion *pot = new Potion();
		Interactable *inter2 = pot;
		Info potloc = room[chamb-1][loc-1].getInfo();
		Info potInfo = {0,0,false,false,false,0,inter2};
		layout[potloc.r][potloc.c].change(potInfo);
	}
	for (int j = 0; j < goldLimit; ++j) {					//GOLD
		int chamb = RandomNumber(5);	//which chamber
		int gtype = RandomNumber(8);
		Info locInfo;
		Info gold;
		int gvalue;
		if (gtype <= 7) {
			while (true){
				int loc = RandomNumber(room[chamb-1].size());		//where in the chamber
				locInfo = room[chamb-1][loc-1].getInfo();
				if (!(locInfo.r == stair_r && locInfo.c == stair_c) && locInfo.I == nullptr) {
					break;
				}
			}
			if (gtype <= 5) {
				gvalue = 2;		//normal
			}
			else {
				gvalue = 1;		//small
			}
			gold = {0,0,false,false,false,false,0,nullptr};
			layout[locInfo.r][locInfo.c].change(gold);
		}
		else {
			Info dragInfo;
			while (true){
				loc = RandomNumber(room[chamb-1].size());		//where in the chamber
				locInfo = room[chamb-1][loc-1].getInfo();
				if (!(locInfo.r == stair_r && locInfo.c == stair_c) && locInfo.I == nullptr) {
					int drag = RandomNumber(8);
					int r = locInfo.r;
					int c = locInfo.c;
					if (drag == 1) {
						--r; --c;
					}
					else if (drag == 2) --r;
					else if (drag ==3 ) {
						--r; ++c;
					}
					else if (drag == 4) ++c;
					else if (drag == 5) {
						++r; ++c;
					}
					else if (drag == 6) ++r;
					else if (drag == 7) {
						++r; --c;
					}
					else --c;
					dragInfo = layout[locInfo.r+r][locInfo.c+c].getInfo();
					if (dragInfo.I == nullptr) {
						break;
					}
				}
			}
			gvalue = 6; 	//dragon
			Dragon *dr = new Dragon();
			Interactable *inter3 = dr;
			gold = {0,0,false,false,false,false,6,inter3};
			dragInfo.coin = 6;
			dragInfo.I = inter3;
			layout[dragInfo.r][dragInfo.c].change(dragInfo);
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
			if (!(locInfo.r == stair_r && locInfo.c == stair_c) && locInfo.I == nullptr) {
				break;
			}
		}
		etype = RandomNumber(18);
		Info enemy;
		if (etype <= 4) {					//human
			Human *h = new Human();
			Interactable *inter = h;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		else if (etype <= 7) {		//dwarf
			Dwarf *d = new Dwarf();
			Interactable *inter = d;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		else if (etype <= 12) {		//Halfling
			Halfling *ha = new Halfling();
			Interactable *inter = ha;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		else if (etype <= 14) {		//Elf
			Elf *e = new Elf();
			Interactable *inter = e;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		else if (etype <= 16) {		//Orc
			Orc *o = new Orc();
			Interactable *inter = o;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		else {										//Merchant
			Merchant *m = new Merchant();
			Interactable *inter = m;
			enemy = {0,0,false,false,false,locInfo.coin,inter};
		}
		layout[chamb-1][loc-1].change(enemy);
	}
}


void mapLayout::move(string s) {
	int r = 0;
	int c = 0;
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
	playerTile.I->Strike(enemyTile.I);
}

void mapLayout::take (string s) {
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
        Info potionTile = layout[PC_r+r][PC_c+c].getInfo();
        Info playerTile = layout[PC_r][PC_c].getInfo();
        playerTile.I->takePotion(potionTile.I, playerTile.I); //add what happens if a null ptr is passed to these functions.
}
