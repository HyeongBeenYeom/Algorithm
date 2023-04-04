#include <cstdio>
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

queue<tuple<int,int,int>> q;
int box[101][101][101];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};
int M,N,H;

void BFS(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());

        q.pop();

        for(int i=0;i<6;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int new_z = z + dz[i];

            if(new_x >=0&&new_x<H&&new_y>=0&&new_y<N&&new_z>=0&&new_z<M&&box[new_x][new_y][new_z] == 0){
                box[new_x][new_y][new_z] = box[x][y][z]+1;
                q.push(make_tuple(new_x,new_y,new_z));
            }
        }
    }
}

int main(){
    int a,ret=0;
    cin >> M >> N >> H;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin >> a;
                if(a==1)
                    q.push(make_tuple(i,j,k));
                box[i][j][k] = a;
            }
        }
    }

    BFS();

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(box[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                if(ret<box[i][j][k])
                    ret = box[i][j][k];
            }
        }
    }
    cout << ret-1;
    return 0;
}