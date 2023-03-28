#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N,K;
int ret = 100000;
queue<pair<int, int>> q;
int visit[100001];

void BFS(int N){
    q.push({N, 0});
    visit[N] = 1;

    int loc, sec;
    while(!q.empty()){
        loc = q.front().first;
        sec = q.front().second;
        q.pop();

        if(loc == K){
            ret = sec;
            return;
        }

        if(loc-1 >= 0 && loc-1 <= 100000 && !visit[loc-1]){
            visit[loc-1] = 1;
            q.push({loc-1, sec+1});
        }
        if(loc+1 >= 0 && loc+1 <= 100000 && !visit[loc+1]){
            visit[loc+1] = 1;
            q.push({loc+1, sec+1});
        }
        if(2*loc >= 0 && 2*loc <= 100000 && !visit[2*loc]){
            visit[2*loc] = 1;
            q.push({2*loc, sec+1});
        }
    }
}

int main(){
    cin >> N >> K;
    BFS(N);
    cout << ret;
    return 0;
}