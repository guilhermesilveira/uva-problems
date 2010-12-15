#include <iostream>

using namespace std;

long long calcula(long long i) {
	if(i==1) return 0;
	if(i%2) return calcula(3*i+1) + 1;
	else return calcula(i/2) + 1;
}

int main() {
	
	long long s,e;
	while((cin >> s >> e)) {
		
		if(s==0 && e==0) break;
		
		if(s>e) {
			long sa = e;
			e = s; s = sa;
		}
		
		bool f=false;
		long long x,dx,v;
		for(long long i=s;i<=e;i++) {
			if(i==1) {
				v = 3;
			} else {
				v = calcula(i);
			}
			if(!f || v>dx) {
				x = i; f = true; dx = v;
			}
		}
		
		cout << "Between " << s << " and " << e << ", " << x << " generates the longest sequence of " << dx << " values." << endl;
		
	}
	return 0;
}
