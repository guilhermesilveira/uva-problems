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
	}
	void adiciona(int i) {
		con[tot++] = i;
	}
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
int vis[200];
int e,d;

bool possivel(int c, int patual) {
//	cout << "visitando " << c << " em " << patual << endl;
	if(c==e && d==patual) return true;
	if(d<=patual) return false;
	int prox;
	for(int i=0;i!=cid[c].tot;i++) {
		prox = cid[c].con[i];
		if(vis[prox]==-1) {
			vis[prox]=patual+1;
			if(possivel(prox,patual+1)) {
				return true;
			}
			vis[prox]=-1;
		}
	}
	return false;
}

bool start() {
	memset(vis,-1,sizeof(vis));
	int s;
	cin >> s >> e >> d;
	s--;e--;
	vis[s]=0;
	return possivel(s,0);
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
