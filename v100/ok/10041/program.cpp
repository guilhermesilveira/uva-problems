#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(char **argv,int argc) {

	int casos;
	cin >> casos;
	while(casos--) {
		int vizinhos;
		long soma = 0;
		cin >> vizinhos;
		vector<int> relativos;
		for(int i=0;i!=vizinhos;i++) {
			int temp;
			cin >> temp;
		//	if(find(relativos.begin(),relativos.end(),temp)==relativos.end()) {
				relativos.push_back(temp);
		//	}
			soma += temp;
		}
		
		// divide soma por vizinhos
		long media;
		if(soma % vizinhos > (vizinhos/2.0)) {
			media = (soma / vizinhos) + 1;
		} else {
			media = (soma / vizinhos);
		}
		
		//cout << media << endl;
		
		soma = 0;
		for(int i=0;i!=relativos.size();i++) {
			soma += abs(relativos[i] - media);
		}
		
		cout << soma << endl;
		
	}

	return 0;

}
