#include <iostream> 
#include <string>
#include <map>

using namespace std;

string m;
string n;
char im;
int in;

int main() {
	while(true) { 
		cin >> m >> n;
		//cout << m << " " << n << " ";
		if(m=="0" && n=="0") break;
		im = m[m.length()-1];
		if(n=="0") {
			cout << "1" << endl;
		} else if(im=='0' || im=='1' || im=='5' || im=='6') {
			cout << im << endl;
		} else if(im=='4') {
			in = n[n.length()-1] - 48;
			if(in%2==0) {
				cout << "6" << endl;
			} else {
				cout << "4" << endl;
			}
		} else if(im=='9') {
			in = n[n.length()-1] - 48;
			if(in%2==0) {
				cout << "1" << endl;
			} else {
				cout << "9" << endl;
			}
		} else {
			int in2 = n[n.length()-1] - 48;
			if(n.length()>1) {
				int tin2=(n[n.length()-2] - 48);
				if(tin2!=10) {
					in2+=10*tin2;
				}
			}
			if(im=='2') {
				if(in2%4==1) {
					cout << "2" << endl;
				} else if(in2%4==2) {
					cout << "4" << endl;
				} else if(in2%4==3) {
					cout << "8" << endl;
				} else {
					cout << "6" << endl;
				}
			} else if(im=='3') {
				if(in2%4==1) {
					cout << "3" << endl;
				} else if(in2%4==2) {
					cout << "9" << endl;
				} else if(in2%4==3) {
					cout << "7" << endl;
				} else {
					cout << "1" << endl;
				}
			} else if(im=='7') {
				if(in2%4==1) {
					cout << "7" << endl;
				} else if(in2%4==2) {
					cout << "9" << endl;
				} else if(in2%4==3) {
					cout << "3" << endl;
				} else {
					cout << "1" << endl;
				}
			} else if(im=='8') {
				if(in2%4==1) {
					cout << "8" << endl;
				} else if(in2%4==2) {
					cout << "4" << endl;
				} else if(in2%4==3) {
					cout << "2" << endl;
				} else {
					cout << "6" << endl;
				}
			}
		}
	}
	return 0; 
}
