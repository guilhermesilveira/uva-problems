
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define FOR(a,b) for(a=0;a<b;a++)

using namespace std;

#define MAXI (110)

int n,p,c,tr;
int target,source;
int fila[MAXI];

int capa[MAXI][MAXI], flux[MAXI][MAXI];
int pai[MAXI];
int min[MAXI];

int resid(int tor, int dest) {
 return capa[tor][dest] - flux[tor][dest];
}

int bfs() {

 int i,j,atual,ffila, ifila, r;

 for(i=0;i<n;i++) {
   pai[i]=-1; min[i]= 1 << 30;
 }

 pai[source] = source;
 fila[0]=source;
 ifila = 1; ffila = 0;
 while(ffila<ifila) {
   atual = fila[ffila++];
   FOR(i,n) {
     r = resid(atual,i);
     if(pai[i]==-1 && r>0) {
       fila[ifila++] = i;
       pai[i] = atual;
       min[i] = min[atual];
       if(min[i]>r) min[i] = r;
     }
   }
 }

 return pai[target] != -1;

}

int main() {

 int i,j,l;
 long k;
 int u,v,z;

 while((scanf("%d %d %d %d",&n,&p,&c,&tr))==4) {

   source = n; target = n + 1;

   n += 2;

   FOR(i,n) FOR(j,n) flux[i][j]=capa[i][j]=0;

   // evita fluxos coincidentes
   FOR(i,tr) {
     scanf(" (%d,%d)%d",&u,&v,&z);
     // conecta u para v com vazao z
     capa[u][v] += z;
   }

   FOR(l,p) {
     scanf(" (%d)%d",&i,&j);
     capa[source][i] = j;
     // cout << "source: " << i << " com " << j << endl;
   }

   //cout << c << endl;

   FOR(l,c) {
     scanf(" (%d)%d",&i,&j);
     //cout << "sink: " << i << " com " << j << endl;
     capa[i][target] = j;
   }

   while(1) {
     if(bfs()==0) break;
     // aumenta o fluxo no caminho
     i = target;
     k = min[target];
     while(pai[i]!=i) {
       j = pai[i];
       flux[i][j] -= k;
       flux[j][i] += k;
       i = j;
     }
   }

   k = 0;
   for(i=0;i!=n;i++) k += flux[i][target];
   cout << k << endl;

 }
 return 0;

}