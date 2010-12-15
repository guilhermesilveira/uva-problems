#include <iostream>

using namespace std;

int inst= 0;
int n,c[40];
#define MM (650)
char mat[MM+100][MM+100];

int diff(int a,int b,int c) {
	int maior, menor;
	if(a>b && a>c) maior = a;
	else maior = (b>c) ?  b : c;
	if(a<b && a<c) menor = a;
	else menor = (b<c) ?  b : c;
	return maior-menor;		
}

int bad,tot;

void st() {

	bad = 0;
	cin >> n;
	int i,j,k,v;
	int m1=0,m2=0;

	for(i=0;i!=n;i++) {
		cin >> c[i];
		bad += c[i];
	}
	tot = bad;

	for(i=0;i!=MM;i++) for(j=0;j!=MM;j++) mat[i][j]=0;

	mat[0][0]=1;
	for(i=0;i!=n;i++) {
		v = c[i];
		for(j=m1;j>=0;j--) {
			for(k=m2;k>=0;k--) {
				if(mat[j][k]) {
					// coloca em um ou no outro
					mat[j+v][k] = mat[j][k+v] = 1;
					if(j+v>m1 && j+v<=MM) m1 = j+v; 
					if(k+v>m2 && k+v<=MM) m2 = k+v;
				}
			}
		}
	}
	
	int dif;
	for(j=m1;j>=0;j--) {
		for(k=m2;k>=0;k--) {
			if(mat[j][k]) {
				dif = diff(j,k,tot-j-k);
				if(dif<bad) bad = dif;
			}
		}
	}

	cout << "Case " << ++inst << ": " << bad << endl;
	
}

int main() {
	
	int t;
	cin >> t;
	while(t--) st();
	return 0;
	
}
