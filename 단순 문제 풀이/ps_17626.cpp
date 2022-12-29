#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N,tmp;
	cin >> N;

	vector<int> dp(N+1);
	dp[1] = 1;
	for(int i=2;i<=N;i++){
		int minimum = 10000000;
		for(int j=1;j*j<=i;j++){
			tmp = i-j*j;
			minimum = min(minimum,dp[tmp]);
		}
		dp[i] = minimum+1;
	}

	cout << dp[N];

}