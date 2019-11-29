#include <iostream>
#include <cstring>
#include <vector>

#ifndef ITEM_H //header
#define ITEM_H

using namespace std;

class Items {
	public: //initialize constructor, getter, and destructor
		Items(char* newDesc);
		char* getDesc();
		~Items();
	private: //initialize item descriptions in memory
		char* desc;
};

#endif