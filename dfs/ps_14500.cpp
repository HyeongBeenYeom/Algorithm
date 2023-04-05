#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 501

int N,M,ret=0;
int paper[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int T_shape_x[4][4] = {{0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,0,1}};
int T_shape_y[4][4] = {{0,1,2,1},{0,0,0,1},{0,1,2,1},{0,1,1,1}};

void DFS(int x, int y, int depth, int val){
    if(depth==4){
        ret = max(ret,val);
        return;
    }

    for(int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x>=0&&new_x<N&&new_y>=0&&new_y<M&&!visit[new_x][new_y]){
            visit[new_x][new_y] = true;

            DFS(new_x, new_y, depth+1, val + paper[new_x][new_y]);

            visit[new_x][new_y] = false;
        }
    }
}

void T_shape(int x, int y){
    for(int i=0;i<4;i++){
        int val=0;
        bool flag=false;

        for(int j=0;j<4;j++){
            int new_x = x + T_shape_x[i][j];
            int new_y = y + T_shape_y[i][j];

            if(new_x >= 0 && new_x < N && new_y>=0 && new_y<M){
                val+=paper[new_x][new_y];
            }
            else{
                flag=true;
                break;
            }
        }
        if(!flag){
            ret = max(ret,val);
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> paper[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visit[i][j] = true;
            DFS(i,j,1,paper[i][j]);
            visit[i][j] = false;

            T_shape(i,j);
        }
    }

    cout << ret;
    return 0;
}