#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	long v,t;
	long b = 0;
	unsigned long long x = 0;
	unsigned long long ult = 2100000000;
	char s[100];
	while(true) {
		scanf("%s",&s);
		if(s[0]=='#') break;
		v = atol(s);
		b = x = 0;
		if(v>=10) { x += 10; v-=10; }
		if(v>=
		while(v) {
			cout << "n:" << x<< " " << v << endl;
			if(v<200) { if(v%2==0) goto imp; x += v /2; break; }
			x += 100; v -= 200;
			cout << x<< " " << v << endl;
			if(v<3000) { if(v%3==0) goto imp; x += v / 3; break; }
			x += 1000; v -= 3000;
			cout << x<< " " << v << endl;
			if(v<40000) { if(v%4==0) goto imp; x += v / 4; break; }
			x += 10000; v -= 40000;
			cout << x<< " " << v << endl;
			if(v<500000) { if(v%5==0) goto imp; x += v / 5; break; }
			x += 100000; v -= 500000;
			cout << x<< " " << v << endl;
			if(v<6000000) { if(v%6==0) goto imp; x += v / 6; break; }
			x += 1000000; v -= 6000000;
			cout << x<< " " << v << endl;
			if(v<70000000) { if(v%7==0) goto imp; x += v / 7; break; }
			x += 10000000; v -= 70000000;
			cout << x<< " " << v << endl;
			if(v<800000000) { if(v%8==0) goto imp; x += v / 8; break; }
			x += 100000000; v -= 800000000;
			cout << x<< " " << v << " " << (v % 9)<< endl;
			if(v<ult) { if(v%9==0) goto imp; x += v / 9; break; }
			x += 1000000000; v -= ult;
			cout << x<< " " << v << endl;
		}
		cout << x << endl;
		continue;
		imp: cout << "Impossible!" << endl;
	}
	return 0;

}


/*bool operator < (const Player &p) const {
	return aaaa;
}

Player(int a,int b,int c) : sc(a),rt(b),n(c){}*/
