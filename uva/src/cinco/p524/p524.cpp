#include <stdio.h>

#define ehPrimo(soma) (soma==3 || soma==5 || soma==7 || soma==11 || soma==13 || soma==17 || soma==19 || soma==23 || soma==29 || soma==31)

long maxV;
char lista[10000000];
long passado[17];
long posNalista;
long inicioUltimaCarreira;

void geraCopia() {
	long zi;
	lista[inicioUltimaCarreira-1] = '\n';
	//cout << "inicioUltima: " << inicioUltimaCarreira <<  "-" << (posNalista-1) << endl;
	for(zi=inicioUltimaCarreira;zi<posNalista-1;zi++) {
		//cout << (zi+posNalista-inicioUltimaCarreira) << "=" << zi << endl;
		lista[(zi-inicioUltimaCarreira)+posNalista] = lista[zi];
	}
	//posNalista+=posNalista+1-(novo<10)?2:3;
	zi = posNalista;
	posNalista+=posNalista - inicioUltimaCarreira;
	inicioUltimaCarreira = zi;
	//std::cout << "(" << lista << ")" << std::endl;
}

void tenta(int nivel, int novo) {
	
	int zi;
	passado[novo] = 1;
	
	if(novo<10) {
		lista[posNalista] = (novo + '1' - 1);
		lista[posNalista+1] = ' ';
		posNalista+=2;
	} else {
		lista[posNalista] = ((novo/10) + '1' - 1);
		lista[posNalista+1] = ((novo%10) + '1' - 1);
		lista[posNalista+2] = ' ';
		posNalista+=3;
	}
	
	nivel++;
	
	if(nivel==maxV) {
		lista[posNalista-1] = 0;
		geraCopia();
		posNalista-=(novo<10)?2:3;
		passado[novo] = 0;
		return;
	}
	
	for(zi=1;zi!=maxV+1;zi++) {
		if(passado[zi]==0 && ehPrimo(zi+novo)) {
			if(nivel==maxV-1) {
				if(ehPrimo(zi+1)) {
					tenta(nivel,zi);
				}
			} else {
				tenta(nivel,zi);
			}
		}
	}
	
	passado[novo] = 0;
	posNalista-=(novo<10)?2:3;

}

int main(int argc, char **argv) {
	
	int counter = 0;
	int i;
	//long zi;
	
	while(scanf("%d",&maxV)==1) {
		
		posNalista = 0;
		counter++;
		inicioUltimaCarreira = 0;
		
		if(counter!=1) printf("\n");

		for(i=0;i!=maxV+1;i++) {
			passado[i]=0;
		}
		
		printf("Case %d: \n",counter);

		tenta(0,1);

		lista[posNalista-1] = 0;
		//for(zi=0;zi!=posNalista-1;zi++) {
		//	if(lista[zi]==0) lista[zi]='-';
		//}
		printf("%s\n",lista);
		//cout << posNalista << endl;
		
	}
	
	return 0;
	
}
