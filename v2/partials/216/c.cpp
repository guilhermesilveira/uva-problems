#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int n;

double dist[10][10];
double p[10][2];

#define FOR(a,b,c) for(a=b;a<c;a++)

double DIST(int i,int j) {
	return sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
}

double mini = -1;
bool pos = false;

bool u[10];
int caminho[10];
int melhor[10];

void tenta(int level,int at,double d) {
	//if(pos && d>mini) return;
	int i;
	if(level==n) {
		/*FOR(i,0,n) cout << caminho[i] << " ";
		cout << " d: " << d << endl;*/
		if(pos==false || d<mini) {
			FOR(i,0,n) melhor[i] = caminho[i];
			mini = d;
			pos = true;
		}
		return;
	}

	FOR(i,0,n) {
		if(u[i]==false) {
			u[i]=true;
			caminho[level] = i;
			if(level==0) tenta(level+1,i,0);
			else tenta(level+1,i,d+dist[at][i]+16);
			u[i]=false;
		}
	}

}

void imp(double d) {
	d *= 100;
	d += 0.5;
	long long v = (long long) d;
	d = v / 100.0;
	printf("%.2lf",d);
}

void pr(int a) {
	cout << p[a][0] << "," << p[a][1];
}

int main() {

	int i,j,k,ins = 0;
	double d;

	while((cin >> n) && n) {

		cout << "**********************************************************" << endl;
		cout << "Network #" << ++ins << endl;

		FOR(i,0,n) {
			cin >> p[i][0] >> p[i][1];
			u[i] = false;
		}

		pos = false;

		FOR(i,0,n) FOR(j,0,n) dist[i][j] = (i==j ? 0 : DIST(i,j));

		/*FOR(i,0,n) {
			FOR(j,0,n) cout << dist[i][j] << " ";
			cout << endl;
		}*/

		tenta(0,-1,0);

		//if(mini==-1) while(1);
		d = 0;

		FOR(i,1,n) {
			int a = i - 1, b = i;
			cout << "Cable requirement to connect (";
			pr(a);
			cout << ") to (";
			pr(b);
			cout << ") is ";
			imp(dist[a][b]);
			d += dist[a][b];
			cout << " feet." << endl;
		}
		//mini += 16 * (n-1);
		cout << "Number of feet of cable required is ";
		imp(mini);
		cout << "." << endl;

	}

	return 0;

}
