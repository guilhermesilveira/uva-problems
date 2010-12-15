#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

char l[100][103];
int n;

void reverse(char *c1,char *c2) {
	int len = strlen(c1);
	if(c1[len-2]=='\r') {
		c2[len-2] = c1[len-2];
		c2[len-1] = c1[len-1];
		len -= 2;
	} else if(c1[len-1]=='\n') {
		c2[len-1] = c1[len-1];
		len--;
	}
	int mid = len%2==0 ? len/2-1 : len/2;
	for(int i=0;i<=mid;i++) {
		c2[i] = c1[len-i-1];
		c2[len-i-1] = c1[i];
	}
	c2[len] = '\0';
}

bool verifica(int y,int x,char *s,int dx,int dy,int len) {
	for(int i=0;i!=len;i++) {
		if(s[i]!=l[y+dy*i][x+dx*i]) {
			return false;
		}
	}
	return true;
}

bool procura(int y,char *s,int dx,int dy) {
	int len = strlen(s);
	len--;
	if(y + dy*len < 0) return false;
	if(y + dy*len > n) return false;
	for(int x=0;x!=n;x++) {
		if(x + dx*len < 0) continue;
		if(x + dx*len > n) continue;
		if(verifica(y,x,s,dx,dy,len+1)) {
			cout << y+1 << "," << x+1 << " " << (y+dy*(len)+1) << "," << (x+dx*(len)+1) << endl;
			return true;
		}
	}
	return false;
}

int main() {
	int i,j,k;
	char s[103];
	cin >> n;
	while(true) {
	//	cout << n << endl;
		if(n==0) return 0;
		for(i=0;i!=n;i++) { scanf(" %s",l[i]); }
		while((scanf(" %s",&s))==1) {
			if(s[0]>='0' && s[0]<='9') goto na;
//			cout << "procurando " << s << endl;
			//reverse(s,r);
			for(i=0;i!=n;i++) {
/*				if((strstr(l[i],s))!=NULL) {
					k = strlen(l[i]) - strlen(strstr(l[i],s));
					cout << (k+1) << "," << i+1 << " " << (k+strlen(s)) << "," << i+1 << endl;
					goto p;
				}
				if((strstr(l[i],r))!=NULL) {
					k = strlen(l[i]) - strlen(strstr(l[i],r));
					cout << (k+strlen(s)) << "," << i+1 << " " << (k+1) << "," << i+1 << endl;
					goto p;
				}*/
				if(procura(i,s,1,0)) goto p;
				if(procura(i,s,-1,0)) goto p;
				if(procura(i,s,0,1)) goto p;
				if(procura(i,s,0,-1)) goto p;
				if(procura(i,s,-1,-1)) goto p;
				if(procura(i,s,1,1)) goto p;
			}
			cout << "Not found" << endl;
			p:;
		}
		na:;
		n = atoi(s);
	}
	return 0;
}
