#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	Player(string, string, string, string, string, string, string, string);
	string PlayerDetails();

private:
	string Name;
	string SecondName;
	string Height;
	string Skills[5];
}

Player::Player(string name, string secondname, string height, string skill1 = "", string skill2 ="", string skill3 = "", string skill4 = "", string skill5 = "")
{
	Name = name;
	SecondName = secondname;
	Height = height;
	Skills[0] = skill1;
	Skills[1] = skill2;
	Skills[2] = skill3;
	Skills[3] = skill4;
	Skills[4] = skill5;
}

string Player::PlayerDetails()
{
	string details = "";
	details.append(Name + " ");
	details.append(SecondName + " ");
	details.append(Height + " ");
	details.append(Name + " ");

	for (int i = 0; i < 5; i++) {
		if (Skills[i] != "") {
				details.append(Skills[i] + " ");
		}
	}
	return details;	
}


int main()
{
	Player player1("Michal", "Obielak", "178", "Obrona", "Atak", "Bieg", "Dystans", "Gol");
	cout<<player1.PlayerDetails();
	return 0;
}


