#include <iostream>

using namespace std;

int n;
int cell[111][111];
int ex;
int tempo;

#define FOR(a,b) for(a=0;a<b;a++)

void st() {

       int i,j,k,l;
       cin >> n;
       cin >> ex >> tempo;
       cin >> l;
       FOR(i,n) FOR(j,n) cell[i][j] = -1;
       while(l--) {
               cin >> i >> j;
               i--;j--;cin >> cell[i][j];
       }

       /*FOR(i,n) {
               FOR(j,n) cout << cell[i][j] << " ";
               cout << endl;
       }*/

       //tempo++;

       // floyd();
       FOR(i,n) {
               FOR(j,n) {
                       if(i==j || cell[j][i]==-1) continue;
                       FOR(k,n) {
                               if(k==i || k==j || cell[i][k]==-1) continue;
                               if(cell[j][k]==-1 || cell[j][k] > cell[j][i]+cell[i][k]) {
                                       cell[j][k] = cell[j][i] + cell[i][k];
                               }
                       }
               }
       }

       l = 0;
       ex--;
       //cout << "ex: " << ex << endl;
       FOR(i,n) {
               /*FOR(j,n) cout << cell[i][j] << " ";
               cout << endl;*/
               if(i!=ex && cell[i][ex]!=-1 && cell[i][ex]<=tempo) l++;
       }
       cout << (l+1) << endl;

}

int main() {
       int t; cin >> t; while(t--) st();
       return 0;
}