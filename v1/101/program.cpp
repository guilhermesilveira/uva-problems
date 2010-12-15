#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vector<int> stacks[26];
int actual[26];
int stacks[26][26];
int stackI[26];

int tamanhoDe(int i) {
	//return stacks[i].size();
	return actual[i];
}

int ondeEsta(int i) {
	return stackI[i];
}

void coloca(int a,int b) {
	stacks[b][actual[b]++] = a; stackI[a] = b;
}

void moveStack(int stack,int from,int stackTo) {
	// para todos do stackI[from]
	bool found = false;
	int limite = tamanhoDe(stack);
	for(int i2=0;i2!=limite;i2++) {
		if(found) {
			// coloca ele em to
			coloca(stacks[stack][i2], stackTo);
		} else if(stacks[stack][i2]==from) {
			// seta o limite do stack....
			actual[stack] = i2;
			found = true;
			// coloca ele em to
			coloca(stacks[stack][i2], stackTo);
		}
	}
}

void limpaStack(int stack,int from) {
	// para todos do stackI[from]
	bool found = false;
	int limite = tamanhoDe(stack);
	for(int i2=0;i2!=limite;i2++) {
		if(found) {
			// joga o cara na stack original dele
			coloca(stacks[stack][i2], stacks[stack][i2]);
		} else if(stacks[stack][i2]==from) {
			// seta o limite do stack....
			actual[stack] = i2;
			found = true;
		}
	}
}

int main(char **argv,int argc) {

	int blocks;
	int i,i2;
	cin >> blocks;
	for(i=0;i!=blocks;i++) {
		actual[i] = 1;
		stacks[i][0] = i;
		stackI[i] = i;
	}
	
	string action1;
	int from;
	string action2;
	int to;
	while(true) {
	
		cin >> action1;
		
		if(action1=="quit") {
			break;
		}
		
		cin >> from >> action2 >> to;
		
		if(from==to || from>=blocks || to>=blocks || from<0 || to<0 || ondeEsta(from)==ondeEsta(to)) {
			continue;
		}

		// executa a acao

		if(action1=="move" && action2=="onto") {

			// limpa a stack a partir de from, inclusive
			limpaStack(ondeEsta(from), from);

			// limpa a stack a partir de to, exclusive
			limpaStack(ondeEsta(to), to);
			actual[ondeEsta(to)]++;

			// coloca from em to
			int target = ondeEsta(to);
			stacks[target][actual[target]++] = from;
			stackI[from] = target;
			
		} else if(action1=="move" && action2=="over") {
		
			//cout << "move " << from << " over " << to << endl;
			
			// limpa a stack a partir de from, inclusive
			limpaStack(ondeEsta(from), from);
			
			// coloca from em to
			int target = ondeEsta(to);
			stacks[target][actual[target]++] = from;
			stackI[from] = target;

		} else if(action1=="pile" && action2=="onto") {
		
			//cout << "pile " << from << " onto " << to << endl;
			// limpa a stack a partir de to, exclusive
			limpaStack(ondeEsta(to), to);
			actual[ondeEsta(to)]++;
			
			// move
			int target = ondeEsta(to);
			moveStack(stackI[from],from,target);
			
		} else if(action1=="pile" && action2=="over") {
		
			int target = ondeEsta(to);
			//cout<< "pile " << from << " over " << to << endl;
			// move
			moveStack(stackI[from],from,target);
			
		}
		
	}

	for(i=0;i!=blocks;i++) {
		if(actual[i]==0) {
			printf("%d:\n",i);
		} else if(actual[i]==1) {
			printf("%d: %d\n",i,stacks[i][0]);
		} else {
			printf("%d:",i);
			for(to=0;to!=actual[i];to++) {
				printf(" %d",stacks[i][to]);
			}
			printf("\n");
		}
	}

	return 0;

}
