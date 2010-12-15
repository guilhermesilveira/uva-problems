#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main (char **argv, int argc) {
	
	int casos;
	scanf(" %d",&casos);
	
	int m, n;
	
	while(casos--!=0) {
		
		scanf(" %d %d",&m,&n);
		
		vector<int> v;
		for(int i = 0;i != m; i++) {
			int z;
			scanf(" %d",&z);
			v.push_back(z);
		}
		
		int posGet = 0;
		int last = 0;
//		printf("perguntando\n");
		for(int i = 0;i != n; i++) {
			int z;
			scanf(" %d",&z);
			printf("z:%d\n",z);
			//if(z != last) {
				//sort(v.begin(),v.begin()+z);
			//}
			while(z != last) {
				printf("add:%d\n",v[last]);
				ord.push(v[last++]);
			}
			last = z;
			printf("%d\n",ord.top() + posGet++);
		}
		
		if(casos!=0) printf("\n");
		
	}


  return 0;

}
