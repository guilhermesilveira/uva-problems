Dentre duas sequencias de k numeros, verifica qual o maximo de
elementos da segunda sequencia maior que da primeira (guloso com sort)

#include <iostream>
#define FOR(a,b) for(a=0;a<b;a++)
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int val(char *c) {
       int v;
       if(c[0]>='2' && c[0]<='9') v = c[0] - '2' + 2;
       else if(c[0]=='T') v = 10;
       else if(c[0]=='J') v = 11;
       else if(c[0]=='Q') v = 12;
       else if(c[0]=='K') v = 13;
       else v = 14;
       v *= 10;
       if(c[1]=='H') v += 4;
       else if(c[1]=='S') v += 3;
       else if(c[1]=='D') v += 2;
       else v += 1;
       return v;
}

bool cmp(const int a,const int b) {
       return a>b;
}

void st() {
       int i,j,k;
       cin >> k;
       vector<int> v[2];
       bool vis[27];
       char c[10];
       for(i=0;i!=k;i++) vis[i]=false;
       FOR(j,2) {
               v[j].resize(k);
               FOR(i,k) {
                       cin >> c;
                       v[j][i] = val(c);
               }
               sort(v[j].begin(),v[j].end(),cmp);
       }
       int tot = 0;
       //FOR(i,k) { cout << v[0][i] << " "; } cout << endl;
       //FOR(i,k) { cout << v[1][i] << " "; } cout << endl;
       FOR(i,k) {
               FOR(j,k) {
                       if(vis[j]) continue;
                       if(v[0][j]<v[1][i]) {
                               tot++;
                               vis[j] = true;
                               break;
                       }
               }
               if(j==k) break;
       }
       cout << tot << endl;
}

int main() {

       int t;
       cin >> t;
       while(t--) st();

}