#include <iostream>

using namespace std;

int mini, maxi;
int val[50000];

void le(int p) {
	
	int temp;
	cin >> temp;
	//cout << "col["<<p<<"]+="<<temp << endl;
	if(temp==-1) return;
	if(p<mini) { mini = p; val[p] = 0; }
	if(p>maxi) { maxi = p; val[p] = 0; }
	val[p] += temp;
	le(p-1);
	le(p+1);
}

int main() {
	
	int caso = 0;
	while((true)) {

		cin >> val[25000];
		if(val[25000]==-1) {
			return 0;
		}
		mini = 25000, maxi=25000;
		cout << "Case " << ++caso << ":" << endl;
		
		le(24999);
		le(25001);
		
		cout << val[mini];
		for(int i=mini+1;i<=maxi;i++) {
			cout << " " << val[i];
		}
		cout << endl << endl;
	}
	
}
