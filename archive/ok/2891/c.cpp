// backtracking

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;
int mini;
bool con[200][200];
int cor[100];
int viz[200];

int s;

void tenta(int proximo,int colocados) {

       if(proximo==n || colocados==s) {
               if(colocados!=s) return;
/*              for(int j=0;j!=n;j++) if(cor[j]==1) cout << (char) (j+'A') << " ";
               cout << endl;
               for(int i=0;i!=n;i++) {
                       cout << cor[i] << " " << viz[i] << "    ";
               }
               cout << endl;*/
               for(int i=0;i!=n;i++) if(cor[i]==0 && viz[i]>=2) return;
               mini++;
               return;
       }

       // tenta pintar
       int i;
       cor[proximo] = 1;
       for(i=0;i!=n;i++) if(con[i][proximo]) {
               viz[i]++;
       }
       tenta(proximo+1, colocados+1);
       for(i=0;i!=n;i++) if(con[i][proximo]) viz[i]--;
       cor[proximo] = 0;

       // tenta nao pintar
       tenta(proximo+1,colocados);

}

bool st() {

       int i,j,k,l,c;

       char theend[8] = "TheEnd\0";
       char name[30];
       cin >> name;
       cout << name << endl;
       i = strlen(name);
       if(name[i-1]=='\n' || name[i-1]=='\r') name[i-1]='\0';
       if(strcmp(name,theend)==0) return false;

       cin >> n >> s >> c;

       for(i=0;i!=n;i++) for(j=0;j!=n;j++) con[i][j] = 0;
       for(i=0;i<=n;i++) cor[i] = viz[i] = 0;

       for(i=0;i!=c;i++) {
               cin >> name;
               j = name[0]-'A';
               k = name[1]-'A';
               con[j][k]=con[k][j]=1;
       }

       mini = 0;

       tenta(0,0);

       cout << mini << endl;

       return true;

}

int main() {

       while(st());
       return 0;

}