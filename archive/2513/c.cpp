#include <iostream>
#include <stdio.h>

using namespace std;

#define FOR(a,b) for(a=0;a!=b;a++)

double gam[200][2][2];
double ponto[200][2];

double pa,pb,pa1,pb1;
int k,l;

double comA, comB;

double calc() {
       int i;
       FOR(i,l) {
               ponto[i+1][0] = ponto[i][0]*pa + ponto[i][1]*pb1;
               ponto[i+1][1] = ponto[i][0]*pa1 + ponto[i][1]*pb;
       }
       return ponto[l][0];
}

void calcComA() {
       ponto[0][0] = 1;
       ponto[0][1] = 0;
       comA = calc();
}

void calcComB() {
       ponto[0][0] = 0;
       ponto[0][1] = 1;
       comB = calc();
}

void st() {

       cin >> pa >> pb >> k >> l;

       pa /= 100;
       pb /= 100;
       pa1 = 1 - pa;
       pb1 = 1 - pb;

       calcComA(); calcComB();

       //cout << comA << " " << comB << endl;

       int i,j;
       double g[200][200];
       double v1 = 0;
       int o;
       double t1;

       FOR(i,k+1) FOR(j,k+1) g[i][j] = 0;
       g[0][0] = 0.5;
       for(i=0;i!=k;i++) {
               for(j=0;j!=k;j++) {
                       if((i + j)%2==1) t1 = comA;
                       else t1 = comB;
                       g[i+1][j] += g[i][j] * t1;
                       g[i][j+1] += g[i][j] * (1-t1);
               }
       }
       for(j=0;j!=k;j++) v1 += g[k][j];

       FOR(i,k+1) FOR(j,k+1) g[i][j] = 0;
       g[0][0] = 0.5;
       for(i=0;i!=k;i++) {
               for(j=0;j!=k;j++) {
                       if((i + j)%2==1) t1 = comB;
                       else t1 = comA;
                       g[i+1][j] += g[i][j] * t1;
                       g[i][j+1] += g[i][j] * (1-t1);
               }
       }
       for(j=0;j!=k;j++) v1 += g[k][j];

       printf("%.1lf\n",v1*100);

}

int main() {

       int t;
       cin >> t;
       while(t--) st();
       return 0;

}