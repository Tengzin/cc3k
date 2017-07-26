#include "tile.h"
#include "interactable.h"
#include <iostream>
using namespace std;

Info Tile::getInfo() const {
	Info i;
	i.r = this->r;
	i.c = this->c;
	i.passage = this->passage;
	i.isWall = this->isWall;
	i.isStep = this->isStep;
	i.coin = this->coin;
	i.I = this->inter;
	return i;
}

void Tile::change(Info target) {
	this->isStep = target.isStep;
	this->passage = target.passage;
	this->inter = target.I;
	this->coin = target.coin;
	this->isWall = target.isWall;
	this->notifyObservers(SubscriptionType::All);
	this->notifyObservers(SubscriptionType::Interactable);
}

Tile::Tile(bool passage, bool isWall, bool isStep, int r, int c) :
	r(r), c(c), passage(passage), isWall(isWall), isStep(isStep) {}


void Tile::notify(Subject &whoNotified) {
	//char typeInter = inter->whatType(inter);
	//Info myInfo = whoNotified.getInfo();	


	
}

SubscriptionType Tile::subType() const {
	if (this->inter == nullptr) return SubscriptionType::None;	
	else return SubscriptionType::Interactable;
}

Tile::~Tile() {
	delete inter;
}
