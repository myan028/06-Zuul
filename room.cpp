#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iterator>
#include <map>

#include "room.h"
#include "item.h"

using namespace std;


Room::Room(char* newName, char* newDesc) { //constructor
  desc = newDesc;
  name = newName;
}

Room::~Room() { //destructor
	delete []desc;
	delete []name;
}


char* Room::getName(){ //getters
  return name;
}

char* Room::getDesc(){
  return desc;
}



void Room::addItem(Items* item){ //add item to end of vector
  items.push_back(item);
}

void Room::removeItem(Items* item){ //remove item from room
    for(vector<Items*>::iterator it = items.begin(); it!=items.end(); ++it){
        if(strcmp((*it)->getDesc(), item->getDesc()) == 0){  
            items.erase(it); 
            break;
        }
    }
}



void Room::setExit( char* direction, Room* room){ //create exits for rooms
  exits.insert(make_pair(direction, room));
}


void Room::printInfo(){ //print out all room info
	cout << "\nItems here: " << endl;
	vector<Items*>::iterator it;
	for(it = items.begin(); it != items.end(); it++){ //print items in the room
		cout << (*it)->getDesc() << endl;
	}
	cout << "\nExits:" << endl;
	map<char*, Room*>::iterator iter; exits.begin();
	for(iter = exits.begin(); iter != exits.end(); iter++){ //print exits and exit direction
		cout << (iter->second)->getName() << " is to the " << iter->first << endl;
	}
}

vector<Items*> Room::getItems(){ //return items
    return items;
}

Room* Room::setRoom(char* direction){ //move user to designated room
  map<char*, Room*>::iterator it; exits.begin();
  for(it = exits.begin(); it != exits.end(); it++){
    if (strcmp(it->first, direction) == 0) {
        return it->second;
    }
  }
}


bool Room::checkDirection(char* direction){ //check for valid direction
  map<char*, Room*>::iterator it; exits.begin();
  for(it = exits.begin(); it != exits.end(); it++){
	if(strcmp(it->first, direction) == 0) {
		return true;
	}
  }
  return false;
}


