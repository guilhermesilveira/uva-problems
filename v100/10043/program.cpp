#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l,w;

vector<int*> vp;
int *p[5001];
int pc;
int m;

#define DA
#ifdef D
	#define DEBUG(x) x
#else
	#define DEBUG(x) ;
#endif

int x1;

void area(int y1, int p2, int y2) {

//	DEBUG(cout << "new call: " << "??p1?? and " << p2 << "\t\t(" << x1 << "," << y1 << ")\t(" << p[p2][0] << "," << y2 << ")" << endl;)

	if(((p[p2][0] - x1) * (y2 - y1))>m) {
		m = (p[p2][0] - x1) * (y2 - y1);
	}

	int pn = p2 + 1;
	while(pn<pc && (p[pn][0]<=x1 || p[pn][1]>=y2 || p[pn][1]<=y1)) {
//		DEBUG(cout << "ignoring point: " << pn << endl;)
		pn++;
	}

	if(pn>=pc) {
		// so i got to the right border
		if((l - x1) * (y2 - y1)>m) { 
//			DEBUG(cout << "new big right border area: " << area1 <<endl;)
			m = (l - x1) * (y2 - y1); 
		}
		return;
	}

//	DEBUG(cout << "FOUND UPPER: " << pn << " :: " << p[pn][0] << "," << p[pn][1] << endl;)
	if((p[pn][1] - y1) * (l-x1) > m) {
		// this point will be my uppermost border
		area(y1,pn,p[pn][1]);
	}

//	DEBUG(cout << "FOUND BOTTOM: " << pn << " :: " << p[pn][0] << "," << p[pn][1] << endl;)
	if((y2 - p[pn][1]) * (l-x1) > m) {
		// this point will be my bottom
		area(p[pn][1],pn,y2);
	}

}

bool ordena(const int *i1, const int *i2) {
	return i1[0] < i2[0];
}

void executa() {
	
	// if there are no points, its nice
	if(pc==0) { cout << (l*w) << endl; return; }
	
//	DEBUG(cout << l << " x " << w << endl;cout << pc << " trees"<< endl;)
	
	m = 0;
	
	// adds a new point at 0,0
	int iz[2];
	iz[0] = 0;
	iz[1] = 0;
	vp.push_back(iz);
	pc++;
	
	sort(vp.begin(),vp.end(),ordena);
	
	int i,i2;
	for(i=0;i!=pc;i++) {p[i]=vp[i];}
	
//	DEBUG(for(int i=0;i!=pc;i++) cout << "tree #" << (i+1) <<": (" <<p[i][0] << "," << p[i][1] << ")"<<endl;)

	for(i=0;i!=pc;i++) {
		if(i!=0 && p[i][0]==p[i-1][0]) continue;
//		DEBUG(cout << "\n\nstarting with tree number " << (i+1) << endl;)
		x1 = p[i][0];
		area(0,i,w);
	}
	
	cout << m << endl;
}

int main() {

	int c,k,bx,by,dx,dy;
	cin >> c;
	while(c--!=0) {
		pc = 0;
		cin >> l >> w;
		vp.clear();
		while(true) {
			cin >> k;
			if(k==0) break;
			if(k==1) {
				int *k = new int[2];
				cin >> k[0] >> k[1];
				if(k[0]==0 || k[0]==l || k[1]==0 || k[1]==w) continue;
				vp.push_back(k);
				pc++;
				continue;
			}
			cin >> bx >> by >> dx>>dy;
			bx -= dx; by -= dy;
			while(k--!=0) {
				int *k = new int[2];
				k[0] = (bx += dx);
				k[1] = (by += dy);
				if(k[0]==0 || k[0]==l || k[1]==0 || k[1]==w) continue;
				vp.push_back(k);
				pc++;
			}
		}
		executa();
	}

}



