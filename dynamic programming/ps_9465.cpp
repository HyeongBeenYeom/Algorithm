#include <cstdio>
#include <iostream>

using namespace std;

int dp[2][100001];
int sticker[2][100001];
int T,n,a;
int ret=0;

int main(){
    cin >> T;
    for(int t=0;t<T;t++){
        ret=0;
        cin >> n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> a;
                sticker[i][j] = a;
            }
        }
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[0][1] + dp[1][0];
        dp[1][1] = sticker[1][1] + dp[0][0];
        ret = max(dp[0][1],dp[1][1]);
        for(int j=2;j<n;j++){
            dp[0][j] = max(dp[0][j-2], dp[1][j-2]);
            dp[0][j] = max(dp[0][j], dp[1][j-1]);
            dp[0][j] += sticker[0][j];
            dp[1][j] = max(dp[0][j-2],dp[1][j-2]);
            dp[1][j] = max(dp[1][j],dp[0][j-1]);
            dp[1][j] += sticker[1][j];
            if(ret < max(dp[0][j], dp[1][j]))
                ret = max(dp[0][j], dp[1][j]);
        }
        cout << ret << '\n';
    }
    return 0;
}