#include <stdio.h>
#include <iostream>

using namespace std;

int d[6];
int v[430000];

void tenta() {
	
	int atual = 0, level = 0;
	int i,j,k,l,m,n,mm = 0, meio = 0;
	for(i=0;i!=6;i++) meio += d[i] * (i+1);
	if(meio % 2 == 1) {
		goto ne;
	}
	meio /= 2;
	for(i=0;i!=430000;i++) v[i] = -1;
	v[0] = 0;
	while(level!=6) {
		if(atual++==d[level]) {
			level++; atual = 0; continue;
		}
		for(i=mm;i>=0;i--) {
			if(v[i]!=-1) {
				v[i+level+1] = 0;
				if(mm<i+level+1 && m<meio) mm = i + level + 1;
				if(i+level+1==meio) {
					cout << "Can be divided." << endl;
					return;
				}
			}
		}
	}
	ne:
	cout << "Can't be divided." << endl;
	
}

int main(char **argv,int argc) {

	int j = 0, i;
	while(true) {
		for(i=0;i!=6;i++) cin >> d[i];
		for(i=0;i!=6;i++) if(d[i]!=0) break;
		if(i==6) break;
		

		
		cout << "Collection #" << ++j << ":" << endl;
		tenta();
		cout << endl;
	}

	return 0;

}
