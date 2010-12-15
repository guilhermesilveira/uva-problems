#include <iostream>

using namespace std;

#define FOR(a,b,c) for(a=b;a<c;a++)

int t;
int flip[100];
int flipc;
int v[40];
int temp[40];

void imp() {
	for(int i=0;i!=t;i++) cout << v[i] << " ";
	cout << endl;
}

void doit(int l) {
	int i;
	//cout << "antes ";
	//imp();
	FOR(i,0,l+1) temp[i] = v[l-i];
	FOR(i,0,l+1) v[i] = temp[i];
	flip[flipc++] = l;
	//cout << "vira " << l << " ";
	//imp();
}

void tenta(int l) {
	//cout << "tentando " << l << endl;
       if(l==0) return;
	if(v[l-1]==l) {
		tenta(l-1);
		return;
	}
	if(v[0]==l) {
		doit(l-1);
		tenta(l-1);
		return;
	}
       int i;
       FOR(i,0,l) if(v[i]==l) break;
	doit(i);
	doit(l-1);
	tenta(l-1);
	return;
}

int main() {

       while(cin >> t && t) {

               int i;
               FOR(i,0,t) cin >> v[i];
		//imp();
		flipc = 0;
               tenta(t);
               cout << flipc;
               FOR(i,0,flipc) cout << " " << (flip[i]+1);
               cout << endl;

       }
       return 0;

}

