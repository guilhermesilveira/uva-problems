// joseph...

#include <iostream>

using namespace std;

bool v[200];

bool ok(int n,int m) {

       int i,j,k,t,at;
       for(i=0;i<n;i++) v[i]=1;
       t = 1; at = 0; v[0] = 0;

       while(t!=n) {

               for(k=0;k!=m;) {
                       at++;
                       if(at==n) at = 0;
                       if(v[at]) k++;
               }

               if(at==1 && t!=n-1) return false;

               v[at] = 0;
               t++;

       }

       return true;

}

void doit(int n) {

       for(int m=2;true;m++) {
               if(ok(n,m)) {
                       cout << m << endl;
                       return;
               }
       }

}

int main() {

       int n;
       while((cin >> n) && n) doit(n);
       return 0;

}