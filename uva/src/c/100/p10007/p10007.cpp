#include <iostream>
#include <map>

using namespace std;

map<unsigned long long int,unsigned long long int> i;

unsigned long long int calc(int n) {
	// eu ja tenho o de n-1
	// ele pode ser inserido antes e a arvore fica pra direita e pra esquerda
	// isto eh, duplica a arvore
	
}



int main(int argv, char **argc) {

	int max;	
	int n;
	i[1] = 1;
	max = 1;

	while(cin >> n) {

		if(n==0) break;
		
		if(n>max) {
			cout << "maior " << n << endl;
			for(int z=max+1;z!=n+1;z++) {
				i[z] = calc(z);
				cout << z << " " << i[z] << endl;
			}
			max = n;
		}

		cout << n << " " << i[n] << endl;

	}

	return 0;

}
