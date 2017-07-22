#include "maplayout.h"
#include "tile.h"
#include <sstream>
using namespace std;

int PC_r,PC_c;

int RandomNumber(n){
	srand(time(0));
	int randNum;
	randNum = 1+(rand()%n);
	return randNum;
}

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

// mapLayout::placeInteractables() {
//   //We first have to generate the stairs
//   //First we select a room for the stairs
//   //Generating a player character
//   int n = RandomNumber(1) //Selecting a room.
//   switch (n) {
//     case 1:
//     int w = r1.rx-r1.lx;
//     int h = r1.ty-r1.by;
//     int c1 = RandomNumber(w);
//     int c2 = RandomNumber(h);
//     int x = r1.lx + c1;
//     int y = r1.ty + c2;
//
//   }
// }

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
