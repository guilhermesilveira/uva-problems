#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)
#define VAL 0

int main() {

	int n = 0;
	int i,w;
	unsigned long long k;
	unsigned long long *vk = new unsigned long long[500001];
	int *v[500001];
	FOR(i,500001) v[i] = (int *) malloc(sizeof(int)*3);

	while((scanf("%d",&n)) && n) {
		k = 0;
		FOR(i,n) { v[i][1] = v[i][2] = -1; vk[i] = 0; }
		FOR(w,n) {
			scanf("%d",&v[w][VAL]);
			i = 0;
			while(i!=w) {
				if(v[i][VAL]<v[w][VAL]) {
					vk[i]++;
					if(v[i][2]==-1) { v[i][2] = w; i = w; }
					else i = v[i][2];
				} else if(v[i][VAL]>v[w][VAL]) {
					k++;
					// soma quantos estao a direita dele
					k+=vk[i];
					if(v[i][1]==-1) { v[i][1] = w; i = w; }
					else i = v[i][1];
				}
			}
		}
		printf("%Lu\n",k);
	}
	return 0;

}
