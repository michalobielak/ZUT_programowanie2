#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
	Player(string, string, string, vector<string>);
	void edit(string, string, string, vector<string>);
	string PlayerDetails();

private:
	string Name;
	string SecondName;
	string Height;
	vector<string> Skills;
};

Player::Player(string name, string secondname, string height, vector<string> skills)
{
	this->Name = name;
	this->SecondName = secondname;
	this->Height = height;
	this->Skills = skills;
}

void Player::edit(string name, string secondname, string height, vector<string> skills)
{
	this->Name = name;
	this->SecondName = secondname;
	this->Height = height;
	this->Skills = skills;
}

string Player::PlayerDetails()
{
	string details = "";
	details.append(Name + " ");
	details.append(SecondName + " ");
	details.append(Height + " ");

	for (int i = 0; i < Skills.size(); i++) {
		details.append(Skills[i] + " ");
	}
	return details;	
}

class Team
{
public:
	Team(string);
	Team(Team *);
	void AddPlayer(string, string, string, vector<string>);
	string displayTeam();
	void editPlayer(int, string, string, string, vector<string>);
	string getName();
	
	private:
		vector<Player> Players;
		string Name;
		
};

Team::Team(string name)
{
	this->Name = name;
}
Team::Team(Team *team)
{
	this->Players = team->Players;
	this->Name = team->Name;
}

void Team::AddPlayer(string name, string secondname, string height, vector<string> skills)
{
	Player player(name, secondname, height, skills);
	this->Players.push_back(player);
}

string Team::displayTeam()
{
	string details = "";
	for(int i = 0; i < Players.size(); i++){
		details.append(this->Players[i].PlayerDetails() + "\n");
	}
	return details;
}

string Team::getName()
{
	return this->Name;
}

void Team::editPlayer(int player, string name, string secondName, string height, vector<string> skills)
{
	this->Players[player].edit(name, secondName, height, skills);
}

void addPlayers(Team *team)
{
	string name, secondName, height, skill;
	int countSkills;
	vector<string> skills;
	cout << team->getName() << endl;;
	for(int k = 0; k < 2; k++){
		cout << "zawodnik nr. " << k+1 << ": " << endl;
		cout << "Podaj imie zawodnika: ";
		cin >> name;
		cout << "Podaj nazwisko zawodnika: ";
		cin >> secondName;
		cout << "Podaj wzrost zawodnika: ";
		cin >> height;
		cout << "Podaj ilosc umiejetnosci : ";
		cin >> countSkills;
		for(int i = 0; i < countSkills; i++){
			cout << "Podaj umiejetnosc nr. " << i + 1 << ": ";
			cin >> skill;
			skills.push_back(skill);
		}
		team->AddPlayer(name, secondName, height, skills);
	}
}

void editPlayerForm(Team *team)
{
	string name, secondName, height, skill;
	int countSkills;
	vector<string> skills;
	cout << "Podaj nowe imie zawodnika: ";
		cin >> name;
		cout << "Podaj nowe nazwisko zawodnika: ";
		cin >> secondName;
		cout << "Podaj nowe wzrost zawodnika: ";
		cin >> height;
		cout << "Podaj nowe ilosc umiejetnosci : ";
		cin >> countSkills;
		for(int i = 0; i < countSkills; i++){
			cout << "Podaj nowa umiejetnosc nr. " << i + 1 << ": ";
			cin >> skill;
			skills.push_back(skill);
		}
		team->editPlayer(0, name, secondName, height, skills);
}

int main()
{
	Team team1("zespol1");
	Team team2("zespol2");
	addPlayers(&team1);
	addPlayers(&team2);
	Team team3(&team2);
	cout << team1.displayTeam() << endl;
	cout << team2.displayTeam() << endl;
	cout << team3.displayTeam() << endl;
	editPlayerForm(&team2);
	cout << team1.displayTeam() << endl;
	cout << team2.displayTeam() << endl;
	cout << team3.displayTeam() << endl;
}


