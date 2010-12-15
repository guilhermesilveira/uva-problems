#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[15],s2[15],u[15];
int len;

int strcmp2(const void *c1, const void *c2) {
       char *s1 = (char *) c1;
       char *s2 = (char *) c2;
       return (*s1)-(*s2);
}

void permuta(int l) {
       char las = 0; int i;
       if(l==len) {
               printf("%s",s2);
               return;
       }
       for(i=0;i<len;i++) {
               if(!u[i] && s1[i]!=las) {
                       u[i]=1;
                       las = s2[l] = s1[i];
                       permuta(l+1);
                       u[i]=0;
               }
       }
}

int main() {
       int n,i;
       scanf("%d",&n);
       while(n--) {
               scanf("%s",s1);
               len = strlen(s1);
               qsort(s1,len,1,strcmp2);
               s2[len]='\n';s2[len+1]='\0';
               for(i=0;i!=len;i++) u[i] = 0;
               permuta(0); printf("\n");
       }
}