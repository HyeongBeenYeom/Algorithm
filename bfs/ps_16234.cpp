#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N,L,R,sum;
int flag = 1;
int A[51][51];
int visit[51][51];
int ret=0;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
vector<pair<int, int>> v;
queue<pair<int,int>> q;

void BFS(int init_r, int init_c){
    q.push({init_r,init_c});
    visit[init_r][init_c] = 1;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            int tmp = abs(A[new_r][new_c] - A[r][c]);
            if(new_r >= 0 && new_c >= 0 && new_r < N && new_c < N && !visit[new_r][new_c]){
                if(tmp >= L && tmp <= R){
                    q.push({new_r, new_c});
                    visit[new_r][new_c] = 1;

                    v.push_back({new_r, new_c});
                    sum += A[new_r][new_c];
                }
            }
        }
    }
}

int main(){
    cin >> N >> L >> R;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    
    while(flag){
        flag = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j]){
                    sum = 0;
                    v.clear();
                    v.push_back({i,j});
                    sum += A[i][j];
                    BFS(i,j);
                }

                if(v.size() >= 2){
                    flag = 1;
                    for(int i=0;i<v.size();i++){
                        A[v[i].first][v[i].second] = sum / v.size();
                    }
                }
            }
        }
        if(flag)
            ret++;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                visit[i][j]=0;
            }
        }
    }    

    cout << ret;

    return 0;
}