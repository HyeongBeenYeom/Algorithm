//소수의 연속합

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int prime_num[4000001] = {0,};
int N;
int prime[4000001];

int main(){
	cin >> N;
	int idx = 0;
	int ret=0;
	int start=0, end=0,sum=0;

	prime_num[0] = prime_num[1] = 1;
	for(int i=2;i*i<=N;i++){
		if(!prime_num[i]){
			for(int j=i+i;j<=N;j+=i)
				prime_num[j] = 1;
		}
	}
	for(int i=1;i<=N;i++){
		if(!prime_num[i]){
			prime[idx] = i;
			idx++;
		}
	}
	while(1){
		if(sum >= N)
			sum -= prime[start++];
		else if(end == idx)
			break;
		else
			sum += prime[end++];
		if(sum == N)
			ret++;
	}
	cout << ret;
}