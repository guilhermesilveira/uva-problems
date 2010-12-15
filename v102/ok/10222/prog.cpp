#include <iostream>
#include <stdio.h>
#define MAX 100000

using namespace std;

int main() {
	
	char s[MAX];
	register int len, i;
	while(fgets(s,MAX,stdin)) {
		len = strlen(s);
		for(i=0;i!=len;i++) {
			if(s[i]>='A' && s[i]<='Z') {
				s[i] += (0 - 'A' + 'a');
			}
			if(s[i]=='K') {
				s[i]='H';
			} else if(s[i]=='k') {
				s[i]='h';
			} else if(s[i]=='2') {
				s[i]='`';
			} else if(s[i]=='3') {
				s[i]='1';
			} else if(s[i]=='4') {
				s[i]='2';
			} else if(s[i]=='5') {
				s[i]='3';
			} else if(s[i]=='6') {
				s[i]='4';
			} else if(s[i]=='7') {
				s[i]='5';
			} else if(s[i]=='8') {
				s[i]='6';
			} else if(s[i]=='9') {
				s[i]='7';
			} else if(s[i]=='0') {
				s[i]='8';
			} else if(s[i]=='-') {
				s[i]='9';
			} else if(s[i]=='=') {
				s[i]='0';
			} else if(s[i]=='e') {
				s[i]='q';
			} else if(s[i]=='E') {
				s[i]='Q';
			} else if(s[i]=='r') {
				s[i]='w';
			} else if(s[i]=='R') {
				s[i]='W';
			} else if(s[i]=='t') {
				s[i]='e';
			} else if(s[i]=='T') {
				s[i]='E';
			} else if(s[i]=='y') {
				s[i]='r';
			} else if(s[i]=='Y') {
				s[i]='R';
			} else if(s[i]=='u') {
				s[i]='t';
			} else if(s[i]=='U') {
				s[i]='T';
			} else if(s[i]=='i') {
				s[i]='y';
			} else if(s[i]=='I') {
				s[i]='Y';
			} else if(s[i]=='o') {
				s[i]='u';
			} else if(s[i]=='O') {
				s[i]='U';
			} else if(s[i]=='p') {
				s[i]='i';
			} else if(s[i]=='P') {
				s[i]='I';
			} else if(s[i]=='[') {
				s[i]='o';
			} else if(s[i]==']') {
				s[i]='p';
			} else if(s[i]=='\\') {
				s[i]='[';
			} else if(s[i]=='d') {
				s[i]='a';
			} else if(s[i]=='f') {
				s[i]='s';
			} else if(s[i]=='g') {
				s[i]='d';
			} else if(s[i]=='h') {
				s[i]='f';
			} else if(s[i]=='j') {
				s[i]='g';
			} else if(s[i]=='k') {
				s[i]='h';
			} else if(s[i]=='l') {
				s[i]='j';
			} else if(s[i]==';') {
				s[i]='k';
			} else if(s[i]=='\'') {
				s[i]='l';
			} else if(s[i]=='c') {
				s[i]='z';
			} else if(s[i]=='v') {
				s[i]='x';
			} else if(s[i]=='b') {
				s[i]='c';
			} else if(s[i]=='n') {
				s[i]='v';
			} else if(s[i]=='m') {
				s[i]='b';
			} else if(s[i]==',') {
				s[i]='n';
			} else if(s[i]=='.') {
				s[i]='m';
			} else if(s[i]=='/') {
				s[i]=',';
			}
		}
		cout << s;
	}
	
}
