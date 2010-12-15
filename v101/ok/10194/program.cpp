#include <iostream>
#include <string>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Team {
public:
	string name;
	int won;
	int lost;
	int draw;
	int games;
	int goals;
	int against;
	int balance;
	int points;
	Team() { won=0;lost=0;draw=0;games=0;goals=0;against=0;balance=0;points=0; }
	void game(int i, int j) {
		games++;
		balance += (i - j);
		goals += i;
		against += j;
		if (i>j) {
		won++;
		points += 3;
		} else if (i == j) {
		points += 1;
		draw++;
		} else {
		lost++;
		}
	}
};

bool comp(const Team *t1,const Team *t2) {

	if(t1->points!=t2->points) {
		return t1->points>t2->points;
	}

	if(t1->won!=t2->won) {
		return t1->won > t2->won;
	}

	if(t1->goals-t1->against!=t2->goals-t2->against) {
		return t1->balance > t2->balance;
	}

	if(t1->goals!=t2->goals) {
		return t1->goals > t2->goals;
	}

	if(t1->games!=t2->games) {
		return t1->games > t2->games;
	}
	
	return strcasecmp(t1->name.c_str(),t2->name.c_str()) < 0;

}
	
void start() {

	// imprime o nome do campeonato
	string championship;
	getline(cin,championship);
	cout << championship << endl;

	int teamsCount;
	cin >> teamsCount;

	vector<Team *> teams;
	map<string,Team *> teamsTable;
	while(teamsCount--!=0) {
		Team *t = new Team;
		getline(cin,t->name);
		teams.push_back(t);
		teamsTable[t->name] = t;
	}

	int gamesCount;
	cin >> gamesCount;
	while(gamesCount--!=0) {
		char team1name[101];
		char team2name[101];
		char c;
		int goals1;
		int goals2;
		cin.getline(team1name,101,'#');
		scanf("%d",&goals1);
		cin >> c;
		scanf("%d",&goals2);
		cin >> c;
		cin.getline(team2name,101);
		string *line = new string(team1name);
		Team *t1 = teamsTable[*line];
		Team *t2 = teamsTable[*new string(team2name)];
		t1->game(goals1,goals2);
		t2->game(goals2,goals1);
	}

	sort(teams.begin(),teams.end(),comp);
	for(int i=0;i!=teams.size();i++) {
		Team *t = teams[i];
		cout << 
			(i+1) << ") " << t->name << " " << t->points << "p, " << t->games << "g ("
			<< t->won << "-" << t->draw << "-" << t->lost << "), " << (t->balance) << "gd ("
			<< t->goals << "-" << t->against << ")" << endl
		;
	}

}

int main(int argcount,char **argv) {

	int caseCount;
	cin >> caseCount;
	int i = 0;
	while(caseCount--!=0) {
		if(i++!=0) cout << endl;
		start();
	}

	return 0;

}
