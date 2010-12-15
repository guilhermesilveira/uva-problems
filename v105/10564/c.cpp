#include <iostream>
#include <stdio.h>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

bool f;
int n, linha[100][100],linhas,t[100];
char pr[500];
int s;

long maneiras[100][100][200];

int sp;

long start(int y,int x,int tot) {
	
	if(x==-1 || x==t[y]) return 0;
	
	tot += linha[y][x];
	if(tot>s) return 0;
	
	if(maneiras[y][x][tot]!=-1) {
		// ja calculei aqui....
		return maneiras[y][x][tot];
	}
	
	if(y==linhas-1) {
		if(tot==s) {
			f = true;
		}
		return;
	}
	
	int v = 0;
	if(!f) pr[y]='L';
	if(y+1<n) v = start(y+1,x-1,tot);
	else v = start(y+1,x,tot);
	
	if(!f) pr[y]='R';
	if(y+1<n) v += start(y+1,x,tot);
	else v += start(y+1,x+1,tot);
	
	maneiras[y][x][tot] = v;
	
	return v;
	
}

int main() {
	
	while((cin >> n >> s)) {
		if(n==0 && s==0) break;
		linhas = 0;
		int i,j,k;
		for(i=n;i!=0;i--) {
			t[linhas] = i;
			FOR(j,i) cin >> linha[linhas][j];
			linhas++;
		}
		for(i=2;i<=n;i++) {
			t[linhas] = i;
			FOR(j,i) cin >> linha[linhas][j];
			linhas++;
		}
		FOR(i,linhas) {
			FOR(j,t[i]) cout << linha[i][j] << " ";
			cout << endl;
		}
		FOR(i,linhas) FOR(j,t[i]) FOR(k,200) maneiras[i][j][k]=-1;
		f = false; long val = 0; int v = 0;
		FOR(i,n) {
			bool b = f;
			sp = i;
			val += start(0,i,0);
			if(!b && f) v = i;
		}
		cout << val << endl;
		pr[linhas] = '\0';
		if(val!=0) cout << v << " " << pr;
		cout << endl;
	}
	return 0;
	
}
