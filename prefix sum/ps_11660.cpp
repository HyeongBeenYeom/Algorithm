#include <cstdio>
#include <iostream>

using namespace std;

int map[1025][1025];
int N,M,a;
int x1,y1,x2,y2;
int ret=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> a;
            map[i][j] = a;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            map[i][j] += map[i-1][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            map[i][j] += map[i][j-1];       
        }
    }

    for(int i=0;i<M;i++){
        ret=0;
        cin >> x1 >> y1 >> x2 >> y2;
        ret = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
        cout << ret << '\n';
    }
    return 0;
}