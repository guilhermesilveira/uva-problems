#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class objeto {
public:
	int peso;
	int preco;
};

int n;
objeto o[1000];
long mm[50];
int g;
long m;

long packit(int maximo) {

	long t[135],i,j,k,ms;
	for(i=0;i!=135;i++) t[i] = -1;
	t[0] = 0;
	for(i=0;i!=n;i++) {
		for(j = 40 - o[i].peso; j >= 0; j--) {
			if(t[j] != -1 && t[j+o[i].peso] < t[j] + o[i].preco) {
				t[j+o[i].peso] = t[j] + o[i].preco;
			}
		}
	}
	ms = 0;
	for(i=0;i<=maximo;i++) {
		if(ms < t[i]) ms = t[i];
	}
	mm[maximo] = ms;
	return ms;
	
}

int comp(const void *a,const void *b) {
	objeto *o1 = (objeto *) a;
	objeto *o2 = (objeto *) b;
	return o1->peso < o2->peso;
}

int main() {

	long t,i,j,k;
	cin >> t;
	while(t--) {
		cin >> n;
		for(i=0;i!=n;i++) {
			cin >> o[i].preco >> o[i].peso;
		}
		//qsort(o,n,sizeof(o[0]),comp);
		for(i=0;i<=40;i++) {
			mm[i] = -1;
		}
		cin >> g;
		m = 0;
		for(i=0;i!=g;i++) { 
			cin >> j; 
			if(mm[j]!=-1) {
				m += mm[j];
			} else {
				m += packit(j);
			}
			
		}
		cout << m << endl;
	}
	return 0;

}
