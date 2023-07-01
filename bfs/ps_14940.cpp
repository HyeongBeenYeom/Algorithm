#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
bool visit[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[1001][1001];
int ret[1001][1001];
int n,m;
int start_n, start_m;

void BFS(int x, int y){
    ret[x][y] = 0;
    visit[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        int N = q.front().first;
        int M = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_N = N + dx[i];
            int new_M = M + dy[i];

            if(new_M >= 0 && new_M < m && new_N >= 0 && new_N < n && !visit[new_N][new_M] && map[new_N][new_M] != 0){
                q.push({new_N, new_M});
                ret[new_N][new_M] = ret[N][M] + 1;
                visit[new_N][new_M] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            if(a==2){
                start_n = i;
                start_m = j;
            }
            map[i][j] = a;
        }
    }

    BFS(start_n, start_m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ret[i][j] == 0){
                if(map[i][j] == 0 || (i == start_n && j == start_m))
                    cout << 0 << ' ';
                else
                    cout << -1 << ' ';
            }
            else
                cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}