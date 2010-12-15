#include <iostream>

using namespace std;

int main() {
	
	int a,b,c,d,caso = 0, casos;
	cin >> casos;
	while(casos--!=0) {
		(cin >> a >> b >> c >> d);
		int e = a + b;
		int f = c + d;
		int val;
		if(e==f) {
			val = c - a;
		} else {
			val = 0;
			if(a!=0) {
				val -= a;
				b += a;
				a = 0;
			}
			//cout << a<<b<<c<<d<<endl;
			//cout << val<<endl;
			//cout <<"inicia" << endl;
			while(e!=f) {
				val += b;
				val++;
				b++;
				e++;
			}
			//cout << a<<b<<c<<d<<endl;
			//cout << val<<endl;
//			cout << (val + b-c) << endl;
//			cout << (val + b-d) << endl;
			if(!(a==c && b==d)) {
//				cout << "soma " << endl;
				val += b - d;
			}
			
			/*val = 0;
			while(e != f) {
				val += b + 1;
				e++;
				b++;
				cout << ": " << b << "," << val << endl;
			}
			cout << ": " << b << "," << val << endl;
			cout << "" << a << " <<<" << c << endl;
			if(c>a) {
//				cout << (c-a-1) << endl;
			}
			val += b - d;*/
		}
		cout << "Case " << (++caso) << ": " << val << endl;
	}
	
}
