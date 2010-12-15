#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int alvo;
int cam[110];
int n;
char j[20][40];

void imprime() {
	for(int i=0;i!=alvo;i++) {
		cout << cam[i] << " ";
	}
	cout << endl;
	for(int i=0;i!=alvo;i++) {
		if(i!=0) printf(", %s",j[cam[i]]);
		else printf("%s",j[cam[i]]);
	}
	cout << endl;
}

void tenta(int selected,int ultimo) {

	if(selected==alvo) {
		imprime();
	}

	if(ultimo==n-1) return;
	
	ultimo++;

	// tenta com ele
	cam[selected] = ultimo;
	tenta(selected+1,ultimo);

	// tenta sem ele
	tenta(selected,ultimo);

}

int main() {

	char l[110];

	gets(l);

	int start = 1;
	int end = 0;

	int a,b;

	if(l[0]=='*') {
		end = -1;
	} else {
		if((sscanf(l,"%d %d",&a,&b))) {
			start = a; end = b;
		} else {
			sscanf(l,"%d",&a);
			start = end = a;
		}
	}

	n = 0;
	while(gets(j[n])) {
		n++;
	}

	if(end==-1) end = n;

	for(a=start;a!=end;a++) {
		alvo = a;
		cout << "Size " << alvo << endl;
		tenta(0,-1);
		cout << endl;
	}

	return 0;


}
