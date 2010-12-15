#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int p,pp;

bool pintado[10001][2];

class Node {
public:
	int id;
	int tot;
	Node *link[10001];
	char eh;
	void clear(int id,char v) {
		this->id = id;
		tot = 0;
		this->eh = v;
	}
	void make(Node *n) {
		this->link[this->tot++] = n;
	}
	bool pinta() {
		cout << "pinta: " << id << "," << eh << endl;
		for(int i=0;i!=tot;i++) {
			if(link[i]->ispintadoOutro()) {
				// nao pode!!!
				return false;
			}
		}
		pintado[id][eh] = 1;
		pp++;
		return true;
	}
	bool ispintado() {
		return (pintado[id][eh]==1);
	}
	bool ispintadoOutro() {
		return pintado[id][eh==0?1:0]==1;
	}
	void despinta() {
		cout << "despinta: " << id << "," << eh << endl;
		pp--;
		pintado[id][eh] = 0;
	}
};

Node **cnodes = (Node **) malloc(sizeof(Node *)*10001);

void link(Node *a,Node *b) {
	a->link[a->tot++] = b;
}

bool tenta(int l) {

	l++;
	cout << "tentando " << l << endl;
	
	// pintei todos
	if(pp==p) {
		return true;
	}

	int j,i=l;

	if(pintado[i][0]==0) {
		if(cnodes[i][0].pinta()) {
			if(tenta(l)) return true;
			cnodes[i][0].despinta();
		}
	}
	if(pintado[i][1]==0) {
		if(cnodes[i][1].pinta()) {
			if(tenta(l)) return true;
			cnodes[i][1].despinta();
		}
	}

	return false;
	
}

int main () {

	int i,j,k,a,b,c,d;
	for(i=0;i!=10001;i++) {
		cnodes[i] = (Node *) malloc(sizeof(Node) * 2);
	}
	while(true) {
		cin >> k >> p;
		if(k==0 && p==0) break;
		for(i=0;i!=p;i++) {
			cnodes[i][0].clear(i,0);
			cnodes[i][1].clear(i,1);
			pintado[i][0] = pintado[i][1] = 0;
		}
		for(i=0;i!=k;i++) {
			cin >> a >> b >> c >> d;
			if(a==0 && b==0) {
			} else if(a==0) {
				cnodes[b][1].make(&cnodes[b][0]);
			} else if(b==0) {
				cnodes[a][1].make(&cnodes[a][0]);
			} else {
				link(&cnodes[a][1],cnodes[b]);
				link(&cnodes[b][1],cnodes[a]);
			}
			if(c==0 && d==0) {
			} else if(c==0) {
				cnodes[d][0].make(&cnodes[d][1]);
			} else if(d==0) {
				cnodes[c][0].make(&cnodes[c][1]);
			} else {
				link(cnodes[c],&cnodes[d][1]);
				link(cnodes[d],&cnodes[c][1]);
			}
		}
		pp = 0;
		if(tenta(-1)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	
	return 0;

}



