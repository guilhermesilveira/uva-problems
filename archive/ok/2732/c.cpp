#include <iostream>
#include <string>

using namespace std;

int main() {

	string s[51];
	int len, l, i = 0,j, k;
	while(true) {
		getline(cin,s[i]);
		if(s[i][0]=='#' && s[i].length()==1) break;
		len = s[i].length();
	//	cout << s[i] << endl;
		while(len++<36) s[i]+=' ';
		i++;
	}
	
	k = i * 2 + 1; 
	for(j=0;j!=k;j++) cout << "-"; cout << endl;
	for(j=0;j!=36;j++) {
		for(l=0;l!=i;l++) {
			cout << "|" << s[l][j];
		}
		cout << "|" << endl;
	}
	for(j=0;j!=k;j++) cout << "-"; cout << endl;
	
	return 0;

}



