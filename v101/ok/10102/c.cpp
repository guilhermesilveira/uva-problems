#include <iostream>
#include <assert.h>

using namespace std;

long m;
char map[2000][2000];

long long men;

void tenta(int y,int x) {

       int i,j,d;
       long long meumen = m * m + 1;
       for(i=0;i!=m;i++) {
               if(y-i > meumen || i-y>meumen) continue;
               for(j=0;j!=m;j++) {
                       if(map[i][j]=='3') {
                               //cout << "com " << y << "," << x << " achei " << i << ","  << j << endl;
                               d = y - i;
                               if(d<0) d = -d;
                               if(x-j<0) d += j-x;
                               else d += x - j;
                               if(d<meumen) meumen = d;
                       }
               }
       }
       //cout << meumen << endl;
       if(meumen>men) men = meumen;

}

int main() {

       int i,j;

       while(cin >> m) {
               assert(m<2000);
               men = 1;
               for(i=0;i!=m;i++) cin >> map[i];
               for(i=0;i!=m;i++) for(j=0;j!=m;j++) if(map[i][j]=='1') tenta(i,j);
               cout << men << endl;
       }
       return 0;

}