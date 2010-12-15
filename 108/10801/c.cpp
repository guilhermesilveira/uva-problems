#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int n,k;
int t[200];

#define FOR(z,a) for(int z=0;z<a;z++)
#define PR(v) cout << v
#define PRS(v) cout << v << " "
char l[1000];
bool vai[200][200];

long minimo[200];
bool v[200];

int TEMPO(int el,int de,int pa) {
	return abs(de-pa) * t[el];
}

void tenta(int at,long t) {

	v[at] = true;
	if(at==k) {
		return;
	}
	cout << at << " at " << t << endl;

	if(t!=0) t += 60;

	// ve quais elevadores para nesse
	FOR(i,n) {
		if(!vai[i][at]) continue;
		//PR("elevador " << i << endl);
		FOR(j,100) {
			if(v[j]) continue;
			if(!vai[i][j]) continue;
			if(minimo[j] <= t + TEMPO(i,at,j)) continue;
			minimo[j] = t + TEMPO(i,at,j);
		}
	}
	int m1 = -1;
	FOR(j,100) {
		if(v[j]) continue;
		if(m1==-1 || minimo[m1]>minimo[j]) {
			m1 = j;
		}
	}

	FOR(j,100) if(!v[j] && minimo[j]!=2<<10) cout << j << "=" << minimo[j] << " ";
	cout << endl;

	if(m1!=-1 && minimo[m1]!=2<<10) tenta(m1,minimo[m1]);
}

int main() {

	while((cin >> n >> k)) {

		cout << "START" << endl;
		FOR(i,n) { cin >> t[i]; }
		FOR(i,100) v[i] = false;
		cout << endl;
		FOR(i,n) FOR(j,100) vai[i][j] = false;
		scanf(" ");
		FOR(i,n) {
			cin.getline(l,1000);
			char *s = strtok(l," ");
			while(s) {
				int v = atoi(s);
				vai[i][v] = true;
				s = strtok(0," ");
			}
		}
		FOR(i,n) {
			FOR(j,51) PRS(vai[i][j]);
			PR(endl);
		}
		FOR(i,100) minimo[i] = 2 << 10;
		minimo[0] = 0;

		if(n!=0) tenta(0,0);

		FOR(i,100) if(minimo[i]!=2<<10) PRS(i << "=" << minimo[i]);
		PR(endl);

		if(v[k]==false) PR("IMPOSSIBLE" << endl);
		else PR(minimo[k] << endl);
	}
	return 0;

}
