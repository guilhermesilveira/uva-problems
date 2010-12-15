#include <iostream>

#define MAXI (1001)

using namespace std;

int main(){

	int i,j,k,l,x,y,n,t;
	int **mat = (int **) malloc(MAXI * sizeof(int));
	for(i=0;i!=MAXI;i++) mat[i] = new int[MAXI];
	char c[10];
	char lin[10000];

	cin >> t;

	while(t--){

		cin >> y >> x;

		for(i=0;i<y;i++) {
			for(j=0;j<x;j++){
				cin >> c;
				if(c[0]=='F') mat[i][j]=1;
				else if(c[0]=='R') mat[i][j]=0;
			}
		}

		for(i=0;i<y;i++)
			for(j=1;j<x;j++)
				if(mat[i][j]!=0)mat[i][j]+=mat[i][j-1];

		int maior=0, menor;

		for(i=0;i<y;i++){

			for(j=0;j<x;j++){

				menor = mat[i][j];

				for(k=i;k<y;k++){

					if(mat[k][j]<menor) menor=mat[k][j];
					if(menor==0) break;

					l = menor*(k-i+1);
					if(l>maior) maior=l;

				}
			}
		}

		cout << (maior*3) << endl;

	}

	return 0;

}
