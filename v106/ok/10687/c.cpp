#include <iostream>

using namespace std;

int tot;

class P {
public:
	int x,y;
	int nos[100];
	int tot;
	void clear() {
		tot = 0;
		v = false;
	}
	void adiciona(int i) {
		nos[tot++] = i;
	}
	bool v;
};

P pontos[1000];

int dist(int p1,int p2) {
	return abs(((pontos[p1].x - pontos[p2].x) * (pontos[p1].x - pontos[p2].x) ) +
		((pontos[p1].y - pontos[p2].y) * (pontos[p1].y - pontos[p2].y) ));
}

void faz(int p1,int p2) {
//	cout << "de " << p1 << " para " << p2 << endl;
	pontos[p1].adiciona(p2);
}

void conecta(int pi) {
	int mini1 = -1;
	int mini2 = -1;
	int minid1 = -1;
	int minid2 = -1;
	int dis;
	for(int i=0;i!=tot;i++) {
		if(i!=pi) {
			dis = dist(pi,i);
			if(mini1==-1) {
				mini1 = i;
				minid1 = dis;
				continue;
			}
			if(mini2==-1) {
					mini2 = i;
					minid2 = dis;
					continue;
			}
			if(dis<minid1 || (dis==minid1 && (pontos[i].x<pontos[mini1].x || (pontos[i].x==pontos[mini1].x && pontos[i].y<pontos[mini1].y)) )) {
			
				mini2 = mini1;
				minid2 = minid1;
				mini1 = i;
				minid1 = dis;
			} else {
				if(dis<minid2 || (dis==minid2 && (pontos[i].x<pontos[mini2].x || (pontos[i].x==pontos[mini2].x && pontos[i].y<pontos[mini2].y)) )) {
					mini2 = i;
					minid2 = dis;
				}
			}
		}
	}
	if(mini1!=-1) faz(pi,mini1);
	if(mini2!=-1) faz(pi,mini2);
}

int busca(int i) {
int k=0;
//	cout << "buscando dentro de " << i<<endl;
	for(int j=0;j!=pontos[i].tot;j++) {
		//cout << "tentando ir para " << pontos[i].nos[j]<<endl;
		if(pontos[pontos[i].nos[j]].v==false) {
			pontos[pontos[i].nos[j]].v=true;
			k++;
			k+=busca(pontos[i].nos[j]);
		}
	}
	return k;
}

int main() {

	while(true) {
		cin >> tot;
		if(tot==0) break;
		for(int i=0;i!=tot;i++) {
			pontos[i].clear();
			cin >> pontos[i].x >> pontos[i].y;
		}
		for(int i=0;i!=tot;i++) {
			conecta(i);
		}
		pontos[0].v=true;
		int t = busca(0)+1;
	//	cout << t << endl;
		if(t==tot) {
			cout << "All stations are reachable." << endl;
		} else { 
			cout << "There are stations that are unreachable."<<endl;
		}
	}

	return 0;

}
