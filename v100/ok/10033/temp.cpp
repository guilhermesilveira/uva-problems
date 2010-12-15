#include <stdio.h>

int main(char **argv,int argc) {

	int count;
	int i;
	
	int registers[10];
	char ram[1000][4];
	
	int executado;
	int temp;
	
	scanf("%d\n",&count);

	while(count--) {
		
		for(i=0;i!=10;i++) {
			registers[i] = 0;
		}
		for(i=0;i!=1000;i++) {
			ram[i][0]=0;
			ram[i][1]=0;
			ram[i][2]=0;
			ram[i][3]=0;
		}
		executado = 0;
		i = 0;

		while(true) {
		
			ram[i][0]=getchar();
			// se for menor que 0, eh erro, fim
			if(ram[i][0]<48) {
				break;
			}
			ram[i][1]=getchar();
			ram[i][2]=getchar();
			getchar();
			/*scanf("%s",&ram[i]);*/
			//printf("%d: %c %c %c\n",i,ram[i][0],ram[i][1],ram[i][2]);
			
			/* se for menor que o correto */
			/*if(ram[i][0]==13 || ram[i][0]==10 || ram[i][0]==0) {
				ram[i][0]=0;
				ram[i][1]=0;
				ram[i][2]=0;
				ram[i][3]=0;
				break;
			}*/
			
			ram[i][0]-=48;
			ram[i][1]-=48;
			ram[i][2]-=48;
			
			//printf("%d %d %d\n", ram[i][0],ram[i][1],ram[i][2]);
			i++;
			
		}
		
		i = 0;
		
		// o while eh ate parar
		//while(false) {
		while(ram[i][0]!=1) {
		
			//printf("%d, %d: %d %d %d\n", executado, i, ram[i][0],ram[i][1],ram[i][2]);
			
			if(ram[i][0]==2) {
				/* seta o registro b para o valor c */
				registers[ram[i][1]]=ram[i][2];
				executado++;i++;
			} else if(ram[i][0]==3) {
				/* adiciona*/
				registers[ram[i][1]] = (registers[ram[i][1]] + (ram[i][2])) % 1000;
				executado++;i++;
			} else if(ram[i][0]==4) {
				/* multiplica*/
				registers[ram[i][1]] = (registers[ram[i][1]] * (ram[i][2])) % 1000;
				executado++;i++;
			} else if(ram[i][0]==5) {
				/* copia */
				registers[ram[i][1]] = registers[ram[i][2]];
				executado++;i++;
			} else if(ram[i][0]==6) {
				/* adicionar registros*/
				registers[ram[i][1]] = (registers[ram[i][1]] + registers[ram[i][2]]) % 1000;
				executado++;i++;
			} else if(ram[i][0]==7) {
				/* multiplicar registros*/
				registers[ram[i][1]] = (registers[ram[i][1]] * registers[ram[i][2]]) % 1000;
				executado++;i++;
			} else if(ram[i][0]==8) {
				temp = registers[ram[i][2]];
				//printf("setando o registro %d com o valor em RAM[] com endereco no registro %d: RAM[%d]\n",ram[i][1],ram[i][2],registers[ram[i][2]]);
				registers[ram[i][1]] = ((ram[temp][0]))*100 + (ram[temp][1])*10 + ram[temp][2];
				executado++;
				i++;
			} else if(ram[i][0]==9) {
				// TESTAR
				//printf("setando a RAM[] com endereco no registro %d: RAM[%d]=%d\n",ram[i][1],registers[ram[i][1]],registers[ram[i][2]]);
				temp = registers[ram[i][1]];
				ram[temp][0] = registers[ram[i][2]] / 100;
				ram[temp][1] = (registers[ram[i][2]] /10 )% 10;
				ram[temp][2] = registers[ram[i][2]] % 10;
				executado++;
				i++;
			} else if(ram[i][0]==0) {
				if(registers[ram[i][2]]!=0) {
					i = registers[ram[i][1]];
				} else {
					i++;
				}
				executado++;
			}
			
			//if(executado==20) break;
			
		}

		/*for(i=0;i!=10;i++) {	
			printf("%d: %d\n" , i,registers[i]);
		}*/

		if(count!=0) {
			printf("%d\n\n",executado+1);
		} else {
			printf("%d\n",executado+1);
		}

	}

	return 0;

}
