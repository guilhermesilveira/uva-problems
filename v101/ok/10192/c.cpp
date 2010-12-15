#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

int main() {

 char s[2][200];
 int len[2];
 int val[200][200];
 int i,j,k,l,inst=0;
 while(true) {

   gets(s[0]);
   if(s[0][0]=='#') return 0;
   gets(s[1]);
   //cout << s[0] << "," << s[1] << endl;
   len[0] = strlen(s[0]);
   len[1] = strlen(s[1]);
   //cout << len[0] << "," << len[1] << endl;
   for(i=0;i!=len[0];i++) val[i][0] = 0;
   for(i=0;i!=len[1];i++) val[0][i] = 0;
   for(i=1;i<=len[0];i++) {
     for(j=1;j<=len[1];j++) {
       if(s[0][i-1]==s[1][j-1]) val[i][j] = val[i-1][j-1]+1;
       else if(val[i-1][j]>=val[i][j-1]) val[i][j] = val[i-1][j];
       else val[i][j] = val[i][j-1];
     }
   }

   cout << "Case #" << ++inst << ": you can visit at most " <<
val[len[0]][len[1]] << " cities." << endl;

 }

 return 0;

}
