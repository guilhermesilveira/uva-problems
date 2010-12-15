#include <iostream>

using namespace std;

int main() {

       int i,j,k,l,x,y,n,mat[110][110];
       while((cin >> y >> x) && !(x==0 && y==0)) {

               for(i=0;i<y;i++) for(j=0;j<x;j++) {
                       cin >> mat[i][j];
                       mat[i][j] = !mat[i][j];
               }
               for(i=0;i<y;i++) {
                       for(j=1;j<x;j++) {
                               if(mat[i][j]!=0) mat[i][j] += mat[i][j-1];
                       }
               }

//              for(i=0;i<y;i++) for(j=0;j<x;j++) cout << mat[i][j];

               int maior = 0, menor;
               for(i=0;i<y;i++) {
                       for(j=0;j<x;j++) {
                               menor = mat[i][j];
                               for(k=i;k<y;k++) {
                                       if(mat[k][j]<menor) menor = mat[k][j];
                                       l = menor*(k-i+1);
                                       if(l>maior) maior = l;
                               }
                       }
               }

               cout << maior << endl;

       }
       return 0;

}