#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int lin;
char map[100][100];
int len[100];

void doIt(int y,int x) {
	if(y<0 || x<0 || y==lin || x==len[y]) return;
	if(map[y][x]!='*' && map[y][x]!=' ') return;
	map[y][x]='#';
	doIt(y-1,x);
	doIt(y+1,x);
	doIt(y,x-1);
	doIt(y,x+1);
} 

void st() {	
	int astx,asty;
	lin = 0;
	while((gets(map[lin]))) {
		len[lin] = strlen(map[lin]);
		if(map[lin][len[lin]-1]=='\n') {
			map[lin][len[lin]-1]='\0';
			len[lin]--;
		}
		if(map[lin][0]=='_') break;
		lin++;
	}
	for(asty=0;asty!=lin;asty++) {
		for(astx=0;astx!=len[asty];astx++) {
			if(map[asty][astx]=='*') {
				doIt(asty,astx);
				goto f;
			}
		}
	}
	f:;
	for(asty=0;asty!=lin;asty++) cout << map[asty] << endl;
	cout << map[lin] << endl;
}
int main() {
	int t;
	char s[30];
	gets(s);
	t = atoi(s);
	while(t--) st();
	return 0;
}
