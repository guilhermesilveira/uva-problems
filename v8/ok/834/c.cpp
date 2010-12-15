#include <iostream>

using namespace std;

int main() {
long long n,v,temp;
while((cin >> n >> v)) {

bool s = false;
cout << "[" << (n/v) << ";";
n = n % v;
while(n!=0) {
   temp = n; n = v; v = temp;
   if(s) cout << ",";
   cout << (n/v);
   n = n % v;
   s = true;
}
cout << "]" << endl;

}
return 0;

}
