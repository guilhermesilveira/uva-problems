#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

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

char a[5],b[5],c[5];
char t1[100],t2[100],t3[100],t4[100];

void preenche(char *c,int nl, char nchar) {
	int len = strlen(c);
	if(len>=nl) return;
	int i, d = nl - len;
	for(i=len;i>=0;i--) c[i+d] = c[i];
	for(i=0;i!=d;i++) c[i] = nchar;
}

void start() {

	scanf(" %s %c %s",a,c,b);
	base_convert(a,t1,16,10);
	base_convert(b,t2,16,10);
	base_convert(a,t3,16,2);
	base_convert(b,t4,16,2);
	preenche(t3,13,'0');
	preenche(t4,13,'0');
	cout << t3 << " " << c << " " << t4 << " = " << 
		(c[0]=='+'?(atol(t1)+atol(t2)):(atol(t1)-atol(t2)))
			 << endl;
	
}

int main() {

	int t; cin >> t; while(t--) start();
	
	return 0;

}
