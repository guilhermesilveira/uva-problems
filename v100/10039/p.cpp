#include <iostream>
#include <assert.h>
#include <map>
#include <string>

using namespace std;

class Cidade {
public:
	string n;
	int tot;
	int con[5000];
	int tempo[5000][2];
	bool visitado;
	int chegada;
};

Cidade c[101];
int cid;
map<string,int> mapa;

int startTime;
int calvo;
int clocal;

int fila[101];
bool valido[101];

void start() {

	int pos = 0;
	int tot = 1, actual;
	fila[0] = clocal;
	valido[0] = true;
	c[clocal].chegada = 0;
	c[clocal].visitado = true;
	int p;

	while(pos!=tot) {

		actual = fila[pos];
		fila[pos++] = false;
		
		cout << "visitando " << c[actual].n << endl;
		
		for(int i=0;i!=c[actual].tot;i++) {
		
			if(c[actual].tempo[i][0]>c[actual].chegada) continue;
			p = c[actual].con[i];
			
			cout << "hmmm" << endl;

			if(p==calvo) {
				// achamos!!!
				cout << "Departure " << " " << c[clocal].n << endl;
				cout << "Arrival   " << c[p].tempo[1] << " " << c[calvo].n << endl;
				return;
			}
			
			cout << c[p].visitado << endl;

			if(!c[p].visitado) {
			
				c[p].visitado = true;
				
				fila[tot] = p;
				valido[tot++] = true;
				
			}
			
		}

	}

	cout << "No connection" << endl;

}

void read() {
	cin >> cid;
	mapa.clear();
	for(int i=0;i!=cid;i++) {
		cin >> c[i].n;
		c[i].tot = 0;
		c[i].visitado = false;
		cout << i <<"::" <<c[i].n << endl;
		mapa[c[i].n] = i;
	}
	int t, tempo, antigo, temp;
	string local, alvo;
	int cant, cnova;
	cin >> t;
	while(t--) {
		int con;
		cin >> con;
		for(int i=0;i!=con;i++) {
			cin >> tempo >> alvo;
			cnova = mapa[alvo];
			if(i!=0) {
				// tenta conectar
				temp = c[cant].tot;
				c[cant].con[temp] = cnova;
				c[cant].tempo[temp][0] = antigo;
				c[cant].tempo[temp][1] = tempo;
				c[cant].tot++;
				cout << "conectando: " << c[cant].n << " e " << c[cnova].n << endl;
				assert(c[cant].tot<5000);
			}
			cant = cnova;
			local = alvo;
			antigo = tempo;
		}
	}
	cin >> startTime >> clocal >> calvo;
}

int main() {

	int t,i=0;
	cin >> t;
	while(t--) { cout << "Scenario " << ++i << endl; read(); start(); cout << endl; }

	return 0;

}
