#include <iostream>
#include <stdio.h>

using namespace std;

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



int main() {

	unsigned long long code = 0;
	int len = 0;
	char c;
	char l[200],lin[10000];
	int i,j,k;

	while(true) {
		code = 0;
		gets(lin);
		if(lin[0]=='#') break;
		len = strlen(lin);
		for(i=0;i!=len;i++) {
			if(lin[i]=='\r' || lin[i]=='\n') break;
			code *= 256;
			code %= 34943;
			code += lin[i];
		}
		code *= 256;
		code *= 256;
//		cout << "f1: " << code << endl;
		code %= 34943;
//		cout << "f2: " << code << endl;
		code = 34943 - code;
		code %= 34943;
		ltoa(code,l,16);
		len = strlen(l);
		if(len==4) printf("%c%c %c%c\n",l[0],l[1],l[2],l[3]);
		else if(len==3) printf("0%c %c%c\n",l[0],l[1],l[2]);
		else if(len==2) printf("00 %c%c\n",l[0],l[1]);
		else printf("00 0%c\n",l[0]);
		//cout << l << endl;
	}

	return 0;

}
