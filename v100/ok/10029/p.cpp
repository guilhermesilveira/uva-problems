#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

int compara(const void *v1, const void *v2) {
	return strcmp((char *)v1,(char *)v2);
}

int main() {
    
    int c = -1;
    register int i,j,l1,l2,k;
	char *vetor = (char *) malloc(30001 * 19);
	char **hs = (char **) malloc(sizeof(char *) * 30001);
	char *tam = (char *) malloc(sizeof(char) * 30001);
	int *vet = (int *) malloc(sizeof(int) * 30001);
	
    while ((scanf(" %s",&vetor[++c * 19]))==1) {
    	hs[c] = &vetor[c * 19];
	    vet[c] = 1;
    }

    /*for(i=0;i!=c;i++) {
    	cout << hs[i] << endl;
    }*/
    qsort(vetor,c,19,compara);
    
    char mudou;
    int maxv = 1;
    
    for (i = 0; i != c; i++) {
    	tam[i] = strlen(hs[i]);
    }
    
    for (i = 0; i != c; i++) {
    	l1 = tam[i];
    	for(j=i+1;j<c;j++) {
    		if(vet[i] + 1 > vet[j]) {
    			k = tam[j] - l1;
	    		if(k==0) {
	    			mudou = 0;
	    			for(k=0;k!=l1;k++) {
	    				if(hs[i][k]!=hs[j][k]) {
	    					if(mudou==1) goto n;
	    					else mudou = 1;
	    				}
	    			}
	    			if(mudou==1) vet[j] = vet[i] + 1;
    			} else if(k==-1) {
    				// perdeu uma letra
    				mudou = 0;
    				for(k=0;k!=l1;k++) {
    					if(hs[i][k+mudou]!=hs[j][k]) {
    						if(mudou==1) goto n;
    						else mudou = 1;
    					}
    				}
    				if(mudou==1) vet[j] = vet[i] + 1;
	    		} else if(k==1) {
	    			// ganhou uma letra
	    			mudou = 0;
	    			for(k=0;k!=11;k++) {
    					if(hs[i][k]!=hs[j][k+mudou]) {
    						if(mudou==1) goto n;
    						else mudou = 1;
    					}
	    			}
    				if(mudou==1) vet[j] = vet[i] + 1;
	    		}
    		}
    		n:;
    	}
    	if(vet[i]>maxv) maxv=vet[i];
    }
    printf("%d\n",maxv);
}
