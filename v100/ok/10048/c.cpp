#include <iostream>
using namespace std;

int c,s,q;

long mat[200][200];
bool con[200][200];

long max(long v1,long v2) {
       return v1>v2?v1:v2;
}

long min(long v1,long v2) {
       return v1<v2?v1:v2;
}

void le() {
       int i,j,k,l;
       for(i=0;i!=c+1;i++) {
               for(j=0;j!=c+1;j++) {
                       mat[i][j] = -1; con[i][j] = false;
               }
               con[i][i] = true;
               mat[i][i] = 0;
       }
       for(i=0;i!=s;i++) {
               cin >> j >> k >> l;
               if(!con[j][k] || mat[j][k]<l) {
                       mat[j][k] = mat[k][j] = l;
                       con[j][k] = con[k][j] = true;
               }
       }
}

void executa() {
       for(int i=0;i!=q;i++) {
               int j,k;
               cin >> j >> k;
               if(!con[j][k]) {
                       cout << "no path" << endl;
               } else {
                       cout << mat[j][k] << endl;
               }
       }
}

void floyd() {
       int i,j,k,l;
       for(i=0;i!=c+1;i++) {
               for(j=0;j!=c+1;j++) {
                       if(i==j || !con[j][i]) continue;
                       for(k=0;k!=c+1;k++) {
                               if(i==k || i==j || !con[i][k]) continue;
                               if(!con[j][k]) mat[j][k] = max(mat[j][i],mat[i][k]);
                               else mat[j][k] = min(max(mat[j][i],mat[i][k]),mat[j][k]);
                               con[j][k] = true;
                       }
               }
       }
}

int main() {

       int inst = 0;
       while(true) {
               cin >> c >> s >> q; if(!c && !q && !s) return 0;
               if(inst) cout << endl;
               cout << "Case #" << ++inst << endl;
               le();
               floyd();
               executa();
       }
       return 0;

}
