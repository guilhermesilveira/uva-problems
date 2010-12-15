#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int n;
	int mat[200][200];
	int val[200];
	bool ok[200];

	int i,j,k,o,l;

	while((cin >> n) && n) {

		for(i=0;i!=n;i++) {
			for(j=0;j!=n;j++) mat[i][j] = 0;
		}
		for(i=0;i!=n;i++) {
			cin >> o;
			for(l=0;l!=o;l++) {
				cin >> j >> k;
				j--;
				mat[i][j] = k;
			}
		}
		for(i=0;i!=n;i++)
		  for(j=0;j!=n;j++)
		    if(i!=j && mat[j][i])
		      for(k=0;k!=n;k++)
			if(i!=k && j!=k && mat[i][k])
			  if(mat[j][k]==0 || mat[j][k]>mat[j][i]+mat[i][k])
			    mat[j][k] = mat[j][i]+mat[i][k];

		k = 0;

		for(i=0;i!=n;i++) 
			ok[i] = true;

		for(i=0;i!=n;i++) {

			val[i] = 0;

			for(j=0;j!=n;j++)
			  if(i!=j) {
			    if(mat[i][j]==0) {
				ok[i] = false;
				break;
				}
			    if(val[i]<mat[i][j])
			      val[i] = mat[i][j];
			  }

			if(!ok[i]) {
				continue;
			}

			if(!ok[k] || val[i]<val[k]) k = i;

		}
		if(val[k]==-1) 	cout << "disjoint" << endl;
		else cout << (k+1) << " " << val[k] << endl;
	}

	return 0;

}
