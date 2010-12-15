/* @JUDGE_ID: 39315ZN 10370 C++ "counting" */

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	
	for(int a=2;a!=201;a++) {
		for(int b=2;b!=a;b++) {
			for(int c=b;c!=a;c++) {
				if(a*a*a<b*b*b+c*c*c) {
					break;
				}
				for(int d=c;d!=a;d++) {
					if(a*a*a==b*b*b+c*c*c+d*d*d)
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")"<< endl;
					else if (a*a*a<b*b*b+c*c*c+d*d*d)
						break;
				}
			}
		}
	}
		
	return 0;
	
}
