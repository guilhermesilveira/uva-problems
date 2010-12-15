// 260

#include <assert.h>
#include <iostream>
#define FOR(a,b) for(int a=0;a<b;a++)

using namespace std;

int n;
char m[221][221],v[221][221];

bool tenta(int y,int x) {
       if(m[y][x]!='w' && m[y][x]!='W') return 0;
       if(x==n-1) return 1;
       v[y][x]=1;
       if(x!=0 && !v[y][x-1]) if(tenta(y,x-1)) return 1;
       if(!v[y][x+1]) if(tenta(y,x+1)) return 1;
       if(y!=0 && !v[y-1][x]) if(tenta(y-1,x)) return 1;
       if(y!=0 && x!=0 && !v[y-1][x-1]) if(tenta(y-1,x-1)) return 1;
       if(y!=n-1 && !v[y+1][x]) if(tenta(y+1,x)) return 1;
       if(y!=n-1 && !v[y+1][x+1]) if(tenta(y+1,x+1)) return 1;
       return 0;
}

int main() {

       int inst = 0;
       while((cin >> n) && n) {
               FOR(i,n) cin >> m[i];
               FOR(y,n) FOR(x,n) v[y][x]=0;
               cout << ++inst << " ";
               FOR(y,n) { if(tenta(y,0)) { cout << "W" << endl; goto n; } }
               FOR(y,n) FOR(x,n) v[y][x]=0;
               cout << "B" << endl;
               n:;
       }
       return 0;

}

