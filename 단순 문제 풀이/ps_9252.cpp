//Longest Common Subsequence

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

char tmp1[1001],tmp2[1001];
int dp[1001][1001];
vector<char> ret;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	
	cin >> tmp1;
	cin >> tmp2;
	int tmp1_size = strlen(tmp1);
	int tmp2_size = strlen(tmp2);
	for(int i=1;i<=tmp1_size;i++){
		for(int j=1;j<=tmp2_size;j++){
			if(tmp1[i-1] == tmp2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}
	int k=tmp1_size;
	for(int i=tmp2_size;i>=0;i--){
		for(int j=k;j>=0;j--){
			if(dp[j][i] == dp[j][i-1])
				break;
			else if(dp[j][i] == dp[j-1][i])
				continue;
			else{
				ret.push_back(tmp1[j-1]);
				k = j-1;
				break;
			}
		}
	}
	cout << dp[tmp1_size][tmp2_size] << '\n';
	for(int i=dp[tmp1_size][tmp2_size]-1;i>=0;i--)
		cout << ret[i];

	return 0;
}