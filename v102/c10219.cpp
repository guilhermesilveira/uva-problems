#include <cmath>
#include <iostream>

using namespace std;

#define MAXI (4000000)

double v[MAXI];

int main() {

	long a,b,c; double d;
	v[0] = 0;
	for(a=1;a<MAXI;a++) v[a] = v[a-1] + (log(a + 0.0) / log(10.0));
	while((cin >> a >> b)) {
		c = a - b;
		d = v[a] - v[b] - v[c];
		cout << ceil(d) << endl;
	}
	return 0;

}


/*trans-meta crusoe
(linus)*/