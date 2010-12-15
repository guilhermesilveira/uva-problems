#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Usuario {
public:
	int userid;
	int problemas;
	int time;
	bool operator > (Usuario &u) {
	cout << " maior"<< endl;
		if(this->problemas!=u.problemas) {
			return this->problemas>u.problemas;
		}
		if(this->time!=u.time) {
			return this->time<u.time;
		}
		return this->userid>u.userid;
	}
	bool operator == (Usuario &u) {
	cout << " menor"<< endl;
		if(this->problemas!=u.problemas) {
			return this->problemas>u.problemas;
		}
		if(this->time!=u.time) {
			return this->time<u.time;
		}
		return this->userid>u.userid;
	}
};

bool compareMaior(const Usuario *u1, const Usuario *u) {
	// se possuem dieferentes numeros de problemas
	if(u1->problemas!=u->problemas) {
		return u1->problemas>u->problemas;
	}
	// se possuem diferentes tempos
	if(u1->time!=u->time) {
		return u1->time<u->time;
	}
	// se possuem diferentes ids
	return u1->userid<u->userid;
}

int main(char **argv,int argc) {

	int user;
	int problem;
	long time;
	char result;

	int count;
	cin >> count;
	
	char linha[201];
	char *t;

	// queima as duas linhas
	scanf("\n\n");
	
	long long tempoUsuarios[101][10];
	long long pontosUsuarios[101][3];
	
	int i,i2;

	while(count--) {

		for(i=0;i!=101;i++) {
			for(i2=0;i2!=10;i2++) {
				tempoUsuarios[i][i2] = 0;
			}
			pontosUsuarios[i][0] = 0;
			pontosUsuarios[i][1] = 0;
			pontosUsuarios[i][2] = 0;
		}

		while(true) {
			t = gets(linha);
			if(!t || t[0]==0) break;
			sscanf(linha,"%ld %ld %ld %c",&user,&problem,&time,&result);
			pontosUsuarios[user][2] = 1;
			if(result=='C' && tempoUsuarios[user][problem]!=-1) {
				// adiciona o tempo caso ainda nao tenha executado um C
				tempoUsuarios[user][problem] += time;
				pontosUsuarios[user][0]++;
				// executa
				pontosUsuarios[user][1] += tempoUsuarios[user][problem];
				// zera o tempo
				tempoUsuarios[user][problem] = -1;
				//cout  << user << " " << problem << " " << time << " " << result << endl;
			} else if(result=='I' && tempoUsuarios[user][problem]!=-1) {
				// adiciona 20 caso ainda nao tenha executado um C
				tempoUsuarios[user][problem] += 20;
				//cout  << user << " " << problem << " " << time << " " << result << endl;
			}
		}

		vector<Usuario *> users;
		for(i=1;i!=101;i++) {

			if(pontosUsuarios[i][2]!=0 && pontosUsuarios[i][0]!=0) {
				Usuario *u = new Usuario;
				u->userid = i;
				u->problemas = pontosUsuarios[i][0];
				u->time = pontosUsuarios[i][1];
				users.push_back(u);
				// adiciona como usuario
			}

		}

		sort(users.begin(),users.end(),compareMaior);

		for(i=0;i!=users.size();i++) {
			cout << users[i]->userid << " " << users[i]->problemas << " " << users[i]->time << endl;
		}

		for(i=1;i!=101;i++) {
			if(pontosUsuarios[i][2]!=0 && pontosUsuarios[i][0]==0) {
				cout << i << " 0 0" << endl;
			}
		}

		if(count!=0) {
			cout << endl;
		}

	}

	return 0;

}
