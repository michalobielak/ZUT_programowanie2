#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

class Item
{
public:
	string name;
	int value;
	Item(string, int);
	string getName();
};

Item::Item(string name, int value)
{
	this->name = name;
	this->value = value;
}

string Item::getName() {
	return this->name;
}

class Room
{
	public:
		Room(int, int, string);
		string getDescription();
		Room *getNeighborN();
		Room *getNeighborE();
		Room *getNeighborS();
		Room *getNeighborW();
		void setNeighborN(Room *);
		void setNeighborE(Room *);
		void setNeighborS(Room *);
		void setNeighborW(Room *);
		bool checkItem();
		void addItem(Item *);
		Item *getItem();
		
		
	private:
		string description;
		int x;
		int y;
		Room *neighborN = NULL;
		Room *neighborE = NULL;
		Room *neighborS = NULL;
		Room *neighborW = NULL;
		Item *item = NULL;
		

};

Room::Room(int x, int y, string description)
{
	this->x = x;
	this->y = y;
	this->description = description;
}

string Room::getDescription()
{
	return this->description;
}

Room *Room::getNeighborN()
{
	return this->neighborN;
}

Room *Room::getNeighborW()
{
	return this->neighborW;
}

Room *Room::getNeighborE()
{
	return this->neighborE;
}

Room *Room::getNeighborS()
{
	return this->neighborS;
}

void Room::setNeighborN(Room* neighbor)
{
	this->neighborN = neighbor;
}

void Room::setNeighborW(Room* neighbor)
{
	this->neighborW = neighbor;
}

void Room::setNeighborE(Room* neighbor)
{
	this->neighborE = neighbor;
}

void Room::setNeighborS(Room* neighbor)
{
	this->neighborS = neighbor;
}

void Room::addItem(Item* item)
{
	this->item = item;
}

bool Room::checkItem()
{
	if (this->item) {
		return true;
	} else {
		return false;
	}
}

Item *Room::getItem()
{
	return this->item;
}

void setNeighborNS(Room* p1, Room* p2)
{
	
	p1->setNeighborS(p2);
	p2->setNeighborN(p1);
}

void setNeighborEW(Room* p1, Room* p2)
{
	p1->setNeighborE(p2);
	p2->setNeighborW(p1);
}

int main()
{
	char steps[23] = {
		'e',
		's',
		's',
		'w',
		'e',
		'n',
		'e',
		'e',
		's',
		'n',
		'n',
		's',
		'e',
		'e',
		'n',
		'e',
		'e',
		'w',
		'w',
		's',
		's',
		'e',
		'e'
	};
	char step;
	int randX, randY;
	int countStep = 0;
	Room* rooms[18];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			rooms[i * 6 + j] =  new Room(i, j, "pokoj");
		}
	}
	setNeighborEW(rooms[0], rooms[1]);
	setNeighborEW(rooms[3], rooms[4]);
	setNeighborEW(rooms[4], rooms[5]);
	setNeighborEW(rooms[6], rooms[7]);
	setNeighborEW(rooms[7], rooms[8]);
	setNeighborEW(rooms[8], rooms[9]);
	setNeighborEW(rooms[9], rooms[10]);
	setNeighborEW(rooms[12], rooms[13]);
	setNeighborEW(rooms[15], rooms[16]);
	setNeighborEW(rooms[16], rooms[17]);
	setNeighborNS(rooms[1], rooms[6]);
	setNeighborNS(rooms[2], rooms[8]);
	setNeighborNS(rooms[3], rooms[10]);
	setNeighborNS(rooms[5], rooms[11]);
	setNeighborNS(rooms[6], rooms[13]);
	setNeighborNS(rooms[8], rooms[14]);
	setNeighborNS(rooms[10], rooms[15]);
	setNeighborNS(rooms[11], rooms[17]);

	int countY = 0;
	cout << "Pokoje bez przedmiotow:" << endl;
	for (int i = 0; i < 18; i++) {
		countY++;
		if (rooms[i]->getNeighborW() == NULL && i == 6) {
			cout << 'X';
		}
		cout << '#';
		if (rooms[i]->getNeighborE() == NULL && countY != 6) {
			cout << 'X';
		}
		if(countY ==6) {
			cout << endl;
			countY = 0;
		}		
	}
	
	Item* item1 = new Item("A Item one", 1);
	Item* item2 = new Item("B Item two", 2);
	Item* item3 = new Item("C Item three", 3);
	
	
	do {
		randX = rand() % 18;	
	} while (rooms[randX]->checkItem());
	rooms[randX]->addItem(item1);
	
	do {
		randX = rand() % 18;
	} while (rooms[randX]->checkItem());
	rooms[randX]->addItem(item2);
	
	do {
		randX = rand() % 18;	
	} while (rooms[randX]->checkItem());
	rooms[randX]->addItem(item3);
	
	cout << endl << "Znalezione pokoje:" << endl;
	Room* room = rooms[0];
	for (int i = 0; i < 23; i++) {
		step = steps[i];
		countStep++;
		switch (step) {
			case 'e': room = room->getNeighborE(); break;
			case 'n': room = room->getNeighborN(); break;
			case 's': room = room->getNeighborS(); break;
			case 'w': room = room->getNeighborW(); break;	
		}
		if (room->checkItem() != NULL) {
			
			cout<<"Step " << countStep << " " << room->getItem()->getName() << endl;
		}
	}
	
	
	cout << endl << "Pokoje z przedmiotami:" << endl;
	for (int i = 0; i < 18; i++) {
		countY++;
			if (rooms[i]->getNeighborW() == NULL && i == 6) {
				cout << 'X';
			}
			if (rooms[i]->checkItem()) {
				cout << rooms[i]->getItem()->getName()[0];
			} else {
				cout << '#';
			}
			if (rooms[i]->getNeighborE() == NULL && countY != 6) {
				cout << 'X';
			}
			if(countY ==6) {
				cout << endl;
				countY = 0;
			}
		
	}
}


