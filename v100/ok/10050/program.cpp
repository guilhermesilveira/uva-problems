// 2.8.3

#include <iostream>
#include <vector>

using namespace std;

int days;
	
vector<int> dados;
bool passou[3651];

// 1, 6, 8, 13, 15, 20, 22
// ignora o resto 0 e 1

int passaPor(int i) {
	
		int total = 0;
		dados.push_back(i);
//		cout << "Iniciando com " << i << endl;
		
		int atual = i;
		while(atual<=days) {
			
			int resto = atual % 7;
			
			if(resto!=0 && resto!=6) {
				if(!passou[atual]) {
				//	cout << "valido " << atual << endl;
					total++;
					passou[atual] = true;
				}
			} /*else {
				cout << "ignorando " << atual << endl;
			}*/
			
			atual += i;
			
		}
		
		//cout << "+=" << total << endl;
		
		return total;
			
}

int main(char **args,int argv) {
	
	int testCases;
	cin >> testCases;
	
	while(testCases-- != 0) {
		
		cin >> days;
		
		int parties;
		cin >> parties;
		
		dados.clear();
		
		//cout << "novo" << endl;
		
		int total = 0;

		for(int i=0; i != 3651; i++ ) {
			passou[i] = false;
		}

		for(int i=0; i != parties; ) {

			// valor fica entre 1 e 100
			int valor;
			cin >> valor;
			
			// se for um dos ignoraveis, continua
			/*if( valor % 7 == 0) {
				continue;
			}*/
			
			// se um divisor dele ja apareceu antes, ignora esse pq soh vai repetir
			/*for(int z=0;z != dados.size(); z++) {
				if( valor % dados[z] == 0) {
					goto proximo;
				}
			}*/
			
			// caso contrario, adiciona ele na lista
			total += passaPor(valor);
			
			// continua
			proximo: i++;
			
		}
		
		cout << total << endl;
		
	}
	
	return 0;
	
}
