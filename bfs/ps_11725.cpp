#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> v[100001];
int parent[100001];
queue<int> q;

int main(){
    parent[1] = 1000000;
    cin >> N;
    int a,b;
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        if(a==1){
            parent[b] = 1;
            q.push(b);
        }
        if(b==1){
            parent[a] = 1;
            q.push(a);
        }
    }

    while(!q.empty()){
        a = q.front();
        q.pop();

        for(int i=0;i<v[a].size();i++){
            if(parent[v[a][i]] == 0){
                parent[v[a][i]] = a;
                q.push(v[a][i]);
            }
        }
    }
    for(int i=2;i<=N;i++){
        cout << parent[i] << '\n';
    }

    return 0;
}