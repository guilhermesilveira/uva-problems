#include <iostream>
using namespace std;
int main() {
	long v,val; int i;
	while((cin >> v)) {
		val=1;i=1;
		while(true) {
			if(val%v==0) break;
			val = (val%v)*10+1;
			i++;
		}
		cout << i << endl;
	}
	return 0;
}

