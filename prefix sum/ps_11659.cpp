#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N,M,a;
    cin >> N >> M;
    int num[100001];
    for(int i=1;i<=N;i++){
        cin >> a;        
        num[i] = num[i-1] + a;        
    }

    int l,r;
    for(int i=0;i<M;i++){
        cin >> l >> r;
        
        cout << num[r] - num[l-1] << '\n';
    }
    return 0;
}