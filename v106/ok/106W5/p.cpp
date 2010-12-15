#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char s[100010];
char t[1010];

void reverse(char *s) {
	int len = strlen(s);
	char c;
	for(int i=0;i<=len/2;i++) {
		c = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = c;
	}
}

void start() {
	cin >> s;
	int i,l1,l2,j,k;
	cin >> i;
	reverse(s);
	l1 = strlen(s);
	s[l1] = '\0';
	while(i--) {
		cin >> t;
		reverse(t);
		l2 = strlen(t);
		t[l2] = '\0';
//		cout << l1 << s << "," << t << endl;
		cout << ((strstr(s,t)==NULL) ? 'n':'y')<<endl;
		
		/*for(j=0;j<=l1-l2;j++) {
			if(s[j]==t[0]) {
				for(k=0;k!=l2;k++) {
					if(s[j+k]!=t[k]) goto m;
				}
				cout << 'y' << endl;
				goto n;
				m:;
			}
		}*/
//		cout << 'n' << endl;
		n:;
	}
}

int main() {

	int t;
	cin >> t;
	while(t--)
	start();

	return 0;

}
