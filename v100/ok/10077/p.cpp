#include <iostream>
#include <string>

using namespace std;

int cit;

class Conexao {
public:
	int de, para;
	int horaSai, horaChega;
};

class Cidade{
public:
	string n;
	Conexao *c[10000];
};

Cidade cidades[101];

void start() {
	
	int i;
	cin >> cit;
	for(i=0;i!=cit;i++) {
		cin >> cidades[i].n;
		cout << cidades[i].n << endl;
	}
	int trens, con, nH, hA;
	string c, ca;
	cin >> trens;
	while(trens--) {
		cin >> con;
		i = 0;
		while(con--) {
			cin >> nH >> c;
			if(i++!=0) {
				// adiciona a conexao
				
			}
			hA = nH;
			ca = c;
		}
	}
	cin >> nH;
	string s,f;
	cin >> s;
	cin >> f;
	
}

int main() {

	int t;
	cin >> t;
	while(t--) start();
	return 0;

}
