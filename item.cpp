#include <iostream>
#include <cstring>
#include <map>

#include "item.h" //include header

using namespace std;

Items::Items(char* newDesc){ //new item description (the id)
  desc = newDesc;
}

char* Items::getDesc(){ //return item ids
  return desc;
}

Items::~Items(){ //destructor for items
  delete[] desc;
}