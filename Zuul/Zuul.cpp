/*
Owen Brunty
Zuul
4/25/21
*/

#include <iostream>
#include<map>
#include "room.h"
#include <vector>

using namespace std;

vector<Room*> roomvect;

struct items {
  string* name;
  int id;
  int roomid;
};

void printRooms(vector<Room*>);


//This function makes the rooms
void createRooms(vector<Room*> roomvect) {
  map<int, string*> schoolmap;
  string* north = (string*)("north");
  string* east = (string*)("east");
  string* south = (string*)("south");
  string* west = (string*)("west");

//The following are all of the rooms with their descriptions, ids, and exits
  //I-20
  Room* i20 = new Room (new string("You are currently in the 1-20 lab at Sunset. All the cool people are hanging out here."));
  roomvect.push_back(i20);
  i20 -> setID(1);
  schoolmap.insert(pair<int,string*> (2, west));

  //1 hall
  Room* onehall = (new Room(new string("Now you're in 1 Hall, one of the central hallways in Sunset."));
  roomvect.push_back(onehall);
  onehall -> setID(2);
  schoolmap.insert(pair<int,string*> (1, east));
  schoolmap.insert(pair<int,string*> (3, south));
  schoolmap.insert(pair<int,string*> (4, north));
		   
  //Library
  Room* library = (new Room(new string("You just entered the library, there's a scowling lady protecting a vast collection of books"));
  roomvect.push_back(library);
  library -> setID(3);
  schoolmap.insert(pair<int,string*> (2, north));
		   
  //Cafeteria
  Room* cafeteria = (new Room(new string("You enter the cafeteria. A sandwich stand catches your eye."));
  roomvect.push_back(cafeteria);
  cafeteria -> setID(4);
  schoolmap.insert(pair<int,string*> (2, south));
  schoolmap.insert(pair<int,string*> (5, west));
  schoolmap.insert(pair<int,string*> (14, east));
  schoolmap.insert(pair<int,string*> (9, north));
		     
  //2 hall
  Room* twohall = (new Room(new string("Now you're in 2 Hall, one of the biggest hallways of the building."));
  roomvect.push_back(twohall);
  twohall -> setID(5);
  schoolmap.insert(pair<int,string*> (4, east));
  schoolmap.insert(pair<int,string*> (7, west));
  schoolmap.insert(pair<int,string*> (6, south));
  schoolmap.insert(pair<int,string*> (8, north));		   

  //Janitorial closet
  Room* janitorcloset = (new Room(new string("You walk into the cramped janitorial closet and are surprised to see a man sitting, looking somwhat sad. He looks at you with a glimmer of hope and asks, 'YOU, have you seen a mop anywhere?'"));
  roomvect.push_back(janitorcloset);
  janitorcloset -> setID(6);
  schoolmap.insert(pair<int,string*> (5, north));
			 
  //Math class
  Room* mathclass = (new Room(new string("You enter a math class and are greeted by many student's lifless eyes turing your way. You get the urge to immdiately leave."));
  roomvect.push_back(mathclass);
  mathclass -> setID(7);
  schoolmap.insert(pair<int,string*> (5, east));
		     		     
  //Science class
  Room* scienceclass = (new Room(new string("After walking into a science classroom you're shocked when you see a woman and think 'I-Is that Ms. Frizzle??'"));
  roomvect.push_back(scienceclass);
  scienceclass -> setID(8);
  schoolmap.insert(pair<int,string*> (5, south));
			
  //Auditorium
  Room* auditorium = (new Room(new string("You walk into a big empty auditorium."));
  roomvect.push_back(auditorium);
  auditorium -> setID(9);
  schoolmap.insert(pair<int,string*> (10, north));
  schoolmap.insert(pair<int,string*> (4, south));
      		      
  //3 hall
  Room* threehall = (new Room(new string("You walk out into 3 hall, no one's in the usualy busy hallway."));
  roomvect.push_back(threehall);
  threehall -> setID(10);
  schoolmap.insert(pair<int,string*> (9, south));
  schoolmap.insert(pair<int,string*> (11, west));
  schoolmap.insert(pair<int,string*> (13, east));
  schoolmap.insert(pair<int,string*> (12, north));
		     
  //Bathroom
  Room* bathroom = (new Room(new string("You enter the bathroom and wonder why it looks like the floor hasn't been mopped recently."
  roomvect.push_back(bathroom);
  bathroom -> setID(11);
  schoolmap.insert(pair<int,string*> (10, east));
					
  //Lit and comp class
  Room* litclass = (new Room(new string("You sneak into a lit and comp class while a student gives a presentation, all eyes are on him. You notice a beautiful Montblanc Patron of art Hadrian limited edition 4810 M Fountain Pen valued at $2,524 sitting on a desk all alone. You shouldn't... but you cant help thinking about it."));
  roomvect.push_back(litclass);
  litclass -> setID(12);
  schoolmap.insert(pair<int,string*> (10, south));
		    
  //Gym
  Room* gym = (new Room(new string("You open a big door and set foot into the gym, all you can hear is the clanking of moving weights and the grunting of those who are moving them."));
  roomvect.push_back(gym);
  gym -> setID(13);
  schoolmap.insert(pair<int,string*> (10, west));

  //Main hall
  Room* mainhall = (new Room(new string("You step out into the main hall of Sunset."));
  roomvect.push_back(mainhall);
  mainhall -> setID(14);
  schoolmap.insert(pair<int,string*> (4, east));
  schoolmap.insert(pair<int,string*> (15, north));
  schoolmap.insert(pair<int,string*> (16, west));
		    
  //Main office
  Room* mainoffice = new Room(new string("You enter the main office. You spot the principal and become nervous although you have nothing to hide."));
  roomvect.push_back(mainoffice);
  mainoffice -> setID(15);
  schoolmap.insert(pair<int,string*> (14, south));
		    		    
  //Exit
  Room* exit = (new Room(new string("You step out of the main doors to Sunset and feel the warm touch of sunlight and a cool breeze. Finally, freedom."));
  roomvect.push_back(exit);
  exit -> setID(16);
  schoolmap.insert(pair<int,string*> (14, west));
}

void createItems(vector<Item*> itemvect) {
    string* mop = (string*)("mop");
    string* book = (string*)("book");
    string* lint = (string*)("ball of lint");
    string* pen = (string*)("fountain pen");
    string* sandwich = (string*)("sandwich");

    Item* mop = (new Item());
    itemvect.push_back(mop);
    mop -> name = mop;
    mop -> id = 1;
    mop -> roomid = 2;

    Item* book = (new Item());
    itemvect.push_back(book);
    book -> name = book;
    book -> id = 2;
    book -> roomid = 3;

    Item* lint = (new Item());
    itemvect.push_back(lint);
    lint -> name = ball of lint;
    lint -> id = 3;
    lint -> roomid = 6;

    Item* pen = (new Item());
    itemvect.push_back(pen);
    pen -> name = pen;
    pen -> id = 4;
    pen -> roomid = 12;

    Item* sandwich = (new Item());
    itemvect.push_back(sandwich);
    sandwich -> name = sandwich;
    sandwich -> id = 5;
    sandwich -> roomid = 4;

}
		    
int move(vector<Room*> roomvect, string direction, int currentRoom) {
  int nextRoom;
  for (vector<Room*>::iterator it = roomvect.begin(); it != roomvect.end(); it++) {
    if (*(*it) -> getID() == currentRoom) {
      map<int, string*> exit = *(*it) -> getExits();
      for (map<int, string*>::const_iterator j = exit.begin(), j != exit.end(); j++) {
	if (strcmp(j -> second, direction) == 0) {
	  int nextRoom = j -> first;
	  return nextRoom;
	}
      }
    }
  }
}

void printRoom(vector<Room*> roomvect, vector<Item*> itemvect, int currentRoom) {
  for (vector<Room*>::iterator it = roomvect.begin(); it != roomvect.end(); it++) {
    if (*(*it) -> getID() == currentRoom) {
      cout << *(*it)->getDescription() << endl;
      for (i = (*it) -> getExits() -> begin(); i != (*it) -> getExits() -> end(); i++) {//printing exits
        cout << "Exits: " << endl;
	cout << it -> second << " " << endl;
      }
      cout << "You look around and see the following stuff: " << endl;
      for (vector<Item*>::iterator j = itemvect.begin(); j != itemvect.end(); j++) {
	if ((*j) -> roomid == currentroom) {
	  cout << (*j) -> name << endl;
	}
      }
    }
  }
}

void takeItem(vector<Room*> roomvect, vector<Item*> itemvect, vector<int>* inventory, int currentRoom, string object) {
  for (vector<Room*>::iterator it = roomvect.begin(); it != roomvect.end(); it++) {
    if (*(*it) -> getID() == currentRoom) {
      for (vector<Item*>::iterator i = itemvect.begin(); i != itemvect.end(); i++) {
	if(((*i) -> roomid == (*it)->getID()) && ((strcmp(object, (*i) -> name) == 0))) {
	  cout << "You grab a " << (*i) -> name; << " off the ground and put it in your pocket." << endl; 
	  inventory->push_back((*i)-> id);
	  (*i) -> roomid = 0;
	}
      }
    }
  }
}

void dropItem(vector<Room*> roomvect, vector<Item*> itemvect, vector<int>* inventory,int currentRoom) {
  cout << "What item do you want to leave behind?" << endl;
  cin >> object;
  for (vector<Item*>::iterator i = itemvect.begin(); i != itemvect.end(); i++) {
    if (strcmp((*i) ->name, object) == 0) {
      for (vector<int>::iterator it = inventory.begin(); it != inventory.end(); it++) {
	if ((*it) == (*i)->id;) {
	  cout << "You take the " << (*i) -> name << " out of your pocket and drop it on the ground." << endl;
	  intventory->erase(it);
	  (*i)-> roomid = currentRoom;
	  break;
	}
      }
    }
  }
}

void printInventory(vector<Item*> itemvect, vector<int> inventory) {
  cout << "You check your pockets and find: " << endl;
  for (vector<int>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    for (vector<Item*>::iterator i = itemvect.begin(); i != itemvect.end(); i++) {
      if ((*i)->id == *it) {
	cout << (*i) -> name << endl;
      }
    }
  }
}
		    
int main() {
  bool playing = true;
  char input[10];
  int currentroom = 1;
  vector<Room*> roomvect;
  vector<Item*> itemvect;
  vector<int> inventory;
  setRooms(&roomvect);
  setItems(&itemvect);

  cout << "You are playing Zuul. You are trapped in Sunset High School and are doing everything you can to escape. To play enter 'move' to move from room to room, 'pickup' to pickup a nearby item, 'drop' to drop an item from your inventory, 'inventory' to check your\
 inventory, 'help' to see how to play, or 'quit' to leave the game. Good luck." << endl;

  while (playing) {

    printRoom(&roomvect, &itemvect, currentroom);
    cout << "What do you want to do?" << endl;
    cin >> input;
    
    if (strcmp("quit", input) == 0) {
      char quit[5];
      cout << "You have selected to quit, you will lose your progress. Are you sure you want to do this?" << endl;
      cin >> quit;
      if (strcmp("yes", quit) == 0) {
	playing = false;
      }
      else if (strcmp("no", quit) == 0) {
	cout << "Ok, the game will not stop." << endl;
      }
      else {
	cout << "Please either enter 'yes' or 'no'." << endl;
      }
    }
    
    else if (strcmp("help", input) == 0) {
      cout << "You are playing Zuul. You are trapped in Sunset High School and are doing everything you can to escape. To play enter 'move' to move from room to room, 'pickup' to pickup a nearby item, 'drop' to drop an item from your inventory, 'inventory' to check your inventory, 'help' to see how to play, or 'quit' to leave the game. Good luck." << endl;
    }

    else if (strcmp("move", input) == 0) {
      cout << "You get the urge to move to a different room, but which direction do you go?" << endl;
      cin >> input;
      if (move(&roomvect, currentroom, input) == 0) {
	cout << "You run into a wall and feel stupid, realizing that there is no room in the direction you just tried to go." << endl;
      }
      else if () {
	currentRoom = move(&roomvect, currentRoom, input);
      }
      else if ((move(&roomvect, currentroom, input) == 16) && (inventory.size() != 5)) {
	cout << "Cheif, the campus monitor stops you. 'Sorry, you cant leave until school's out... unless you have something for me.'" << endl;
	cout << "Maybe if you come back with 5 items you find thoughout the school you could bribe cheif and get out of here." << endl;
      }
      else if ((move(&roomvect, currentroom, input) == 16) && (inventory.size() == 5)) {
	cout << "Cheif, the campus monitor stops you. 'Sorry, you cant leave until school's out... unless you ha- oh whats that you have?'" << endl;
	cout << "'Hmm, ok fine ill take it... you can pass.'" << endl;
	currentroom = 16;
	printRoom(&roomvect, &itemvect, currentroom);
	cout << "You did it. You finally did it. You escaped Sunset and beat Zuul, congratulations." << endl;
	playing = false;
      }
    }

    else if (strcmp("inventory", input) == 0) {
      printInventory(&itemvect, inventory);
    }
    
    else if (strcmp("drop", input) == 0) {
      dropItem(&roomvect, &itemvect, &inventory, currentRoom);
    }

    else if (strcmp("pickup", input) == 0) {
      cout << "You think to yourself, 'What item do I want to pick up?'" << endl;
      cin >> input;
      takeItem(&roomvect, &itemvect, &inventory, currentroom, input);
    }


  }
}


