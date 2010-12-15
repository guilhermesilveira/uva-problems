#include <iostream>

using namespace std;

#define MAX (25)

int t,r,h;

long long tp[MAX];
int tr[MAX][MAX];

long long rp[MAX];
int rh[MAX][MAX];

long long hp[MAX];
int ht[MAX][MAX];

long long maxPrice = -1;
bool foundSome;
int tv,rv,hv;

void ch(int ti,int ri,int hi, long long val) {
	if(foundSome==false || val<maxPrice) {
		maxPrice = val;
		tv = ti;
		rv = ri;
		hv = hi;
		foundSome = true;
	}
}

void cr(int ti,int ri, long long val) {
	
	for(int i=0;i!=h;i++) {
		if(rh[ri][i]==0 && ht[i][ti]==0) { // && (!foundSome || val + tp[i] < maxPrice)) {
//			cout << "tentando h=" << i << endl;
			ch(ti,ri,i,val+hp[i]);
		}
	}

}

void ct(int ti, long long val) {
	
	for(int i=0;i!=r;i++) {
		if(tr[ti][i]==0 && (!foundSome || val + rp[i] <= maxPrice)) {
			//cout << "tentando r=" << i << endl;
			cr(ti,i,val+rp[i]);
		}
	}

}

bool doIt() {

	foundSome = false;
	maxPrice = -1;
	for(int i=0;i!=t;i++) {
		if(!foundSome || tp[i]<=maxPrice)
	//	cout << "tentando t=" << i << endl;
		ct(i,tp[i]);
	}
	return foundSome;

}

void read() {

	int i,j;
//	cout << "novo" << endl;
	for(i=0;i!=t;i++) {
		cin >> tp[i];
	//	cout << tp[i] << "::";
		for(j=0;j!=r;j++) {
			cin >> tr[i][j];
		//	cout << tr[i][j];
		}
		//cout << endl;
	}

	for(i=0;i!=r;i++) {
		cin >> rp[i];
//		cout << rp[i] << "::";
		for(j=0;j!=h;j++) {
			cin >> rh[i][j];
	//		cout << rh[i][j];
		}
		//cout << endl;
	}

	for(i=0;i!=h;i++) {
		cin >> hp[i];
		//cout << "hotel " << i << "::" << hp[i] << "::";
		for(j=0;j!=t;j++) {
			cin >> ht[i][j];
			//cout << ht[i][j];
		}
		//cout << endl;
	}


}

int main() {

	while((cin >> t >> r >> h)) {

		read();
		if(!doIt()) {
			cout << "Don't get married!" << endl;
		} else {
			cout << (tv) << " " << (rv) << " " << (hv) << ":" << (tp[tv] + rp[rv] + hp[hv]) << endl;
		}

	}

}


