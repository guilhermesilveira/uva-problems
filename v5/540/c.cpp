#include <iostream>
#include <stdlib.h>

#define REP(a,b) for(int a=0;a<b;a++)

using namespace std;

int **time,n;
int tot[1001];

int tim(int v) {
	REP(i,n) REP(j,tot[i]) if(v==time[i][j]) return i;
}

int main() {

	int fs,fe;
	int fila[1001];

	int ja[200000];
	int jatot = 0;

	time = (int **) malloc (sizeof(int *)*1001);
	char s[200];
	REP(i,1001) time[i] = new int(1001);
	int k,l;
	while((cin >> n)) {
		fs = fe = 0;
		REP(i,n) tot[i] = 0;
		REP(i,n) {
			cin >> tot[i];
			REP(j,tot[i]) cin >> time[i][j];
		}
		while(1) {
			cin >> s;
			if(s[0]=='S') break;
			if(s[0]=='E') {
				cin >> k;
				l = tim(k);
				
			} else if(s[0]=='D') {
				
			}
		}
	}

	return 0;

}
