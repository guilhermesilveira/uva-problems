#include <iostream>

using namespace std;

int main() {

	int pag, start, end, i;
	while((cin >> pag) && pag!=0) {
		int fol = (pag) / 4 + (pag%4==0?0:1);
		cout << "Printing order for " << pag << " pages:" << endl;
		start = 1;
		if(pag%4!=0) {
			end = pag + 4 - ((pag) % 4);
		} else {
			end = pag;
		}
		for(i=0;i!=fol;i++) {
			cout << "Sheet " << (i+1) << ", front: ";
			if(end>pag) {
				cout << "Blank, ";
				end--;
			} else {
				cout << end-- << ", ";
			}
			cout << start++ << endl;
	//		cout << end << "," << start << endl;
			if(start<=pag) {
				cout << "Sheet " << (i+1) << ", back : ";
				cout << start++ << ", ";
				if(end>pag) {
					cout << "Blank";
					end--;
				} else {
					cout << end--;
				}
				cout << endl;
			}
		}
	}

}
