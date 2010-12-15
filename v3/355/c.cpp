#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void preenche(char *c,int nl, char nchar) {
	int len = strlen(c);
	if(len>=nl) return;
	int i, d = nl - len;
	for(i=len;i>=0;i--) c[i+d] = c[i];
	for(i=0;i!=d;i++) c[i] = nchar;
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

bool eh(char *in,int b) {
	if((*in)=='-') in++;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			if((*in)-'0'>=b) return false;
		} else if((*in)>='A' && (*in)<='F') {
			if((*in)-'A'+10>=b) return false;
		} else {
			return false;
		}
		in++;
	}
	return true;
}

int main() {

	int b1,b2;
	char a1[100],a2[100];
	while((cin >> b1 >> b2 >> a1)) {
		if(eh(a1,b1)) {
			if(b1==b2) {
				cout << a1 << " base " << b1 << " = " << a1 << " base " << b1 << endl;
				continue;
			}
			if((a1[0])=='-') {
				base_convert(&a1[1],a2,b1,b2);
				cout << a1 << " base " << b1 << " = -" << a2 << " base " << b2 << endl;
			} else {
				base_convert(a1,a2,b1,b2);
				cout << a1 << " base " << b1 << " = " << a2 << " base " << b2 << endl;
			}
		} else {
			cout << a1 << " is an illegal base " << b1 << " number" << endl;
		}
	}
	return 0;
}
