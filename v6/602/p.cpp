#include <iostream>

using namespace std;

int offset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

char *dia(int i) {
	if(i==0) return "Sunday";
	if(i==1) return "Monday";
	if(i==2) return "Tuesday";
	if(i==3) return "Wednesday";
	if(i==4) return "Thursday";
	if(i==5) return "Friday";
	return "Saturday";
}

char *mes(int i) {
	if(i==1) return "January";
	if(i==2) return "February";
	if(i==3) return "March";
	if(i==4) return "April";
	if(i==5) return "May";
	if(i==6) return "June";
	if(i==7) return "July";
	if(i==8) return "August";
	if(i==9) return "September";
	if(i==10) return "October";
	if(i==11) return "November";
	return "December";
}
void invalido(int y,int m,int d) {
	cout << m << "/" << d <<"/" << y << " is an invalid date." << endl;
}
int dayofweek( int year, int month, int day )     	/* 0 = Sunday */
   {
   year -= month < 3;
   return (year + year/4 - year/100 + year/400 + offset[month-1] + day) % 7;
}

void tentaNovo(int y,int m, int d) {
	cout << mes(m) << " " << d << ", " << y << " is a " << dia(dayofweek(y,m,d)) << endl;
}

#define ehBisAnt(v) (v%4==0)

void tentaAntigo(int y,int m,int d) {
	int val = 4;
	for(int i=0;i!=y;i++) {
		if(ehBisAnt(i)) {
			val += 366;
		} else {
			val += 365;
		}
		val %= 7;
	}
	for(int i=1;i!=m;i++) {
		if(i==1 ||i==3 || i==5 || i==7 || i==8 || i==10 || i==12) {
			val += 31;
		} else if(i==2) {
			if(ehBisAnt(y)) val += 29;
			else val += 28;
		} else {
			val += 30;
		}
		val %= 7;
	}
	val += d - 1;
	val %= 7;
	cout << mes(m) << " " << d << ", " << y << " is a " << dia(val) << endl;
}




int main() {

int m,d,y;
	while((cin >>m >> d >> y)) {
		if(m==0 && d==0 && y==0) return 0;
		if(y<0 || d<=0 || m<=0) {
			// invalido
			invalido(y,m,d);
			continue;
		}
		if(d>31 || (
		!(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d==31)) {
			// invalido
			invalido(y,m,d);
			continue;
		} else if(m==2) {
			if(y<1752) {
				if(y%4==0 && d>29) {
					// invalido
					invalido(y,m,d);
					continue;
				} else if(y%4!=0 && d>28) {
					invalido(y,m,d);
					continue;
				}
			} else {
				if(y%4==0 && (y%100!=0 || (y%100==0 && y%400==0))) {
					if(d>29) {
						// invalido
						invalido(y,m,d);
						continue;
					}
				} else if(d>28) {
					// invalido
					invalido(y,m,d);
					continue;
				}
			}
		}
		if(y==1752 && m==9) {
			if(d>=3 && d<=13) {
				invalido(y,m,d);
				continue;
			}
			if(d<=2) tentaAntigo(y,m,d);
			else tentaNovo(y,m,d);
			continue;
		}
		if(y>1752 || (y==1752 && (m>9 || (m==9 && d>=14)))) {
			tentaNovo(y,m,d);
		} else {
			tentaAntigo(y,m,d);
		}
	}

	return 0;
	
}
