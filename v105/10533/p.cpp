#include <stdio.h>
#include <math.h>

#define MAX (1000000)

int main () {

	register int i,pc=1;
	long c;
	int p[100000],m,j,k;
	p[0] = 2;
	long MMAX = (long) sqrt(MAX);
	int pz[MMAX+100];
	pz[2] = 1;
	pz[1] = 0;
	pz[0] = 0;

	for(i=3;i<=MMAX;i++) {
		pz[i] = 0;
	}
	
	for(i=3;i<=MMAX;i+=2) {
		for(j=1;j<pc;j++) {
			if(i % p[j] == 0) goto n;
		}
		// verifica a soma dos digitos tambem e'
		k = i; j = i;
		printf("tenta:::: %d\n",i);
		do {
		k=j;
		printf("tenta: %d,",k);
		while(k!=0) {
			j += (k%10);
			k /= 10;
		printf("tenta: %d,",k);
		printf("saiu: %d",j);
		}
		printf("saiu: %d",j);
		}while(j>=10);
		if(i!=j && pz[j]==0) { printf("Nao er: %d %d\n",i,j); continue; }
		if(i<100) printf("OK: %d %d\n",i,j);
		p[pc++] = i;
		pz[i] = 1;
		//printf("primos: %d\n",i);
		n:;
	}
	
	printf("primos: %d\n",pc);

	scanf("%d",&k);
	while(k--) {
		scanf("%d %d",&j,&m);
		c = 0;
		for(i=j;i<=m;i++) {
			if(pz[i]==1) {
				printf("%d eh\n",i);
				c++;
			}
		}
		printf("%ld\n",c);
	}

	return 0;

}
