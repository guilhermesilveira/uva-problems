#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <string>

int rows, columns;
long long matrix[10][100];
long long dp[10][100];
int anterior[10][100];
int minimo[100];
int atual[100];

using namespace std;

int main() {

	 long long TOP = 2, menorSoma;
	 for(int i=2;i!=31;i++) {
	 	TOP *= 2;
	 }
	 TOP++;
	 int menor, i, i2, minV, primeira, yMenos1,yMais1,igual,yIgual,ultima;

    while((cin >> rows >> columns)) {

         for(i=0;i!=rows;i++) {
              for(i2=0;i2!=columns;i2++) {
              	cin >> matrix[i][i2];
              }
              dp[i][0] = TOP;
              dp[i][columns-1] = matrix[i][columns-1];
         }
         
         if(columns==1) {
         	menorSoma = TOP;
            for(i2=0;i2!=rows;i2++) if(matrix[i2][0]<menorSoma) { menorSoma = matrix[i2][0]; minV = i2;}
            cout << (minV+1) << endl;
            cout << menorSoma << endl;
         	continue;
         }
         
         if(rows==1) {
         	menorSoma = 0;
            for(i2=0;i2!=columns-1;i2++) {
            	menorSoma += matrix[0][i2];
	            cout << "1 ";
            }
            cout << "1" << endl;
            cout << (menorSoma+matrix[0][columns-1]) << endl;
         	continue;
         }

         for(int x=columns-2;x!=-1;x--) {
         	
         	 // para cada coluna
	         for(int y=0;y!=rows;y++) {
	         	
			    // se esta no fim
			    if(y == rows-1) {
			    	
			    	primeira = dp[0][x+1];
			    	yMenos1 = dp[y-1][x+1];
			    	yIgual = dp[y][x+1];
			    	
			    	if(primeira <= yMenos1 && primeira <= yIgual) {
			    		dp[y][x] = primeira + matrix[y][x];
			    		anterior[y][x] = 0;
			    	} else if(yMenos1 <= yIgual) {
			    		dp[y][x] = yMenos1 + matrix[y][x];
			    		anterior[y][x] = y-1;
			    	} else {
			    		dp[y][x] = yIgual + matrix[y][x];
			    		anterior[y][x] = y;
			    	}
			    	
			    } else if(y==0) {
			    	
			    	yIgual = dp[0][x+1];
			    	yMais1 = dp[1][x+1];
			    	ultima = dp[rows-1][x+1];
			    	
			    	if(yIgual <= yMais1 && yIgual <= ultima) {
			    		dp[0][x] = yIgual + matrix[0][x];
			    		anterior[0][x] = 0;
			    	} else if(yMais1 <= ultima) {
			    		dp[0][x] = yMais1 + matrix[0][x];
			    		anterior[0][x] = 1;
			    	} else {
			    		dp[0][x] = ultima + matrix[0][x];
			    		anterior[0][x] = rows-1;
			    	}
			    	
			    } else {
			    	
			    	yMenos1 = dp[y-1][x+1];
			    	igual = dp[y][x+1];
			    	yMais1 = dp[y+1][x+1];
			    	if(yMenos1 <= yMais1 && yMenos1 <= igual) {
			    		dp[y][x] = yMenos1 + matrix[y][x];
			    		anterior[y][x] = y-1;
			    	} else if(igual <= yMais1) {
			    		dp[y][x] = igual + matrix[y][x];
			    		anterior[y][x] = y;
			    	} else {
			    		dp[y][x] = yMais1 + matrix[y][x];
			    		anterior[y][x] = y+1;
			    	}
			    	
			    }
	         }
         	
         }

		menor = 0;
		for(i=1;i!=rows;i++) {
			if(dp[i][0] < dp[menor][0]) {
				menor = i;
			}
		}
		menorSoma = dp[menor][0];
		
		printf("%d ", menor+1);
		
		for(i = 0; i < columns-2;i++) {
			printf("%d ", (anterior[menor][i]+1));
			menor = anterior[menor][i];
		}
		
		printf("%d\n", (anterior[menor][columns-2]+1));
		cout << menorSoma << endl;

    }

    return 0;

}
