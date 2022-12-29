#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N,M;
	cin >> M >> N;
	int *prime = new int[1000001]{0,};
	prime[1] = 1;
	int tmp;
	for(int i=2;i*i<=N;i++){
		tmp = 2;
		if(prime[i])
			continue;
		while(i*tmp<=N){
			prime[i*tmp] = 1;
			tmp++;
		}
	}
	for(int i=M;i<=N;i++){
		if(!prime[i])
			cout << i << '\n';
	}
	delete[] prime;


	return 0;
}