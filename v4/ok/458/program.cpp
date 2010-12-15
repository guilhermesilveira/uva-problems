#include <iostream>
#include <string>

using namespace std;

int main(char **argv,int argc) {

	string linha;
	long  size;
	long i;

	while((cin >> linha) != 0) {
	
		size = linha.size();
		for(i=0;i!=size;i++) {
			linha[i] = linha[i] - 7;
		}
		cout << linha << endl;
	
	}

	return 0;

}
