#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

char *ltoa(long n, char *out, int rout) {
	int p = 0;
	char temp[50];
	long t;
	while(n > 0) {
		t = n % rout;
		if(t<10) temp[p] = '0' + t;
		else temp[p] = 65 + t - 10;
		p++;
		n /= rout;
	}
	if(p==0) temp[p++] = '0';
	for(int i=0;i!=p;i++) {
		out[i] = temp[p-i-1];
	}
	out[p] = '\0';
	return out;
}

/*
**  Calling parameters: 1 - Number string to be converted
**                      2 - Buffer for the  converted output
**                      3 - Radix (base) of the input
**                      4 - Radix of the output
**  Returns: Pointer to converted output
*/
char *base_convert(const char *in, char *out, int rin, int rout)
{
      long n;
      char *dummy;
      n = strtol(in, &dummy, rin);
      dummy = ltoa(n, out, rout);
      return dummy;
}

int main() {

	int i;
	char s[30], t[50], stam, ttam;
	int baseAtual;
	int novaBase;
	char *b10, b10tam;

	while((cin >> s >> baseAtual >> novaBase)) {

		stam = strlen(s);

		b10 = base_convert((const char*) s, t, baseAtual, novaBase);
		if((i=strlen(b10))>7) {
			cout << "  ERROR" << endl;
		} else {
			while(i++!=7) {
				putchar(' ');
			}
			cout << b10 << endl;
		}

	}

}
