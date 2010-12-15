/* @JUDGE_ID: 39315ZN 131 C++ "Poker" */

#include "stdio.h"

#define STRAIGHTFLUSH	0
#define FOUROFAKIND		1
#define FULLHOUSE		2
#define FLUSH			3
#define STRAIGHT		4
#define THREEOFAKIND	5
#define TWOPAIRS		6
#define ONEPAIR			7
#define HIGHESTCARD		8

#define IGUAIS(a,b,c,d) (deck[a][0]==deck[b][0] && deck[a][0]==deck[c][0] && deck[a][0]==deck[d][0])
#define IGUAISTRES(a,b,c) (deck[a][0]==deck[b][0] && deck[a][0]==deck[c][0])
#define IGUAISDOIS(a,b) (deck[a][0]==deck[b][0])
#define DUASDUPLAS(a,b,c,d) ((IGUAISDOIS(a,b) && IGUAISDOIS(c,d)) || (IGUAISDOIS(a,c) && IGUAISDOIS(b,d)) || (IGUAISDOIS(a,d) && IGUAISDOIS(b,c)))

#define SEQUENCIATRES(a,b,c) (deck[a][0]+1==deck[b][0] && deck[b][0]+1==deck[c][0])
#define SEQUENCIAQUATRO(a,b,c,d) (deck[a][0]+1==deck[b][0] && deck[b][0]+1==deck[c][0] && deck[c][0]+1==deck[d][0])
#define SEQUENCIA(a,b,c,d,e) (deck[a][0]+1==deck[b][0] && deck[b][0]+1==deck[c][0] && deck[c][0]+1==deck[d][0] && deck[d][0]+1==deck[e][0])

char *resultados[9] = {
	"straight-flush",
	"four-of-a-kind",
	"full-house",
	"flush",
	"straight",
	"three-of-a-kind",
	"two-pairs",
	"one-pair",
	"highest-card"
};

int calculaPontos(int a,int b,int c,int d,int e,int resultado);

char deck[10][3];

inline int permutaUma(int resultado) {
	resultado = calculaPontos(5,1,2,3,4,resultado);
	resultado = calculaPontos(0,5,2,3,4,resultado);
	resultado = calculaPontos(0,1,5,3,4,resultado);
	resultado = calculaPontos(0,1,2,5,4,resultado);
	resultado = calculaPontos(0,1,2,3,5,resultado);
	return resultado;
}

inline int permutaQuatro(int resultado) {
	resultado = calculaPontos(5,6,7,8,4,resultado);
	resultado = calculaPontos(5,6,7,3,8,resultado);
	resultado = calculaPontos(5,6,2,7,8,resultado);
	resultado = calculaPontos(5,6,7,3,8,resultado);
	resultado = calculaPontos(5,6,7,8,4,resultado);
	return resultado;
}

inline int permutaTres(int resultado) {
	resultado = calculaPontos(0,1,5,6,7,resultado);
	resultado = calculaPontos(0,5,6,7,4,resultado);
	resultado = calculaPontos(0,5,2,6,7,resultado);
	resultado = calculaPontos(0,5,6,3,7,resultado);
	resultado = calculaPontos(5,1,2,6,7,resultado);
	resultado = calculaPontos(5,1,6,3,7,resultado);
	resultado = calculaPontos(5,1,6,7,4,resultado);
	resultado = calculaPontos(5,6,2,3,7,resultado);
	resultado = calculaPontos(5,6,2,7,4,resultado);
	resultado = calculaPontos(5,6,7,3,4,resultado);
	return resultado;
}

inline int permutaDuas(int resultado) {
	resultado = calculaPontos(0,1,2,5,6,resultado);
	resultado = calculaPontos(0,1,5,3,6,resultado);
	resultado = calculaPontos(0,1,5,6,4,resultado);
	resultado = calculaPontos(0,5,2,3,6,resultado);
	resultado = calculaPontos(0,5,2,6,4,resultado);
	resultado = calculaPontos(0,5,6,3,4,resultado);
	resultado = calculaPontos(5,1,2,3,6,resultado);
	resultado = calculaPontos(5,1,6,3,4,resultado);
	resultado = calculaPontos(5,6,2,3,4,resultado);
	return resultado;
}

