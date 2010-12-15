#include <stdio.h> 
#include <iostream> 
#include <string> 

using namespace std;

int checa(string str1,string str2,int i1,int i2,int len1,int len2) {
	int maximoAchados = 0;
	int ultimoAchado = i1;
	cout << "checando " << i1 << " " << i2 << endl;
	for(;i2<=len2;i2++) {
		for(int z=ultimoAchado;z!=len1;z++) {
			cout <<str1[z]<<" " << str2[i2]<<endl;
			if(str1[z]==str2[i2])  {
				// achou um cara, ve se eh melhor pegando ele ou nao
				int c = checa(str1,str2,ultimoAchado+1,i2,len1,len2);
				int c2 = checa(str1,str2,ultimoAchado, i2+1, len1,len2);
				if(c>c2) {
					// este cara eh melhor
					cout << "achados: "<<(maximoAchados+c)<<endl;
					return maximoAchados + c;
				} else {
					// nao vale a pena continuar com esse, sem ele eh melhor (c2)
					cout << "achados: "<<(maximoAchados+c2)<<endl;
					return maximoAchados + c2;
				}
			}
		}
	}
	exit(0);
	return maximoAchados;
}

inline void contem(string str1,string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int maximal = 0;
	for(int inicial=0;inicial!=len2;inicial++) {
		cout << "iniciando em " << str2[inicial] << endl;
		int maximoAchados = checa(str1,str2,0,inicial,len1,len2);
		if(maximoAchados>maximal) maximal = maximoAchados;
		cout << endl;
	}
	cout << maximal << endl;
}

int main() {
	string str1;
	string str2;
	while(getline(cin,str1)) { 
		getline(cin,str2);
		//cout << str1 << " e " << str2 << endl;
		contem(str1,str2);
	}
	return 0; 
}
