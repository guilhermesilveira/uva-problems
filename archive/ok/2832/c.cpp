#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Time {
public:
	char nome[100];
	int prob[4][2];
	int ac;
	int penalty;
};

bool comp(const Time &t1, const Time &t2) {

	if(t1.ac!=t2.ac) return t1.ac>t2.ac;
	return t1.penalty<t2.penalty;
	// falta verificar se os dois forem iguais, o que fazer?

}

int main() {

	int n,i,j;

	cin >> n;

	vector<Time> times;

	for(i=0;i!=n;i++) {

		Time t;
		cin >> t.nome;
		t.penalty = t.ac = 0;

		for(j=0;j!=4;j++) {

			cin >> t.prob[j][0] >> t.prob[j][1];
			if(t.prob[j][1]!=0) {
				t.ac++;
				t.penalty += t.prob[j][1] + (t.prob[j][0]-1)*20;
			}

		}
		
		times.push_back(t);
	}

//	sort(times.begin(),times.end(),comp);

	Time &t = *min_element(times.begin(),times.end(),comp);
	cout << t.nome << " " << t.ac << " " << t.penalty << endl;

}
