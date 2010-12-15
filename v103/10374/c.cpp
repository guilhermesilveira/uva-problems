#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int dep, par;
char d[30][100];
int dp[30];
int vot[30];
char p[30][100];

char *getl(char *s) {
	gets(s);
	int len = strlen(s);
	while(len && (s[len-1]==13 || s[len-1]==10)) { s[--len]='\0'; }
	return s;
}

void st() {

	int i,j,k;
	dep = par = 0;
	scanf("%d\n",&dep);
	for(i=0;i<dep;i++) {
		getl(d[i]);
		getl(p[par]);
//		cout << d[i] << " - " << p[par] << endl;
		for(j=0;j<par;j++) {
			if(strcmp(p[j],p[par])==0) { dp[i] = j; goto nex; }
		}
		dp[i] = par++;
		nex:;
	}

	for(i=0;i!=par;i++) vot[i]=0;
	scanf("%d\n",&k);
	char s[200];
	while(k--) {
		getl(s);
		for(i=0;i<dep;i++) if(!strcmp(d[i],s)) { vot[dp[i]]++; break; }
	}

	int maxi = *max_element(vot,&vot[par]);
	int n = -1;
	for(i=0;i!=par;i++){
		if(vot[i]==maxi) {
			if(n!=-1) goto tie;
			else n = i;
		}
	}
	cout << p[n] << endl;
	return;

	tie:cout << "tie" << endl;
	

}

int main() {

	int t;
	scanf("%d\n",&t);
	while(t--) {
		st();
		if(t) cout << endl;}

	return 0;

}
