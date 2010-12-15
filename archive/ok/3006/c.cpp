#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char l[300];
char comandos[300];
int lencmd;
int len;

bool exec(char c,int p) {

       if(p==-1) return false;

       char &ch = l[p];

       if(c=='R' || c=='L') {
               if(ch=='1') ch='2';
               else if(ch=='2') ch='1';
               else if(ch=='3') ch='4';
               else if(ch=='4') ch='3';
               if(c=='R' && (ch=='1' || ch=='4')) return exec(c,p-1);
               else if(c=='L' && (ch=='2' || ch=='3')) return exec(c,p-1);
       } else if(c=='U' || c=='D') {
               if(ch=='1') ch='4';
               else if(ch=='2') ch='3';
               else if(ch=='3') ch='2';
               else if(ch=='4') ch='1';
               if(c=='U' && (ch=='4' || ch=='3')) return exec(c,p-1);
               else if(c=='D' && (ch=='1' || ch=='2')) return exec(c,p-1);
       }

       return true;

}

bool cmd() {

       for(int i=0;i!=lencmd;i++) {
               char c = comandos[i];
               if(!exec(c,len-1)) return false;
       }
       return true;

}

int main() {

       while(true) {
               cin >> l >> comandos;
               if(l[0]=='E') break; len = strlen(l); lencmd = strlen(comandos);
               if(cmd()) cout << l << endl;
               else cout << "OUT" << endl;
       }
       return 0;

}