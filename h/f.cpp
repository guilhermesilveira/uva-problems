#include <iostream>
#include <stdio.h>
#define FOR(a,b) for(a=0;a!=b;a++)
#define MAIOR(a,b) ((a)>(b)?a:b)

using namespace std;

int main() {
	
	int tot=0;
	int st = 0;
	int en = 'z'-'a';
	int val[15001][30];
	char pal[15001][15];
	int maxi[30];
	int i,j,k,len;
	FOR(i,30) maxi[i]=0;
	while((scanf("%s",pal[tot]))==1) {
//		cout << tot << "," << pal[tot] << endl;
		len = strlen(pal[tot]);
		for(i=st;i<=en;i++) { val[tot][i] = 0; }
		for(i=0;i!=len;i++) {
			val[tot][pal[tot][i]-'a']++;
		}
		for(i=st;i<=en;i++) {
			if(val[tot][i]>maxi[i]) {
				goto v;
			}
		}
		for(i=0;i!=tot;i++) {
			for(j=st;j<=en;j++) {
				if(val[i][j]<val[tot][j]) break;
			}
			if(j==en+1) {
				// englobou
				goto n;
			}
		}
		v:
		for(i=st;i<=en;i++) maxi[i]=MAIOR(maxi[i],val[tot][i]);
		tot++;
		n:;
	}
	for(i=0;i!=tot;i++) {
		printf("%s\n",pal[i]);
	}
	
	return 0;
	
}
