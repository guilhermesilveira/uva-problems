#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

	char in[100], out[100];
	int lin, lout;
	long l1,l2;
	
	while(true) {
		scanf("%s",in);
		if(in[0]=='0' && in[1]=='x') {
			printf("%s\n",base_convert(&in[2],out,16,10));
		} else {
			if(atol(in)<0) return 0;
			printf("0x%s\n",base_convert(in,out,10,16));
		}
	}

}
