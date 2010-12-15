#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

int val[100][100];

void con(int y1,int x1,int y2,int x2) {
       if(y2<0 || x2<0 || y2>7 || x2>7) return;
       val[y1*10+x1][y2*10+x2] = val[y2*10+x2][y1*10+x1] = 1;
       //cout << (y1*10+x1) << "-" << (y2*10+x2) << endl;
}

void make(int y,int x) {
       if(y>7 || x>7) return;
       con(y,x,y+2,x-1); con(y,x,y+2,x+1);
       con(y,x,y+1,x-2); con(y,x,y+1,x+2);
       con(y,x,y-2,x-1); con(y,x,y-2,x+1);
       con(y,x,y-1,x-2); con(y,x,y-1,x+2);
}

void getready() {
       int i,j,k;
       FOR(i,80) {
               FOR(j,80) val[i][j] = -1;
               val[i][i] = 0;
       }
       FOR(i,8) {
               FOR(j,8) make(i,j);
       }
       //FOR(i,78) if(i%10<8) FOR(j,78) if(j%10<8) if(val[i][j]==0) cout << i << " com " << j << endl;
       FOR(i,78) {
               if(i%10>7) continue;
               FOR(j,78) {
                       if(j%10>7) continue;
                       if(i==j || val[j][i]==-1) continue;
                       FOR(k,78) {
                               if(k%10>7) continue;
                               if(k==j || i==k || val[i][k]==-1) continue;
                               if(val[j][k]==-1 || val[j][k] > val[j][i] + val[i][k]) {
                                       val[j][k]=val[j][i]+val[i][k];
                                       //cout << "S: " << j << "," << k << ":" << val[j][k]<<endl;
                               }
                       }
               }
       }
}

#define VZ(az) (((az[0]-'a')*10) + (az[1]-'1'))

int main() {
       getready();
       char s1[10],s2[10];
       while((cin >> s1 >> s2)) {
//              cout << VZ(s1) << "-" << VZ(s2) << endl;
               cout << "To get from " << s1 << " to " << s2 << " takes " << val[VZ(s1)][VZ(s2)] << " knight moves." << endl;
       }
}
