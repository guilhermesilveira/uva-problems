#include <iostream>
#include <stdio.h>

using namespace std;

#define FOR(a,b,c) for(int a=b;a<c;a++)

int tot;
int val[10];
bool us[10];

void comp(int t,int y) {
	if(t>=tot || y>=tot) return;
	printf("if %c < %c then\n",'a'+t,'b'+y);
	comp(y,y+1);
	printf("else\n");
	comp(t,y+1);
}

void st(int v) {
	char c = 'a';
	tot = v;
	FOR(i,0,10) us[i] = false;
	cout << "program sort(input,output);\nvar\n";
	FOR(i,0,v) {
		if(i) putchar(',');
		putchar(c+i);
	}
	printf(" : integer;\nbegin\n\treadln(");
	FOR(i,0,v) {
		if(i) putchar(',');
		putchar(c+i);
	}
	printf(");\n");
	comp(0,1);
	printf("end.\n");
}

int main() {

	int in=0,t;
	cin >> t;
	while(t--) {
		cin >> in; st(in);
		if(t!=0) cout << endl;
	}
	return 0;

}
