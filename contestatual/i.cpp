#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

bool ispal(char *c,int l) {
	int i;
	i=0;
	FOR(i,l) if(c[i]!=c[l-1-i]) return 0;
	return 1;
}

bool isnumer(char *c,int l) {
	int i;
	FOR(i,l) if(c[i]<'0' || c[i]>'9') return 0;
	return 1;
}

bool isstr(char *c,int l) {
	int i;
	FOR(i,l) if(c[i]<'a' || c[i]>'z') return 0;
	return 1;
}

bool csp(char *c) {
	int a = 0;
	bool l = 0;
	while(*c!='\0') {
		if(*c==' ' && l) return 0;
		if(*c==' ') {
			//cout << "achei 1" << endl;
			l=1;
			a++;
			if(a>2) return 0;
		} else {//cout << c << " ";
			l=0;
		}
		c++;
	}
	//cout << "achei tot " << a << endl;
	if(a!=2) return 0;
	return 1;
}

int main() {

	int i,j,k;
	char linha[30000];
	char a[30000],b[30000],m[30000];
	int v;
	char o[7];
	int l1,l2,l3;

	int let1[200],let2[200];

	while((gets(linha))) {

		//cout << "\t\t" << linha << endl;
		l3 = strlen(linha);
		while(linha[l3-1]=='\r' || linha[l3-1]=='\n') l3--;
		linha[l3] = '\0';
		if(sscanf(linha,"%s %s %s",&a,&m,&b)!=3) {
			FOR(i,7) o[i]='F';
			goto t;
		}

		//cout << a << " " << v << " " << b << endl;

		FOR(i,7) o[i]='T';
		l1=strlen(a); l2 = strlen(b);
		if(!isnumer(m,strlen(m))) {
			FOR(i,7) o[i]='F';
			goto t;
		}
		sscanf(m,"%d",&v);

		if(!isstr(a,l1) || !isstr(b,l2) || !csp(linha) || l1>1000 || l2>1000 || v<0 || v>1000) {
			FOR(i,7) o[i]='F';
			goto t;
		}

		if(!ispal(b,l2)) o[1]='F';
		FOR(i,200) let1[i]=let2[i]=0;
		FOR(i,l1) let1[a[i]]++;
		FOR(i,l2) let2[b[i]]++;
		FOR(i,200) if(let1[i] && !let2[i]) o[2]='F';
		FOR(i,200) if(let1[i] && let2[i] && let1[i]>let2[i]) o[3]='F';

		j=0;
		FOR(i,l1) {
			while(j!=l2 && b[j]!=a[i]) j++;
			if(j==l2) { o[4]='F'; break; }
			j++;
		}
		

		if(l1+v!=l2) o[5]='F';
		if(v>=l1) o[6]='F';

		t: cout << o << " ";
		FOR(i,7) if(o[i]=='F') { cout << "The solution is not accepted" << endl; goto n; }
		if(i==7) cout << "The solution is accepted" << endl;
n:;
	}

}
