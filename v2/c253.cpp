#include <iostream>

using namespace std;

char v[50];

#define ig() (c0==v[6] && c1==v[7] && c2==v[8] && c3==v[9] && c4==v[10] && c5==v[11])

bool gira3(char c0,char c1,char c2,char c3,char c4,char c5,int l) {
 if(l==6) return false;
 return ig() || gira3(c0,c2,c4,c1,c3,c5,l+1);
}

bool gira2(char c0,char c1,char c2,char c3,char c4,char c5,int l) {
 if(l==6) return false;
 return ig() || gira2(c3,c1,c0,c5,c4,c2,l+1) || gira3(c0,c1,c2,c3,c4,c5,0);
}

bool gira(char c0,char c1,char c2,char c3,char c4,char c5,int l) {
 if(l==6) return false;
 return ig() || gira(c1,c5,c2,c3,c0,c4,l+1) || gira2(c0,c1,c2,c3,c4,c5,0);
}

int main() {

 while((cin >> v)) {
   if(gira(v[0],v[1],v[2],v[3],v[4],v[5],0)) cout << "TRUE" << endl;
   else cout << "FALSE" << endl;
 }
 return 0;

}
