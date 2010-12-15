
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int n;
int cap[110];
int flu[110];
bool visitado[110];

int maxi[110][110];
int atu[110][110];
bool pos[110][110];

int sources, sinks;
int source[110];
int sink[110];
bool ehsink[110];

int p[250];
int plen;

bool procuraPath(int atual) {
	
	visitado[atual] = true;
	p[plen] = atual;
	plen++;

	// terminei?
	if(ehsink[atual]) {
		//cout << "eh" << endl;
		cout << "atual: ";
		for(int i=0;i!=plen;i++) {
			cout << p[i] << " ";
		}
		cout << endl;
		return true;
	}
	
	// para todos
	for(int i=0;i!=n;i++) {
		// eh possivel
		if(pos[atual][i] && !visitado[i]) {
			// esse canal esta com espaco ainda?
			if(maxi[atual][i]>atu[atual][i]) {
				// o node eh sink ou esta com espaco no node?
				if(ehsink[i] || flu[i]<cap[i]) {
					// beleza, podemos tentar ele
					if(procuraPath(i)) return true;
				}
			}
		}
	}
	
	visitado[atual] = false;
	plen--;
	return false;

}

int main() {

	while((cin >> n)) {
		int i,j,k;
		for(i=0;i!=n;i++) cin >> cap[i];
		for(i=0;i!=n;i++) {
			for(j=0;j!=n;j++) {
				maxi[i][j] = atu[i][j] = 0;
				pos[i][j] = false;
			}
		}
		long maior = 0;
		long total = 0;
		cin >> k;
		while(k--) {
			cin >> i >> j;
			i--; j--;
			//cout << "linkando " << i << " e " << j << endl;
			pos[i][j] = true;
			cin >> maxi[i][j];
			if(maxi[i][j]>maior) maior = maxi[i][j];
		}
		cin >> sources >> sinks;
		for(i=0;i!=sources;i++) {
			cin >> source[i];
			source[i]--;
		}
		for(i=0;i!=sinks;i++) {
			cin >> sink[i];
			sink[i]--;
			ehsink[sink[i]] = true;
		}
		
		while(true) {
			
			for(i=0;i!=sources;i++) {
				plen = 0;
				for(j=0;j!=n;j++) visitado[j] = false;
				if(procuraPath(source[i])) {
					goto continua;
				}
			}
			break;

			continua:

			int min = cap[p[0]]-flu[p[0]];
			int min2;
			cout << "min," << min << endl;

			for(i=1;i<plen;i++) {
				min2 = maxi[p[i-1]][p[i]]-atu[p[i-1]][p[i]];
				if(min2<min) min = min2;
				cout << p[i] << "," << p[(i-1)]<<"min," << min << endl;
				min2 = cap[p[i]]-flu[p[i]];
				if(min2<min) min = min2;
				cout << "min," << min << endl;
			}

			flu[p[0]] += min;
			for(i=1;i<plen;i++) {
				// atualiza todos eles
				flu[p[i]] += min;
				atu[p[i-1]][p[i]] += min;
				atu[p[i]][p[i-1]] = - atu[p[i-1]][p[i]];
			}

			total += min;
			cout << min << endl;

			for(int i=0;i!=1000000000;i++);

		}

		cout << total << endl;
		
	}
	return 0;
	
}
