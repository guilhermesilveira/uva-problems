#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

       char lin[300];

       int len,i;
       while(true) {
               gets(lin);
               if(lin[3]=='O') break;
               gets(lin);
               len = strlen(lin);
               for(i=0;i!=len;i++) {
                       if(lin[i]>='A' && lin[i]<='Z') {
                               if(lin[i]<='E') lin[i] = lin[i] + 'V' - 'A';
                               else lin[i] = lin[i] + 'A' - 'F';
                       }
               }
               printf("%s\n",lin);
               gets(lin);
       }
       return 0;

}
