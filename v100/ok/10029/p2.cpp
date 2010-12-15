#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAXW 25002
#define MAXL 19
#define BACK (500)
#define HASH(x,l) (hash(x,l) % BACK)

int compara(const void *v1, const void *v2) {
	return strcmp((char *)v1,(char *)v2);
}

int hash(char *c,int len) {
	int tot = 0;
	for(int i=0;i!=len;i++) {
		tot = tot*32 + (c[i]-'a');
	}
	return tot<0?0-tot:tot;
}

int c = -1;
char **hs = (char **) malloc(sizeof(char *) * MAXW);

char **hashset[BACK];
class Link {
public:
	
};
int tot[BACK];

int find(char *s,int len,int hashcode) {
	int teto = tot[hashcode], meio, cmp;
	int chao = -1;
	while (teto - chao > 1) {
		meio = (teto + chao) / 2;
		cmp = strcmp(hashset[hashcode][meio], s);
		if (cmp > 0) teto = meio;
		else if (cmp < 0) chao = meio;
		else break;
	}
	return (cmp) ? -1 : meio;
}

int findHash(char *s,int len) {
/*	int hashcode = HASH(s,len), v;
	for(int i=0;i!=tot[hashcode];i++) {
		if((v=strcmp(hashset[hashcode][i],s))==0) return i;
		else if(v>0) return -1;
	}
	return -1;*/
	return find(s,len,HASH(s,len));
}

bool add(char *s,int len) {
	int hashcode = HASH(s,len);
	/*for(int i=0;i!=tot[hashcode];i++) {
		if(strcmp(hashset[hashcode][i],s)==0) return false;
	}*/
	hashset[hashcode][tot[hashcode]++] = s;
	return true;
}

int main() {
    
    int i,j,l1,l2,k;
	char *vetor = (char *) malloc(MAXW * MAXL);
	int valido[MAXW];

	for(i=0;i!=BACK;i++) {
		hashset[i] = (char **) malloc(sizeof(char *) * ((MAXW*3)/BACK));
		tot[i] = 0;
	}
	
    while ((scanf(" %s",&vetor[++c * MAXL]))==1) {
    	// vejamos se ja existe
//    	if(add(&vetor[c * MAXL],strlen(&vetor[c * MAXL]))) {
	    	hs[c] = &vetor[c * MAXL];
	    	valido[c] = 1;
//	    } else {
//	    	c--;
//	    }
    }
    
    qsort(vetor,c,MAXL,compara);

	for(i=0;i!=c;i++) {
		if(i==0 || strcmp(hs[i-1],hs[i])!=0) {
			add(hs[i],strlen(hs[i]));
		} else {
			valido[i] = 0;
		}
	}

/*	for(i=0;i!=BACK;i++) {
	    if(tot[i]!=0) {
//		    qsort(hashset[i],tot[i],MAXL,compara);
		    printf("%d:: ",i);
	    	for(j=0;j!=tot[i];j++) printf("%s,",hashset[i][j]);
		    printf("\n");
	    }
	}*/
	
    char mudou, novo[MAXL];
    int maxv = 1,l;
    
    for (i = 0; i != c; i++) {
    
    	if(!valido[i]) continue;
    
    	l1 = strlen(hs[i]);

    	strcpy(novo,hs[i]);

    	for(j=0;j!=l1;j++) {
    		mudou = novo[j];
    		for(k=mudou+1;k<='z';k++) {
	    		novo[j] = k;
	    		if(findHash(novo,l1)!=-1) {
//		    		printf("%s\n",novo);
	    		}
    		}
    		novo[j] = mudou;
    	}

    	// insere
    	novo[l1] = '\0';
    	for(j=0;j!=l1;j++) {
    		// DESDE 0??? desde J???
    		for(k=0;k!=l1;k++) {
    			if(k<j) {
    				novo[k] = hs[i][k];
    			} else {
    				novo[k+1] = hs[i][k];
    			}
    		}
    		for(k=novo[j]+1;k<='z';k++) {
    			novo[j] = k;
	    		if(findHash(novo,l1+1)!=-1) {
//		    		printf("%s\n",novo);
	    		}
    		}
    		novo[j] = hs[i][j];
    	}

		// remove
    	novo[l1-2] = '\0';
    	for(j=0;j!=l1;j++) {
    		// desde 0?? desde j??
    		for(k=0;k!=l1;k++) {
    			if(k<j) {
    				novo[k] = hs[i][k];
    			} else if(k>j){
    				novo[k-1] = hs[i][k];
    			}
    		}
    		for(k=novo[j]+1;k<='z';k++) {
    			novo[j] = k;
	    		if(findHash(novo,l1-1)!=-1) {
//		    		printf("%s\n",novo);
	    		}
    		}
    		novo[j] = hs[i][j];
    	}
    	
    }

    printf("%d\n",maxv);

}
