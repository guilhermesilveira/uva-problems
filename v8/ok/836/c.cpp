#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

       int i,j,k,l,x,y,n,u;
       char lin[110];
       int mat[110][110];
       cin >> u;
       while(u--) {

               cin >> lin;
               y = x = strlen(lin);
               for(i=0;i!=y;i++) mat[0][i] = lin[i]-'0';
               for(i=1;i<y;i++) {
                       cin >> lin;
                       for(j=0;j<x;j++) {
                               mat[i][j] = lin[j] - '0';
                       }
               }
               for(i=0;i<y;i++) {
                       for(j=1;j<x;j++) {
                               if(mat[i][j]!=0) mat[i][j] += mat[i][j-1];
                       }
               }

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

               if(u!=0) cout << endl;

       }
       return 0;

}