#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {

	char *linha = new char[1000003];
	int *mapas = new int[1000003];

	int c = 1, casos, i, z, maxMap, size;
	int start, end;

	while((scanf("%s",linha))==1) {

		if(linha[0]=='\n' || linha[0]==0) break;

		size = strlen(linha);
		printf("Case %d:\n",c++);
		scanf(" %d", &casos);

		z = -100; maxMap = 0;
		char ultimo = '2';
		for(i = 0; i != size; i++) {
			if(linha[i]!=ultimo) {
				mapas[maxMap++] = i;
				ultimo = linha[i];
			}
		}

		//for(i=0;i!=maxMap;i++) cout << "i: " << mapas[i] << endl;

		for(i = 0; i != casos; i++) {
			
			scanf(" %d %d", &start, &end);
			
			if(start > end) {
				z = start;
				start = end;
				end = z;
			}
			
			for(z = 1; z < maxMap; z++) {
				if(start<mapas[z]) {
					// achei um ponto
					break;
				}
			}

			if(z==maxMap) {
				if(end<size) {
					cout << "Yes" << endl;
					continue;
				} else {
					cout << "No" << endl;
					continue;
				}
			}

			z--;

			//cout << mapas[z] << " " << mapas[z] << endl;

			if(mapas[z+1]>end) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}

			
		}
		
	}
	
	return 0;
	
}
