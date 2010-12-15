#include <string>
#include <iostream>

using namespace std;

int main(char **argv,int argc) {

	string str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; 
	char p;
	int position;

	while(cin.get(p)) {
		position = str.find(p);
		if(position==string::npos) {
			cout << p;
		} else {
			cout << str[position-1];
		}
	}

	return 0;

}
