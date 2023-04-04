//Floyd-Warshall algorithm

#include <cstdio>
#include <iostream>

#define MAX 101
#define INF 1000000

using namespace std;

int adj[MAX][MAX];

int main(){
    int N,M;

    cin >> N >> M;

    int a,b;
    int ret=INF,mini=INF,tmp;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                adj[i][j] = 0;
            else if(adj[i][j] == 1)
                continue;
            else
                adj[i][j] = INF;
        }
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }        
        }
    }    
    for(int i=1;i<=N;i++){
        tmp=0;
        for(int j=1;j<=N;j++){
            tmp += adj[i][j];
        }
        if(tmp<mini){
            mini = tmp;
            ret = i;
        }
    }
    cout << ret;
    return 0;
}