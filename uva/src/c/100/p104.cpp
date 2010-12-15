/* @JUDGE_ID: 39315ZN 104 C++ "Largura" */

#include <iostream>
#include <vector>

using namespace std;

int moedas;
double conversoes[20][20];

struct sequencia {
	int moedas[21];
	int mudancas;
	double valor;
};

/*inline void print(sequencia &s) {
	cout << "(sequencia) ";
	for(int i=0;i!=s.mudancas;i++) {
		cout << s.moedas[i] << " ";
	}
	cout << "==" << s.valor << "== ";
	cout << endl;
}*/

inline void copia(sequencia &s,sequencia &sn,int i) {
	for(int z=0;z!=s.mudancas;z++) {
		sn.moedas[z] = s.moedas[z];
	}
	sn.mudancas = s.mudancas + 1;
	sn.moedas[s.mudancas] = i;
	sn.valor = 1;
	sn.valor=s.valor * conversoes[s.moedas[s.mudancas-1]][i];
}

inline void instancia() {
	
	vector<sequencia> lista;
	for(int i=0;i!=moedas;i++) {
		sequencia s;
		s.mudancas = 1;
		s.moedas[0]=i;
		s.valor = 1;
		lista.push_back(s);
//		cout << "inicio em " << i << endl;
	}

	while(lista.size()!=0) {

		sequencia s = lista[0];
		lista.erase(lista.begin());
		
		//print(s);
		
		// gera filhos
		for(int i=0;i!=moedas;i++) {
			
			// nao muda para a mesma moeda nunca
			if(i==s.moedas[s.mudancas-1]) {
				continue;
			}
			
			sequencia sn;
			copia(s,sn,i);

			// se for a mesma, checa para o fim, caso contrario, ignora
			if(i==sn.moedas[0]) {
//				cout << "comparando valor : " << i << " " << sn.valor << endl;
				if(sn.valor>=1.01) {
					for(int z=0;z!=sn.mudancas-1;z++) {
						cout << (sn.moedas[z] + 1) << " ";
					}
					cout << (sn.moedas[0] + 1);
					cout << endl;
					return;
				}
			} else if(sn.mudancas!=moedas+1) {
				lista.push_back(sn);
			}
			
		}
		
	}

	cout << "no arbitrage sequence exists" << endl;
	
	nextStep:
	moedas = 0;
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


