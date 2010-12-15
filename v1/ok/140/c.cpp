#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(a,b,c) for(int a=b;a<c;a++)

using namespace std;

int tot=0;
int ord[40];
bool us[40];
bool con[40][40];
bool ex[40];
int maxi;

int mel[40];

int dist(int a,int b) {
	FOR(i,0,40) {
		if(a==ord[i]) {
			FOR(j,0,40) {
				if(b==ord[j]) return abs(i-j);
			}
		}
	}
}

void tenta(int lev) {
	if(lev==tot) {
		int val = 0;
		FOR(i,0,40) {
			if(!ex[i]) continue;
			FOR(j,0,40) if(con[i][j]) val = max(val,dist(i,j));
		}
		if(val<maxi) {
			maxi = val;
			FOR(i,0,tot) mel[i] = ord[i];
		}
		return;
	}
	FOR(i,0,40) {
		if(us[i] || !ex[i]) continue;
		ord[lev] = i;
		us[i] = true;
		tenta(lev+1);
		us[i] = false;
	}
}

int main() {

	char s[10000];
	char c,c2;
	int len;
	while(true) {
		FOR(i,0,40) {
			FOR(j,0,40) con[i][j] = false;
			con[i][i] = true;
			us[i] = ex[i] = false;
		}
		gets(s);
		if(s[0]=='#') return 0;
		char *nod = strtok(s,";");
		while(nod) {
			c = nod[0];
			ex[c-'A'] = true;
			len = strlen(nod);
			FOR(i,2,len) {
				c2 = nod[i];
				if(c2<'A' || c2>'Z') continue;
				con[c-'A'][c2-'A'] = con[c2-'A'][c-'A']=true;
				ex[c2-'A'] = true;
			}
			nod = strtok(0,";");
		}
		tot = 0;
		FOR(j,0,30) if(ex[j]) tot++;
		maxi = tot + 10;
		tenta(0);
		//FOR(j,0,30) if(ex[j]) cout << (char)(j+'A') << " ";
		/*cout << endl;
		FOR(i,0,30) {
			if(!ex[i]) continue;
			FOR(j,0,30) if(ex[j]) cout << con[i][j] << " ";
			cout << endl;
		}*/
		FOR(j,0,tot) cout << (char)(mel[j]+'A') << " ";
		cout << "-> " << maxi << endl;
	}
	return 0;

}
