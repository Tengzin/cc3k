#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//#include "interactable.h"
//#include "map.h"
#include "mapdisplay.h"
#include "maplayout.h"
#include "character.h"
#include "player.h"
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

using namespace std;

//Global variables
// if the player attacks 1 merchant, ALL future merchants become aggressive
bool merch_aggressive = 0;
//Potions
bool RH_checked = 0;
bool BA_checked = 0;
bool BD_checked = 0;
bool PH_checked = 0;
bool WA_checked = 0;
bool WD_checked = 0;
mapLayout l;
int level = 1;
bool enemyMove = true;      // if user types "r" it resets everything. I did continue (ie start over the while loop)
							// if might be easier to put these variable in the while so they get reset
bool gameFinished = false;

int main() {

	
	while (!gameFinished) {
		// constructing the PC
		cout << "Please choose your character, one of s, d, v, g, or t" << endl;
		string s;
		cin >> s;
		if (s == "q") break;
		else if (s == "s" || s == "d" || s == "v" || s == "g" || s == "t") {
			l.placeInteractables(s);
		}
		else continue;
		cout << l << "Player character has spawned." << endl; // prints board and action at bottom of board


															  // movement, combat, taking potions
		string dir;
		while (cin >> s && !gameFinished) {
			if (s == "q" || s == "r") break;
			else if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "ne" || s == "nw" || s == "se" || s == "sw") l.move(s);
			else if (s == "f") enemyMove = !enemyMove;
			else if (s == "u") {
				cin >> dir;
				l.take(dir);
				if (dir == "q" || dir == "r") break;
				// take potion in dir direction
			}
			else if (s == "a") {
				cin >> dir;
				// l.attack(dir);
				if (dir == "q" || dir == "r") break;

				// attack enemy in dir direction
			}
			cout << l;
		}

		if (s == "q" || dir == "q") break;
		if (s == "r" || dir == "r") continue;
	}
}
