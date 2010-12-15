#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)

char minu(char c) { return (c>='A' && c<='Z')? c-'A'+'a' : c; }
bool isalphaz(char c) { return (c>='A' && c<='Z') || (c>='a' && c<='z'); }

int main() {

	char s[100];
	bool ok[300];
	bool extra[300];
	int i,j,k,l,lin,ins=0;

	printf("+----------+----------------+-----------------------------+\n");
	printf("| Keyboard | # of printable | Additionally, the following |\n");
	printf("|          |      lines     |  letter keys can be broken  |\n");

	while(true) {
		lin = 0;
		gets(s);
		if(!strncmp(s,"finish",6)) break;
		printf("+----------+----------------+-----------------------------+\n");
		FOR(i,300){ok[i]=extra[i]=1;}
		l=strlen(s);
		FOR(i,l) ok[minu(s[i])]=extra[minu(s[i])]=0;
		bool b = true;

		while(b) {

			gets(s);
			l=strlen(s);
			if(!strncmp(s,"END",3)) b=0;

			FOR(i,l) {
				s[i] = minu(s[i]);
				if(isalphaz(s[i]) && !ok[s[i]]) goto nex;
			}

			FOR(i,l) if(isalphaz(s[i])) extra[s[i]]=0;
			lin++;
			nex:;
		}

		l = 0;
		for(i='a';i<='z';i++) if(extra[i]) s[l++] = i;
		for(i=l;i<28;i++) s[i] = ' ';
		s[28] = '\0';
		printf("|%6d    |%9d       | %s|\n",++ins,lin,s);

	}

	printf("+----------+----------------+-----------------------------+\n");
	return 0;

}
