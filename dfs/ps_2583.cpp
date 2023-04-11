#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int area=0,ret;
int map[101][101];
bool visit[101][101];
vector<int> v;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x, int y){
    visit[x][y] = true;

    for(int i=0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && !visit[new_x][new_y] && !map[new_x][new_y]){
            ret++;
            DFS(new_x, new_y);
        }
    }
}

int main(){
    cin >> M >> N >> K;
    int x,y,x_prime,y_prime;
    for(int i=0;i<K;i++){
        cin >> x >> y >> x_prime >> y_prime;
        for(int j=x;j<x_prime;j++){
            for(int k=y;k<y_prime;k++){
                visit[k][j]=true;
                map[k][j] = 1;
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                ret=1;
                area++;
                DFS(i,j);
                v.push_back(ret);
            }
        }
    }

    sort(v.begin(),v.end());
    cout << area << '\n';
    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    
    return 0;
}