#include <stdio.h> 
#include <iostream> 
#include <string> 
#include <math.h>

using namespace std;

unsigned long calcula(unsigned long &int1,unsigned long &int2, int nivel) {
	long double pp = pow(2.0,nivel);
	unsigned long long p = (unsigned long long) pp;
	if(int1>=p) {
		if(int2>=p) {
			//cout << "duplo ignorado " << p << endl;
			int1-=p;
			int2-=p;
			return 0;
		} else {
			//cout << int1 << " e " << int2 << " adicionando " << (p) << endl;
			int1-=p;
			return p;
		}
	}
	if(int2>=p) {
		//cout << int1 << " e " << int2 << " adicionando " << (p) << endl;
		int2-=p;
		return p;
	}
	return 0;
}

int main() {
	unsigned long int2;
	unsigned long int1;
	while(cin >> int1 >> int2) { 
		unsigned long resultado = 0;
		if(int1!=int2) {
			for(int i=31;i!=-1;i--)  {
				resultado += calcula(int1,int2,i);
			}
		}
		cout << resultado << endl;
	}
	return 0; 
}
