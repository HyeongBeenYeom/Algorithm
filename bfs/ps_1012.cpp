#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int M,N,K;
int field[51][51];
int visit[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> q;

void BFS(int init_x, int init_y){
    q.push({init_x,init_y});
    visit[init_x][init_y] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && field[new_x][new_y] && !visit[new_x][new_y]){
                q.push({new_x, new_y});
                visit[new_x][new_y] = 1;
            }
        }
    }

}
int main(){
    int T,x,y,ret;
    cin >> T;
    for(int t=0;t<T;t++){
        ret = 0;
        cin >> M >> N >> K;
        for(int k=0;k<K;k++){
            cin >> x >> y;
            field[x][y] = 1;
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j] && field[i][j]){
                    BFS(i,j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                visit[i][j] = 0;
                field[i][j] = 0;
            }
        }
    }
    return 0;
}