/*
Owen Brunty
room.cpp
4/25/21
*/

#include <iostream>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

Room::Room(string* newDescription) {
  description = newDescription;
}

string* Room::getDescription() {
  return description;
}

void Room::setID(int newID) {
  id = newID;
}

int Room::getID() {
  return id;
}

void Room:: setExits(map<int, string*> newExits) {
  exits = newExits;
}

map<int, string*>* Room:: getExits() {
  return &exits;
}