const char LETRADEZ = '9' + 1;
const char LETRAONZE = '9' + 2;
const char LETRADOZE = '9' + 3;
const char LETRATREZE = '9' + 4;
const char LETRAQUATORZE = '9' + 5;

int main(int argc, char **argv) {
	
	while(scanf("%s %s %s %s %s %s %s %s %s %s",deck[0],deck[1],deck[2],deck[3],deck[4],deck[5],deck[6],deck[7],deck[8],deck[9])==10) {
		
		int resultado = HIGHESTCARD;
		
		printf("Hand: %s %s %s %s %s ",deck[0],deck[1],deck[2],deck[3],deck[4]);
		printf("Deck: %s %s %s %s %s ",deck[5],deck[6],deck[7],deck[8],deck[9]);
		
		// traduz as letras para numeros
		for(int i=0;i!=10;i++) {
			if(deck[i][0]=='A') {
				deck[i][0]='1';
			} else if(deck[i][0]=='T') {
				deck[i][0]=LETRADEZ;
			} else if(deck[i][0]=='J') {
				deck[i][0]=LETRAONZE;
			} else if(deck[i][0]=='Q') {
				deck[i][0]=LETRADOZE;
			} else if(deck[i][0]=='K') {
				deck[i][0]=LETRATREZE;
			}
		}
		
		//printf("Hand: %s %s %s %s %s ",deck[0],deck[1],deck[2],deck[3],deck[4]);
		//printf("Deck: %s %s %s %s %s ",deck[5],deck[6],deck[7],deck[8],deck[9]);

		// sem permutar
		resultado = calculaPontos(0,1,2,3,4,resultado);
		
		// permuta uma
		resultado = permutaUma(resultado);
		
		// permuta duas
		resultado = permutaDuas(resultado);
		
		// permuta tres
		resultado = permutaTres(resultado);
		
		// permuta quatro
		resultado = permutaQuatro(resultado);
		
		// permuta cinco
		resultado = calculaPontos(5,6,7,8,9,resultado);
		
		printf("Best hand: %s\n",resultados[resultado]);
		
	}

	return 0;

}

bool checaPara(int a,int b,int c,int d,int e) {
	if( deck[b][0]+1==deck[c][0] ) {
		if( SEQUENCIATRES(c,d,e) ||
		    SEQUENCIATRES(c,e,d) ||
		    SEQUENCIA(d,a,b,c,e) ||
		    SEQUENCIA(e,a,b,c,d) ||
		    SEQUENCIATRES(d,e,a) ||
		    SEQUENCIATRES(e,d,a) ) {
			return true;
		}
	} else if ( deck[b][0]+1==deck[d][0] ) {
		if( SEQUENCIATRES(d,c,e) ||
		    SEQUENCIATRES(d,e,c) ||
		    SEQUENCIA(c,a,b,d,e) ||
		    SEQUENCIA(e,a,b,d,c) ||
		    SEQUENCIATRES(c,e,a) ||
		    SEQUENCIATRES(e,c,a) ) {
			return true;
		}
	} else if ( deck[b][0]+1==deck[e][0] ) {
		if( SEQUENCIATRES(e,c,d) ||
		    SEQUENCIATRES(e,d,c) ||
		    SEQUENCIA(c,a,b,e,d) ||
		    SEQUENCIA(d,a,b,e,c) ||
		    SEQUENCIATRES(c,d,a) ||
		    SEQUENCIATRES(d,c,a) ) {
			return true;
		}
	} else {
		if( SEQUENCIAQUATRO(c,d,e,a) ||
		    SEQUENCIAQUATRO(c,e,d,a) ||
		    SEQUENCIAQUATRO(d,c,e,a) ||
		    SEQUENCIAQUATRO(d,e,c,a) ||
		    SEQUENCIAQUATRO(e,c,d,a) ||
		    SEQUENCIAQUATRO(e,d,c,a) ) {
			return true;
		}
	}
	return false;
}

