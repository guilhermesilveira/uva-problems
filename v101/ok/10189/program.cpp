#include <stdio.h>
#define MAX_LENGTH 101

int main(char **argv,int argc) {

	int m,n,i,x;
	char ultimaLinha[MAX_LENGTH];
	char linha[MAX_LENGTH];
	int field = 1;
	
	while(true) {
	
		// le o valores do campo
		scanf("%d %d",&m,&n);
		
		// para se os dois forem zero
		if(m==0 && n==0) {
			break;
		}
		
		if(field!=1) {
			printf("\n");
		}
		
		printf("Field #%d:\n",(field++));
		
		// se n ou m = 0, continua
		if(n==0 || m==0) {
			continue;
		}
		
		ultimaLinha[n] = 0;
		
		// parseioa a primeira linha
		for(i=0;i!=m;i++) {
		
			// le a linha inteira
			scanf("%s\n",&linha);
			//printf("lido: %s\n",linha);
			
			if(linha[0]=='.') {
				linha[0]='0';
			}

			// compara com o anterior
			for(x=1;x<n;x++) {
				if(linha[x]=='.') {
					// se essa eh . e a anterior bomba, explode
					linha[x] = linha[x-1]=='*' ? '1' : '0';
				} else if(linha[x-1]!='*'){
					// essa eh uma bomba 
					// se a anterior nao era
					// soma uma bomba na anterior
					linha[x-1]++;
				}
			}
			
			if(i!=0) {
			
				// compara com a linha anterior
				for(x=0;x<n;x++) {
					if(linha[x]!='*') {
						// se essa eh .
						// se a anterior eh bomba, soma um
						if(ultimaLinha[x]=='*') {
							linha[x]++;
						}
						if(x>0 && ultimaLinha[x-1]=='*') {
							linha[x]++;
						}
						if(x!=n-1 && ultimaLinha[x+1]=='*') {
							linha[x]++;
						}
					} else {
						// essa eh uma bomba 
						// se a anterior nao era
						// soma uma bomba na anterior
						if(ultimaLinha[x]!='*') {
							ultimaLinha[x]++;
						}
						if(x>0 && ultimaLinha[x-1]!='*') {
							ultimaLinha[x-1]++;
						}
						if(x!=n-1 && ultimaLinha[x+1]!='*') {
							ultimaLinha[x+1]++;
						}
					}
				}
				
				// imprime a linha anterior
				printf("%s\n",ultimaLinha);
				
			}
			
			// copia a linha em linha anterior
			for(x=0;x!=n;x++) {
				ultimaLinha[x] = linha[x];
			}
			
		}
		
		printf("%s\n",ultimaLinha);
		
	}

	return 0;

}
