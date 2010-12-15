#include <iostream>
#include <map>

using namespace std;

//struct numero {
//	char 50
//}

map<unsigned long long int,unsigned long long int> i;

int main(int argv, char **argc) {

	int max;	
	int n;
	i[0] = 0;
	i[1] = 1;
	i[2] = 1;
	max = 2;
	unsigned long long int temp;

	while(cin >> n) {

		if(n>max) {
			//cout << "maior";
			for(int z=max+1;z!=n+1;z++) {
				temp = i[z-1] + i[z-2];
				if(temp<=0) {
					cout << z << " ";
					cout << temp << " ";
					cout << i[z-1] << " ";
					exit(0);
				}
				i[z] = temp;
				//cout << z << " " << i[z] << endl;
			}
			max = n;
		}
		cout << "The Fibonacci number for " << n << " is " << i[n] << endl;

	}

	return 0;

}
