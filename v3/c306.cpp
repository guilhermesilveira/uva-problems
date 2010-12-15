#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;
#define FOR(a,b) for(a=1;a<=b;a++)

int main() {
    

	int m,k;
	char c[210], pkc[210];
	int nciclos, p[210], ciclode[210], ciclo[210][210]; //salvar em c[i][0] o tam do ciclo i
	int i, j, l, pos;

	while(true) {
		scanf("%d",&m);
		if(!m) break;
		
        //inicializa tudo com 0
		FOR(i,m) { cin >> p[i]; ciclode[i] = 0; ciclo[i][0]=0; FOR(j,m) ciclo[i][j] = 0;}
        nciclos = 0;
        pkc[m+1] = '\0';
		//fatora p em ciclos
		for (i = 1; i <= m ; i++) {
            if(ciclode[i] == 0){
                          nciclos++;
                          j = i;
                          k = 1;
                          do {  ciclo[nciclos][0]++;
                                ciclo[nciclos][k] = j;
                                ciclode[j] = nciclos;
                                j = p[j];
                                k++;
                          }   while (j != i);
            }    
        }
        
//        FOR(i,m) {FOR(j,m) cout << ciclo[i][j] << " "; cout << endl;}

        while(true) {

			scanf("%d",&k);
			if(k==0) { scanf(" "); break;}

            //le c
			gets(c);
			l = strlen(c);
			while(l<=m) c[l++] = ' ';
			c[m+1]='\0'; 
            
            //salva a permutacao de c em pkc
			FOR(i,nciclos) {
                   l = ciclo[i][0];
                   FOR(j,l){
                            pos = (j+k)%l;
                            if(pos == 0) pos = l;
                            pkc[ciclo[i][pos]] = c[ciclo[i][j]];
                   }                        
            }
			cout << &pkc[1] << endl;
		}
		cout << endl;
	}
}
