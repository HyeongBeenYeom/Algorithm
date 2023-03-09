#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int big[11]={0,};
    int ret[11]={0,};
    for(int i=1;i<=N;i++){
        cin >> big[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<N;j++){
            if(big[i]==0 && ret[j]==0){
                ret[j] = i;
                break;
            }
            else if(ret[j]==0)
                big[i]--;
        }
    }
    for(int i=0;i<N;i++){
        cout << ret[i] << ' ';
    }
    return 0;
}