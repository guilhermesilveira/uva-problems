#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


// Converte da base b para a base 10, eh isso?

unsigned long long toBase10(const char *in, int b) {
	unsigned long long v = 0;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			v = v * b + ((*in)-'0');
		} else if((*in)>='A' && (*in)<='F') {
			v = v * b + ((*in)-'A'+10);
		}
		in++;
	}
	return v;
}

char *ltoa(unsigned long long n, char *out, int rout) {
	int p = 0;
	char temp[50];
	long long t;
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
      unsigned long long n;
      char *dummy;
      n = toBase10(in, rin);
      dummy = ltoa(n, out, rout);
      return dummy;
}


void st() {

	char st[2][40];
	cin >> st[0];
	char c;

	c = st[0][8];
	st[0][8] = '\0';
	base_convert(st[0],st[1],2,10);
	cout << st[1] << ".";
	st[0][8] = c;

	c = st[0][16];
	st[0][16] = '\0';
	base_convert(&st[0][8],st[1],2,10);
	cout << st[1] << ".";
	st[0][16] = c;

	c = st[0][24];
	st[0][24] = '\0';
	base_convert(&st[0][16],st[1],2,10);
	cout << st[1] << ".";
	st[0][24] = c;
	c = st[0][24];

	base_convert(&st[0][24],st[1],2,10);
	cout << st[1] << endl;

}


int main() {

	int t;
	cin >> t;
	while(t--) st();
	return 0;


}
