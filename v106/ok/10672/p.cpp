#include <iostream>

using namespace std;

int n;
int pos[11000];
int pai[11000];
int filhosC[11000];

int main() {

	int t, k, z, j, tot, m;
	while((cin >> n)) {
		if(n==0) break;
//		cout << "novo" << endl;
		for(int i=0;i!=n;i++) {
			cin >> t >> k >> z;
			t--;
//			cout << "lendo " << t << " com " << z << " filhos" << endl;
			pos[t] = k;
			filhosC[t] = z;
			for(j=0;j!=z;j++) {
				cin >> k;
				k--;
				pai[k] = t;
			}
		}
		tot = n;
		m = 0;
		while(tot!=0) {
			for(j=0;j!=n;j++) {
				if(filhosC[j]==0) {
					//cout << "removendo " << j << endl;
					filhosC[j] = -1;
					tot--;
					filhosC[pai[j]]--;
					if(pos[j]==0) {
						pos[pai[j]] -= 1;
						m++;
					} else if(pos[j]>1) {
						pos[pai[j]] += (pos[j] - 1);
						m += (pos[j] - 1);
					} else if(pos[j]<=0) {
						pos[pai[j]] -= (1 - pos[j]);
						m += (1 - pos[j]);
					}
				} else if(filhosC[j]>0){
					//cout << j << " contem " << filhosC[j] << endl;
				}
			}
		}
		cout << m << endl;
	}

	return 0;
	
}
