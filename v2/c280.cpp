#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;
bool mat[110][110];

void st() {

       int i,j,k,l;
       for(i=0;i!=n;i++) {
               for(j=0;j!=n;j++) mat[i][j] = false;
               //mat[i][i] = 1;
       }

       while(true) {
               cin >> i;
               if(i==0) break;
               i--;
               while(true) {
                       cin >> j;
                       if(j==0) break;
                       j--;
                       mat[i][j] =  true;
               }
       }

       for(i=0;i!=n;i++) {
               for(j=0;j!=n;j++) {
                       if(i==j || !mat[j][i]) continue;
                       for(k=0;k!=n;k++) {
                               if(mat[j][k] || i==k || !mat[i][k]) continue;
                               mat[j][k] = true;
                       }
               }
       }

       cin >> i;
       while(i--) {
               cin >> j;
               j--;
               l=0;
               for(k=0;k!=n;k++) if(!mat[j][k]) l++;
               cout << l;
               for(k=0;k!=n;k++) if(!mat[j][k]) cout << " " << (k+1);
               cout << endl;
       }

}

int main() {

       while((cin >> n) && n) st();
       return 0;

}