#include <iostream>

using namespace std;

int main() {

	int a,b,i,j,k,l,tot;
	bool v[110];
	while((cin >> a >> b)) {

		if(!a && !b) break;

		tot = a;
		for(i=0;i!=a;i++) v[i] = true;

		int at = -1;

		int z = 0;

		while(tot!=1) {

			at++;
			if(at==a) at = 0;
			if(v[at]) z++;

			if(z==b) {
				v[at] = false;
				cout << "kill " << at << endl;
				// acha o cara da esquerda
/*				while(true) {
					at++;
					if(at==a) at = 0;
					if(v[at]) break;
				}*/
				//cout << "esq: " << at << endl;
				tot--;
				z = 0;
			}

		}

		for(i=0;i!=b;i++) if(v[i]) break;

		cout << (i+1) << endl;

	}

}
