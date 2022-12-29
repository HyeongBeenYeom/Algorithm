#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int N;
int height[50001];
int sum[50001];
int minimum[50001];

int main(){
	cin >> N;
	int tmp;
	for(int i=1;i<=N;i++){
		cin >> tmp;
		height[i] = tmp;
		if(i==1)
			sum[i] = tmp;
		else if(i==N){
			sum[i] = sum[i-1]+tmp;
		}
		else{
			tmp *=2;
			sum[i] = sum[i-1] +tmp;
		}
	}
	
	int a,b,c,d;
	minimum[0] = sum[N] * sum[N];
	for(int i=1;i<N;i++){
		for(int j=i;j<N-1;j++){
			a = (sum[j] - height[j]) * (sum[j] - height[j]);
			
		}
	}
	return 0;
}