#include <stdio.h>
#include <stdlib.h>

int 
cmpFunc (const void *a, const void *b)
{
  return ( *(long*)a - *(long*)b );

}


int main(int argc, char **argv) {

	int size, i, questions, meioInicial, posAtual, leftLimit, rightLimit;
	int iterative;
	long tamanhos[50000], quest;
	
	scanf("%d",&size);
	
	for(iterative = 0,i = 0; i != size; i++) {

		scanf("%ld", &quest);
		
		if(!bsearch(&quest,tamanhos,iterative,sizeof(long),cmpFunc)) {
			tamanhos[iterative++] = quest;
		}/* else {
			printf("skipping %ld\n", quest); 
		}*/

	}
	
	size = iterative;
	/*/for(i = 0; i != size; i++) printf("%ld ", tamanhos[i]);
	//printf("\n");*/

	meioInicial = size / 2; 
	/*/printf("new total %d, meio::%d\n", size,meioInicial); */

	scanf(" %d",&questions);
	for(i = 0; i != questions; i++) {
		
		scanf("%ld", &quest);
		
		if(quest > tamanhos[size-1]) {
			printf("%ld X\n",tamanhos[size-1]);
			continue;
		}
		
		if(quest < tamanhos[0]) {
			printf("X %ld\n",tamanhos[0]);
			continue;
		}
		
		if(size == 1) {
			/* quer dizer que ele eh o unico valor na lista */
			printf("X X\n");
			continue;
		}
		
		posAtual = meioInicial;
		leftLimit = 0;
		rightLimit = size;
		iterative = 0;

		while(1) {
			
			if(tamanhos[posAtual] > quest && tamanhos[posAtual-1] < quest) {
				break;
			}
			
/*			printf("searching for %ld @ %d (=%ld) [%d-%d]\n",quest,posAtual,tamanhos[posAtual],leftLimit,rightLimit); */
			
			if(tamanhos[posAtual] < quest) {
				leftLimit = posAtual;
				posAtual = leftLimit + ((rightLimit - leftLimit) / 2);
			} else if(tamanhos[posAtual] == quest) {
				if(posAtual == 0) {
					/* se achou na primeira posicao e tem mais de 1 */
					printf("X %ld\n",tamanhos[posAtual+1]);
					goto proximo;
				} else if(posAtual==size-1) {
					/* esta no fim */
					printf("%ld X\n",tamanhos[posAtual-1]);
					goto proximo;
				} else {
					/* esta no meio*/
					printf("%ld %ld\n",tamanhos[posAtual-1],tamanhos[posAtual+1]);
					goto proximo;
				}
			} else {
				/* entao eh maior */
				rightLimit = posAtual;
				posAtual = leftLimit + (rightLimit - leftLimit) / 2;
			}

/*/			if(iterative++==10) break;*/
			
		}
		
		printf("%ld %ld\n",tamanhos[posAtual-1],tamanhos[posAtual]);
		proximo:
		iterative = 0;
		
	}


	return 0;

}
