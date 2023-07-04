#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v;
int arr[10];
bool visit[10];

void DFS(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int x=0;
    for(int i=0;i<N;i++){
        if(v[i] != x && arr[cnt-1] <= v[i]){
            arr[cnt] = v[i];
            x = arr[cnt];
            DFS(cnt+1);
        }
    }
}

int main(){
    int a;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    DFS(0);
    return 0;
}