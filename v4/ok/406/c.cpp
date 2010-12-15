#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int pc=3;
	int pr[2000];
	pr[0]=1;
	pr[1]=2;
	pr[2]=3;
	int i,j,k,n;
	for(i=5;i!=10001;i+=2) {
		for(j=1;j!=pc;j++) if(i%pr[j]==0) break;
		if(j==pc) pr[pc++] = i;
	}
	
	//cout << pc << endl;
	
	int g;
	while((cin >> k >> n)) {
		// acha a posicao de k na lista
		for(i=0;i!=pc;i++) if(pr[i]>k) break;
		//cout << "pos: " << i << endl;
		if(i%2!=0) g = n * 2 -1;
		else g = n * 2;
		cout << k << " " << n << ":";
		int l = (i/2) - g/2;
		for(j=0;j!=g;j++) {
			if(j+l<0) continue;
			if(j+l>=pc || pr[j+l]>k) break;
			cout << " " << pr[j+l];
		}
		cout << endl << endl;
	}
	
	return 0;
	
}
