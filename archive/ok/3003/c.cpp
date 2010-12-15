#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int n,a,b,c;
	string s,s1,s2;
	int men,mai,v;
	while((cin >> n) && n) {
		cin >> s1 >> a >> b >> c;
		mai = men = a * b * c;
		s2 = s1;
		for(int i=1;i<n;i++) {
			cin >> s >> a >> b >> c;
			v = a *  b * c;
			if(v>mai) {
				mai = v;
				s2 = s;
			}
			if(v<men) {
				men = v;
				s1 = s;
			}
		}
		if(men==mai) {
			cout << "No child has lost jelly." << endl;
		} else cout << s1 << " has lost jelly to " << s2 << "." << endl;
	}
	
	return 0;
	
}
