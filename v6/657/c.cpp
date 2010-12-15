#include <iostream>

using namespace std;

int ap[10];
int y,x;
bool vis[100][100];
char lin[100][100];

int busca(int a,int b,bool conta) {

	if(a<0 || b<0 || a==y || b==x) return 0;

	if(vis[a][b]) return 0;

	if(lin[a][b]=='.') return 0;

	if(!conta) {
		if(lin[a][b]=='X') {
			vis[a][b] = 1;
			return 0;
		} else {
			return 0;
		}
	}

	vis[a][b] = 1;

	int k = 0;

	if(lin[a][b]=='X') {
		busca(a-1,b,false);
		busca(a+1,b,false);
		busca(a,b+1,false);
		busca(a,b-1,false);
		k = 1;
	} else if(lin[a][b]=='*') {
		k += busca(a-1,b,true);
		k += busca(a+1,b,true);
		k += busca(a,b+1,true);
		k += busca(a,b-1,true);
	}

	return k;

}

int main() {

	int inst = 0;

	while((cin >> x >> y) && !(x==0 && y==0)) {

		int i,j,k;
		for(i=0;i!=y;i++) cin >> lin[i];
		for(i=0;i<=6;i++) ap[i] = 0;
		for(i=0;i!=y;i++) for(j=0;j!=x;j++) vis[i][j] = false;
		for(i=0;i!=y;i++) {
			for(j=0;j!=x;j++) {
				k = busca(i,j,true);
				//if(k!=0) cout << k << endl;
				ap[k]++;
			}
		}
		cout << "Throw " << ++inst << endl;
		for(i=1;i<=6;i++) {
			for(j=0;j!=ap[i];j++) cout << i << " ";
		}
		cout << endl;

	}

	return 0;

}