bool checaNormal (int a,int b,int c,int d,int e) {
	if( deck[a][0]==deck[b][0]+1) {
		return checaPara(b,a,c,d,e);
	} else if ( deck[a][0]==deck[c][0]+1 ) {
		return checaPara(c,a,b,d,e);
	} else if ( deck[a][0]==deck[d][0]+1 ) {
		return checaPara(d,a,b,c,e);
	} else if ( deck[a][0]==deck[e][0]+1 ) {
		return checaPara(e,a,b,c,d);
	} else if ( deck[a][0]==deck[b][0]-1 ) {
		return checaPara(a,b,c,d,e);
	} else if ( deck[a][0]==deck[c][0]-1 ) {
		return checaPara(a,c,b,d,e);
	} else if ( deck[a][0]==deck[d][0]-1 ) {
		return checaPara(a,d,c,b,e);
	} else if ( deck[a][0]==deck[e][0]-1 ) {
		return checaPara(a,e,c,d,b);
	} else {
		// o a esta solto!!!
		return false;
	}
}

#define IGUAISQUATRO(a,b,c,d) (deck[A][0]==a && deck[B][0]==b && deck[C][0]==c && deck[D][0]==d)

bool checaQUATRO(int A,int B,int C,int D,char a,char b,char c,char d) {
	if(IGUAISQUATRO(a,b,c,d) ||
	   IGUAISQUATRO(a,b,d,c) ||
	   IGUAISQUATRO(a,c,b,d) ||
	   IGUAISQUATRO(a,c,d,b) ||
	   IGUAISQUATRO(a,d,b,c) ||
	   IGUAISQUATRO(a,d,c,b) ||
	   IGUAISQUATRO(b,a,c,d) ||
	   IGUAISQUATRO(b,a,d,c) ||
	   IGUAISQUATRO(b,c,a,d) ||
	   IGUAISQUATRO(b,c,d,a) ||
	   IGUAISQUATRO(b,d,a,c) ||
	   IGUAISQUATRO(b,d,c,a) ||
	   IGUAISQUATRO(c,a,b,d) ||
	   IGUAISQUATRO(c,a,d,b) ||
	   IGUAISQUATRO(c,b,a,d) ||
	   IGUAISQUATRO(c,b,d,a) ||
	   IGUAISQUATRO(c,d,a,b) ||
	   IGUAISQUATRO(c,d,b,a) ||
	   IGUAISQUATRO(d,a,c,b) ||
	   IGUAISQUATRO(d,a,b,c) ||
	   IGUAISQUATRO(d,c,a,b) ||
	   IGUAISQUATRO(d,c,b,a) ||
	   IGUAISQUATRO(d,b,a,c) ||
	   IGUAISQUATRO(d,b,c,a)) {
	   	return true;
	} else {
		return false;
	}
}

bool IGUAL(int A,int B,int C,int D,int E,char a,char b,char c,char d,char e) {
	if(a==deck[A][0]) {
		return checaQUATRO(B,C,D,E,b,c,d,e);
	} else if(b==deck[A][0]) {
		return checaQUATRO(B,C,D,E,a,c,d,e);
	} else if(c==deck[A][0]) {
		return checaQUATRO(B,C,D,E,b,a,d,e);
	} else if(d==deck[A][0]) {
		return checaQUATRO(B,C,D,E,b,c,a,e);
	} else if(e==deck[A][0]) {
		return checaQUATRO(B,C,D,E,b,c,d,a);
	}
	return false;
}

bool checaEspecial (int a,int b,int c,int d,int e) {
	// 1 2 3 4 5
	if(IGUAL(a,b,c,d,e,'1','2','3','4','5'))
		return true;
	// 0 j q k 1
	else if(IGUAL(a,b,c,d,e,':',';','<','=','1'))
		return true;
	return false;
}

