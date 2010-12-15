// 201
#include <iostream>
#define FOR(a,b) for(int a=0;a<b;a++)

using namespace std;

int n=0;
int len[10];
bool f;
bool l[2][10][10];
#define HOR (0)
#define VER (1)

void tenta(int y,int x,int d) {
       if(y==n || x==n || y+d==n || x+d==n) return;
       // tenta aumentar
       if(l[VER][y+d][x] && l[HOR][y][x+d]) tenta(y,x,d+1);
       // tenta fechar do outro lado
       //cout << "tt" << y << "," << x << ":" << d << endl;
       FOR(i,d) {
               //cout << i << "," << (y+i) << "," << (x+d) << "," <<
l[VER][y+i][x+d] << endl;
               if(!l[VER][y+i][x+d]) return;
       }
       FOR(i,d) if(!l[HOR][y+d][x+i]) return;
       len[d]++;
       //cout << "square: " << y << "," << x << ":" << d << endl;
       f=true;
}

int main() {

       int inst = 0,m,a,b;
       char c[10];
       while((cin >> n)) {
               if(inst) cout << endl << "**********************************" << endl << endl;
               cout << "Problem #" << ++inst << endl << endl;
               FOR(i,10) len[i] = 0;
               FOR(i,10) FOR(j,10) l[0][i][j] = l[1][i][j] = 0;
               f=false;
               cin >> m;
               while(m--) {
                       cin >> c >> a >> b;
                       a--; b--;
                       if(c[0]=='H') l[HOR][a][b] = 1;
                       else l[VER][b][a] = 1;
               }
               FOR(i,n-1) FOR(j,n-1) if(l[HOR][i][j] && l[VER][i][j]) tenta(i,j,1);
               FOR(i,10) if(len[i]) cout << len[i] << " square (s) of size " << i << endl;
               if(!f) cout << "No completed squares can be found." << endl;
       }
       return 0;

}