/* @JUDGE_ID: 39315ZN 104 C++ "Largura" */

#include <iostream>
#include <vector>

using namespace std;

int st[21];
double vs[21];
vector<int> minstack;

int minsize;

int moedas;
double conversoes[20][20];

inline void troca(int nivel) {
	minsize = nivel+1;
	minstack.clear();
	for(int i=0;i!=nivel+1;i++) {
		minstack.push_back(st[i]);
	}
}

// prints the current stack
void printStack(int nivel) {
	for(int i=0;i!=nivel+1;i++ ) {
		cout << st[i] << " ";
	}
	cout<<endl;
}

// tenta o ciclo
void tentaCiclo(double v,int next, int nivel) {

	// se o nivel ja vai estourar agora, nao adianta	
	if(nivel>=minsize-2) {
		return;
	}

	// novo nivel
	v *= conversoes[st[nivel]][next];
	nivel++;
	vs[nivel] = v;
	st[nivel] = next;
	
	// se for a moeda inicial
	if(next==st[0] && v>1.01) {
		cout << "encontrado!!!"<< v<<endl;
		printStack(nivel);
		troca(nivel);
		// nao continua nos filhos, q nao vale a pena
		return;
	}

	if(next==st[0]) {
		return;
	}
	
	// se o cara ja esta contido e 
	/*for(int i=0;i!=nivel;i++) {
		if(st[i]==next && conversoes[st[nivel-1]][next]<vs[i]) {
		//	return;
		}
	}*/
	
	//cout << v << ") ";
	//printStack(nivel);

	// se for o ultimo nivel, nao gera os filhos
	if(nivel>=moedas-1) {
		//cout << "fim";
		return;
	}

	for(int i=0;i!=moedas;i++) {
		
		// se for a mesma, ignora
		if(i==next) continue;
		
		if(nivel<minsize) {
			tentaCiclo(v,i,nivel);
		}
		
	}

	return;
	
}

inline void instancia() {
	
	minstack.clear();
	minsize = moedas + 10;

	for(int i=0;i!=moedas;i++) {
		// joga ele no stack
		st[0] = i;
		for(int z=0;z!=moedas;z++) {
			if(i!=z) {
				tentaCiclo(1,z,0);
			}
		}
	}

	if(minstack.size()==0) {
		cout << "no arbitrage sequence exists" << endl;
		return;
	}
	cout << "Encontrado: ";
	for(int i=0;i!=minstack.size();i++) {
		cout << (minstack[i]+1) << " ";
	}
	cout << endl;

}

int main(int argc, char **argv) {
	
	while(cin >> moedas) {
		
		//cout << moedas << endl;
		for(int i=0;i!=moedas;i++) {
			for(int z=0;z!=moedas;z++) {
				if(i==z) conversoes[i][z]=1;
				else cin >> conversoes[i][z];
				//cout << conversoes[i][z] << " ";
			}
			//cout << endl;
		}
		
		instancia();
		
	}
	
	return 0;

}


