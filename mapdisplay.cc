#include "mapdisplay.h"
#include "tile.h"
#include "info.h"
using namespace std;

mapDisplay::mapDisplay() {
	ifstream layoutFile("layout.txt");
	string s;
	while (getline(layoutFile, s)) {
		istringstream iss{ s };
		char c;
		vector <char> row;
		while (iss >> noskipws >> c) {
			if (c == '\n') break;
			row.push_back(c);
		}
		display.push_back(row);
	}
}

ostream &operator<<(ostream &out, const mapDisplay &md) {
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 79; ++j) {
			out << md.display[i][j];
		}
		out << endl;
	}
	return out;
}

void mapDisplay::notify(Subject &whoNotified) {
	Info myInfo = whoNotified.getInfo();
	int r = myInfo.r;
	int c = myInfo.c;
	/*if (myInfo.I != nullptr) {
	//Get the character for the interactable and put it here.
	//for test
	display[r][j] = 'K'
	}*/
	if (myInfo.coin > 0) {
		display[r][c] = myInfo.coin;
	}
	else if (myInfo.passage) {
		display[r][c] = '#';
	}
	else if (myInfo.isStep && myInfo.isWall) {
		display[r][c] = '+';
	}
	else if (myInfo.isStep) {
		display[r][c] = '.';
	}
}

SubscriptionType mapDisplay::subType() const {
	return SubscriptionType::All;
}

mapDisplay::~mapDisplay() { }
