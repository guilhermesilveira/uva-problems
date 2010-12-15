#include <iostream>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int main() {

       int ar[15];
       int tot = 15;
       ar[0]=561;
       ar[1]=1105;
       ar[2] = 1729;
       ar[3] = 2465;
       ar[4] = 2821;
       ar[5] = 6601;
       ar[6] = 8911;
       ar[7] = 10585;
       ar[8] = 15841;
       ar[9] = 29341;
       ar[10] = 41041;
       ar[11] = 46657;
       ar[14] = 52633;
       ar[12] = 62745;
       ar[13] = 63973;
       int i,j;
       while((cin >> i) && i) {
               for(j=0;j!=tot;j++) if(ar[j]==i) break;
               if(j!=tot)  cout << "The number " << i << " is a Carmichael number." << endl;
               else cout << i << " is normal." << endl;
       }
       return 0;

}