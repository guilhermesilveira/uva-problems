#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*void start() {
}*/

/*bool start() {
  return false;
}*/

int n;
double pes[110];
int posc;
double tot;
double pos[3100000];
int quem[3100000];
int pre[3100000];

int main () {
	
	while(true) {
		cin >> n;
		int i,j,k;
		if(n==0) return 0;
		tot = 0;
		double minval = 0;
		for(i=0;i!=n;i++) {
			cin >> pes[i];
			tot += pes[i];
			if(i==0 || pes[i]<minval) {
				minval = pes[i];
			}
		}
		double mindes = 0.98 * tot / 1.98;
		double maxdes = 1.02 * tot / 2.02;
//		cout << mindes << "," << maxdes << endl;
		posc = 0;
		int temp;
		for(i=0;i!=n;i++) {
			temp = posc;
			if(pes[i]<=maxdes) {
				pre[temp] = -1;
				quem[temp] = i;
				pos[temp++] = pes[i];
				if(pes[i]>=mindes) {
					cout << i << endl;
					goto fim;
				}
			}
			// foi com uma so?
			for(j=0;j!=posc;j++) {
				pos[temp] = pos[j] + pes[i];
				if(pos[temp]<=maxdes) {
//					cout << endl << pos[temp] << endl;
					pre[temp] = j;
					quem[temp] = i;
					if(pos[temp]>=mindes) {
						// achei
						while(pre[temp]!=-1) {
							cout << (quem[temp]+1) << " ";
							temp = pre[temp];
						}
						cout << (quem[temp]+1);
						cout << endl;
						goto fim;
					}
					if(pos[temp]+minval<=maxdes) {
						temp++;
					}
				}
			}
			posc = temp;
		}
		//assert(false);
		fim:;
	}

	
	return 0;
	
}
