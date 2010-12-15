#include <iostream>
#include <stdio.h>

using namespace std;

char hand[52][2];
char temp[52][2];

int shuffles[100][52];

char suits[4][10] = {"Clubs","Diamonds","Hearts","Spades"};
char hands[13][10]= {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};

int main(char **argv,int argc) {

	int cases;
	int actualCase = 0;
	int knownShuffles;
	scanf("%d",&cases);

	char line[20];
	int s;
	int i;
	int j;
	
	while(cases--!=0) {

		if(actualCase++!=0) {
			printf("\n");
		}

		scanf("%d",&knownShuffles);
		for(i=0;i!=knownShuffles;i++) {
			for(int z=0;z!=52;z++) {
				scanf("%d ",&shuffles[i][z]);
			}
			scanf("\n");
		}

		// zera a mao
		for(i=0;i!=4;i++) {
			for(int y=0;y!=13;y++) {
				hand[i*13+y][0] = y;
				hand[i*13+y][1] = i;
			}
		}

		// executa as trocas
		while(true) {
			cin.getline(line,18);
			if(line[0]==0 || line[1]=='\n') break;
			sscanf(line,"%d",&s);
			for(j=0;j!=52;j++) {
				temp[j][0] = hand[j][0];
				temp[j][1] = hand[j][1];
			}

			for(j=0;j!=52;j++) {
				hand[j][0] = temp[shuffles[s-1][j]-1][0];
				hand[j][1] = temp[shuffles[s-1][j]-1][1];
			}
		}

		for(i=0;i!=52;i++) {
			printf("%s of %s\n",hands[hand[i][0]],suits[hand[i][1]]);
		}

	}

	return 0;

}
