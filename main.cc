#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//#include "interactable.h"
#include "map.h"
#include "mapdisplay.h"
#include "maplayout.h"
using namespace std;

//Global variables
// if the player attacks 1 merchant, ALL future merchants become aggressive
bool merch_aggressive = 0;
int level = 1;
bool enemyMove = true;      // if user types "r" it resets everything. I did continue (ie start over the while loop)
                            // if might be easier to put these variable in the while so they get reset


int main() {

  bool gameFinished = false;
  while (!gameFinished) {

    // constructing the PC
    cout << "Please choose your character, one of s, d, v, g, or t" << endl;
    string s;
    cin >> s;
    if (s == "q") break;
    else if (s == "s" || s == "d" || s == "v" || s == "g" || s == "t") {
      // call character constructor or something
    }
    else continue;

    // constructing the mapLayout and mapDisplay
    mapLayout l;
    l.init();
    // have to add all the enemies, potions, stairs, coins, and PC here
    cout << l << "Player character has spawned." << endl; // prints board and action at bottom of board


    // movement, combat, taking potions
    string dir;
    while(cin >> s) {
      if (s == "q" || s == "r") break;
      else if (s == "no" || s == "so" || s == "ea" || s == "we" || s == "ne" || s == "nw" || s == "se" || s == "sw") l.move(s);
      else if (s == "f") enemyMove = !enemyMove;
      else if (s == u) {
        cin >> dir;
        if (dir == "q" || dir == "r") break;
        // take potion in dir direction
      }
      else if (s == a) {
        cin >> dir;
        if (dir == "q" || dir == "r") break;
        // attack enemy in dir direction
      }
    }
    if (s == "q" || dir == "q") break;
    if (s == "r" || dir == "r") continue;
  }
}
