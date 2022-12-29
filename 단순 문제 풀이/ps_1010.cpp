//다리 놓기

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,N,M;
	cin >> T;
	while(T--){
		int ret = 1;
		cin >> N >> M;
		for(int i=M, j = 1;i>M-N;i--, j++){
			ret *= i;
			ret /= j;
		}
		cout << ret << '\n';
	}
}

