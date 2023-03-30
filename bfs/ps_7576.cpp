#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int visit[1001][1001];
int box[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> q;
int M,N;

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >=0 && new_x < N && new_y >=0 && new_y < M && box[new_x][new_y]==0){
                box[new_x][new_y] = box[x][y]+1;
                q.push({new_x, new_y});
            }
        }
    }
}
int main(){
    cin >> M >> N;
    int a, ret=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> a;
            if(a==1)
                q.push({i,j});
            box[i][j] = a;
        }
    }

    BFS();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(box[i][j] == 0){
                cout << -1;
                return 0;
            }
            if(ret < box[i][j])
                ret = box[i][j];
        }
    }
    cout << ret-1;
    return 0;
}