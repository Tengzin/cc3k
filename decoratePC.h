#ifndef DECORATEPC_H
#define DECORATEPC_H

class PCDecorator: public Player {
protected: Player *character;
public:
  PCDecorator(Player *p);
  virtual ~PCDecorator();

  int getHP();
  int getAtk();
  int getDef();

};


#endif