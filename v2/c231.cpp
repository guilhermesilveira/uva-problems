#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

      int temp, tot=0, inst = 0,i,j,k;
      int val[100000];
      long quantia[100000],m=1;
      while(true) {

              tot = 0;
              m = 1;
              while(true) {
                      scanf("%d",&val[tot]);
                      if(val[tot]==-1) break;
                      tot++;
              }
              if(tot==0) return 0;

              for(i=0;i<tot;i++) {
                      quantia[i] = 1;
              }
              for(i=0;i<tot;i++) {
                      for(j=i+1;j<tot;j++) {
                              if(val[j]<=val[i] && quantia[j]<quantia[i]+1) quantia[j] = quantia[i] + 1;
                      }
                      if(quantia[i]>m) m = quantia[i];
              }

              printf("Test #%d:\n  maximum possible interceptions: %ld\n",++inst,m);
              putchar('\n');

      }
      return 0;

}

