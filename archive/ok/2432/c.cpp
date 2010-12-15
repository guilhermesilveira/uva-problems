#include <iostream>

using namespace std;

int pais[200][200];
int filhos[200];
int im[200];

#define FOR(a,b) for(a=0;a<b;a++)

void st() {

       int n,m,i,j,k;
       cin >> n >> m;
       FOR(i,n) {
               FOR(j,n) pais[i][j] = 0;
               filhos[i] = 0;
               im[i] = 0;
       }
       while(m--) {
               cin >> i >> j;
               i--;
               filhos[i] = j;
               while(j--) {
                       cin >> k;
                       k--;
                       pais[k][i] = 1;
               }
       }

       int imp = 0;
       while(imp!=n) {
               FOR(i,n) {
                       if(im[i]==0 && filhos[i]==0) {
                               im[i] = 1;
                               if(imp!=0) cout << " ";
                               cout << (i+1);
                               FOR(j,n) {
                                       if(pais[i][j]) filhos[j]--;
                               }
                               imp++;
                               break;
                       }
               }
       }
       cout << endl;

}

int main()  {

       int t; cin >> t; while(t--) st();
       return 0;

}