#include <iostream>

using namespace std;

int main(char **argv,int argc) {

	int varCount;
	int valorAntigo;
	int valor;
	bool passado[3001];
	int diferenca;
	bool erro;
	int count;
	while((cin >> varCount)) {
		erro = false;
		for(int i=0;i!=3001;i++) {
			passado[i] = false;
		}
		if(varCount==0) {
			cout << "Not jolly" << endl;
			continue;
		} else if(varCount==1) {
			cin >> valor;
			cout << "Jolly" << endl;
			continue;
		}
		
		// pega a primeira
		cin >> valorAntigo;
		
		for(count=1;count!=varCount;count++) {
		
			// pega a proxima
			cin >> valor;
			
			if(erro) continue;
			
			// calcula a diferenca
			diferenca = (valor - valorAntigo);
			if(diferenca<0) {
				diferenca = 0 - diferenca;
			} else if(diferenca==0) {
				erro = true;
				continue;
			}
			
			if(diferenca>varCount-1) {
				erro = true;
				continue;
			}
			
			if(passado[diferenca]) {
				erro = true;
				continue;
			}

			// seta
			passado[diferenca]=true;
			valorAntigo = valor;
			
		}
		for(count=1;count!=varCount;count++) {
			if(passado[count]==false) {
				cout << "Not jolly" << endl;
				goto proximo;
			}
		}
		cout << "Jolly" << endl;
		proximo:
		count = count;
	}

	return 0;

}

/*
			if(passado[diferenca]) {
				// para aqui
				erro = true;
				continue;
			} else {
				passado[diferenca] = true;
				valorAntigo = valor;
			}
*/
