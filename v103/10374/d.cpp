#include <stdio.h>
#include <string.h>

int main() {

	int i,j,k,l,m,n,o,p;
	char part[30][100];
	char cand[30][100];
	bool val[30];
	int  capa[30];
	int  voto[30];
	int cand_c;
	char s[100];

	scanf("%d\n",&p);
	while(p--) {

		scanf("%d\n",&cand_c);
		for(i=0;i!=cand_c;i++) {
			gets(cand[i]);
			gets(part[i]);
		}

		// candidates
		for(i=0;i!=cand_c;i++) val[i]=0;
		for(i=0;i!=cand_c;i++) {
			for(j=0;j!=cand_c;j++) {
				if(strcmp(part[j],part[i])==0) {
					capa[i]=j;
					val[j]=1;
					break;
				}
			}
		}

		scanf("%d\n",&o);
		for(i=0;i!=cand_c;i++) voto[i]=0;

		// votes, please
		while(o--) {
			gets(s);
			for(i=0;i!=cand_c;i++) {
				if(strcmp(cand[i],s)==0) {
					voto[capa[i]]++;
					break;
				}
			}
		}

		j=0;
		// finds the maximum voted
		for(i=1;i<cand_c;i++) if(val[i] && voto[i]>voto[j]) j = i;

		// is it a tie?
		for(i=0;i<cand_c;i++) {
			if(val[i] && i!=j && voto[i]==voto[j]) {
				printf("tie\n");
				goto nex;
			}
		}

		// not a tie, go ahead
		printf("%s\n",part[j]);
		
		nex:
		if(p) printf("\n");

	}
	return 0;

}
