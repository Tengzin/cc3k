#include "enemy.h"

// Enemy Class Methods
Enemy::Enemy(int hp, int atk, int def, int gold_drop, bool aggressive, bool allergy,
  int num_atks, double atk_multiplier, double player_miss_chance):
  Character{hp, atk, def},
  gold_drop{gold_drop}, aggressive{aggressive}, allergy{allergy},
  num_atks{num_atks}, atk_multiplier{atk_multiplier},
  player_miss_chance{player_miss_chance} {}
