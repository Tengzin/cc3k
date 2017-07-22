#include "enemy.h"

// Enemy Class Methods
Enemy::Enemy(int hp, int atk, int def):
  Character{hp, atk, def, 0} {}

void Enemy::Strike(Player *pc) {
  pc->beStruckBy(this);
}

void Enemy::beStruckBy(Player *pc) {
  const int dmg = pc->getAtk();
  damaged(dmg);
  if (this->isDead() == true) pc->autoLoot();
}
