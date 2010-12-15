#include <iostream>
#include <string>

using namespace std;

int mat[300][300];
int alt[300][300];
int y,x,n,z,maxi;

int MAIOR(int a,int b) {
	return a>b?a:b;
}

void atualiza(int i,int j,int yz,int xz,int z) {
	if(yz<0 || xz<0 || yz==y || xz==x) return;
	if(alt[i][j]<alt[yz][xz]) {
		mat[i][j] = MAIOR(mat[i][j],mat[yz][xz]+1);
		if(mat[i][j]>maxi) maxi = mat[i][j];
	}
}

string s;

void st() {
	cin >> s;
	int i,j,k;
	maxi = 1;
	cin >> y >> x;
	for(i=0;i!=y;i++) {
		for(j=0;j!=x;j++) { 
			cin >> alt[i][j];
			mat[i][j]=1; 
		}
	}
	for(z=100;z>=0;z--) {
		//cout << z << " ate agora: " << maxi << endl;
		for(i=0;i!=y;i++) {
			for(j=0;j!=x;j++) {
				if(alt[i][j]==z) {
					atualiza(i,j,i-1,j,z);
					atualiza(i,j,i+1,j,z);
					atualiza(i,j,i,j-1,z);
					atualiza(i,j,i,j+1,z);
				}
			}
		}
		/*for(i=0;i!=y;i++) {
			for(j=0;j!=x;j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	cout << s << ": " << maxi << endl;
}


int main() {
	int t;
	cin >> t;
	while(t--) st();
	return 0;
}
