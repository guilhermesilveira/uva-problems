#include <iostream>

using namespace std;
#define FOR(a,b) for(a=0;a<b;a++)
#define REP(a,b) for(int a=0;a<b;a++)
#include <algorithm>

int cod[5][5];
bool ja[5][5];
int col[5];int lin[5];
int diag[2];

void st() {

	int i,j,k,l;

	for(i=0;i<2;i++) FOR(j,5) cin >> cod[i][j];
	cin >> cod[2][0] >> cod[2][1] >> cod[2][3] >> cod[2][4];
	for(i=3;i<5;i++) FOR(j,5) cin >> cod[i][j];

	FOR(i,5) col[i]=lin[i]=0;
	lin[2]=col[2]=diag[1]=diag[0]=1;

	//FOR(i,5) { FOR(j,5) cout << cod[i][j] << " ";cout << endl;}

	FOR(i,75) {

		cin >> l;

		FOR(k,5) FOR(j,5)
			if(!(k==2 && j==2) && cod[k][j]==l) {
				lin[k]++; col[j]++;
				if(k+j==4) diag[0]++;
				else if(k==j) diag[1]++;
				goto nex;
			}
		// nao foi achado
		//cout << l << ": NAO ACHEI" << endl;
		continue;

		nex:
		//cout << l << ": " << endl;
		//FOR(k,5) cout << lin[k] << " "; cout << endl;
		//FOR(k,5) cout << col[k] << " "; cout << endl;
		if(*max_element(col,&col[5])==5
			 || *max_element(diag,&diag[2])==5
			 || *max_element(lin,&lin[5])==5 ) break;

	}
	cout << "BINGO after " << (i+1) << " numbers announced" << endl;
	for(;i<74;i++)cin>>l;

}


int main() {

	int t; cin >> t; while(t--) st(); return 0;

}
