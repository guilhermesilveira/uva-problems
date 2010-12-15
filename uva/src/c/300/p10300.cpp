/* @JUDGE_ID: 39315ZN 10370 C++ "counting" */

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	
	unsigned long long int tamanho = 0;
	unsigned long long int qualidade = 0;
	
	int count;
	cin >> count;
	
	while(count--!=0) {
		
		int farmers = 0;
		cin >> farmers;
		
		unsigned long long int geral = 0;
		
		while(farmers--!=0) {
			cin >> tamanho;
			cin >> qualidade;
			cin >> qualidade;
			geral += (tamanho * qualidade);
		}
		
		cout << geral << endl;
		
	}
		
	return 0;
	
}
