#include <iostream>
#include <string.h>

using namespace std;

int c,l;

int cid[101][101];

int fila[200];
int fs,fe;

int vis[200];

#define empilha(az,t) fila[fe++] = az; vis[az] = t;
#define des() (fila[fs++])

bool start() {
	memset(fila,-1,sizeof(fila));
	memset(vis,-1,sizeof(vis));
	fe = fs = 0;
	int s;
	int e,d;
	cin >> s >> e >> d;
	//cout << s << " " << e << " " << d << endl;
	s--;e--;
	empilha(s, 0);
/*	if(s==e && d==0) return true;
	if(cid[s][e]==1 && d==1) return true;
	if(d==1) return false;*/
	int prox;
	while(fs!=fe) {
//	cout << fe << "," << fs << "," << fila[fs] << endl;
		prox = des();
		//cout << "visitando " << prox << " em " << vis[prox] << endl;
		if(prox==e) {
			if(vis[e]==d) {
				return true;
			} else {
			//	return false;
			}
		}
		if(vis[prox]==d) {
			continue;
		}
		for(int i=0;i!=c;i++) {
			if(cid[prox][i]!=0) {
				empilha(i,vis[prox]+1);
			}
		}
	}
	return false;
}

void read() {
	memset(cid,0,sizeof(cid));
	for(int i=0;i!=l;i++) {
		int a,b;
		cin >> a >> b;
		cid[a-1][b-1] = 1;
		cid[b-1][a-1] = 1;
		//cout << "con " << (a-1) << " e " << (b-1) << endl;
	}
/*	for(int i=0;i!=c;i++) {
		for(int j=0;j!=c;j++) {
			cout << cid[i][j] << " ";
		}
		cout << endl;
	}*/
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
