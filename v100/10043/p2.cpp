#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l,w;

vector<int*> p;
int pc;
int ddx,ddy;

#define DA
#ifdef D
	#define DEBUG(x) x
#else
	#define DEBUG(x) ;
#endif

bool verifica(int tx, int ty) {
	
	if(tx<ty) {
		if(tx>ddx || (tx==ddx && ty>ddy)) {
			ddx = tx;
			ddy = ty;
			DEBUG(cout << "new size: " << tx << "," << ty << "::"<<area1 <<endl;)
			return true;
		}
	} else {
		if(ty>ddx || (ty==ddx && tx>ddy)) {
			ddx = ty;
			ddy = tx;
			DEBUG(cout << "new size: " << tx << "," << ty << "::"<<area1 <<endl;)
			return true;
		}
	}
	
	return false;
	
}

void area(int x1, int y1, int p2, int y2) {

	DEBUG(cout << "new call: " << "??p1?? and " << p2 << "\t\t(" << x1 << "," << y1 << ")\t(" << p[p2][0] << "," << y2 << ")" << endl;)

	if(verifica((p[p2][0] - x1),(y2 - y1))) {
			DEBUG(cout << "comeco BEM POSICIONADO " << endl;);
	}

	int pn = p2 + 1;
	while(pn<pc && (p[pn][0]<=x1 || p[pn][1]>=y2 || p[pn][1]<=y1)) {
//		DEBUG(cout << "ignoring point: " << pn << endl;)
		pn++;
	}

	if(pn>=pc) {
		// so i got to the right border
		if(verifica((l - x1),(y2 - y1))) {
			DEBUG(cout << "BORDA DIREITA" << endl;);
		}
		return;
	}
	
//	DEBUG(cout<<"achado: " << pn << endl;)

	// lets test if this area is bigger than the previous ones
	if(verifica((p[pn][0] - x1),(y2 - y1))) {
			DEBUG(cout << "BEM POSICIONADO " << endl;);
	}

	DEBUG(cout << "FOUND UPPER: " << pn << " :: " << p[pn][0] << "," << p[pn][1] << endl;)
	area(x1,y1,pn,p[pn][1]);

	DEBUG(cout << "FOUND BOTTOM: " << pn << " :: " << p[pn][0] << "," << p[pn][1] << endl;)
	area(x1,p[pn][1],pn,y2);

}

bool ordena(const int *i1, const int *i2) {
	return i1[0] < i2[0];
}

void executa() {
	
	// if there are no points, its nice
	if(pc==0) { cout << (l)<<" " <<(w) << endl; return; }
	
	DEBUG(cout << l << " x " << w << endl;cout << pc << " trees"<< endl;)
	
	// adds a new point at 0,0
	int iz[2];
	iz[0] = 0;
	iz[1] = 0;
	p.push_back(iz);
	pc++;
	
	sort(p.begin(),p.end(),ordena);
	
	DEBUG(for(int i=0;i!=pc;i++) cout << "tree #" << (i+1) <<": (" <<p[i][0] << "," << p[i][1] << ")"<<endl;)

	ddx = 0; ddy = 0;
	int i,i2;
	for(int i=0;i!=pc;i++) {
		if(i!=0 && p[i][0]==p[i-1][0]) continue;
//		DEBUG(cout << "\n\nstarting with tree number " << (i+1) << endl;)
		area(p[i][0],0,i,w);
	}
	
	cout << ddx <<" " << ddy << endl;
}

int main() {

	int c,bx,by,dx,dy,a,b,cas=0;
	while(true) {
		pc = 0;
		cin >> a >> b;
		cin >> l >> w;
		if(a==b && b==0 && l==w && w==0) break;
		if(a<0) {
			l -= a;
			a = 0 - a;
		} else if(a>0) {
			l -= a;
			a = 0 - a;
		}
		w -= b;
		b = 0 - b;
		DEBUG(cout << a <<"," << b << "-" << l <<","<<w << endl;)
		p.clear();
		int kz;
		cin >> kz;
		while(kz--!=0) {
			int *k = new int[2];
			cin >> k[0] >> k[1];
			k[0]+=a;
			k[1]+=b;
			if(k[0]==0 || k[0]==l || k[1]==0 || k[1]==w) continue;
			p.push_back(k);
			pc++;
		}
		executa();
	}

}



