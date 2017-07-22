#include "maplayout.h"
#include "tile.h"
#include <sstream>
using namespace std;
//PC,stairway,potions,gold,enemies
int PC_r,PC_c;
int stair_r,stair_y;
std::vector<Tile> r1;
std::vector<Tile> r2;
std::vector<Tile> r3;
std::vector<Tile> r4;
std::vector<Tile> r5;
std::vector<vector<Tile> room;
// Room 1 :
// (4,4) (4,29)
// (7,4) (7,29)
// Room 2 : a
// (4,40) (4,62)
// (7,40) (7,63)
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

int RandomNumber(n){
	srand(time(0));
	int randNum;
	randNum = 1+(rand()%n);
	return randNum;
}


// void roords (int &room, int &x, int &y) {
// 	room = RandomNumber(7);
// 	Coords p = v[room-1];
// 	int width = p.rx-p.lx;
// 	int height = p.by-p.ty;
// 	x = x + RandomNumber(width);
// 	y = y + RandomNumber(height);
// }

mapLayout::init() {
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
				mytile.attach(md);
				row.push_back(mytile);
			}
      if (c=='|') {
				Tile mytile(false, true, false, width, height);
				mytile.attach(md);
				row.push_back(mytile);
			}
      if (c == '+') {
				Tile mytile(true, false, true, width, height);
				mytile.attach(md);
				row.push_back(mytile);
			}
      if (c == '.') {
				Tile mytile(false, false, true, width, height);
				mytile.attach(md);
				row.push_back(mytile);
			}
      if (c == '#') {
				Tile mytile(true, false, false, width, height);
				mytile.attach(md);
				row.push_back(mytile);
			}
      if (c == ' ') {
				Tile mytile(false, false, false, width, height);
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

ostream &operator<<(ostream &out, const mapLayout &md) {
  out << *(l.md);
  return out;
}

void mapLayout::placeInteractables() {
  //We first generate the PC
	int char_n = RandomNumber(5);
	int x = RandomNumber(room[char_n-1].size());
	Info charloc = room[char_n-1][x-1].getInfo();
	Info playerInfo = {0,0,,,}//Create struct for PC;
	layout[charLoc.r][charLoc.c].change(playerInfo);
	//DONE WITH PC
	//Now stairs
	int stair_n = RandomNumber(5);
	while (stair_n == char_n) {
		stair_n = RandomNumber(5);
	}
	x = RandomNumber(room[stair_n-1].size());
	Info stairLoc = room[stair_n][x-1].getinfo();
	stair_r = stairLoc.r;
	stair_c = stairLoc.c;
	//Done with Stairs (add stair location checker in move)
	//Now make the potions.
  for (int i = 0; i < potionLimit; ++i) {

	}
	for (int j = 0; j < goldLimit; ++j) {

	}
	for (int j = 0; j < EnemiesLimit; ++j) {

	}
}

void mapLayout::move(string s) {
	int x = 0;
	int y = 0;
	if (s == "no") --y;
	if (s == "so") ++y;
	if (s == "we") --x;
	if (s == "ea") ++x;
	if (s == "ne") {
		++x; --y;
	}
	if (s == "se") {
		++x; ++y;
	}
	if (s == "sw") {
		--x; ++y;
	}
	if (s == "nw") {
		--x; --y;
	}
		Info currTile = layout[PC_r][PC_c].getInfo();
		Info nextTile = layout[PC_r+x][PC_c+y].getInfo();
		if (nextTile.isStep) {
			layout[PC_r+x][PC_c+y].change(currTile);
			layout[PC_r][PC_c].change(nextTile);
			PC_r = PC_r+x;
			PC_c = PC_c+y;
		}
		// else throw ("DONT GO HERE, Are ye blind?")
	}
