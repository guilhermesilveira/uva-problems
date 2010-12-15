#include <iostream>

using namespace std;

int main() {

unsigned long long l1,l2;

while((cin >> l1 >> l2)) {

if(l1>l2) cout << l1 - l2 << endl;
else cout << l2 - l1 << endl;

}

return 0;


}
