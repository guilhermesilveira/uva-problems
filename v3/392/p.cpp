#include <iostream>

using namespace std;

int main() {

	int x[9], i;
	
	while((cin >> x[8] >> x[7] >> x[6] >> x[5] >> x[4] >> x[3] >> x[2] >> x[1] >> x[0])) {
		
		bool usado = false;
		for(i=8;i>=0;i--) {
			if(x[i]!=0) {
				if(usado) {
					cout << " ";
					if(x[i]==1 && i>0) {
						cout << "+ ";
					} else if(x[i]==-1 && i>0) {
						cout << "- ";
					} else if(x[i]>0) {
						cout << "+ " << (x[i]);
					} else {
						cout << "- " << (0-x[i]);
					}
					if(i>0) cout << "x";
					if(i>1) cout << "^" << i;
				} else {
					if(x[i]==1 && i>0) {
					} else if(x[i]==-1 && i>0) {
						cout << "-";
					} else if(x[i]>0) {
						cout << (x[i]);
					} else {
						cout << "-" << (0-x[i]);
					}
					if(i>0) cout << "x";
					if(i>1) cout << "^" << i;
					usado = true;
				}
			}
		}
		if(!usado) {
			cout << "0";
		}
		cout << endl;
	}

}
