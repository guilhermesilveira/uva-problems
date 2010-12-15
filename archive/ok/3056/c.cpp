#include <iostream>

using namespace std;

int main() {

	int maxw,dx,dy;
	int atuw,atuy,atuy2;
	int maxatuw;
	while((cin >> maxw) && maxw) {

		maxatuw = atuw = atuy = atuy2 = 0;

		while(true) {
		
			cin >> dx >> dy;
			if(dx==-1 && dy==-1) break;

			if(atuw+dx>maxw) {
				atuw = 0;
				atuy = atuy2;
			}

			atuw += dx;

			if(atuw>maxatuw) maxatuw = atuw;

			if(atuy+dy>atuy2) atuy2 = atuy + dy;

		}

		cout << maxatuw << " x " << atuy2 << endl;


	}

	return 0;


}
