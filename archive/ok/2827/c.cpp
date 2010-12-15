#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cor[20];
double pos[20][2];
int contot[20];
bool con[20][20];
vector<int> vec;

int mini;

bool comp(const int &c1, const int &c2) {
	return contot[c1]>=contot[c2];
}

#define FOR(a,b) for(a=0;a!=b;a++)
#define DIST(a,b) ((pos[a][0]-pos[b][0])*(pos[a][0]-pos[b][0])+(pos[a][1]-pos[b][1])*(pos[a][1]-pos[b][1]))

void tenta(int level,int corAtual) {
	if(corAtual>mini) return;
	if(level==n) {
		// cheguei ao fim
		int i;
		//FOR(i,n) {
			//cout << cor[i] << " ";
		//}
		//cout << "::" <<corAtual << endl;
		if(corAtual<mini) mini=corAtual;
		//cout << mini << endl;
		return;
	}
	int i,j,node;
	node = vec[level];
	FOR(i,corAtual) {
		// tenta com essa cor, pode?
		//cout << "tentando " << node << " de cor " << i << endl;
		FOR(j,n) {
			if(j==node) continue;
			if(con[node][j] && cor[j]==i) break;
		}
		if(j==n) {
			cor[node] = i;
			//cout << "tenta " << node << " de " << i << endl;
			tenta(level+1,corAtual);
		} else {
			//cout << "nao pode " << node << " de cor " << i << endl;
		}
	}
	// tenta com uma cor nova
	cor[node] = corAtual;
	//cout << "tenta " << node << " de " << corAtual << endl;
	tenta(level+1,corAtual+1);
	// zera a cor dele mesmo
	cor[node] = -1;
}

int main() {

	int i,j,inst=0;
	while((cin >> n) && n) {

		FOR(i,n) cin >> pos[i][0] >> pos[i][1];
		mini = n;
		// mini = 5;
		// if(n<5) mini = n;
		vec.clear();
		FOR(i,n) {
			cor[i] = -1;
			contot[i] = 0;
			FOR(j,n) {
				if(i==j) continue;
				if(DIST(i,j)<=400) {
					//cout << "conectando " << i  << " com " << j << endl;
					con[i][j] = 1;
					contot[i]++;
				} else {
					con[i][j] = 0;
				}
			}
			vec.push_back(i);
		}
		sort(vec.begin(),vec.end(),comp);
	//	FOR(i,n) {
//			j = vec[i];
			//cout << j << ": " << contot[j] << endl;
		//}
		cor[vec[0]] = 0;
		tenta(1,1);
		cout << "The towers in case " << ++inst << " can be covered in " << mini << " frequencies." << endl;

	}
	
	return 0;
	
}
