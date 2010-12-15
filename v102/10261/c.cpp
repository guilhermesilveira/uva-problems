#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define FOR(a,b) for(a=0;a<b;a++)
#define REP(a,b) for(int a=0;a<b;a++)

using namespace std;

char d[1000];
int le() {
	int v;
	/*gets(d);
	if(sscanf(d,"%d",&v)==1) return v;
	return -1;*/
	cin >> v;
	return v;
}

int fer[30000],pre[30000],ult[30000];

void st() {

	int tam = le() * 100;
	int v;
	int i,j,k = 0;
	FOR(i,tam+100) fer[i] = ult[i] = pre[i] = 0;
	fer[0] = -1;

	int total = 0;
	bool parei = 0;
	//cout << "comec" << endl;

	while((v=le())!=0) {

//		v /= 100;
		//cout << v << " " << total << endl;

		if(parei) continue; // se parou, ignora esse
		k++; // estamos no kesimo

		bool cabe = 0;
		for(i=tam-v;i>=0;i--) {

			// se nao ativado ignora
			if(!(fer[i])) continue;

			// se cabe na esquerda, tenta la
			if(i+v<=tam) {
				fer[i+v] = ult[i+v] = k;
				cabe = 1;
				pre[i+v] = i;
			}

			// se nao cabe na direita, tira daqui
			if((total-i)+v>tam) {
				fer[i] = 0;
			} else {
				cabe = 1;
			}

		}
		// se coube em algum lugar.... ok
		if(cabe) {
			total += v;
			//cout << "ad o " << k << endl;
		} else {
			k--;
			parei = 1;
		}

	}

	// sai imprimindo
#define DEBUG(a) a
DEBUG(
	FOR(i,tam+1) cout << fer[i] << " ";
	cout << endl;
	FOR(i,tam+1) cout << pre[i] << " ";
	cout << endl;
	FOR(i,tam+1) cout << ult[i] << " ";
	cout << endl;)


	// procura o k na lista
	FOR(i, tam+1) if(fer[i]==k) break;

	vector<int> li;
//	cout << i << endl;
	// agora roda o iterativo
	while(ult[i]!=0) {
/*		cout << "estamos em " << i << endl;
		cout << "vis: " << ult[i] << " " <<pre[i]<< " " << fer[i] << endl;*/
		li.push_back(ult[i]);
		i = pre[i];
	}

	cout << k << endl;

	for(i=1;i<=k;i++) {
		if(find(li.begin(),li.end(),i)!=li.end()) cout << "port" << endl;
		else cout << "starboard" << endl;
	}

}


int main() {

	int t = le();
	while(t--) {
		st();
		if(t) cout << endl;
	}

	return 0;

}
