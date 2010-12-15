#include <iostream>
using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int mat[150][150];
bool con[150][150];

int st() {

       int n,m;
       int i,j,k;
       cin >> n >> m;

       FOR(i,n) {
             FOR(j,n) { mat[i][j] = 0; con[i][j] = false; }
             con[i][i] = true;
       }

       while(m--) {
               cin >> i >> j >> k;
               i--; j--;
               if(!con[i][j] || mat[i][j]>k) {
                       mat[j][i] = mat[i][j] = k;
                       con[i][j] = con[j][i] = true;
               }
       }

       // floyid warshall
       FOR(i,n) {
               FOR(j,n) {
                       if(i==j) continue;
                       FOR(k,n) {
                               if(i==k || j==k || !con[j][i] || !con[i][k]) continue;
                               if(!con[j][k] || mat[j][k]>mat[j][i]+mat[i][k]) {
                                       mat[j][k] = mat[j][i] + mat[i][k];
                                       con[j][k] = true;
                               }
                       }
               }
       }

       long menor;
       bool achado = false;

       for(i=0;i<n;i++) {

               // maximum distance found till now
               long dmax = mat[i][0];

               // if not connected to one of those, ignores it
               FOR(j,5) if(!con[i][j] || mat[i][j]!=mat[i][0]) goto f;

               // hmm... takes the maximum distance ever
               FOR(j,n) {
                       if(i!=j && !con[i][j]) goto f;
                       if(con[i][j] && dmax<mat[i][j]) dmax = mat[i][j];
               }

               // is it the smallest maximum distance?
               if(!achado || menor>dmax) {
                       menor = dmax;
                       achado=true;
               }

               f:;

       }

       if(!achado) return -1;

       return menor;

}

int main() {
       int t,i=0;
       cin >> t;
       while(t--) {
               cout << "Map " << ++i << ": " << st() << endl;
       }
       return 0;
}
