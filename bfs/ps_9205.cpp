#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct loc{
    int x;
    int y;
};

int t,n;
loc home;
loc festival;
loc convi[101];
queue<pair<int,int>> q;
bool visit[101];
bool flag;

bool BFS(){
    q.push({home.x, home.y});

    while(!q.empty()){
        int new_x = q.front().first;
        int new_y = q.front().second;
        q.pop();

        if(abs(festival.x-new_x) + abs(festival.y - new_y) <= 1000){
            return true;
        }
        for(int i=0;i<n;i++){
            if(visit[i])
                continue;

            if((abs(convi[i].x - new_x) + abs(convi[i].y - new_y)) <= 1000){
                visit[i] = true;
                q.push({convi[i].x, convi[i].y});
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;

    while(t--){
        cin >> n;

        cin >> home.x >> home.y;
        for(int i=0;i<n;i++){
            cin >> convi[i].x >> convi[i].y;
        }
        cin >> festival.x >> festival.y;

        if(BFS())
            cout << "happy\n";
        else
            cout << "sad\n";
        fill(visit, visit+101, false);
        while(!q.empty())
            q.pop();
    }
    
    return 0;
}