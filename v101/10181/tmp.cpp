#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(char **args,int argv) {

	vector<string> lista;
	string s;
	int counter = 0;
	while(getline(cin,s)) {
		if(counter++%500==0) {
			cout << counter << endl;
		}
		if(find(lista.begin(),lista.end(),s)!=lista.end()) {
			// ja contem
			cout << s << endl;
			exit(0);
		}
		lista.push_back(s);
	}

}
