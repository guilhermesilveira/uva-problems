#include <iostream>

using namespace std;

bool npode[2000];

bool sobra[2000];

int inst[4000][2];
int r,n;
int instinv;

void tenta() {

       int i,j,k,l;
       for(i=0;i!=n;i++) npode[i] = true;

       for(i=0;i!=r;i++) {
               // se for para ignora,  ignora
               if(instinv==i) continue;
               if(npode[inst[i][0]] && npode[inst[i][1]]) {
                       // se os dois podem, o segundoi nao pode
                       npode[inst[i][1]] = false;
               } else if(!npode[inst[i][0]] && npode[inst[i][1]]) {
                       // se o primeiro nao pode e o segundo pode
                       // entao o primeiro pode e o segundo nao pode
                       npode[inst[i][0]] = true;
                       npode[inst[i][1]] = false;
               }
       }

       // agora verifica quantos sobraram
       int tot = 0;
       for(i=1;i<n;i++) {
               if(npode[i]) {
                       sobra[i] = true;
               }
       }

}

void st() {

       int i,j,k;
       cin >> n >> r;
       for(i=0;i!=r;i++) { cin >> inst[i][0] >> inst[i][1]; inst[i][0]--;
inst[i][1]--; }
       instinv = -1;
       for(i=0;i!=n;i++) sobra[i] = false;
       tenta();
       int soma = 0;
       for(i=1;i<n;i++) {
		if(sobra[i]) {
			inst[r][0] = 0;
			inst[r][1] = i;
			r++;
			soma++;
		}
	}
       for(i=0;i!=n;i++) sobra[i] = false;
       for(j=0;j!=r;j++) {
               instinv = j;
               tenta();
       }
       for(j=1;j<n;j++) if(sobra[j]) soma++;
       cout << soma << endl;

}

int main() {

       int t,inst=0;
       cin >> t; while(t--) {  st();}
       return 0;

}
