#include <iostream>

using namespace std;

int main() {
	
    int casos;
    cin >> casos;

    unsigned long long *valores = (unsigned long long *) malloc(2147483648 * sizeof(unsigned long long));
    long long v = 2;
    for (int i = 2; i != 32; i++) {
        v = v * 2;
        cout << i << ":"<< v << endl;
    }
    
    unsigned long long val4 = 1, val3 = 2, val2 = 4;
    valores[0] = 1;
    valores[1] = 2;
    valores[2] = 4;
    valores[3] = 8;
//    for (unsigned long long i = 4; i <= 2147483647; i++) {
    for (unsigned long long i = 4; i <= 100; i++) {
    	valores[i] = valores[i-1] + (val2+= (val3 += (++val4)));
    	cout << i << ":: " << valores[i] << endl;
    }
    
    unsigned long long z;
    for (int i = 0; i != casos; i++) {
    	cin >> z;
    	cout << z << endl;
    	//if(z==0) cout << "0" << endl;
//		else cout << valores[z-1] << endl;
    }
    
}
