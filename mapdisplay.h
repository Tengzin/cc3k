#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "observer.h"
using namespace std;

class mapDisplay : public Observer {
  vector<vector<char>> display;
  public:
  mapDisplay();
  void notify(Subject &whoNotified);
  SubscriptionType subType () const override;
  ~mapDisplay();
  friend std::ostream &operator<<(std::ostream &out, const mapDisplay &md);
};

#endif
