#include <iostream>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int pos[1010][2];
bool con[1010][1010];
bool c[1010];
double DIST[1101][1101];

bool cmp(const double *v1,const double *v2) {
	return v1[2] < v2[2];
}

int main() {
	
	int n,m;
	int a,b;
	while((cin >> n)) {
		for(int i=0;i!=n;i++) cin >> pos[i][0] >> pos[i][1];
		cin >> m;
		for(int i=0;i!=n;i++) c[i]=false;
		for(int i=0;i!=n;i++) for(int j=0;j!=n;j++) con[i][j]=false;
		for(int i=0;i!=n;i++) for(int j=0;j!=n;j++) DIST[i][j]=sqrt(0.0+(pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
		for(int i=0;i!=m;i++) {
			cin >> a >> b;
			a--; b--;
			con[a][b]=con[b][a]=1;
		}
		int v = 1;
		for(int i=1;i<n;i++) if(con[0][i]) c[i]=true;
		vector<double* > vec;
		double *at = new double[3], *nov;
		at[0]=0;
		at[1]=0;
		at[2]=0;
		vec.push_back(at);
		double total = 0;
		while(v!=n) {
			vector<double*>::iterator it = min_element(vec.begin(),vec.end(),cmp);
			at = (*it);
			int atual = (int) at[1];
			// se ja conectei, ignora essa
			if(c[atual]) continue;
			cout << "agora em " << atual << endl;
			// ainda nao conectei com ela
			c[atual] = true;
			// adiciona os que ela se conecta
			
			total += at[2];
			v++;
			for(int i=0;i!=n;i++) {
				if(!c[i]) {
					// gera a coisinha!!!
					nov = new double[3];
					nov[0]=at[1];
					nov[1]=i;
					nov[2] = DIST[atual][i];
					vec.push_back(nov);
				}
			}
			vec.erase(it);
		}
		printf("%.2lf\n",total);
	}
	
	return 0;
	
}
