#include <iostream>

using namespace std;

int n,m;
bool tab[200];

int main() {

       while((cin >> n) && n)  {
               m = 1;
               while(true) {
                       m++;
                       for(int i=0;i!=n;i++) tab[i]=false;
                       int pos = 0;
                       int rem = 1;
                       tab[0] = true;
                       //cout << "tenta: " << m << endl;
                       while(true) {
                               int i = 0;
                               while(i!=m) {
                                       pos++;
                                       if(pos==n) pos = 0;
                                       if(!tab[pos]) i++;
                               //      cout << i << " " << pos << endl;
                               }
                               rem++;
                               tab[pos] = true;
                               //cout << "r: " << pos << endl;
                               if(rem==n) {
                                       if(pos==1) goto f;
                               }
                               if(pos==1) break;
                       }
               }
               f:
               cout << m << endl;
       }
       return 0;

}

