#include "goblin.h"
#include <ctime>
#include <cstdlib>
#include <string>

using std::string;

int RandomNumber(int n) {
	srand(time(0));
	int randNum;
	randNum = 1 + (rand() % n);
	return randNum;
}

Goblin::Goblin():
Player{110, 15, 20} {}

void Goblin::beStruckBy(Enemy *e) {
  const int dmg = e->getAtk();
  float multi = 1;

  if (e->isElf() == true) {
    const int miss_two = RandomNumber(2);
    if (miss_two == 1) { damaged(dmg); }
  }

  else if (e->isOrc() == true) multi = 1.5;
  const int miss = RandomNumber(2);
  if (miss == 1) { damaged(dmg * multi); }
}

void Goblin::autoLoot() {
  gold += 5; // additional gold from killing
  const int loot = RandomNumber(2);
  gold += loot;
}
