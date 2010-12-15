#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

	int n;
	char s[100];
int i,j,len;
	int val[10100];
	bool *v[10000];
	for(i=0;i!=10000;i++) v[i] = new bool[20100];

	while(true) {

cin >> s;
len = strlen(s);
for(i=0;i!=len;i++) if(s[i]==':') { s[i]='\0'; break;}
n = atoi(s);
if(!n) break;

for(i=0;i!=n;i++) scanf("%d",&val[i]);
int k;

for(i=1;i<n;i++) {
for(j=0;j<20100;j++) v[i][j]=0;
for(j=i+1;j<n;j++) {
	v[i][val[j]-val[i]+10000]=1;
}
}

printf("yes\n");
continue;
nao:
printf("no\n");


	}
	return 0;

}
