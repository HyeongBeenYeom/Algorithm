#include <cstdio>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int weight[51];
	int height[51];
	int rank[51]={0,};

	for(int i=0;i<N;i++){
		scanf("%d %d",&weight[i], &height[i]);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(weight[i]<weight[j] && height[i]<height[j]){
				rank[i]++;
			}
		}
		printf("%d\n",rank[i]+1);
	}
}