#ifndef TILE_H
#define TILE_H
#include "subject.h"
#include "observer.h"

class Tile : public Subject, public Observer {  //+this inherits from Subject
	int r;
	int c;
	bool passage;
	bool isWall;
	bool isStep;
	int coin = 0;
	//  Interactable *inter = nullptr;

public:
	Info getInfo() const override;
	void change(Info target);
	Tile(bool passage, bool isWall, bool isStep, int r, int c);
	void notify(Subject &whoNotified) override;
	SubscriptionType subType() const override; //Virtual? //If interactable return that else return something else;
	~Tile();

};


#endif
