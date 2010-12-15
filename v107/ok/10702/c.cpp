#include <iostream>
#include <assert.h>

using namespace std;

int main() {

       int c,s,e,t,i,j,k,l,tab[101][101],end[101];
       int mat[1001][101];

       while(true) {

               cin >> c >> s >> e >> t;
               if(c==0 && s==0 && e==0 && t==0) return 0;

               for(i=1;i<=c;i++) {
                       for(j=1;j<=c;j++) cin >> tab[i][j];
               }

               for(i=0;i!=e;i++) cin >> end[i];
               for(i=1;i<=c;i++) mat[0][i] = -1;
               mat[0][s] = 0;

               for(l=1;l<=t;l++) {
                       for(i=1;i<=c;i++) mat[l][i]=-1;
      //                cout << l << ": ";
                       for(i=1;i<=c;i++) {
                               for(j=1;j<=c;j++) {
                               		if(mat[l-1][j]!=-1)
                                       if(mat[l][i]==-1 || mat[l][i] < mat[l-1][j] + tab[j][i]) {
                                               mat[l][i] = mat[l-1][j] + tab[j][i];
                                       }
                               }
    //                           cout << mat[l][i] << " ";
                       }
  //                     cout << endl;
               }

			int maior = -1;
               for(i=0;i!=e;i++) {
//               	cout << "e" << end[i] << endl;
               		if(mat[t][end[i]]!=-1 && maior<mat[t][end[i]])
                       maior = mat[t][end[i]];
               }
               if(maior==-1) cout << 0 << endl;
				else cout << maior << endl;

       }

       return 0;

}
