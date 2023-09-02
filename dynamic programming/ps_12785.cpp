#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int w,h,x,y;
long long ret;
long long dp[201][201];

long long fill(int start_x, int start_y, int end_x, int end_y){
    memset(dp, 0, sizeof(dp));

    dp[start_y][start_x] = 1;
    for(int i=start_y;i<=h;i++){
        for(int j=start_x;j<=w;j++){
            if(i == start_y && j == start_x)
                continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000007;
        }
    }
    return dp[end_y][end_x] % 1000007;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> w >> h;
    cin >> x >> y;

    if(w == x && h == y){
        cout << fill(1,1,w,h) % 1000007;
    }
    else{
        cout << (fill(1,1,x,y) * fill(x,y,w,h)) % 1000007;
    }

    return 0;
}