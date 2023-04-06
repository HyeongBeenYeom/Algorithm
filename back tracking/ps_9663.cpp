#include <cstdio>
#include <iostream>

using namespace std;

int N,ret=0;
int board[16];

void check(int qnum){
    bool flag;
    if(qnum==N){
        ret++;
        return;
    }
    for(int i=0;i<N;i++){
        flag=true;
        board[qnum] = i;

        for(int j=0;j<qnum;j++){
            if(board[j] == board[qnum] || abs(qnum-j) == abs(board[qnum] - board[j])){
                flag = false;
                break;
            }
        }
        if(flag){
            check(qnum+1);
        }
    }
}
int main(){
    cin >> N;
    check(0);
    cout << ret;
    return 0;
}