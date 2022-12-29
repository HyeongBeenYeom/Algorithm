//계단 오르기

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int dp[301];
int score[301];
int n;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> score[i];
    }
    int tmp=0;
    int ret=0;
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]);

    for(int i=4;i<=n;i++){
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }

    cout << dp[n];

    return 0;
}