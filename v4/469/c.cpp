#include <iostream>
#include <string>
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;

int Y,X;

int main() {

	int t,x,y;
	cin >> t;
	char lin[150][150];
	int ar[150][150];

	Y = X = 0;

	while(t--) {

		while(1) {
			cin >> lin[Y];
			if(lin[Y][0]!='W' && lin[Y][0]!='L') break;
			Y++;
		}
		while(1) {
			cin >> lin[Y];
			X = 0;
			Y = 1;
		}
		if(t) cout << endl;
	}

}
