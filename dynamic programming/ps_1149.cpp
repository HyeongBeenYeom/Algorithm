#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int dp[1001][4];

int main(){
    int N;
    cin >> N;
    int cost[1001][4];

    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            cin >> cost[i][j];
        }
    }
    
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    
    for(int i=1;i<=N;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];        
    }
    
    cout << min(dp[N][2],min(dp[N][0],dp[N][1]));
    return 0;
}