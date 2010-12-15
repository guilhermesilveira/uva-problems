#include <iostream>

using namespace std;

int main() {
	
	int traps[3];
	int position[10];
	int squares;
	int players;
	int diceRolls;
	int diceRoll1,diceRoll2;
	int currentPlayer;
	bool paused[10];
	
	while(true) {
		
		cin >> players >> squares;
		if(players==0 && squares==0) break;
		
		//cout << "NOVO:::" << players << " " << squares << endl;
		currentPlayer = 0;

		cin >> traps[0] >> traps[1] >> traps[2];
		//cout << traps[0] << " " << traps[1] << " " << traps[2] << endl;

		cin >> diceRolls;
		//cout << diceRolls << endl;
		
		for(int i=0;i!=players;i++) {
			paused[i] = false;
			position[i] = 0;
		}
		
		while(diceRolls!=0) {
			
			//cout << "vez do " << currentPlayer << endl;
			
			// se ele esta pausado
			if(paused[currentPlayer]) {
				//cout << currentPlayer << " aguarda" << endl;
				paused[currentPlayer] = false;
				currentPlayer++;
				if(currentPlayer==players) currentPlayer = 0;
				continue;
			}

			// se ele nao esta pausado, le os dados
			cin >> diceRoll1 >> diceRoll2;
			diceRolls--;
			//cout << currentPlayer << " anda " << (diceRoll1+diceRoll2) << endl;
			
			// avanca
			position[currentPlayer] += diceRoll1 + diceRoll2;
			//cout << currentPlayer << " cai em " << (position[currentPlayer]) << endl;
			
			// se ja passou
			if(position[currentPlayer] > squares) {
				continue;
			}
			
			if(position[currentPlayer]==traps[0] || position[currentPlayer]==traps[1] || position[currentPlayer]==traps[2]) {
				//cout << currentPlayer << " cai em trap" << endl;
				paused[currentPlayer] = true;
			}

			currentPlayer++;
			if(currentPlayer==players) currentPlayer = 0;

		}

		cout << (currentPlayer+1) << endl;
		//if(caso++==4) break;

	}
	
}
