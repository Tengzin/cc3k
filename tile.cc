#include "tile.h"

Info Tile::getInfo() const {
  Info i;
  i.r = this->r;
  i.c = this->c;
  i.passage = this->passage;
  i.isWall = this->isWall;
  i.isStep = this->isStep;
  i.coin = this->coin;
  i.I = this->inter;
}

void Tile::change(Info target) {
  this->isStep = target.isStep;
  this->inter = target.I;
  this.notifyObservers(SubscriptionType::All);
  this.notifyObservers(SubscriptionType::Interactable);
}

Tile::Tile(bool passage, bool isWall, bool isStepable, int r, int c) :
  passage(passage), isWall(isWall), isStepable(isStepable), r(r), c(c) {}

void Tile::notify(Subject &whoNotified) {
  Info myInfo = whoNotified.getinfo();
  this->inter.notify(myInfo.I);
}

SubscriptionType Tile::subType() {
  if (this->inter == nullptr) return SubscriptionType::None;
  else return SubscriptionType::Interactable;
}

Tile::~Tile() {
  delete this->inter;
}
