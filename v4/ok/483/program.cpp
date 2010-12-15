#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(char **argv,int argc) {

	while(true) {

		string str;
		if(!getline(cin,str)) break;
		//cout << str << endl;

		int printable = 0;
		string::iterator start = str.begin();
		string::iterator i;
		for(i=str.begin();i!=str.end();i++) {
			if((*i)==' ') {
				if(printable > 1) {
					reverse(start,i);
				}
				printable = 0;
				start = (i + 1);
			} else {
				printable++;
			}
		}
		
		if(printable>1) {
			reverse(start,i);
		}
		
		cout << str << endl;
		//cout << printable << endl;

	}
	
	cout << endl;

	return 0;

}
