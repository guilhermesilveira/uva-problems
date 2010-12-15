#include <iostream>

using namespace std;

int main() {

 long long a,l,b,n;
 int inst=0;

 while((cin >> a >> l)) {
   if(a==-1 && l==-1) return 0;
   b = a;
   n = 1;
   while(b!=1 && b<=l) {
     if(b%2) {
       b = b * 3 + 1;
       n++;
     } else {
       b /= 2;
       n++;
     }
   }
   if(b>l) n--;
   cout<<"Case " << ++inst  << ": A = "<<a << ", limit = " << l << ",
number of terms = " << n << endl;
 }

 return 0;

}