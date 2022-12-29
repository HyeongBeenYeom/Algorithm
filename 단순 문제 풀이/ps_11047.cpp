#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,K,idx;
	int ret = 0;
	int n;
	cin >> N >> K;
	int coin[11];

	for(int i=0;i<N;i++){
		int tmp;
		if(tmp <= K)
			idx = i;
		cin >> tmp;
		coin[i] = tmp;
	}
	while(K){
		n = K/coin[idx];
		K = K- n*coin[idx];
		idx--;
		ret += n;
	}
	cout << ret << '\n';
}