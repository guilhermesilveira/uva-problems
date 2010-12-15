#include <iostream>

using namespace std;

double h,u,d,f,dd;
bool con;

long tenta(double uatual,double hatual,int dia) {
	//cout << "dia " << dia << endl;
	if(uatual>0) {
		hatual += uatual;
		//cout << "alcanca " << hatual << endl;
		if(hatual>h) {
			con = true;
			return dia;
		}
	}
	hatual -=  d;
	//cout << "cai " << hatual << endl;
	if(hatual<0) {
		con = false;
		return dia;
	}
	return tenta(uatual - dd,hatual,dia+1);
}

int main() {
	
	while((cin >> h) && h) {
		
		cin >> u >> d >> f;
		dd = u * f / 100;
		//f = (100 - f) / 100.0;
//		cout << "dd: " << dd << endl;
		con = false;
		long v = tenta(u,0,1);
		if(con) cout << "success";
		else cout << "failure";
		cout << " on day " << v << endl;
		
	}
	return 0;
	
}
