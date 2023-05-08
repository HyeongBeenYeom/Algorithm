#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int arr[10];
vector<int> v;
bool visit[10];

void DFS(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<N;i++){
        if(arr[cnt-1] <= v[i]){            
            arr[cnt] = v[i];
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