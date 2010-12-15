#include <iostream>
#include <stdio.h>

using namespace std;

char pi[100000];

void infixaParaPosfixa () {

   int t;
   int n, i, j;

   char inf;
   t = 0;

   i = 1; j = 0;
   int val = 0;

   pi[t++] = '(';                          // empilha '('
   while((scanf("%c",&inf))==1) {
	//cout << "c " << inf << " v " << val  << endl;
      // a pilha está em pi[0..t-1]
      switch (inf) {
         char x;
         case '(': pi[t++] = inf;          // empilha
		   val=1;
                   break;
         case ')': while (1) {                // desempilha
                      x = pi[--t];
                      if (x == '(') break;
                      putchar(x);
                   }
		   val=1;
                   break;
         case '+': 
         case '-': while (1) {
                      x = pi[t-1];
                      if (x == '(') break;
                      --t;                    // desempilha
                      putchar(x);
                   }
                   pi[t++] = inf;          // empilha
		   val=1;
                   break;
         case '*':
         case '/': while (1) {
                      x = pi[t-1];
                      if (x == '(' || x == '+' || x == '-') 
                         break;
                      --t;
                      putchar(x);
                   }
                   pi[t++] = inf;
		   val=1;
                   break;
	 case '\r':
		break;
	 case '\n':
	 case '\0':
		//cout << "fim de linha " << val << endl;
		if(val==0) goto f;
		val = 0;
	 	break;
         default:
		putchar(inf);
		val = 1;
		break;
	i++;
      }
   }
f:
	while (1) {
	// desempilha
		char x = pi[--t];
		if (x == '(') break;
		putchar(x);
	}
	val=1;
	//cout << "fim" << endl;
}  

int main() {

	int n;
	cin >> n;
	while(n--) {
		scanf(" ");
		infixaParaPosfixa();
		if(n) putchar('\n');
	}
	return 0;


}
