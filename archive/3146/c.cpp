#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(a,b) for(a=0;a<b;a++)

int naip(char c) {
	if(c=='C') return 0;
	if(c=='D') return 1;
	if(c=='H') return 2;
	return 3;
}

#define PI pair<char,int>
#define P2 pair<int,char>

int valor(char c) {

	if(c>='0' && c<='9') return c-'0';
	if(c=='T') return 10;
	if(c=='J') return 11;
	if(c=='Q') return 12;
	if(c=='K') return 13;

}

vector<PI> cards;

void carta(int v) {
	if(v==13) cout << 'K';
	if(v>=1 && v<=9) cout <<  (char) (v+'0');
	if(v==10) cout << "10";
	if(v==11) cout << "J";
	if(v==12) cout << "Q"; 
}

void imp(int i) {
	carta(cards[i].second);
	cout << cards[i].first;
}
vector<P2> sai;
void imp2(int i) {
	carta(sai[i].first);
	cout << sai[i].second;
}

void st() {

	int i,j,k;
	char c[10][4];
	cards.clear();sai.clear();
	FOR(i,5) {
		cin >> c[i];
		if(c[i][0]=='A') c[i][0]='1';
		if(c[i][1]=='0') {
			c[i][0]='T';
			c[i][1]=c[i][2];
			c[i][2]='\0';
		}
		cards.push_back(make_pair((c[i][1]),valor(c[i][0])));
	}

	sort(cards.begin(),cards.end());

	for(i=0;i!=4;i++) {
		if(cards[i].first==cards[i+1].first) break;
	}

	int sel = i, base = i + 1;
	int v;
	//imp(sel);cout<<endl;
	for(j=1;j!=7;j++) {
		v=(cards[base].second+j)%13;
		if(!v) v=13;
		if(cards[sel].second==v) {
			// valido!
		//cout << "valido "<<v << endl;
			goto n;
		}
	}
	// invalido, troca a selecao
	i=sel; sel=base;base=i;
	

n:;
	int dif = cards[sel].second - cards[base].second;
	if(dif<0) dif = 13 - cards[base].second + cards[sel].second;
	imp(sel); cout << " ";
	imp(base); cout << " ";

	FOR(i,5) if(i!=sel && i!=base) {
		sai.push_back(make_pair(cards[i].second,cards[i].first));
		//cout<< endl << i << endl;
	}

	sort(sai.begin(),sai.end());
#define IC(i) imp2(i); cout << " ";
	/*FOR(i,sai.size()){
		cout << i<<":";
		IC(i); cout << endl;
	}*/


	if(dif==1) {
		IC(0);IC(1);IC(2);
	} else if(dif==2) {
		IC(1);IC(0);IC(2);
	} else if(dif==3) {
		IC(1);IC(2);IC(0);
	} else if(dif==4) {
		IC(0);IC(2);IC(1);
	} else if(dif==5) {
		IC(2);IC(0);IC(1);
	} else if(dif==6) {
		IC(2);IC(1);IC(0);
	}
	cout << endl;


}


int main() {
	int t;
	cin >> t;
	while(t--) st();
	return 0;
}
