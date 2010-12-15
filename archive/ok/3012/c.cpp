#include <iostream>

using namespace std;

void imp(int n,char c) {
       while(n!=0) {
               cout << c;
               n /= 10;
       }
}

void imp2(int n,int k,char c) {
       int a1 = 0,a2=0;
       while(n!=0) {
               a1++;
               n /= 10;
       }
       while(k!=0) {
               a2++;
               k /= 10;
       }
       a2 -= a1;
//      cout << a2 << endl;
       while(a2--!=0) cout << c;
}

int gcd(int a,int b) {
       if(a==0) return b;
       else return gcd(b % a, a);
}

int main() {

       int n,i,j,k,l,o,p;
       int inst = 0;
       while((cin >> n) && n) {
               cout << "Case " << ++inst << ":" << endl;
               p = 0;
               for(i=0;i!=n;i++) { cin >> j; p += j; }
               bool neg = false;
               if(p<0) { neg = true; p = - p; }
               if((p % n)==0) {
                       if(neg) cout << "- ";
                       cout << (p/n) << endl;
               } else {

                       int init = p / n;
                       p = p % n;

                       int gc = gcd(p,n);
                       p/=gc; n/=gc;

                       if(neg) cout << "  ";
                       if(init) imp(init,' ');
                       imp2(p,n,' ');
                       cout << p << endl;

                       if(neg) cout << "- ";
                       if(init) cout << init;
                       imp(n,'-');
                       cout << endl;

                       if(neg) cout << "  ";
                       if(init) imp(init,' ');
                       cout << n << endl;

               }
       }
       return 0;

}