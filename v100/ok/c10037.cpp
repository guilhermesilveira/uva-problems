#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> p1;
#define pb push_back
#define FOR(a,b) for(a=0;a<b;a++)

int n,i,j,k;
void le() {
       cin >> n;
       p1.clear();
       FOR(i,n) { cin >> j; p1.pb(j); }
       sort(p1.begin(),p1.end());
}

void st(bool p) {
       int s = n,v1,v2,v3,t=0,a,b,c,d;
       while(s) {
               if(s==1) {
                       t+=p1[0];
                       if(p) cout << p1[0] << endl;s--; continue;
               }
               if(s==2) {
                       t+=p1[1];
                       if(p) cout << p1[0] << " " << p1[1] << endl;
                       s-=2;
                       continue;
               }
               if(s==3) {
                       t+=p1[0]+p1[1]+p1[2];
                       if(p) {
                       cout << p1[0] << " " << p1[1] << endl;
                       cout << p1[0] << endl;
                       cout << p1[0] << " " << p1[2] << endl;
                       }
                       s-=3;
                       continue;
               }
               d = p1[s-1];
               c = p1[s-2];
               b = p1[1];
               a = p1[0];
               if(c+a<2*b) {
                       if(p) {cout << a << " " << d << endl;
                       cout << a << endl;
                       cout << a << " " << c << endl;
                       cout << a << endl;}
                       t+=c+a+a+d;
               } else {
                       if(p) {cout << a << " " << b << endl;
                       cout << a << endl;
                       cout << c << " " << d << endl;
                       cout << b << endl;}
                       t+=2*b+a+d;
               }
               s-=2;
//              FOR(i,s) cout << p1[i] <<","; cout << endl;
       }
if(!p)  cout << t << endl;
}

int main() {
       int t;
       cin >> t;
       while(t--) { le();st(0);st(1);if(t) cout << endl;  }
       return 0;
}