#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int dp[15][15]={0,};

	for(int i=1;i<15;i++){
		dp[0][i] = i;
	}
	for(int i=1;i<15;i++){
		for(int j=1;j<15;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	int T;
	cin >> T;
	int x,y;
	for(int i=0;i<T;i++){
		cin >> x;
		cin >> y;
		cout << dp[x][y] << '\n';
	}
	return 0;
}