#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define MAXW 25200
#define MAXL 18

#define EXISTS(s) binary_search(words[s.size()][s[0]-'a'].begin(),words[s.size()][s[0]-'a'].end(),s)

using namespace std;

class track {
public:
	string s;
	track *anterior;
};

char **set[17];
int **tot[17];

char **all = (char **) malloc(sizeof(char *) * MAXW);

/*bool bfs(string &from, string &to) {

	track *t = new track;
	t->s = from;
	t->anterior = t;

	//queue<track *> pilha;
	queue<string> pilha;
	pilha.push(from);

	set<string> passado[30];
	passado[from[0]-'a'].insert(from);

	while(pilha.size() != 0) {

		track *t = pilha.front();
		pilha.pop();
		
		// gera todas as filhas
		for(int i = 0; i != s.size(); i++) {

			char oldchar = s[i];
			for(char c = 'a'; c <= 'z'; c++) {

				if(c!=oldchar) {
					s[i] = c;
					if(s == to) {
						// achei
						track *nt = new track;
						nt->s = t->s;
						nt->anterior = t;
						t->s[i] = oldchar;
						string buffer = "";
						while(nt->anterior != nt) {
							buffer = nt->s + "\n" + buffer;
							nt = nt->anterior;
						}
						cout << (nt->s) << endl;
						cout << buffer;
						return true;
					}
					if(binary_search(words[t->s.size()][t->s[0]-'a'].begin(),words[s.size()][t->s[0]-'a'].end(),t->s) && !binary_search(passado[t->s[0]-'a'].begin(),passado[t->s[0]-'a'].end(),t->s)) {
						track *nt = new track;
						nt->s = t->s;
						nt->anterior = t;
						passado[t->s[0]-'a'].insert(t->s);
						pilha.push(t->s);
					}
				}

			}
			t->s[i] = oldchar;

		}

	}

	return false;

}*/

int main(char **argv,int argc) {

	while(cin.peek()!='\n') {
		string str;
		getline(cin,str);
		if(words[str.length()][str[0]-'a'][str.c_str()]==NULL) {
			cout << str << endl;
			track *t = new track();
			t->s = str.c_str();
			words[str.length()][str[0]-'a'][str.c_str()] = t;
		}
	}
	
	return 0;
	
	string str;
	getline(cin,str);

	int caso = 0;
	while(true) {

		string from,to;
		if(!(cin >> from >> to)) break;

		if(caso++!=0) cout << endl;

		//cout << from << " " << to << endl;

		/*if(from.size()!=to.size() || !EXISTS(from) || !EXISTS(to)) {
			cout << "No solution." << endl;
			continue;
		}*/


	//	if(!bfs(from,to)) {
			cout << "No solution." << endl;
		//}

	}
	
	return 0;

}
