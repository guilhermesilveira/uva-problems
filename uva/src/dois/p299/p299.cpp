/* @JUDGE_ID: 39315ZN 299 C++ "Largura" */

#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

struct state {
	int pontos[50];
	int nivel;
	int pontuacao;
	int corretos;
};

vector<state> passado;
vector<state> lista;
int pontos;

void print(state &ns) {
	for(int i=0;i!=pontos;i++) {
		cout << ns.pontos[i] << " ";
	}
	//cout << "corretos " << ns.corretos;
	cout << endl;
}

bool fim(state &s) {
	/*cout << "testando: ";
	print(s);*/
	for(int i=0;i<pontos;i++) {
		if(s.pontos[i]!=i+1){ return false;}
	}
	return true;
}

bool jaPassou(state &s) {
	for(int i=s.corretos;i!=passado.size();i++){
		bool p = true;
		for(int z=0;z!=pontos;z++) {
			// se algum ponto for diferente, eh outro
			if(s.pontos[z]!=passado[i].pontos[z]) { p=false; break; }
		}
		// se todo os pontos foram iguais, eh aqui
		if(p==true) {
			return true;
		}
	}
	return false;
}

void pontua(state &ns,int pontosPai) {
	//ns.corretos=0;
	for(int i=0;i!=pontos;i++) {
		if(ns.pontos[i]!=i+1) {
			ns.corretos=i;
			//cout<<"corretos="<<i << " " << ns.pontos[i] << " " << i;
			//print(ns);
			break;
		}
	}
	// pontuacao eh a distancia do primeiro invalido
	for(int i=0;i!=pontos;i++) {
		if(ns.pontos[i]!=i) {
			ns.pontuacao = pontosPai + abs(ns.pontos[i] - i);
			//print(ns);
			return;
		}
	}
	// todos estao no ponto!!!!
	ns.pontuacao = 0;
	//ns.pontuacao = ns.nivel + 1;
	//cout << ns.pontuacao << endl;
	/*for(int i=0;i!=pontos;i++) {
		ns.pontuacao += abs(ns.pontos[i]-i);
	}*/
	//print(ns);
	//cout << "pont: " << ns.pontuacao << endl;
}

bool ordenaStates(const state &s1,const state &s2) {
	return s1.pontuacao<s2.pontuacao;
//	return s1.nivel<s2.nivel;
//return true;
}

int main(int argc, char **argv) {
	
	int inst;
	cin >> inst;
	
	for(int i=0;i!=inst;i++) {
		
		cin >> pontos;
		
		state inicial;
		inicial.nivel = 0;
		
		for(int z=0;z!=pontos;z++) {
			int p;
			cin >> p;
			inicial.pontos[z]=p;
		}
		
		while(!fim(inicial)) {
			for(int z=0;z!=pontos-1;z++) {
				if(z==inicial.pontos[z]) continue;
				// se o proximo ponto for maior, ignora
				if(inicial.pontos[z+1]>inicial.pontos[z]) continue;
				// achei a troca
				int temp = inicial.pontos[z+1];
				inicial.pontos[z+1]=inicial.pontos[z];
				inicial.pontos[z]=temp;
				inicial.nivel++;
				break;
			}
		}
		
		cout<<"Optimal train swapping takes " << inicial.nivel << " swaps."<<endl;

		/*pontua(inicial,0);
		
		lista.push_back(inicial);
		int skipped = 0;
		
		if(fim(inicial)) {
			cout<<"Optimal train swapping takes 0 swaps."<<endl;
			goto proxima;
		}

		while(lista.size()!=0) {
			sort(lista.begin(),lista.end(),ordenaStates);
			state s = lista[0];
			lista.erase(lista.begin());
			// gera os filhos
			for(int z=s.corretos;z<pontos-1;z++) {
				// se o proixmo ponto for um a mais que este, ignora...
				if(s.pontos[z+1]==s.pontos[z]+1) {
					skipped++;
					if(skipped%1000==0) {
						print(s);
						cout<<"skipped " << skipped << endl;
					}
					continue;
				}
				state ns;
				ns.nivel = s.nivel + 1;
				//ns.corretos = 0;
				for(int z2=0;z2!=pontos;z2++) {
					ns.pontos[z2] = s.pontos[z2];
				}
				//cout<<"copiando: "<<endl;
				int guardar = ns.pontos[z];
				ns.pontos[z] = ns.pontos[z+1];
				ns.pontos[z+1] = guardar;
				pontua(ns,s.pontuacao);
				if(fim(ns)) {
					cout<<"Optimal train swapping takes "<<ns.nivel<<" swaps."<<endl;
					goto proxima;
				}
				if(!jaPassou(ns)) {
					lista.push_back(ns);
					passado.push_back(ns);
				} else {skipped++;}
			}*/
	}
	
	return 0;
	
}
