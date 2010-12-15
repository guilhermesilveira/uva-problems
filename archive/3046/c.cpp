#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

void st() {

	int tot = 0;
	char pal[2000][30];
	int len[2000];

	while(true) {
		if(!cin.getline(pal[tot],25)) break;
		if(strlen(pal[tot])==0 || pal[tot][0]=='\n' || pal[tot][0]=='\r') break;
		len[tot] = strlen(pal[tot]);
		if(pal[
		tot++;
	}

	int i,j,k,l1,l2,m,n;
	for(i=0;i!=tot;i++) {

		l1 = len[i];
		k = 0;

		for(j=0;j!=tot;j++) {

/*			if(i==j) continue;

			n = l1;
			if(n>len[j]) n = len[j];

			for(m=0;m!=n;m++) {
				if(pal[i][m]!=pal[j][m]) break;
			}
			if(k<m) {
				k = m;
				//cout << "ig: " << k << " com " << pal[j] << endl;
			}*/

		}

		cout << pal[i] << endl;
		cout << " ";

//		printf("%s ",pal[i]);
//		for(m=0;m!=k;m++) putchar(pal[i][m]);
		putchar('\n');


	}

}

int main() {

	int n;
	scanf("%d ",&n);
	while(n--) {
		st();
		if(n) cout << endl;
	}
	return 0;

}
