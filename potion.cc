#include "potion.h"
#include "player.h"
#include <ctime>
#include <cstdlib>
#include <string>

using std::string;

// Player Class Methods

int RandomNumber(int n) {
	srand(time(0));
	int randNum;
	randNum = 1 + (rand() % n);
	return randNum;
}

#include <iostream>
using namespace std;

extern bool RH_checked;
extern bool BA_checked;
extern bool BD_checked;
extern bool PH_checked;
extern bool WA_checked;
extern bool WD_checked;

char Potion::whatType(Interactable *i) { return 'P'; }

void Potion::notify(Player *pc) {
  const int pot = RandomNumber(6);
  if (pot == 1) {
    pot_type = "RH";
    if (RH_checked == true) {
    cout << "There is a Healing potion here! It will heal up to 10 HP." << endl;
    }
  }
  else if (pot == 2) {
    pot_type = "BA";
    if (BA_checked == true) {
    	cout << "There is a Boost ATK potion here! It will grant 5 ATK." << endl;
		}
  }
  else if (pot == 3) {
    pot_type = "BD";
    if (BD_checked == true) {
    cout << "There is a Boost DEF potion here! It will grant 5 DEF." << endl;
    }
  }
  else if (pot == 4) {
    pot_type = "PH";
    if (PH_checked == true) {
    cout << "There is a Poison potion here! It will do 10 damage." << endl;
    }
  }
  else if (pot == 5)
  {
    pot_type = "WA";
    if (WA_checked == true) {
    cout << "There is a Wound ATK potion here! Lose 5 ATK." << endl;
    }
  }
  else {
	  pot_type = "WD";
	  if (WD_checked == true) {
		  cout << "There is a Wound DEF potion here! Lose 5 DEF." << endl;
	  }
  }
}

string Potion::getPotType() {
	return pot_type;
}
