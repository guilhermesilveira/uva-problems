#include <iostream>

using namespace std;


class StrArray {
public:
    char **s;
    int tot;
    StrArray(int i){
        s = (char **) malloc(sizeof(char *)*i);
        clear();
    }
    void clear() {
        tot = 0;
    }
    void add(char *c) {
        s[tot++] = c;
    }
    void split(char *st, char c) {
        clear();
        bool b = false;
        char *start = st;
        while((*st)!='\0') {
            if((*st)!=c) {
                if(!b) {
                    start = st;
                    b = true;
                }
            } else {
                (*st) = '\0';
                if(b) {
                    b = false;
                    add(start);
                }
            }
            st++;
        }
        if(b) { add(start); }
    }
    int *toInt() {
        int *z = (int *) malloc(sizeof(int) * tot);
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = -atoi(s[i]+1);
        	else z[i] = atoi(s[i]);
        }
        return z;
    }
    long *toLong() {
        long *z = (long *) malloc(sizeof(long) * tot);
        for(int i=0;i!=tot;i++) {
        	if(s[i][0]=='-') z[i] = -atol(s[i]+1);
        	else z[i] = atol(s[i]);
        }
        return z;
    }
};


bool isCharacter(char c) {
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool isVocal(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
		c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

StrArray ar = StrArray(10000);
const char *DEPENDS = "DEPEND";
const char *INSTALL = "INSTALL";
const char *LIST = "LIST";
const char *REMOVE = "REMOVE";

char comp[10000][15];
bool dep[10000][10000];

int compc = 0;
int findComp(char *c) {
	int len = strlen(c);
	if(c[len-1]=='\n' || c[len-1]=='\r') c[len-1]='\0';
	int i;
	for(i=0;i!=compc;i++) {
		if(strcmp(comp[i],c)==0) return i;
	}
	for(i=0;i!=10000;i++) dep[compc][i] = false;
	strcpy(comp[compc++],c);
	return compc-1;
}

void addDep(int v1,int v2) {
	cout << v1 << " depends on " << v2 << endl;
	dep[v1][v2]=true;
}

void depends() {
	int val = findComp(ar.s[1]);
	for(int i=2;i<ar.tot;i++) {
		int v2 = findComp(ar.s[i]);
		addDep(val,v2);
	}
}
void list() {
	cout << "list ";
}
void install() {
	cout << "install ";
	findComp(ar.s[1]);
}
void remove() {
	cout << "remove ";
	findComp(ar.s[1]);
}

void parse() {
	int len = strlen(ar.s[0]);
	if(ar.s[0][len-1]=='\n' || ar.s[0][len-1]=='\r') ar.s[0][len-1]='\0';
	if(strcmp(ar.s[0],DEPENDS)==0) depends();
	else if(strcmp(ar.s[0],LIST)==0) list();
	else if(strcmp(ar.s[0],INSTALL)==0) install();
	else if(strcmp(ar.s[0],REMOVE)==0) remove();
	cout << "..." << endl;
}

int main() {
	
	char s[10000];
	
	while(true) {
		
		cin.getline(s,10000);
		cout << s << endl;
		
		if(s[0]=='E' && s[1]=='N' && s[2]=='D') break;
		
		ar.clear();
		ar.split(s,' ');
		
		parse();
		
	}

	return 0;
	
}
