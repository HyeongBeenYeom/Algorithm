#include <cstdio>
#include <iostream>

using namespace std;

int N,A;
int arr[1001];
int dp[1001];
int ret=0;

int main(){

    cin >> N;

    fill_n(dp,N,1);

    for(int i=0;i<N;i++){
        cin >> A;
        arr[i] = A;
    }
    
    
    for(int i=N-1;i>=0;i--){
        if(i==N-1){
            dp[i] = 1;
            ret = dp[i];
        }
        else{
            for(int j=i+1;j<N;j++){
                if(arr[i]<arr[j]){
                    if(dp[i] < dp[j]+1)
                        dp[i] = dp[j]+1;
                    if(ret < dp[i]){
                        ret = dp[i];
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}