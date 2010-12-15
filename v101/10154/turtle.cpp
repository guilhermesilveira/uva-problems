#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX (6000)
#define PESO 0
#define CONS 1
#define DIFF 2

#define TURTLES(i) (turtles[ord[i]])

int **turtles;
int n;
vector<int> ord;

bool compara(const int i1,const int i2) {
/*	if(turtles[i1][CONS]==turtles[i2][CONS]) {
		return turtles[i1][DIFF] < turtles[i2][DIFF];
	}
	return (turtles[i1][CONS] < turtles[i2][CONS]);*/
return (turtles[i1][DIFF] > turtles[i2][DIFF]);
}

int main() {

	turtles = new int *[MAX];

	int a,b;
	n = 0;

	while((cin >> a >> b)) {
		if(b-a<0) continue;
		turtles[n] = new int[3];
		turtles[n][PESO] = a;
		turtles[n][CONS] = b;
		turtles[n][DIFF] = b - a;
		ord.push_back(n++);
	}

	sort(ord.begin(),ord.end(),compara);

	int aguenta[MAX], length[MAX];
	int maxT = 1;

	for(int i=0;i!=n;i++) {
		length[i] = 1;
		aguenta[i] = TURTLES(i)[DIFF];
//		cout << "turtle " << i << "::" << TURTLES(i)[CONS] << endl;
	}
	
	for(int i=0;i!=n;i++) {
		for(int j=i+1;j<n;j++) {
			if(length[i]+1>length[j] ||
			  (length[i]+1==length[j] && aguenta[i]-TURTLES(j)[PESO]>aguenta[j])) {
			  	if(aguenta[i] < TURTLES(j)[PESO]) continue;
			  	length[j] = length[i] + 1;
			  	aguenta[j] = aguenta[i] - TURTLES(j)[PESO];
			}
		}
		/*cout << "iter " << i << endl;
		for(int j=0;j!=n;j++) {
			cout << j << ":: " << length[j] << "," << aguenta[j] << endl;
		}*/
	}
	
	for(int i=0;i!=n;i++) {
		if(length[i]>maxT) maxT=length[i];
	}
	
	cout << maxT << endl;

}
