#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N,M,ret=0;
bool before,is_Pn;
string S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N;
    cin >> M;
    cin >> S;

    for(int i=0;i<S.size();i++){
        if(S[i] == 'O')
            continue;
        int tmp=0;

        while(S[i+1] == 'O' && S[i+2] == 'I'){
            tmp++;
            if(tmp == N){
                tmp--;
                ret++;
            }
            i+=2;
        }
        tmp=0;
    }

    cout << ret;
    return 0;
}