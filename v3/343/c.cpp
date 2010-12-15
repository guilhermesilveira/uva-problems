#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define REP(a,c,b) for(int _n=b,a=c;a<_n;a++)

unsigned long long toBase10(const char *in, int b) {
	unsigned long long v = 0;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			v = v * b + ((*in)-'0');
		} else if((*in)>='A' && (*in)<='Z') {
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
	for(int i=0;i!=p;i++) out[i] = temp[p-i-1];
	out[p] = '\0';
	return out;
}

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
		} else if((*in)>='A' && (*in)<='Z') {
			if((*in)-'A'+10>=b) return false;
		} else {
			return false;
		}
		in++;
	}
	return true;
}

int basemin(char *in) {
	int b = 2;
	while((*in)!='\0' && (*in)!='\n' && (*in)!='\r') {
		if((*in)>='0' && (*in)<='9') {
			b = max(b,(*in)-'0'+1);
		} else if((*in)>='A' && (*in)<='Z') {
			b = max(b,(*in)-'A'+10+1);
		}
		in++;
	}
	return b;
}

int main() {

	char s1[100],s2[100];
	char t1[1000],t2[1000];

	while(scanf("%s %s",s1,s2)==2) {

		int v1 = basemin(s1), v2 = basemin(s2);

		REP(i,v1,37) {
			base_convert(s1,t1,i,10);
			REP(j,v2,37) {
				base_convert(s2,t2,j,10);
				if(strcmp(t1,t2)==0) {
					cout << s1 << " (base " << i << ") = " << s2 << " (base " << j << ")" << endl;
					goto f;
				}			
			}
		}

		cout << s1 << " is not equal to " << s2 << " in any base 2..36\n";

	f:;

	}

	return 0;

}
