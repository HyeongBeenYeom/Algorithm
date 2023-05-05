#include <cstdio>
#include <iostream>

using namespace std;

int N,M;
int arr[10];

void DFS(int init, int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=init; i<=N;i++){
        arr[cnt] = i;
        DFS(i,cnt+1);
    }
}

int main(){

    cin >> N >> M;

    DFS(1,0);

    return 0;
}