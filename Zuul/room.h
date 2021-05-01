/*
Owen Brunty
room.h
4/25/21
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Room {
 public:
  Room(string*);
  string* getDescription();
  int getID();
  map<int, string*>* getExits();
  void setExits(map<int, string*>);
  void setID(int);
 private:
  string* description;
  int id;
  map<int, string*> exits;
};
