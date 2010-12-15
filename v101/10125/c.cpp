// 10125
// procurando uma soma exata de tres inteiros pertencentes a S para com um inteiro pertencente a S

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


	int n,i,j,k,u;
	long v,alvo,t;
	vector<long> s;

	while((cin >> n) && n) {

		s.clear();
		for(i=0;i!=n;i++) {
			cin >> v;
			s.push_back(v);
		}

		// nao
		if(i<4) goto n;

		// ordena
		sort(s.begin(),s.end());

		for(k=n-1;k>=0;k--) {
			alvo = s[k];
			for(i=0;i<k;i++) {
				v = s[i];
				for(j=i+1;j<k;j++) {
					//if(v+s[j] > alvo) break;
					t = v + s[j];
					t = alvo - t;
					cout << "para " << k << endl;
					if(binary_search(s.begin()+j+1,s.end(),t)) {
						cout << alvo << endl;
						goto f;
					}
				}
			}
		}
n:

	cout << "no solution" << endl;
	f:;
		

	}
	return 0;

}
