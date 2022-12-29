#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int N,a,ret=0;
	int prime[1001]={0,};
	prime[1]=1;
	cin >> N;
	int tmp;
	for(int i=2;i*i<1000;i++){
		tmp = 2;
		if(prime[i])
			continue;
		while(i*tmp<=1000){
			prime[i*tmp] = 1;
			tmp++;
		}
	}
	for(int i=0;i<N;i++){
		cin >> a;
		if(!prime[a])
			ret++;
	}
	cout << ret;
	return 0;
}