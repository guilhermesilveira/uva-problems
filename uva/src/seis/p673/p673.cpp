#include <iostream>
#include <stdio.h>
#include <string>
//#include <stack>

using namespace std;

string str;
int ifound;
//stack<char> st;
char cfound[129];

bool ehValida() {

	int len = str.length();
	int ifound = 0;
	//while(!st.empty()) st.pop();
	
	for(int i=0;i!=len;i++) {
		if(str[i]=='(') {
			//st.push(')');
			cfound[ifound++] = ')';
		} else if(str[i]=='[') {
			//st.push(']');
			cfound[ifound++] = ']';
		} else if(str[i]==')') {
			//if(st.size()==0 || st.top()!=')') {
			if(ifound--==0 || cfound[ifound]!=')') {
				return false;
			}
			//st.pop();
		} else if(str[i]==']') {
			//if(st.size()==0 || st.top()!=']') {
			if(ifound--==0 || cfound[ifound]!=']') {
				return false;
			}
			//st.pop();
		}
	}
	
	if(ifound!=0) return false;
	
	return true;

}

int main(int argc, char **argv) {

	char s[130];
	int inst;
	cin.getline(s, 129);
	sscanf(s, "%d", &inst);
	
	while(inst--!=0) {
		getline(cin,str);
		//cout << str << " " ;
		if(ehValida()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;

}
