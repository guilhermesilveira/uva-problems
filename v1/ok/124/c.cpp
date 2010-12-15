#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

char var[50];
int vtot = 0;
int res[100][2];
int rtot;

bool us[50];
int cam[50];

void imp() {
	for(int i=0;i!=vtot;i++) putchar(var[cam[i]]);
	putchar('\n');
}

void tenta(int lev) {
	int i,j,k;
	if(lev==vtot) {
		imp();
		return;
	}
	FOR(i,vtot) {
		if(us[i]) continue;
		FOR(j,rtot) if(res[j][1]==i && !us[res[j][0]]) goto f;
		us[i] = true;
		cam[lev] = i;
		tenta(lev+1);
		us[i] = false;
	f:;
	}
}

int f(char c) {
	for(int i=0;i!=vtot;i++) if(var[i]==c) return i;
	int i = 1/0;
}

int main() {

	char s[1000];
	int i;
	int t=0;
	while(gets(s)) {
		if(t) putchar('\n');
		t=1;
		FOR(i,50) us[i] = false;
		vtot = rtot = 0;
		char *n = strtok(s," ");
		while(n) {
			var[vtot++] = n[0];
			n = strtok(0," ");
		}
		sort(var,&var[vtot]);
		gets(s);
		n = strtok(s," ");
		while(n) {
			res[rtot][0] = f(n[0]);
			n = strtok(0," ");
			res[rtot++][1] = f(n[0]);
			n = strtok(0," ");
		}
		tenta(0);
	}

}
