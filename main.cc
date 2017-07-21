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
//bool merch_agressive = 0;


int main() {
  //can't bool merch_agressive = 0; go here? I don't know if it matters too much

  // string s;
  // while(getline(cin, s)) {
  //   istringstream(iss);
  //   string word;
  //   while(iss >> word) {
  //
  //   }
  // }
  mapLayout l;
  l.init();
  cout << l;
}
