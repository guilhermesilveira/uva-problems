#include <stdio.h> 
#include <iostream> 
#include <string> 

using namespace std;

inline void contem(string str1,string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int maximal = 0;
	for(int inicial=0;inicial!=len2;inicial++) {
		int maximoAchados = 0;
		int ultimoAchado = 0;
		for(int i=inicial;i<=len2;i++) { 
			for(int z=ultimoAchado;z!=len1;z++) {
				if(str1[z]==str2[i])  {
					ultimoAchado = z + 1;
					maximoAchados++;
					// achou este cara, continua
					break;
				}
			}
		} 
		if(maximoAchados>maximal) maximal = maximoAchados;
	}
	cout << maximal << endl;
}

inline int soma(string s) {
	int total = s.length();
	int soma = 0;
	for(int i=0;i!=total;i++) {
		if(s[i]>='a' && s[i]<='z') s[i]-=32;
		if(s[i]>='A' && s[i]<='Z') {
			soma+=s[i]-'A'+1;
		}
	}
	//cout << s << soma << endl;
	while(soma>=10) {
		int tempSoma = soma;
		soma = 0;
		while(tempSoma!=0) {
			soma+=tempSoma%10;
			tempSoma/=10;
		}
	}
	//cout << soma << endl;
	return soma;
}

int main() {
	string str1;
	string str2;
	// para cada conjunto de nomes
	while(cin >> str1 >> str2) { 
		// passa caracter a caracter para calcular o valor
		float soma1 = soma(str1);
		float soma2 = soma(str2);
		float total = 0;
		if(soma1==0 && soma2==0) {
			total = 0;
		} else if(soma1==0 || soma2==0) {
			total = 0;
		} else {
			total = soma1>soma2?soma2/soma1:soma1/soma2;
		}
		printf("%.2f %%\n",total*100);
	}
	return 0; 
}
