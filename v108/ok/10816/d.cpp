#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;

#define FOR(a,b) for(a=0;a<b;a++)

double mat[200][200];
double MV = 2 << 15;

void floyd() {
	int i,j,k;
	FOR(i,n) FOR(j,n) if(i!=j && mat[j][i]!=MV)
		FOR(k,n) if(i!=k && j!=k && mat[i][k]!=MV)
			mat[j][k]=min(max(mat[j][i],mat[i][k]),mat[j][k]);
}

double dist[200];
int pre[200];

int arestas;
struct {
	int de,para;
	double custo,t;
} a[20100];

void imp(int st,int p) {
	if(p==st) {
		cout << (st+1);
		return;
	}
	imp(st,pre[p]);
	cout << " " << (p+1);
}

double ford(int st,int en) {
	double mv = mat[st][en];
	int i,j,k,l;
	dist[st] = 0;
	FOR(i,n) {
		FOR(j,arestas) {
			if(a[j].t<=mv && dist[a[j].para]>dist[a[j].de]+a[j].custo) {
				//cout << "aresta: " << j << " " << a[j].de << "->" << a[j].para << endl;
				dist[a[j].para]=dist[a[j].de]+a[j].custo;
				pre[a[j].para]=a[j].de;
			}
		}
		/*FOR(j,n) cout << pre[j] << " ";cout << endl;
		FOR(j,n) cout << dist[j] << " ";cout << endl;
		cout << endl;*/
	}
//	FOR(i,n) cout << pre[i] << " ";cout << endl;
	imp(st,en);cout<<endl;
	return dist[en];
}

int main() {

	int i,j,k,l;
	while((cin >> n >> l)) {
		int st,en;
		cin >> st >> en;
		st--; en--;
		FOR(i,n) { FOR(j,n) mat[i][j]=MV; mat[i][i]=0;}
		double v1,v2;
		k=0;
		while(l--) {
			cin >> i >> j >> v1 >> v2;
			i--;j--;
			mat[i][j]=mat[j][i]=min(mat[i][j],v1);
			a[k].de=i;
			a[k].para=j;
			a[k].custo=v2;
			a[k].t=v1;
			k++;
			a[k].de=j;
			a[k].para=i;
			a[k].custo=v2;
			a[k].t=v1;
			k++;
		}
		arestas = k;
		FOR(i,n) dist[i]=MV;
		floyd();
		double mv = mat[st][en];
		v1 = ford(st,en);
		printf("%.1lf %.1lf\n",v1,mv);
	}
	return 0;

}
