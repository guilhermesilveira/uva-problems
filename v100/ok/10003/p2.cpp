#include <iostream>

using namespace std;

int p;
int ps[51];
int m[55][55];
int curS;

void preenche(int y,int x) {
	
	int min = -1,v;
	int xs = x, xe =  x + 1, ye = y - 1;

	if(y==0) {
		m[y][x] = 0;
		return;
	}
	
	for(int i=0;i<y;i++) {

		v = m[i][xs]+m[ye][xe];
		if(min==-1 || v<min) min = v;
		ye--;
		xe++;
		
	}
	
	if(x==0) {
		if(y==p) {
			v = curS;
		} else {
			v = ps[y];
		}
	} else if(x==p-y) {
		v = curS - ps[p-y-1];
	} else {
		v = ps[x+y] - ps[x-1];
	}
	min += v;

	m[y][x] = min;

}

int main() {

	int i,j;
	while((cin >> curS)) {
		if(curS==0) return 0;
		cin >> p;
		for(i=0;i!=p;i++) {
			cin >> ps[i];
		}
		if(p==0) {
			cout << "The minimum cutting is 0." << endl;
			continue;
		}
		
		for(j=0;j<=p;j++) {
			for(i=0;i<=p-j;i++) {
				preenche(j,i);
				//cout << m[j][i] << " ";
			}
			//cout << endl;
		}
		
		cout << "The minimum cutting is " << m[p][0] << "." << endl;
	}
	return 0;

}
