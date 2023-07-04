#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

char map[600][600];
bool visit[600][600];
queue<pair<int,int>> q;
int N,M;
int start_x, start_y;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ret = 0;

void BFS(){
    int init_x = start_x;
    int init_y = start_y;
    q.push({init_x,init_y});
    visit[init_x][init_y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && !visit[new_x][new_y] && map[new_x][new_y] != 'X'){
                q.push({new_x,new_y});
                visit[new_x][new_y] = true;
                if(map[new_x][new_y] == 'P')
                    ret++;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    string tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        for(int j=0;j<M;j++){
            map[i][j] = tmp[j];
            if(tmp[j] == 'I'){
                start_x = i;
                start_y = j;
            }
        }
    }

    BFS();

    if(ret == 0)
        cout << "TT";
    else
        cout << ret;
    return 0;
}