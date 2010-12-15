#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

char mapa[300];


vector<string> dicionario;
vector<string> codes;
map<string,string> mapaDePalavras;

bool executaPara(int i) {

	if (i == codes.size()) {
		// executar o decode de outra maneira, letra a letra!!
		for (int q = 0; q != codes.size(); q++) {
			cout << mapaDePalavras[codes[q]];
			if (q != codes.size() - 1) {
				cout << " ";
			}
		}
		cout << "FIM" << endl;
		cout << endl;
		return true;
	}

	string p = codes[i];
	int pLength = p.size();

/*	if (mapaDePalavras[p]) {
		if (executaPara(i + 1))
			return true;
		return false;
	}*/

	vector<char> lista;
	for (int z=0;z!=dicionario.size();z++) {
		string c = dicionario[z];
		if (c.size() == pLength) {
			lista.clear();
			bool valid = true;
			for (int charCount = 0; charCount != pLength; charCount++) {
				if (mapa[p[charCount]]==0) {
					lista.push_back(p[charCount]);
					mapa[p[charCount]] = c[charCount];
				} else if (
					mapa[p[charCount]] != c[charCount]) {
					valid = false;
					break;
				}
			}
			if(valid) {
				mapaDePalavras[p]=c;
				if(executaPara(i+1)) return true;
				mapaDePalavras.erase(p);
			}
			for(int x=0;x!=lista.size();x++) {
				mapa[lista[x]]=0;
			}
		}
	}

	return false;
}
	
int main(char **argv,int argc) {
	
	char linha[82];
	int valor;
	cin >> valor;
	string p;
	for(int i=0;i!=valor;i++) {
		getline(cin,p);
		dicionario.push_back(p);
	}

	
	while(getline(cin,p)) {
		for (int i = 0; i != 260; i++) {
			mapa[i] = 0;
		}
		mapaDePalavras.clear();

		// executa o SPLIT AQUI EM CODES

		if (!executaPara(0)) {
			for (int q = 0; q != codes.size(); q++) {
				for (int w = 0; w != codes[q].size(); w++) {
					printf("*");
				}
				if (q != codes.size() - 1) {
					printf(" ");
				}
			}
			printf("\n");
	}

	}

}

