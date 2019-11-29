#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iterator>
#include <map>

#include "room.h"
#include "item.h"

/*
Code by Michael Yan, 11/26/19
This is a simple text-based Zuul game which loosely models the popular FPS game CS:GO.
*/

using namespace std;

int main() {
	
	vector<Room*> Rooms; //primary vectors
	vector<Items*> inventory;

	Items* usps = new Items("usps"); //initializing items in items vector
	Items* bomb = new Items("bomb");
	Items* defuse = new Items("defuse");
	Items* m4a1s = new Items("m4a1s");
	Items* riot = new Items("riot");

	
	Room* currentRoom; //whichever room the user is currently in, all room attributes accessible there
	
	Room* A_site = new Room("A site", "at bomb site A. There doesn't seem to be anything here.");
	Room* CT_stairs = new Room("CT stairs", "at counter-terrorist spawn stairs.");
  
	Room* jungle = new Room("jungle", "at jungle.");
	Room* CT_spawn = new Room("CT Spawn", "at counter-terrorist spawn. This is where you start.");
	

	Room* window = new Room("window", "at window. You can snipe terrorists here.");
	Room* B_site = new Room("B site", "at bomb site B. The bomb has been planted here!");
	Room* apartments = new Room("apartments", "in the apartments.");
	Room* mid = new Room("mid", "at mid (middle).");
	Room* T_spawn = new Room("T spawn", "at T Spawn, the place where terrorists spawn");
	Room* palace = new Room("palace", "in the palace.");
	Room* bench = new Room("bench", "at the bench.");
	Room* kitchen = new Room("kitchen", "in the kitchen. It smells good.");
	Room* cat = new Room("cat", "at cat.");
	Room* hotbox = new Room("hotbox", "at hotbox.");
	Room* triplestack = new Room("triplestack", "at triplestack.");
	Room* danger = new Room("danger", "at danger boxes.");
	
	CT_stairs->addItem(riot); //placing items into rooms
	CT_spawn->addItem(usps);
	kitchen->addItem(m4a1s);
	T_spawn->addItem(defuse);
	B_site->addItem(bomb);

  
  
  

	//setting all possible exits for rooms
	A_site->setExit("north", palace);
	A_site->setExit("west", jungle);
	A_site->setExit("south", CT_stairs);
	CT_stairs->setExit("north", A_site);
	CT_stairs->setExit("west", CT_spawn);
	jungle->setExit("west", window);
	jungle->setExit("east", A_site);
	jungle->setExit("north", cat);
	window->setExit("west", B_site);
	window->setExit("east", jungle);
	window->setExit("north", mid);
	window->setExit("south", kitchen);
	B_site->setExit("north", apartments);
	B_site->setExit("south", bench);
	B_site->setExit("east", window);
	CT_spawn->setExit("east", CT_stairs);
	CT_spawn->setExit("west", kitchen);
	apartments->setExit("south", B_site);
	apartments->setExit("east", mid);
	mid->setExit("west", apartments);
	mid->setExit("east", cat);
	T_spawn->setExit("south", cat);
	palace->setExit("west", cat);
	palace->setExit("south", A_site);
	bench->setExit("north", B_site);
	bench->setExit("east", kitchen);
	//bench->setExit("east", danger);
	//kitchen->setExit("north", bench);
	//kitchen->setExit("west", T_spawn);
	kitchen->setExit("north", window);
	kitchen->setExit("east", CT_spawn);
	kitchen->setExit("west", bench);
	cat->setExit("north", T_spawn);
	cat->setExit("south", jungle);
	cat->setExit("east", palace);
	cat->setExit("west", mid);
	/*hotbox->setExit("north", cat);
	hotbox->setExit("west", CT_spawn);
	hotbox->setExit("south", triplestack);
	triplestack->setExit("north", hotbox);
	triplestack->setExit("south", danger);
	danger->setExit("north", triplestack);
	danger->setExit("west", bench);*/
	
	currentRoom = CT_spawn; //user starts at counter-terrorist spawn

	//Rooms.push_back();
	Rooms.push_back(A_site);
	Rooms.push_back(CT_stairs);
	Rooms.push_back(jungle);
	Rooms.push_back(window);
	Rooms.push_back(B_site);
	Rooms.push_back(CT_spawn);
	Rooms.push_back(apartments);
	Rooms.push_back(mid);
	Rooms.push_back(T_spawn);
	Rooms.push_back(palace);
	Rooms.push_back(cat);
	Rooms.push_back(bench);
	Rooms.push_back(kitchen);
	Rooms.push_back(cat);
	Rooms.push_back(hotbox);
	Rooms.push_back(triplestack);
	Rooms.push_back(danger);
  
	cout << "Welcome to CS:GO Zuul.\n" << "You are playing on the map MIRAGE.\n" << "You are a counter-terrorist.\n" << "\nTo win, you must use a defuse kit to defuse the bomb, wherever it is. " << "If you attempt to defuse the bomb without a defuse kit, you will be blown up." << endl;
	cout << "\nHere are a list of action commands: go, pick, drop, defuse, quit, help" << endl;

  
  
	while(true){
		vector<Items*>::iterator it;
		for(it = inventory.begin(); it != inventory.end(); it++) {
			if (strcmp((*it)->getDesc(), bomb->getDesc()) == 0) {
				cout << "YOU LOST! You picked up the bomb and it blew up in your face." << endl;
				return 0;
			}
			else if(strcmp((*it)->getDesc(), defuse->getDesc()) == 0 && currentRoom == B_site){
				cout << "YOU WON! You made it to B site and defused the bomb. Counter-Terrorists Win." << endl;
				return 0;
			}
		}

		cout << "\n\nYou are " << currentRoom->getDesc() << endl;
		currentRoom->printInfo();
		cout << endl;
		
		cout << "Your inventory: " << endl;
		for(it = inventory.begin(); it != inventory.end(); it++) {
		  cout<< (*it)->getDesc() << endl;
		}
		  
		  
		  
		  
		  
		char input[100];
		cout << "\nWhat would you like to do? Type 'help' for a list of actions. " << endl;
		cin.getline(input, 100);
		
		if(strcmp(input, "help") == 0){ //if user needs help
				cout << "\nNeed help? Here are a list of actions you can do:\n" << "Type 'go', 'get', 'drop', 'quit', or 'help'." << endl;
				cout << endl;
		}
		
		else if(strcmp(input, "go") == 0){
			cout<< "Input the direction where you want to go: (north, south, east, west)" << endl;
			cin.getline(input, 100);
			vector<Room*>::iterator iter;
			for(iter = Rooms.begin(); iter != Rooms.end(); iter++) {
				if (strcmp((*iter)->getName(), currentRoom->getName())==0) {
					if((*iter)->checkDirection(input)){
						currentRoom = (*iter)->setRoom(input);          
						break;
					}
				}
			}
		}
		
		
		else if(strcmp(input, "get") == 0){
			cout << "Type the name of the item you would like to pick up. " << endl;
			cin.getline(input, 100);
			vector<Items*>::iterator ite;
			for(ite = currentRoom->getItems().begin(); ite != currentRoom->getItems().end(); ++ite) {   
				if (strcmp((*ite)->getDesc(), input) == 0) {
					inventory.push_back(*ite);
					currentRoom->removeItem(*ite);
					break;
				}
			}
		}


		else if(strcmp(input, "drop") == 0){
		cout<< "Type the name of the item you would like to drop. It will be placed in the current room." << endl;
		cin.getline(input, 100);
		for(it = inventory.begin(); it != inventory.end(); it++) {
		  if (strcmp((*it)->getDesc(), input)==0) {
			currentRoom->addItem(*it); 
			it = inventory.erase(it);
			break;
		  }
		}
		}

		else if(strcmp(input, "quit") == 0){ //if user wants to quit
			return 0;
				
		}
		else{ //if action is not recognized
			cout << "That is not a valid action." << endl;
		}
    }
  }