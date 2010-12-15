#include <iostream>
#include <stdio.h>

using namespace std;

int mat[30][30][30];
bool b[30][30][30];

#define FOR(a,b) for(a=0;a!=b;a++)

int n,n2;

void mak(int x,int y,int z,int pos) {

       if(x==n) x=0;
       if(z==-1) z=n-1;
       if(y==-1) y=n-1;

       mat[x][y][z] = pos;
       b[x][y][z]=true;

       if(pos==n2) {
               // ultimo, coloca e para
               return;
       }
       
       if(pos==9 || pos==10 || pos==19) {
       	cout << pos << ";" << x << "," << y << "," << z << endl;
       } 

       if(z==n-2) {
               int ya = (y==0) ? n-1 : y-1;
               cout << ya << endl;
               // regra do penultimo layer para cima
               if(b[x][ya][z+1]) { cout << "ja " << x << "," << ya << "," << z+1 << endl;mak(x,y,z-1,pos+1);}
               // regra do penultimo layer para baixo
               else mak(x,ya,z+1,pos+1);
       } else if(z==n-1) {
               // regra do ultimo layer (vai pro primeiro)
               mak(x+1,y,0,pos+1);
       } else {
               // regra dos outros layers (desce = z++)
               mak(x+1,y,z+1,pos+1);
       }

}

int main() {

       int u,o,p,tc=0;
       while((cin >>n) && n!=0) {

               if(tc!=0) cout << endl;
               tc=1;

               if(n==1) {
                       cout << "    1\n";
                       continue;
               }

               FOR(u,n) FOR(o,n) FOR(p,n) b[u][o][p]=false;
               n2 = n * n * n;
               mak(n/2,n/2,n-1,1);

               for(int i=0;i!=n;i++) {
                       if(i!=0) cout << endl;
                       for(int j=0;j!=n;j++) {
                               for(int k=0;k!=n;k++) {
                                       printf("%5d ",mat[k][j][i]);
                               }
                               cout << endl;
                       }
               }

       }

       return 0;

}
