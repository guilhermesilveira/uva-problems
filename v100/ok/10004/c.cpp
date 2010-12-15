#include <iostream>
#include <stack>

using namespace std;

#define FOR(a,v) for(a=0;a<v;a++)

int main() {

       int mat[201][201], dist[201], n, i ,j, k;
       while((cin >> n) && n) {

               FOR(i,n) FOR(j,n) mat[i][j] = 0;
               cin >> i;
               while(i--) { cin >> j >> k; mat[j][k] = mat[k][j] = 1; }
               FOR(i,n) dist[i] = 0; dist[0] = 2;
               stack<int> s; s.push(0);
               while(!s.empty()) {
                       i = s.top(); s.pop();
                       FOR(j,n) {
                               if(mat[i][j]) {
                                       if(dist[j] && (dist[i]+1-dist[j])%2) goto imp;
                                       if(!dist[j]) {
                                               s.push(j);
                                               dist[j] = dist[i] + 1;
                                       }
                               }
                       }
               }
               cout << "BICOLORABLE." << endl; continue;
               imp: cout << "NOT BICOLORABLE." << endl; continue;

       }

       return 0;

}
