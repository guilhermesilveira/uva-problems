#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int n,k,m,t,i,j;
	bool f[30];
	while((cin >> n >> k >> m)) {
		if(n==0 && k==0 && m==0) break;
		int falta = n;
		for(i=0;i<=n+1;i++) {
			f[i] = true;
		}
		f[0]=f[n+1]=false;
		int p1 = 0;
		int p2 = n+1;
		while(falta!=0) {
			i = j = 0;
			while(i!=k) {
				if(f[p1]) i++;
				if(i==k) break;
				p1++;
				if(p1>n) p1 = 1;
			}
			while(j!=m) {
				if(f[p2]) j++;
				if(j==m) break;
				p2--;
				if(p2==0) p2 = n;
			}
			if(p1==p2) {
				if(falta!=n) putchar(',');
				printf("%3d",p1);
				falta--;
				f[p1]=false;
			} else {
				if(falta!=n) putchar(',');
				printf("%3d%3d",p1,p2);
				falta-=2;
				f[p1] = f[p2] = false;
			}
		}
		putchar('\n');
	}
	return 0;
}


