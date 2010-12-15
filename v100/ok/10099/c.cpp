#include <iostream>
using namespace std;

int n,r;
int dis[105][105];
bool pos[105][105];

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

void le() {
       int i,j,k,l;
       for(i=0;i!=n;i++) {
               for(j=0;j!=n;j++) {
                       dis[i][j] = -1;
                       pos[i][j] = false;
               }
       }
       for(i=0;i!=r;i++) {
               cin >> j >> k >> l;
               dis[j-1][k-1] = dis[k-1][j-1] = l;
               pos[j-1][k-1] = pos[k-1][j-1] = true;
       }
}

void floyd() {
       int i,j,k;
       for(i=0;i!=n;i++) {
               for(j=0;j!=n;j++) {
                       if(i==j || !pos[j][i]) continue;
                       for(k=0;k!=n;k++) {
                               if(i==k || j==k || !pos[i][k]) continue;
                               if(!pos[j][k]) dis[j][k] = MIN(dis[j][i],dis[i][k]);
                               else dis[j][k] = MAX(MIN(dis[j][i],dis[i][k]),dis[j][k]);
                               pos[j][k] = true;
                       }
               }
       }
}

int main() {

       int inst = 0;
       while(true) {
               cin >> n >> r;
               if(n==0 &&!r) return 0;
               cout << "Scenario #" << ++inst << endl;
               le();
               floyd();
               int i,f,t;
               cin >> i >> f >> t;
               int temp = dis[i-1][f-1] - 1;
               cout << "Minimum Number of Trips = " << ((t)/temp +
((t)%temp!=0?1:0)) << endl;
               cout << endl;
       }
       return 0;

}
