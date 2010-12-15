#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)
#define FOR3(a,b,c) for(a=b;a<c;a++)
char s[300];
bool n[11];

void le(char c) {
       switch (c) {
               case 'C':
                       n[3]=true;
                       break;
               case 'D':
                       n[9] = true;
               case 'E':
                       n[8] = true;
               case 'F':
                       n[7] = true;
               case 'G':
                       n[4] = true;
               case 'A':
                       n[3] = true;
               case 'B':
                       n[1] = n[2] = true;
                       break;
               case 'c':
                       n[10] = true;
               case 'd':
                       n[9] = true;
               case 'e':
                       n[8] = true;
               case 'f':
                       n[7] = true;
               case 'g':
                       n[4] = true;
               case 'a':
                       n[3] = true;
               case 'b':
                       n[2]=true;
                       break;
               default:
                       break;
       }
}

void st() {
       bool p[11];
       int i,j,k,l;
       int pc[11];
       FOR(i,11) { p[i] = false; pc[i] = 0; }
       gets(s);
       l = strlen(s);
       char c;
       FOR(i,l) {
               c = s[i];
               FOR3(j,1,11) n[j] = false;
               le(c);
               /*cout << "l: ";
               FOR3(j,1,11) cout << " " << n[j];
               cout << endl;*/
               FOR3(j,1,11) {
                       if(n[j] && !p[j]) { p[j] = true; pc[j]++; }
                       else if(!n[j]) p[j] = false;
               }
       }
       cout << pc[1];
       FOR3(j,2,11) cout << ' ' << pc[j];
       cout << endl;
}

int main() {

       int t;
       cin >> t;
       gets(s);
       while(t--)st();
       return 0;

}