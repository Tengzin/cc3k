#include "enemy.h"

// Enemy Class Methods
Enemy::Enemy() {};
int getHP() { return hp; }
int getAtk() { return atk; }
int getDef() { return def; }

void Enemy::Strike(Player *pc) {
  pc->beStruckBy(this);
}

void Enemy::beStruckBy(Player *pc) {
  const int dmg = pc->getAtk();
  damaged(dmg);
  if (this->isDead() == true) pc->autoLoot();
}

void movement() { return true; }
