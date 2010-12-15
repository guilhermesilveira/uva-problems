#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

cout << "n e" << endl;
cout << "- -----------" << endl;
cout << "0 1" << endl << "1 2" << endl << "2 2.5" << endl;
int v=1;
double val = 0;
for(int i=0;i!=10;i++) {
if(i!=0) v *= i;
val = val + (1.0 / v);
if(i>2) printf("%d %.9lf\n",i,val);
}

}
