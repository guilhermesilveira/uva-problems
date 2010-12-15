#include <iostream>

using namespace std;

// onde esta o i
int esperando[21];
// quem esta na posicao i
int pos[21];
bool esperava[21];

int main() {

	int i,j,k,l,x;
	for(i=0;i!=20;i++) {
		esperava[i] = false;
		pos[i] = -1;
	}

	while(true) {
		cin >> x;
		if(x==99) break;
		esperando[x] = x;
		esperava[x] = true;
		pos[x] = x;
	}

	while((cin >> x)) {
		// o cara nessa posicao cai fora
		
	}

	for(i=0;i!=20;i++)
		if(esperava[i]) {
			cout << "Original position " << i;
			if(esperando[i]==-1) {
				cout << " did not park" << endl;
			} else {
				cout << " parked in " << esperando[i] << endl;
			}
		}

	return 0;

}
