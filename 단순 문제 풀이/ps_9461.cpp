#include <cstdio>
#include <iostream>

using namespace std;

long long dp[101]={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T,tmp;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<101;i++){
		dp[i] = dp[i-2]+dp[i-3];
	}
	for(int i=0;i<T;i++){
		cin >> tmp;
		cout << dp[tmp] << '\n';
	}
}