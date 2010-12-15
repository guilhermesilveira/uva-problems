// backtracking

#include <iostream>

using namespace std;

int pos[15][2];
int mat[11][11];
int minp;

int n;
bool vis[12];

int dist(int a,int b) {
       int c = 0;
       if(pos[a][0]<pos[b][0]) c += pos[b][0] - pos[a][0];
       else c += pos[a][0] - pos[b][0];
       if(pos[a][1]<pos[b][1]) c += pos[b][1] - pos[a][1];
       else c += pos[a][1] - pos[b][1];
       return c;
}

void tenta(int dist,int level,int atual) {

       // prune it
       if(minp!=-1 && dist>minp) return;

       if(level==n) {
               // soma a distancia ao cara inicial
               dist += mat[atual][0];
               if(minp==-1 || dist<minp) minp = dist;
               return;
       }

       for(int i=1;i<=n;i++) {
               if(!vis[i]) {
                       vis[i] = true;
                       tenta(dist + mat[atual][i],level+1,i);
                       vis[i] = false;
               }
       }

}

int st() {

       int dx,dy,sx,sy;
       cin >> dx >> dy >> pos[0][0] >> pos[0][1];
       cin >> n;
       int i,j,k,l;

       if(n==0) return 0;

       for(i=1;i<=n;i++) cin >> pos[i][0] >> pos[i][1];

       for(i=0;i<=n;i++)
               for(j=0;j<=n;j++)
                       mat[i][j] = dist(i,j);

       for(i=0;i<=n;i++) vis[i] = 0;

       minp = -1;

       tenta(0,0,0);

       return minp;

}

int main() {

       int t; cin >> t;
               while(t--) cout << "The shortest path has length " << st() << endl;
       return 0;

}