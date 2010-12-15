#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

char ja[1100][1100];
int minas, r, c;

typedef struct P {
	int x,y;
	int z;
};

P *rec[100000];
int recC = 0;

#define n() (recC!=0 ? rec[--recC] : new P() );

P *novoP(int y,int x,int z) {
	P *p = n();
	p->y = y;
	p->x = x;
	p->z = z;
	return p;
}

P *novoP2(P *po,int y,int x) {
	P *p = n();
	p->y = po->y + y;
	p->x = po->x + x;
	p->z = po->z + 1;
	return p;
}

#define frz(p) if(recC!=100000) rec[recC++] = p;

P *q[1000001];
int qe;
int qs;

#define push(p) q[qe++]=p
#define pop() q[qs++]
#define empty() (qs==qe)

void comeca(int sr, int sc, int fr, int fc) {
	
	qe = 0;
	qs = 0;
	push(novoP(sr,sc,0));
	
	while(!empty()) {
		
		P* p = pop();
		
		if(p->x == fc && p->y == fr) {
			cout << p->z << endl;
			return;
		}
		
		if(p->y!=0 && ja[p->y-1][p->x]==0) {
			ja[p->y-1][p->x]=1;
			P *pn = novoP2(p,-1,0);
			push(pn);
		}

		if(p->y!=r-1 && ja[p->y+1][p->x]==0) {
			ja[p->y+1][p->x]=1;
			P *pn = novoP2(p,+1,0);
			push(pn);
		}

		if(p->x!=0 && ja[p->y][p->x-1]==0) {
			ja[p->y][p->x-1]=1;
			P *pn = novoP2(p,0,-1);
			push(pn);
		}
		if(p->x!=c-1 && ja[p->y][p->x+1]==0) {
			ja[p->y][p->x+1]=1;
			P *pn = novoP2(p,0,+1);
			push(pn);
		}
		
		frz(p);
		
	}
	
}

int main() {
	
	int so;
	int d,e;
	int i,j;
	int a,b,t;

	while(true) {
		
		cin >> r >> c;
		if(r==0 && c==0) return 0;
		
		for(i=0;i!=r;i++) {
			for(int j=0;j!=c;j++) {
				ja[i][j] = 0;
			}
		}
		
		cin >> minas;
		for(i=0;i!=minas;i++) {
			cin >> a >> t;
			for(j=0;j!=t;j++) {
				cin >> b;
				ja[a][b] = 1;
			}
		}
		
		cin >> a >> b >> d >> e;
		comeca(a,b,d,e);

	}

	return 0;
	
}

