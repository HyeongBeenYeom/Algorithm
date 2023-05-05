#include <cstdio>
#include <iostream>

using namespace std;

int N,M;
int arr[10];
bool visit[10];

void DFS(int init, int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=init; i<=N;i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = i;
            DFS(i+1,cnt+1);
            visit[i] = false;
        }
    }
}
int main(){

    cin >> N >> M;

    DFS(1,0);

    return 0;
}