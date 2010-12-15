#include <iostream>
#include <string>

using namespace std;

#define poe(u) val[maxi++] = u;

int main() {

	int n,x,p[21],i,j,k,l,c = 1,b[51],val[51],maxi;
	while((cin >> n >> x)) {
		for(i=0;i!=20;i++) { cin >> p[i]; }
		for(i=0;i!=n;i++) {b[i]=0;}
		cout << "Selection #" << c++ << endl;
		if(n==x) goto imp;
		l = n;
		maxi=0;
		for(i=0;i!=20;i++) {
			k = 0;
			while(k < n) {
				j = p[i];
				while(j!=0) {
					if(k>=n) goto ne;
					if(b[k]==0) { j--; }
					if(j==0) break;
					else k++;
				}
				b[k]=-1;
				if(--l==x) goto imp;
			}
			ne:;
		}
		imp:
		for(i=0;i!=n;i++) {
			if(b[i]==0) {
				poe(i);
			}
		}
		for(i=0;i<maxi-1;i++) cout << (val[i]+1) << " ";
		cout << (val[maxi-1]+1) << endl;
		maxi = 0;
		cout << endl;
	}

	return 0;

}
