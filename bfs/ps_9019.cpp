#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T;
int A,B;
queue<pair<int,string>> q;
bool visit[10000];

void BFS(){
    q.push({A,""});

    while(!q.empty()){
        int a = q.front().first;
        string s = q.front().second;
        visit[a] = true;
        q.pop();

        if(a == B){
            cout << s << '\n';
            return;
        }

        int D = (a*2)%10000;
        if(!visit[D]){
            visit[D] = true;
            q.push({D, s + 'D'});
        }

        int S = a-1 < 0 ? 9999 : a-1;
        if(!visit[S]){
            visit[S] = true;
            q.push({S, s + 'S'});
        }

        int L = (a%1000)*10 + (a/1000);
        if(!visit[L]){
            visit[L] = true;
            q.push({L, s + 'L'});
        }

        int R = (a%10)*1000 + (a/10);
        if(!visit[R]){
            visit[R] = true;
            q.push({R, s + 'R'});
        }
    }
}

int main(){
    cin >> T;    
    for(int t=0;t<T;t++){
        cin >> A >> B;
        BFS();
        q = queue<pair<int,string>>();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}