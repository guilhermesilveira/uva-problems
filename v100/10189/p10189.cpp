#include <iostream>
#include <string>

using namespace std;

long instCount = 0;
long y;
long x;
char lastLine[101];
char line[101];

int main(int argc, char **argv) {

	while(true) {
	
		cin >> y >> x;
		
		if(y==0 && x==0) {
			break;
		}
		
		if(instCount!=0) cout << endl;
		
		cout << "Field #" << ++instCount << endl;
		
		for(int i=0;i!=x;i++) {
			lastLine[i]='0';
		}
		lastLine[x] = 0;
		
		for(int iy=0;iy!=y;iy++) {
		
			scanf("%s",line);
			for(int ix=0;ix!=x;ix++) {
			
				// para cada caracter da linha atual
				if(line[ix]=='*') {
				
					// se for uma bomba
					if(lastLine[ix]!='*') {
						// se o ultimo for diferente de bomba, soma um
						lastLine[ix]++;
					}

					// compara as diagonais superiores
					// compara agora com o anterior
					if(ix!=0 && lastLine[ix-1]!='*') {
						lastLine[ix-1]++;
					}
					// compara agora com o posterior
					if(ix!=x-1 && lastLine[ix+1]!='*') {
						lastLine[ix+1]++;
					}
					
					continue;
					
				}
				
				// se eh um ponto
				
				// se o da linha anterior for uma bomba
				if(lastLine[ix]=='*') {
					line[ix]='1';
				} else {
					line[ix]='0';
				}
				
				if(ix!=0 && lastLine[ix-1]=='*') {
					line[ix]++;
				}
				if(ix!=x-1 && lastLine[ix+1]=='*') {
					line[ix]++;
				}
				
				// compara agora com o anterior
				if(ix!=0 && line[ix-1]=='*') {
					line[ix]++;
				}
				// compara agora com o posterior
				if(ix!=x-1 && line[ix+1]=='*') {
					line[ix]++;
				}

			}
			
			// se a linha for diferente de 0, imprime a ultima linha
			if(iy!=0) {
				printf("%s\n",lastLine);
			}
			// copia para a ultima linha
			for(int ix=0;ix!=x;ix++) {
				lastLine[ix]=line[ix];
			}
			
		}
		
		printf("%s\n",lastLine);
		
	}
	
	return 0;

}
