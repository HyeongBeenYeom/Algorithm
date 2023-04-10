#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int N;
char painting[101][101];
bool visit[101][101];
int rgb_ret=0, rb_ret=0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x, int y){
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !visit[new_x][new_y] && painting[x][y] == painting[new_x][new_y])
            DFS(new_x, new_y);
    }
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> painting[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                DFS(i,j);
                rgb_ret++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(painting[i][j] == 'G')
                painting[i][j] = 'R';
        }
    }
    memset(visit, false , sizeof(visit));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                DFS(i,j);
                rb_ret++;
            }
        }
    }

    cout << rgb_ret << ' ' << rb_ret;

    return 0;
}