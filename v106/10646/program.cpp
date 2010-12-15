#include <iostream>
#include <string>

#define VALORDE(x) (val[x][0]>='2' && val[x][0]<='9' ? val[x][0]-'0' : 10 )

using namespace std;

int main() {
	
	int casos, caso =1, novaPosicao, y, x, tirar;
	cin >> casos;
	string val[52];
	
	while(casos--!=0) {
		
		for(int i=51;i!=-1;i--) {
			cin >> val[i];
		}
		for(int i=0;i!=52;i++) {
	//		cin >> val[i];
		//	cout << i << "=" << val[i] << " ";
		}
		//cout << endl;
		
		y = 0;
		
		// pega a carta da 25 posicao
		x = 25;
		//cout << "y=" << y << ",x=" << x << ",val[x]=" << val[x] << endl;
		y += VALORDE(x);
		tirar = 10 - VALORDE(x);
		novaPosicao = x + tirar + 1;
		x = novaPosicao;

		//cout << "y=" << y << ",x=" << x << ",val[x]=" << val[x] << endl;
		y += VALORDE(x);
		tirar = 10 - VALORDE(x);
		novaPosicao = x + tirar + 1;
		x = novaPosicao;

		//cout << "y=" << y << ",x=" << x << ",val[x]=" << val[x] << endl;
		y += VALORDE(x);
		tirar = 10 - VALORDE(x);
		novaPosicao = x + tirar + 1;
		x = novaPosicao;
		
		if((52-(y-1)) >= x) {
			// ok
			y = 52 - (y-1);
		} else {
			novaPosicao = x - (52-(y-1));
			y = 25 - novaPosicao - 1;
		}
/*		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << (52 - y) << endl;
		cout << val[52-y-1] << endl;
		cout << val[52-y] << endl;
		cout << val[52-y+1] << endl;*/
		cout << "Case " << caso++ << ": " << val[y] << endl;
	}
	
}
