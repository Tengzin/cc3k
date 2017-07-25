#include "enemy.h"
#include "player.h"

// Enemy Class Methods
Enemy::Enemy(int hp, int atk, int def):
	Character{ hp, atk, def } {};

void Enemy::notify(Player *pc) {
  this->Strike(pc);
}

void Enemy::Strike(Player *pc) {
  pc->beStruckBy(this);
}

void Enemy::beStruckBy(Player *pc) {
  const int dmg = pc->getAtk();
  damaged(dmg);
  bool deadOrNot = this->checkDead();
  if (deadOrNot == true) pc->autoLoot();
}

bool Enemy::movement() { return true; }
