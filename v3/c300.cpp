#include <iostream>
#include <stdio.h>

using namespace std;

char *cm(int m) {
	if(m==0) return "imix";
	if(m==1) return "ik";
	if(m==2) return "akbal";
	if(m==3) return "kan";
	if(m==4) return "chicchan";
	if(m==5) return "cimi";
	if(m==6) return "manik";
	if(m==7) return "lamat";
	if(m==8) return "muluk";
	if(m==9) return "ok";
	if(m==10) return "chuen";
	if(m==11) return "eb";
	if(m==12) return "ben";
	if(m==13) return "ix";
	if(m==14) return "mem";
	if(m==15) return "cib";
	if(m==16) return "caban";
	if(m==17) return "eznab";
	if(m==18) return "canac";
	return "ahau";
}

int main() {

	int t; cin >> t; cout << t << endl;

	int d,a,mes;
	char m[1009];
	int tot;
	while(t--) {

		scanf("%d. %s %d",&d,&m,&a);
		tot = a*365;
		tot += d;
		char c1=m[0],c2=m[1],c3=m[2];

		if(c1=='p' && c2=='o') mes=1;
		else if(c1=='n' && c2=='o') mes=2;
		else if(c1=='z' && c2=='i') mes=3;
		else if(c1=='z' && c2=='o') mes=4;
		else if(c1=='t' && c2=='z') mes=5;
		else if(c1=='x' && c2=='u') mes=6;
		else if(c1=='y' && c2=='o') mes=7;
		else if(c1=='m' && c2=='o') mes=8;
		else if(c1=='c' && c2=='h') mes=9;
		else if(c1=='y' && c2=='a') mes=10;
		else if(c1=='z' && c2=='a') mes=11;
		else if(c1=='c' && c2=='e') mes=12;
		else if(c1=='m' && c2=='a') mes=13;
		else if(c1=='k' && c2=='a') mes=14;
		else if(c1=='m' && c2=='u') mes=15;
		else if(c1=='p' && c2=='a') mes=16;
		else if(c1=='k' && c2=='o') mes=17;
		else if(c1=='c' && c2=='u') mes=18;
		else mes=19;

		//cout << "mes: " << mes << endl;
		tot += (mes-1) * 20;

		int ano = tot / (20*13);
		tot = tot % (20*13);	
		mes = tot % 13 + 1;
		int dia = tot % 20;
		cout << mes << " "  << cm(dia) << " " << ano << endl;

	}

	return 0;

}

