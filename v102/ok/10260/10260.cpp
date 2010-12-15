#include <stdio.h>
#include <string>

using namespace std;

int main() {
	
	char s[30],v[30],vc;
	string val = "01230120022455012623010202";
	register int i, len, bet, c;
	
	while(fgets(s,25,stdin)) {
		
		vc = 0;
		
		for(i=0;s[i]!='\r' && s[i]!='\n' && s[i]!='\0';i++) {
			
			c = s[i] - 'A';
			
			if(val[c]=='0') {
				bet = 1;
				continue;
			}
			if(vc==0 || bet==1 || (val[c]!=v[vc-1])) {
				v[vc++] = val[c];
				bet = 0;
			}
			
		}

		v[vc] = 0;
		printf("%s\n",v);

	}
	
}
