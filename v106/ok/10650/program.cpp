#include <iostream>
#include <vector>
#include <assert.h>

int pr[4000];

using namespace std;

int main() {
	
	int a,b,c,dif,p=1,e,primeiro;
	pr[0]=2;
	for(a=3;a!=36001;a++) {
		for(b=0;b!=p;b++) if(a%pr[b]==0) goto nao;
		pr[p++]=a;
		nao:;
	}
	vector<int> pz;

	while(true) {
		
		cin >> a >> b;
		if(a==0 && b==0) break;
		
		if(a>b) {
			c = b;b=a;a=c;
		}
		
		for(c=0;pr[c]<a;c++);
		
		int count = 0;
		// comecando em cada c possivel, ate faltar no minimo 2
		for(;pr[c]<b && c<=p-2 && pr[c+1]<=b && pr[c+2]<=b;c++) {
			dif = pr[c+1] - pr[c];
			if(pr[c+2]-pr[c+1]!=dif) {
				continue;
			}
			if(c!=0 && pr[c]-pr[c-1]==dif) {
				continue;
			}
			pz.clear();
			pz.push_back(pr[c]);
			pz.push_back(pr[c+1]);
			pz.push_back(pr[c+2]);
			e = c+3;
			while(e<p && pr[e]-pr[e-1]==dif && pr[e]<=b) {
				pz.push_back(pr[e++]);
			}
			c = e - 2;
			// verifico se o proximo primo tambem eh valido
			if(pr[c+2]-pr[c+1]!=dif) {
				for(e=0;e!=pz.size()-1;e++) {
					cout << pz[e] << " ";
				}
				cout << pz[e] << endl;
				count++;
			}
			prox:;
		}
		
	}
	
	
}
