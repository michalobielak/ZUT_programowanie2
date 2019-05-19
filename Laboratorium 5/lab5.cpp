#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

class Room
{
	public:
		Room(int, int, string);
		string getDescription();
		Room* getNeighborN();
		Room* getNeighborE();
		Room* getNeighborS();
		Room* getNeighborW();
		void setNeighborN(Room);
		void setNeighborE(Room);
		void setNeighborS(Room);
		void setNeighborW(Room);
		
	private:
		string description;
		int x;
		int y;
		Room *neighborN;
		Room *neighborE;
		Room *neighborS;
		Room *neighborW;

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

Room* Room::getNeighborN()
{
	return this->neighborN;
}

Room* Room::getNeighborW()
{
	return this->neighborW;
}

Room* Room::getNeighborE()
{
	return this->neighborE;
}

Room* Room::getNeighborS()
{
	return this->neighborS;
}

void Room::setNeighborN(Room neighbor)
{
	*this->neighborN = &neighbor;
}

void Room::setNeighborW(Room neighbor)
{
	this->neighborW = neighbor;
}

void Room::setNeighborE(Room neighbor)
{
	this->neighborE = neighbor;
}

void Room::setNeighborS(Room neighbor)
{
	this->neighborS = neighbor;
}

void setNeighborNS(Room p1, Room p2)
{
	p1.setNeighborS(p2);
	p2.setNeighborN(p1);
}

void setNeighborEW(Room p1, Room p2)
{
	p1.setNeighborW(p2);
	p2.setNeighborE(p1);
}

int main()
{
	Room rooms[3][6];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			rooms[i][j] = *Room(i, j, "pokoj o polozeniu " + i + ", " + j)
		}
	}
	
	setNeighborEW(rooms[0][0], rooms[0][1]);
	setNeighborEW(rooms[0][3], rooms[0][4]);
	setNeighborEW(rooms[0][4], rooms[0][5]);
	setNeighborEW(rooms[1][0], rooms[1][1]);
	setNeighborEW(rooms[1][1], rooms[1][2]);
	setNeighborEW(rooms[1][2], rooms[1][4]);
	setNeighborEW(rooms[2][0], rooms[2][1]);
	setNeighborEW(rooms[2][3], rooms[2][4]);
	setNeighborEW(rooms[2][4], rooms[2][5]);
	setNeighborNS(rooms[0][1], rooms[1][0]);
	setNeighborNS(rooms[0][3], rooms[1][2]);
	setNeighborNS(rooms[0][4], rooms[1][4]);
	setNeighborNS(rooms[0][5], rooms[1][5]);
	setNeighborNS(rooms[1][0], rooms[2][1]);
	setNeighborNS(rooms[1][2], rooms[2][2]);
	setNeighborNS(rooms[1][4], rooms[2][3]);
	setNeighborNS(rooms[1][5], rooms[1][5]);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			cout << '#';
			if (rooms[i][j].getNeighborE()) {
				cout << 'X';
			}
			cout << endl;
		}
	}
}


