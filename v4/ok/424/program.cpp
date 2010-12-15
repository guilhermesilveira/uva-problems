#include <iostream>
#include <string>

#define SUPERMAX 120

using namespace std;

int main (char **argv, int argc) {

	string total = "";

	for(int i=0;i!=SUPERMAX;i++) total += "0";

	while (true) {

		string newline;
		getline(cin,newline);
		if(newline=="0") break;

		// soma newLine em b
		int newlen = newline.size();
		while(newlen!=SUPERMAX) {
			newline = "0" + newline;
			newlen++;
		}
		//cout << newline << endl;

		for(int i=SUPERMAX;i!=0;i--) {
			int b = total[i] + newline[i] - '0' - '0';
			if(b > 9) {
				b -= 10;
				total[i-1]++;
			}
			total[i] = '0' + b;
		}

	}

	while(total[0]=='0' && total.size()!=1) {
		total = total.substr(1);
	}

  	cout << total << endl;

  return 0;

}
