#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int c,l;

class Cidade {
public:
	int tot;
	int con[101];
	void clear() {
		tot=0;
		memset(d,-1,sizeof(d));
	}
	void adiciona(int i) {
		con[tot++] = i;
	}
	int d[101];
};

class Con {
public:
	Con(int p,int de) {
		para = p; d = de;
	}
	int para;
	int d;
};

Cidade cid[200];
Con *fila[100000];
int fs,fe;

#define empilha(az) fila[fe++] = az;;
#define des() (fila[fs++])

bool start() {
	fe = fs = 0;
	int s;
	int e,d;
	cin >> s >> e >> d;
	s--;e--;
	empilha(new Con(s,0));
	Con *prox;
	while(fs!=fe) {
		prox = des();
		if(prox->para==e && prox->d==d) {
			return true;
		}
		if(prox->d==d) {
			continue;
		}
		for(int i=0;i!=cid[prox->para].tot;i++) {
			int para = cid[prox->para].con[i];
			//cout << "indo de " << prox->d << " para " << para << " em " << (prox->d+1) << endl;
			Con *c = new Con(para,prox->d+1);
			empilha(c);
		}
	}
	return false;
}

void read() {
	int i;
	for(i=0;i!=c;i++) {
		cid[i].clear();
	}
	int a,b;
	for(i=0;i!=l;i++) {
		cin >> a >> b;
		cid[a-1].adiciona(b-1);
		cid[b-1].adiciona(a-1);
	}
}

int main() {
	while(true){
		cin >> c >> l;
		if(c==0 && l==0) break;
		read();
		if(start()) {
			cout << "Yes, Teobaldo can travel." << endl;
		} else {
			cout << "No, Teobaldo can not travel." << endl;
		}
	}
	return 0;
}
