#include <cstdio>
#include <iostream>

using namespace std;


int dp[501][501] = {0,};
int tmp[501][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	int r,c;
	for(int i=1;i<=N;i++){
		cin >> r >> c;
		tmp[i][0] = r;
		tmp[i][1] = c;
	}

	for(int i=1;i<N;i++){
		for(int j=0;i+j<=N;j++){
			dp[j][i+j] = 2147483647;
			for(int k=j;k<=i+j;k++){
				dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + tmp[j][0] * tmp[k][1] *tmp[i+j][1]);
			}
		}
	}
	cout << dp[1][N];

	return 0;
}