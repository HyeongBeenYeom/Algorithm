#include <cstdio>
#include <iostream>

using namespace std;

#define INF 1000

int adj[101][101];
int N;

int main(){
    cin >> N;
    int a;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> a;
            if(i==j)
                adj[i][j] = INF;
            else{                
                if(a)
                    adj[i][j] = a;
                else
                    adj[i][j] = INF;
            }
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
        for(int j=1;j<=N;j++){
            if(adj[i][j]!=INF)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}