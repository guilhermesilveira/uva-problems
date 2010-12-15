#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)

int b[100],g[100],s[100];
char st[1000000];

#define LIMPA(z,ar) FOR(z,n) ar[z]=0;

int main() {

	int n;
	int i,j,k,l,q;

	int lgame;
	int lset;
	

	while(scanf("%d %s",&n,st)==2) {
		
		if(n>80) { cout << n << " ERRO COM TIMES" << endl; exit(0); }
l=strlen(st);	
FOR(i,n) b[i]=g[i]=s[i]=0;
lgame=lset=0;

//cout << endl << n << endl;
FOR(i,l) {
	q = st[i] - 'A';

	int maiork = 0;
	if(b[q]==3) {
		FOR(j,n) if(q!=j && b[j]>2) goto cont;
		// q: ganhei o game
		g[q]++;
		LIMPA(j,b);
		goto nex;
	}
	cont:;
	if(b[q]==4) {
		// q: ganhei o game
		g[q]++;
		LIMPA(j,b);
		goto nex;
	}

	// se tem alguem com 4, diminui ele
	FOR(j,n) if(b[j]==4) { b[j]=3; goto nex; }

	// ganhei o ball
	b[q]++;
	
	nex:;
	// se alguem ganhou 6
	FOR(j,n) if(g[j]==6) {

			q = 0;
			FOR(k,n) if(j!=k && g[k]) q = 1;
			if(q==0) s[j]++;

			s[j]++;
			LIMPA(j,g);
			goto mat;

	}
	
	FOR(j,n) if(g[j]>g[maiork]) maiork=j;

	q=0;
	FOR(j,n) if(j!=maiork && g[j]>q) q=g[j];
	if(g[maiork]-g[j]>=2) {
		FOR(k,n) if(maiork!=k && g[k]) break;
		if(k==n) s[maiork]++;
		s[maiork]++;
		LIMPA(j,g);
	}

	mat:;
	FOR(j,n) {
		if(s[j]>=3) {
			cout << (char)(j+'A') << endl;
			goto fim;
		}
	}

	/*FOR(j,n) {
		cout << g[j] << " ";
	} cout << endl;
	FOR(j,n) {
		cout << s[j] << " ";
	} cout << endl << endl;*/
	

}


fim:;
	}
	return 0;
}
