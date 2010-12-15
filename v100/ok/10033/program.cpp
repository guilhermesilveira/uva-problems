#include <stdio.h>
#include <stdlib.h>

int main(char **argv,int argc) {

	int count;
	int i;
	
	int registers[10];
	int ram[1000];
	char line[5];
	
	int executado;
	int temp;
	
	int a,b,c;
	
	scanf("%d\n",&count);

	while(count--) {
	
		// limpando tudo
		for(i=0;i!=10;i++) {
			registers[i] = 0;
		}
		
		for(i=0;i!=1000;i++) {
			ram[i]=0;
		}

		executado = 0;
		
		i = 0;

		// lendo a ram
		while(gets(line)!=0) {
		
			if(!line[0]) {
				break;
			}
			ram[i++]=atoi(line);
			//printf("%d: %d\n",i-1,ram[i-1]);
	
		}
		
		i = 0;
		
		a = ram[i] / 100;
		
		// executando a ram
		while(true) {
		
			a = ram[i] / 100;
			b = (ram[i] / 10) % 10;
			c = ram[i] % 10;
			//printf("%d, %d: %d %d %d\n", executado, i, a,b,c);
			
			if(a==1) {
				executado++;
				break;
			} if(a==2) {
				registers[b]=c;
			} else if(a==3) {
				registers[b] = (registers[b] + (c)) % 1000;
			} else if(a==4) {
				registers[b] = (registers[b] * (c)) % 1000;
			} else if(a==5) {
				registers[b] = registers[c];
			} else if(a==6) {
				registers[b] = (registers[b] + registers[c]) % 1000;
			} else if(a==7) {
				registers[b] = (registers[b] * registers[c]) % 1000;
			} else if(a==8) {
				registers[b] = ram[registers[c]];
			} else if(a==9) {
				ram[registers[c]] = registers[b];
			} else if(a==0 && registers[c]!=0) {
				i = registers[b];
				executado++;
				continue;
			}
			
			executado++;
			i++;

		}

		printf("%d\n",executado);
		if(count) {
			printf("\n");
		}

	}

	return 0;

}
