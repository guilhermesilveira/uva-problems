#include <stdio.h>
#include <iostream>
#include <string>

#define MAIOR 1
#define MENOR 2
#define NAO_SEI 0

#define IMPRIME_TRUE printf("Stan may be honest\n")
#define IMPRIME_FALSE printf("Stan is dishonest\n")

#define VALOR(a) a=='h' ? MAIOR : MENOR

using namespace std;

int main(char **argv,int argc) {

	char val;
	char answer[15];
	bool mayBeTrue;
	int chute[11],i;
	
	while(true) {
	
		proximo:
	
		for(i=0;i!=11;i++) {
			chute[i] = NAO_SEI;
		}

		mayBeTrue = true;
		while(true) {

			scanf("%d\n",&val);
			if(val == 0) {
				return 0;
			}

			fgets(answer,10,stdin);

			if(answer[0]=='r') {
			
				for(i=1;i!=11;i++) {
				
					if(chute[i]!=NAO_SEI) {
						if(i < val && chute[i]!=MENOR) {
							IMPRIME_FALSE;
							goto proximo;
						} else if(i > val && chute[i]!=MAIOR) {
							IMPRIME_FALSE;
							goto proximo;
						} else if(i==val) {
							// nao pode ter dado outra resposta para ele!!
							IMPRIME_FALSE;
							goto proximo;
						}
					}
					
				}
				IMPRIME_TRUE;
				// achou, para
				break;

			}

			// se ja existia esta resposta
			if(chute[val] != NAO_SEI) {
				// se for diferente do que ja estava
				if(chute[val] != (VALOR(answer[4]))) {
					IMPRIME_FALSE;
					// le ate o fim
					while(val != 0 && answer[0]!='r') {
						scanf("%d\n",&val);
						fgets(answer,10,stdin);
					}
					break;
				}
				continue;
			}

			chute[val] = VALOR(answer[4]);

		}
		
	}

	return 0;

}
