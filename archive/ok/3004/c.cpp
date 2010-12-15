#include <iostream>
#include <assert.h>
#include <stdio.h>

using namespace std;

int arred(int v) {
	if(v%10==0) return v;
	if(v%10==1) return v-1;
	if(v%10==2) return v-2;
	if(v%10==3) return v+2;
	if(v%10==4) return v+1;
	if(v%10==5) return v;
	if(v%10==6) return v-1;
	if(v%10==7) return v-2;
	if(v%10==8) return v+2;
	if(v%10==9) return v+1;
}

int main() {
	
	double v1,v2;
	while(true) {
		
		int p11,p12;
		int p21,p22;

		scanf(" %d.%d %d.%d",&p11,&p12,&p21,&p22);
		if(0==p12 && 0==p21 && p11==0 && p22==0) return 0;
		
		p12 = arred(p12);
		if(p12==100) {
			p12=0; p11++;
		}

		if(p11>p21 || (p11==p21 && p12>p22)) {
			cout << "Not enough money offered." << endl;
			continue;
		}
		
		if(p11==p21 && p12==p22) {
			cout << "Exact amount." << endl;
			continue;
		}
		
		int v1 = p21 - p11;
		int v2 = p22 - p12;
		if(v2<0) {
			v1--;
			v2 += 100;
		}
		
		if(v1<0 || v2<0) while(true);
		assert(v1>=0);
		
		bool b = false;
		if(v1>=20) {
			cout << "$20*" << (v1/20);
			v1 %= 20;
			b=true;
		}
		if(v1>=10) {
			if(b) cout << " ";
			cout << "$10*" << (v1/10);
			v1 %= 10;
			b=true;
		}
		if(v1>=5) {
			if(b) cout << " ";
			cout << "$5*" << (v1/5);
			v1 %= 5;
			b=true;
		}
		if(v1>=2) {
			if(b) cout << " ";
			cout << "$2*" << (v1/2);
			v1 %= 2;
			b=true;
		}
		if(v1!=0 && v1!=1) while(true);
		assert(v1==0 || v1==1);
		if(v1!=0) {
			if(b) cout << " ";
			cout << "$1*" << (v1);
			v1 = 0;
			b=true;
		}
		if(v1!=0) while(true);
		assert(v1==0);
		if(v2>=100) while(true);
		assert(v2<100);
		if(v2>=50) {
			if(b) cout << " ";
			cout << "50c*" << (v2/50);
			v2 %= 50;
			b=true;
		}
		if(v2>=20) {
			if(b) cout << " ";
			cout << "20c*" << (v2/20);
			v2 %= 20;
			b=true;
		}
		if(v2>=10) {
			if(b) cout << " ";
			cout << "10c*" << (v2/10);
			v2 %= 10;
			b=true;
		}
		if(v2>=5) {
			if(b) cout << " ";
			cout << "5c*" << (v2/5);
			v2 %= 5;
			b=true;
		}
		
		if(v2!=0) while(true);
		assert(v2==0);
		
		cout << endl;
		
		continue;
		
	}
	
	return 0;
	
}