/* calcula o conteudo maximo de uma mao */
int calculaPontos(int a,int b,int c,int d,int e,int resultado) {
	
	bool mesmoNaipe = false;
	// todos sao do mesmo naipe
	if(deck[a][1]==deck[b][1] && deck[a][1]==deck[c][1] && deck[a][1]==deck[d][1] && deck[a][1]==deck[e][1]) {
		mesmoNaipe = true;
	}
	
	bool straight = false;
	// se algum for 1, faz o check especial
	if(deck[a][0]=='1' || deck[b][0]=='1' || deck[c][0]=='1' || deck[d][0]=='1' || deck[e][0]=='1') {
		if(checaEspecial(a,b,c,d,e)) {
			straight = true;
		}
	}
	else if(checaNormal(a,b,c,d,e)) straight = true;
	
	if(straight && mesmoNaipe) {
		if(resultado<STRAIGHTFLUSH)
			return resultado;
		return STRAIGHTFLUSH;
	}
	
	// four
	if( IGUAIS(a,b,c,d) || 
	    IGUAIS(a,b,c,e) || 
	    IGUAIS(a,b,e,d) || 
	    IGUAIS(a,e,c,d) || 
	    IGUAIS(e,b,c,d) ) {
    	if(resultado<FOUROFAKIND)
    		return resultado;
	    return FOUROFAKIND;
	}
	
	// fullhouse
	// tem que ter uma tripla e uma dupla
	// three
	if( (IGUAISTRES(a,b,c) && IGUAISDOIS(d,e)) || 
	    (IGUAISTRES(a,b,d) && IGUAISDOIS(c,e)) || 
	    (IGUAISTRES(a,b,e) && IGUAISDOIS(c,d)) || 
	    (IGUAISTRES(a,c,d) && IGUAISDOIS(b,e)) || 
	    (IGUAISTRES(a,c,e) && IGUAISDOIS(b,d)) || 
	    (IGUAISTRES(a,d,e) && IGUAISDOIS(b,c)) || 
	    (IGUAISTRES(b,c,d) && IGUAISDOIS(a,e)) || 
	    (IGUAISTRES(b,c,e) && IGUAISDOIS(a,d)) || 
	    (IGUAISTRES(b,d,e) && IGUAISDOIS(a,c)) || 
	    (IGUAISTRES(c,d,e) && IGUAISDOIS(a,b)) ) {
    	if(resultado<FULLHOUSE)
    		return resultado;
	    return FULLHOUSE;
	}
	
	
	// flush
	if(mesmoNaipe) {
		if(resultado<FLUSH)
			return resultado;
		return FLUSH;
	}
	
	// straight
	if(straight) {
		if(resultado<STRAIGHT)
			return resultado;
		return STRAIGHT;
	}
	
	// three
	if( IGUAISTRES(a,b,c) || 
	    IGUAISTRES(a,b,d) || 
	    IGUAISTRES(a,b,e) || 
	    IGUAISTRES(a,c,d) || 
	    IGUAISTRES(a,c,e) || 
	    IGUAISTRES(a,d,e) || 
	    IGUAISTRES(b,c,d) || 
	    IGUAISTRES(b,c,e) || 
	    IGUAISTRES(b,d,e) || 
	    IGUAISTRES(c,d,e) ) {
    	if(resultado<THREEOFAKIND)
    		return resultado;
	    return THREEOFAKIND;
	}
	
	// two pairs
	if (DUASDUPLAS(a,b,c,d) ||
		DUASDUPLAS(a,b,d,e) ||
		DUASDUPLAS(a,c,d,e) ||
		DUASDUPLAS(b,c,d,e)) {
    	if(resultado<TWOPAIRS)
    		return resultado;
	    return TWOPAIRS;
	}

	// one pair
	if( IGUAISDOIS(a,b) || 
	    IGUAISDOIS(a,c) || 
	    IGUAISDOIS(a,d) || 
	    IGUAISDOIS(a,e) || 
	    IGUAISDOIS(b,c) || 
	    IGUAISDOIS(b,d) || 
	    IGUAISDOIS(b,e) || 
	    IGUAISDOIS(c,d) || 
	    IGUAISDOIS(c,e) || 
	    IGUAISDOIS(d,e) ) {
    	if(resultado<ONEPAIR)
    		return resultado;
	    return ONEPAIR;
	}
	
	// se nao possui nada, retorna nada
	return resultado;
	
}

