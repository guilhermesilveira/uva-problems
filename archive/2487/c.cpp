#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOR(a,b) for(int a=0;a<b;a++)

using namespace std;

char s[100];
char tit[100];

int n;
int mel[1000], pre[1000], quem[1000], quant[1000];

void getl(char *c) {
	gets(c);
	int i;
	for(i=strlen(c);i>=0;i--) if(c[i]!='\n' && c[i]!='\r' && c[i]!='\0') break;
	c[i+1] = '\0';
}

void imp(int p) {
	if(p==-1) {
		return;
	}
	if(pre[p]!=-1) imp(pre[p]);
	int dia = quem[p]+1;
	int q = quant[p];
	if(q==1)
		cout << "On day " << dia << " collect 1 lolly."  << endl;
	else
		cout << "On day " << dia << " collect " << q << " lollies."  << endl;
}

void zera() {
	FOR(i,300) { mel[i] = quant[i] = 0; quem[i] = pre[i]=-1;}
	n = 0;
}

int zz = 0;

void termina() {

	int maxi = 0;
	FOR(i,300) if(mel[i]>maxi) { maxi = mel[i]; }
	int pos = 0;
	FOR(i,300) if(mel[i]==maxi) { pos = i; break; }

	/*cout << "achado " << pos << endl;
	
	FOR(j,15) cout << mel[j] << " ";
	cout << endl;
	FOR(i,10) cout << pre[i] << " ";
	cout << endl;
	FOR(i,10) cout << quem[i] << " ";
	cout << endl;
*/
	if(zz++) cout << endl;

	if(maxi==1) 
		cout << "In " << tit << " 1 lolly can be obtained:" << endl;
	else
		cout << "In " << tit << " " << maxi << " lollies can be obtained:" << endl;

	imp(pos);
	zera();
}


int main() {

	zera();
	getl(s);
	strcpy(tit,s);
	while(true) {
		getl(s);
		if(s[0]=='#') { termina(); break; }
		else if(s[0]<'0'  || s[0]>'9') { termina(); strcpy(tit,s); continue; }
		else {
			int val,tem;
			sscanf(s,"%d %d", &val,&tem);
			int maior = 0, mdia = -1;
			FOR(j,n+1) if(mel[j]>maior) {
					mdia = j;
					maior = mel[j];
			}
			int novo = val + maior;
			//cout << val << " tempo: " << tem << endl;
			//cout << "maior: " << maior << " " << novo << endl;
			for(int j=n+tem;j<300;j++) {
				if(mel[j] < novo) {
					mel[j] = novo;
					pre[j] = mdia;
					quem[j] = n;
					quant[j] = val;
				}
			}
			//FOR(j,15) cout << mel[j] << " ";
			//cout << endl;
			n++;
		}
	}
	return 0;

}
