#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "observer.h"
using namespace std;
class Tile;

class mapDisplay : public Observer {
  vector<vector<char>> display;
  public:
  mapDisplay();
  void notify(Subject &whoNotified) override;
  SubscriptionType subType () const override;
  ~mapDisplay();
  friend std::ostream &operator<<(std::ostream &out, const mapDisplay &md);
};

#endif
