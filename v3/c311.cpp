#include <iostream>

using namespace std;

int main() {

	int a,b,c,d,e,f;
	int mini;
	int temp,livre;

	while(true) {
		cin >> a >> b >> c >> d >> e >> f;
		if(!a && !b && !c && !d && !e && !f) break;

		mini = f;
		f = 0;

		if(e>0) {
			mini += e;
			temp = e * 11;
			if(a>=temp) a -= temp;
			else a = 0;
			e = 0;
		}

		while(d>0) {
			mini++;
			d--;
			if(b>=5) {
				b-=5;
				continue;
			}
			temp = 20 - b * 4;
			b = 0;
			if(a>=temp) a-=temp;
			else a = 0;
		}

		mini += (c / 4);
		c %= 4;

		if(c>0) {
			mini++;
			if(c==3) {
				int livre = 9;
				if(b!=0) {
					b--;
					livre = 5;
				}
				if(a>=livre) a -= livre;
				else a = 0;
			} else if(c==2) {
				int livre = 18;
				if(b>=3) {
					b -= 3;
					livre = 6;
				} else {
					livre -= 4 * b;
					b = 0;
				}
				if(a>=livre) a -= livre;
				else a = 0;
			} else {
				// cabem 5
				int livre = 27;
				if(b>=5) {
					b -= 5;
					livre = 7;
				} else {
					livre -= 4 * b;
					b = 0;
				}
				if(a>=livre) a -= livre;
				else a = 0;
			}
			c = 0;
		}

		mini += (b / 9);
		b %= 9;

		if(b>0) {
			mini++;
			livre = 36 - b * 4;
			b = 0;
			if(a>=livre) a-=livre;
			else a = 0;
		}

		mini += (a / 36);
		if(a%36!=0) mini++;

		cout << mini << endl;

	}
	return 0;

}
