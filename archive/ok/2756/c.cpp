// exercicio C da equipe masculina

#include <iostream>

using namespace std;

int main() {

 int t,i,j,k;
 long long v[33000];
 for(i=3;i!=33000;i++) {
   j = i/2 - 1;
   v[i] = (j *(j+1)/2);
   j = i - (i/2) - 1;
   v[i] += (j * (j+1) / 2);
 }
 cin >> t;
 while(t--) {
   cin >> i;
   cout << v[i] << endl;
 }
 return 0;

}