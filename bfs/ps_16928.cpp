#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N,M;
bool visit[101];
int board[101];
int shortcut[101];
int dx[6] = {6,5,4,3,2,1};
queue<int> q;

void BFS(){
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0;i<6;i++){
            int new_x = x + dx[i];
            if(new_x==100){
                cout << board[x]+1;
                return;
            }
            if(new_x < 100 && !visit[new_x]){
                if(shortcut[new_x] != 0)
                    new_x = shortcut[new_x];
                if(!visit[new_x]){
                    board[new_x] = board[x] + 1;
                    visit[new_x] = true;
                    q.push(new_x);
                }

            }
        }
    }

}

int main(){
    cin >> N >> M;
    int start, end;
    for(int i=0;i<N;i++){
        cin >> start >> end;
        shortcut[start] = end;
    }
    for(int i=0;i<M;i++){
        cin >> start >> end;
        shortcut[start] = end;
    }

    BFS();

    return 0;
}