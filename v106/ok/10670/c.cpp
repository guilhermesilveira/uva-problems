#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Agencia {
	public:
	char n[30];
	int mini;
};

bool comp(const Agencia &a1,const Agencia &a2) {
	if(a1.mini!=a2.mini) return a1.mini<a2.mini;
	return strcmp(a1.n,a2.n)<=0;
}

int main() {
	
	int i,j,k,l,t;
	cin >> t;
	int inst = 0;
	long a,b,n2,n,m,v1,v2;
	char c;
	while(t--) {
		cout << "Case " << ++inst << endl;
		cin >> n2 >> m >> l;
		vector<Agencia> v;
		for(j=0;j!=l;j++) {
			
			n = n2;
			Agencia ag;
			scanf(" %[^:]:%ld,%ld",ag.n,&a,&b);
			
			long long mini = 0;
			if(a==0) goto f;
			if(b==0) {
				while(n>=m*2) n/=2;
			}
			if(n==m) goto f;
			
			while(n!=m) {
				if(n<m*2) {
					// so da para pegar de 1 em 1!!!
					mini += (n-m) * a;
					n=m;
				} else {
					// vale mais a pena com qual dos dois?
					v1 = (n/2) * a;
					if(n%2) v1 += a;
					v2 = b;
					if(v1<v2) {
						mini += v1;
					} else {
						mini += v2;
					}
					n /= 2;
				}
			}
			
			f:
			ag.mini = mini;
			v.push_back(ag);
			
			
		}
		sort(v.begin(),v.end(),comp);
		for(i=0;i!=l;i++) {
			Agencia ag = v[i];
			cout << ag.n << " " << ag.mini << endl;
		}
	}
	
	return 0;
	
}
