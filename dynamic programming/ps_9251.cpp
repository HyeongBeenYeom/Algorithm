#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][1001];
char A[1001];
char B[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> A >> B;

    for(int i=1;i<=strlen(A);i++){
        for(int j=1;j<=strlen(B);j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[strlen(A)][strlen(B)];
    return 0;
}