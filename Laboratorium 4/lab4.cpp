#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

class Player
{
public:
	Player(string, string, string, vector<string>);
	Player(string);
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

Player::Player(string lineWithPlayers)
{
	string player[8];
	stringstream playerString;
	for (int i = 0; i < lineWithPlayers.size(); i++) {
		if (lineWithPlayers[i] == ';') {
			lineWithPlayers[i] = ' ';
		}
	}
	playerString << lineWithPlayers;
	for (int i = 0; i < 8; i++) {
		playerString >> player[i];
		cout << player[i]<<endl;;
	}
	vector<string> skills;
	for(int i = 3; i < 8; i++){
		skills.push_back(player[i]);
	}
	this->Name = player[0];
	this->SecondName = player[1];
	this->Height = player[2];
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
	details.append(Name + ";");
	details.append(SecondName + ";");
	details.append(Height + ";");

	for (int i = 0; i < Skills.size(); i++) {
		details.append(Skills[i] + ";");
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
	void addPlayersFromFile(string fileWithTeam);
	bool TeamSaveToFile();
	
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
	details.append(this->getName() + "\n");
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

void Team::addPlayersFromFile(string fileWithTeam)
{
	string lineWithPlayer;
	ifstream newTeam(fileWithTeam.c_str());
	if (newTeam.is_open()) {
		while (!newTeam.eof()) {
			getline(newTeam, lineWithPlayer);
			Player player(lineWithPlayer);
			this->Players.push_back(player);
		}
	}
	newTeam.close();
}

bool Team::TeamSaveToFile()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	stringstream fileName;
	fileName << "druzyna" << this->getName() <<  st.wHour  << st.wMinute << st.wSecond << ".txt";
	string name = fileName.str();
	ofstream file(name.c_str());
	if (file.is_open()) {
		for(int i = 0; i < Players.size(); i++){
			file << this->Players[i].PlayerDetails() << endl;
		}
	}
	file.close();
	return true;
}

void addPlayers(Team *team, string players[5][8])
{
	string name, secondName, height, skill;
	int countSkills;
	cout << team->getName() << endl;
	for(int k = 0; k < 5; k++){
		name = players[k][0];
		secondName = players[k][1];
		height = players[k][2];
		vector<string> skills;
		for(int i = 3; i < 8; i++){
			skills.push_back(players[k][i]);
		}
		team->AddPlayer(name, secondName, height, skills);
	}
}

void editPlayerForm(Team *team, string players[5][8])
{
	string name, secondName, height, skill;
	int countSkills;
	vector<string> skills;
	name = players[0][0];
	secondName = players[1][1];
	height = players[2][2];
	for(int i = 3; i < 8; i++){
		skills.push_back(players[4][i]);
	}
	team->editPlayer(0, name, secondName, height, skills);
}

int main()
{
	string playersTeam1[5][8] = {
		{
			"Dawid", "Kownacki", "186", "Podania", "Przyjecia pilki", "Gra Glowa", "Walka", "Obrona"
		},
		{
			"Robert", "Lewandowski", "185", "Obrona", "Podania", "Przyjecia pilki", "Gra Glowa", "Walka"
		},
		{
			"Arkadiusz", "Milik", "186", "Podania", "Gra Glowa", "Walka", "Obrona", "Przyjecia pilki"
		},
		{
			"Krzysztof", "Piatek", "183", "Gra Glowa", "Walka", "Obrona", "Przyjecia pilki", "Podania"
		},
		{
			"Piotr", "Zielinski", "180", "Walka", "Obrona", "Podania", "Przyjecia pilki", "Gra Glowa"
		},
	};
	
	string playersTeam2[5][8] = {
		{
			"Dawid", "Krychowiak", "186", "Podania", "Przyjecia pilki", "Gra Glowa", "Walka", "Obrona"
		},
		{
			"Mateusz", "Klich", "183", "Obrona", "Podania", "Przyjecia pilki", "Gra Glowa", "Walka"
		},
		{
			"Jakub", "B³aszczykowski", "176", "Podania", "Gra Glowa", "Walka", "Obrona", "Przyjecia pilki"
		},
		{
			"Michal", "Pazdan", "181", "Gra Glowa", "Walka", "Obrona", "Przyjecia pilki", "Podania"
		},
		{
			"Kamil", "Glik", "190", "Walka", "Obrona", "Podania", "Przyjecia pilki", "Gra Glowa"
		},
	};
	
	string fileWithTeam;
	cout << "Podaj nazwe pliku z druzyna: ";
	cin >> fileWithTeam;
	Team team1("zespol1");
	Team team2("zespol2");
	addPlayers(&team1, playersTeam1);
	addPlayers(&team2, playersTeam2);
	Team team3(&team2);
	Team team4("zespol z pliku");
	team4.addPlayersFromFile(fileWithTeam);
	cout << team1.displayTeam() << endl;
	cout << team2.displayTeam() << endl;
	cout << team3.displayTeam() << endl;
	cout << team4.displayTeam() << endl;
	editPlayerForm(&team4, playersTeam1);
	cout << team1.displayTeam() << endl;
	cout << team2.displayTeam() << endl;
	cout << team3.displayTeam() << endl;
	cout << team4.displayTeam() << endl;
	if (team1.TeamSaveToFile()) {
		cout << "Zapisano plik druzyny " << team1.getName() << endl; 
	}
	if (team2.TeamSaveToFile()) {
		cout << "Zapisano plik druzyny " << team2.getName() << endl; 
	}
	if (team3.TeamSaveToFile()) {
		cout << "Zapisano plik druzyny " << team3.getName() << endl; 
	}
	if (team4.TeamSaveToFile()) {
		cout << "Zapisano plik druzyny " << team4.getName() << endl; 
	}
	
}


