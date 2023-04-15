#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,level=2,ret=0,eat=0,minimum_time=0;
bool caneat = false, is_first=true;
int moved_x,moved_y;
int time[21][21];
int space[21][21];
bool visit[21][21];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
queue<pair<int,int>> q;

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >=0 && new_x < N && new_y >= 0 && new_y < N && !visit[new_x][new_y] && space[new_x][new_y] <= level){                
                if(space[new_x][new_y] < level && space[new_x][new_y] != 0){
                    if(is_first){
                        minimum_time = time[x][y]+1;
                        caneat = true;
                        is_first = false;
                    }
                }
                q.push({new_x, new_y});
                visit[new_x][new_y] = true;
                time[new_x][new_y] = time[x][y] + 1;                
            }
        }
    }
}

int main(){
    cin >> N;
    int a;    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a;
            if(a==9){
                q.push({i,j});
                visit[i][j] = true;
                space[i][j] = 0;
            }
            else{
                space[i][j] = a;    
            }
            
            if(a < level && a!=0)
                caneat = true;
        }
    }
    bool flag;
    while(caneat){
        flag = false;
        caneat = false;
        is_first = true;
        BFS();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(time[i][j] == minimum_time && space[i][j] != 0 && space[i][j] < level){
                    flag = true;
                    space[i][j] = 0;
                    moved_x = i;
                    moved_y = j;
                    ret += minimum_time;
                    eat++;
                    if(eat == level){
                        eat=0;
                        level++;
                    }
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!caneat)
            break;
        q = queue<pair<int,int>>();
        memset(visit, false, sizeof(visit));
        memset(time, 0, sizeof(time));
        q.push({moved_x, moved_y});
        visit[moved_x][moved_y] = true;
    }

    cout << ret;
    return 0;
}