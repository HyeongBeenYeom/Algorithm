#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[101][101];
bool visit[101][101];
int N,M;
int hour=0,cheese=0,ret;
queue<pair<int,int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void BFS(){
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >=0 && new_x < N && new_y >= 0 && new_y < M && !board[new_x][new_y] && !visit[new_x][new_y]){
                q.push({new_x, new_y});
                visit[new_x][new_y] = true;
            }
            else if(board[new_x][new_y] == 1){
                board[new_x][new_y] = 2;
            }
        }
    }
}

int main(){

    cin >> N >> M;
    int a;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> a;
            if(a)
                cheese++;
            board[i][j] = a;
        }
    }
    
    while(cheese){
        ret = cheese;

        BFS();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                    cheese--;
                }
            }
        }
        hour++;
        memset(visit, false, sizeof(visit));
    }

    cout << hour << '\n';
    cout << ret;
    return 0;
}