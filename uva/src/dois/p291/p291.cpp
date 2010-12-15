// 88

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define ULTIMO (caras[caras.size()-1])

using namespace std;

vector<int> caras;
vector<int> passou;

void revoluciona();

void PROXIMO(int valor,int proximo) {
	if(find(passou.begin(),passou.end(),valor)==passou.end()) {
		caras.push_back(proximo);
		passou.push_back(valor);
		revoluciona();
		caras.erase(caras.end()-1);
		passou.erase(passou.end()-1);
	}
}

void revoluciona() {
	if(passou.size()==9) {
		for(int i=0;i!=caras.size();i++) {
			printf("%d",caras[i]);
		}
		cout << endl;
		return;
	}
	if(ULTIMO==1) {
		PROXIMO(12,2);
		PROXIMO(13,3);
		PROXIMO(15,5);
	} else if(ULTIMO==2) {
		PROXIMO(12,1);
		PROXIMO(23,3);
		PROXIMO(25,5);
	} else if(ULTIMO==3) {
		PROXIMO(13,1);
		PROXIMO(23,2);
		PROXIMO(34,4);
		PROXIMO(35,5);
	} else if(ULTIMO==4) {
		PROXIMO(34,3);
		PROXIMO(45,5);
	} else if(ULTIMO==5) {
		PROXIMO(15,1);
		PROXIMO(25,2);
		PROXIMO(35,3);
		PROXIMO(45,4);
	}
}

void estarta(int z) {
	caras.push_back(z);
	passou.push_back(z*10);
	revoluciona();
	caras.erase(caras.end()-1);
	passou.erase(passou.end()-1);
}

int main(int argc, char **argv) {

	estarta(1);
	return 0;
	
}
