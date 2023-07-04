#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;
int map[500][500];
int ret[500][500];
queue<pair<int,int>> q;
int dx[2] = {1,1};
int dy[2] = {0,1};
bool visit[500][500];
int maximum = -1;

void BFS(){
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visit[x][y])
            continue;
        visit[x][y] = true;

        for(int i=0;i<2;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y <= new_x){
                ret[new_x][new_y] = max(ret[new_x][new_y], map[new_x][new_y] + ret[x][y]);
                q.push({new_x, new_y});
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> map[i][j];
        }
    }

    ret[0][0] = map[0][0];

    BFS();

    for(int i=0;i<n;i++){
        maximum = max(maximum, ret[n-1][i]);
    }

    cout << maximum;
    return 0;
}