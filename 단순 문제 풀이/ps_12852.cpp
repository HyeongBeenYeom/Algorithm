#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, ret[1000001];

int find_minimum(int n){
	for(int i=1; i<=n;i++){
		ret[i] = i-1;
	}
	for(int i=2;i<=n;i++){
		if(i%2==0)
			ret[i] = min(ret[i],ret[i/2]);
		if(i%3==0)
			ret[i] = min(ret[i],ret[i/3]);
		ret[i] = min(ret[i],ret[i-1])+1;
	}
	cout << ret[n] << '\n';

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	find_minimum(N);

	while(N != 0){
		cout << N << ' ';
		if(N == 1)
			break;
		if(ret[N] == ret[N-1] + 1)
			N -= 1;
		else if(N%2 == 0 && ret[N] == ret[N/2]+1)
			N /=2;
		else if(N%3 == 0 && ret[N] == ret[N/3]+1)
			N /= 3;
	}
}