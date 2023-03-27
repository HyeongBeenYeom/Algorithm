#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> node[1001];
int visit[1001];

void DFS(int n){
    visit[n] = 1;
    int next;
    for(int i=0;i<node[n].size();i++){
        next = node[n][i];
        if(!visit[next])
            DFS(next);
    }
}

int main(){
    cin >> N >> M;
    int x,y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    int ret=0;
    for(int i=1;i<=N;i++){
        if(visit[i])
            continue;
        DFS(i);
        ret++;
    }
    cout << ret;
    return 0;
}