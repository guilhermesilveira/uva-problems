#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n,k;
int mat[100][100];
int tot[100];
int cor[100];

vector<int> ver;

bool comp(const int a,const int b) {
	return tot[a]>tot[b];
}

int minimo;

void tenta(int level,int cores) {

	if(level==n) {
		if(cores<minimo) minimo = cores;
		return;
	}

	int ar = ver[level], i, j;

	for(i=0;i!=cores;i++) {

		for(j=0;j!=n;j++) if(mat[ar][j] && cor[j]==i) break;

		if(j!=n) continue;

		cor[ar] = i;
		tenta(level+1,cores);

	}

	cor[ar] = cores;
	tenta(level+1,cores+1);
	cor[ar] = -1;

}

int main() {

	char lin[100];

	while((cin >> n) && n) {

		for(int i=0;i!=n;i++) for(int j=0;j!=n;j++) mat[i][j] = 0;

		ver.clear();

		for(int i=0;i!=n;i++) {
			cin >> lin;
			k = lin[0]-'A';
			int len = strlen(lin);
			for(int j=2;j<len;j++) {
				mat[k][lin[j]-'A'] = mat[lin[j]-'A'][k] = 1;
			}
			ver.push_back(i);
		}

		for(int i=0;i!=n;i++) {
			tot[i] = 0;
			cor[i] = -1;
			for(int j=0;j!=n;j++) if(mat[i][j]) tot[i]++;
		}

		sort(ver.begin(),ver.end(),comp);

		minimo = n;

		tenta(0,0);

		if(minimo==1) cout << minimo << " channel needed." << endl;
		else cout << minimo << " channels needed." << endl;

	}
	return 0;


}
