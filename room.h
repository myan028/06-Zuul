#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#ifndef ROOM_H
#define ROOM_H

#include "item.h"

using namespace std;

class Room {
	public: //initialize room constructor, methods, and destructor
		Room(char* newName, char* newDesc);
		char* getName();
		char* getDesc();
		void setExit(char* direction, Room* room);
		void addItem(Items* item);
		void removeItem(Items* item);
		void printInfo();
		Room* setRoom(char* direction);
		bool checkDirection(char* direction);
		vector<Items*> getItems();
		~Room();
	private: //initialize all room variables and vectors
		//initializes variables
		char* desc;
		char* name;
		vector<Items*> items;
		map<char*, Room*> exits;
};

#endif