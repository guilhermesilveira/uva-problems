#include <iostream>

using namespace std;

int n,m,mini;

int conexoes[36][36];
int cc[36];

#define SIM 1
#define NAO 0
#define UNK 2

char tem[36];

void tenta(int p) {

	while(tem[p]!=UNK && p<=n) {
		p++;
	}
	
	//cout << "novo p: " << p << endl;

	if(p>n) {
		int k = 0;
		// parei, conta e termina, se tem algum UNK, para
		for(int i=1;i<=n;i++) {
			if(tem[i]==SIM) k++;
			if(tem[i]==UNK) return;
		}
		cout << "fim valido: "<< k << endl;
		if(k < mini) {
			mini = k;
			cout << "novo: " << mini <<endl;
			for(int i=1;i<=n;i++) {
				if(tem[i]==SIM) cout << i << endl;
			}
		}
		return;
	}

	// vou tentar marcar como SIM
	tem[p] = SIM;
	int volta[36];
	int voltac = 0,i;
	for(i=0;i!=cc[p];i++) {
		//conexoes[p][i]
		if(tem[conexoes[p][i]]==UNK) {
			volta[voltac++] = conexoes[p][i];
			tem[conexoes[p][i]] = NAO;
		}
	}
	tenta(p+1);
	for(i=0;i!=voltac;i++) {
		tem[volta[i]] = UNK;
	}
	
	// vou tentar marcar como NAO
	//tem[p] = NAO;
	//tenta(p+1);

	// vou voltar
	tem[p] = UNK;

}

int main() {

	int i,j,b;

	while((cin >> n>>m)) {

		if(n==0 && m==0) break;

		for(i=1;i<=n;i++) {
			for(j=0;j<=36;j++) conexoes[i][j] = 0;
			cc[i] = 0;
			tem[i] = UNK;
		}

		for(i=0;i!=m;i++) {
			cin >> j >> b;
			conexoes[j][cc[j]++] = b;
			conexoes[b][cc[b]++] = j;
		}

		mini = n;

		tenta(1);

		cout << mini << endl;

	}

}
