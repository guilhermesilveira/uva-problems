#include <iostream>

using namespace std;

int main() {

 long tam[1000][1000];
 long val[2][10000];
 int inst = 0;
 int len1,len2;
 while(true) {
   cin >> len1 >> len2;
   if(!len1 && !len2) return 0;
   int i,j,k,l;
   for(i=0;i!=len1;i++) cin >> val[0][i];
   for(i=0;i!=len2;i++) cin >> val[1][i];
   for(i=0;i!=len1;i++) tam[i][0] = 0;
   for(i=0;i!=len2;i++) tam[0][i] = 0;
   long maxi = 0;
   for(i=1;i<=len1;i++) {
     for(j=1;j<=len2;j++) {
       if(val[0][i-1]==val[1][j-1]) {
         tam[i][j] = tam[i-1][j-1]+1;
       } else if(tam[i-1][j]>=tam[i][j-1]) {
         tam[i][j] = tam[i-1][j];
       } else {
         tam[i][j] = tam[i][j-1];
       }
     }
   }
   cout << "Twin Towers #" << ++inst << endl << "Number of Tiles : "
<< tam[len1][len2] << endl << endl;
 }

}
