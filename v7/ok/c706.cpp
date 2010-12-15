#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)

int s;
char n[100];
char sai[30][500];

void imp(int n,int col) {
       int i;
       // direita inteiro
       if(n==1 || n==3 || n==4 || n>=7 || !n) {
               FOR(i,s) sai[i+s+2][col+s+1]=sai[i+1][col+s+1]='|';
       }
       // na esquerda inteira
       if(n==6 || n==8 || !n) {
               FOR(i,s) sai[i+s+2][col]=sai[i+1][col]='|';
       }
       // na esquerda em cima
       if(n==9 || n==4 || n==5) {
               FOR(i,s) sai[i+1][col]='|';
       }
       // na esquerda em baixo
       if(n==2) {
               FOR(i,s) sai[i+s+2][col]='|';
       }
       // em cima, horizontal
       if(n>=5 || n==2 || n==3 || !n) {
               FOR(i,s) sai[0][col+i+1]='-';
       }
       // no meio, horizontal
       if((n>=2 && n<=6) || n>=8) {
               FOR(i,s) sai[s+1][col+i+1]='-';
       }
       // em baixo, horizontal
       if(n==6 || n>=8 || n==2 || n==3 || n==5 || !n) {
               FOR(i,s) sai[2*s+2][col+i+1]='-';
       }
       if(n==5 || n==6) {
               FOR(i,s) sai[i+s+2][col+s+1]='|';
       }
       if(n==2 || n==4) {
               FOR(i,s) sai[i+1][col+s+1]='|';
       }
}

void st() {

       int i,l=strlen(n),j;
       int col = 0;
       FOR(i,2*s+3) FOR(j,500) sai[i][j]=' ';
       FOR(i,l) {
               if(i) col++;
//              cout << col << endl;
               imp(n[i]-'0',col);
               col += (s + 2);
       }
//      FOR(i,col) cout << (i%10); cout << endl;
       FOR(i,2*s+3) { sai[i][col]='\0'; cout << sai[i] << endl; }

}

int main() {
       while((cin >> s >> n)) {
               if(s==0 && n[0]=='0' && n[1]=='\0') break;
               st(); cout << endl;
       }
       return 0;
}