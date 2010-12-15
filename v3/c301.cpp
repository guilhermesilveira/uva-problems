#include <iostream>

using namespace std;

int cap,dest,npedidos;
int m[50][10];
int s[10];

void coloca (int ped) {
int i;
	for (i=m[ped][0];i<m[ped][1];i++) {
		s[i]+=m[ped][2];
	} 
}

void tira (int ped) {
int i;
	for (i=m[ped][0];i<m[ped][1];i++) {
		s[i]-= m[ped][2];
	} 
}

bool sit[100];

int ganhomaximo = 0;

void res(int ped,int ganho) {

	int aceita = 1;
	int i, max, max2;
	
	if(ganho>ganhomaximo) ganhomaximo =  ganho;

	if(ped==npedidos) {
/*		cout << "prof: " << ped << endl;
		for(i=0;i<ped;i++) {
			cout << sit[i] << " ";
		}cout << " lucro " << ganho << endl;*/
		return;
	}

	for (i=m[ped][0];i<m[ped][1];i++) {
		if (s[i]+m[ped][2] > cap) {aceita = 0; break;}
		//cout << cap << "--- "<<s[i]+m[ped][2]<<endl;
	}

	sit[ped]=0;
	res(ped+1,ganho);

	if (aceita) {
		sit[ped] = 1;
		coloca(ped);
		res(ped+1,ganho+m[ped][3]);
	        tira(ped);
	}

}

int main() {

	int i;

	while(1) {
		cin >> cap >> dest >> npedidos;
		if(!cap && !dest && !npedidos) break;
		i=0;
                int j;
		for (j=0; j<7;j++) {
			s[j] = 0;
		}	
		while(i<npedidos) {
			cin >> m[i][0] >> m[i][1] >> m[i][2];
			m[i][3] = (m[i][1]-m[i][0])*m[i][2];
//			cout << m[i][0] << " "  << m[i][1] << " " << m[i][2] << " " << m[i][3] << endl;
			i++;
		}
		ganhomaximo = 0;
		res(0,0);
		cout << ganhomaximo << endl;
	}

}
