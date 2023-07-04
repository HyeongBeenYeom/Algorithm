#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int A,B;
queue<pair<long long int,int>> q;
int ret = -1;

void BFS(){
    while(!q.empty()){
        long long int a = q.front().first;
        int num = q.front().second;
        q.pop();

        if(a == B){
            ret = num;
            return;
        }

        if(a*2 <= B)
            q.push({a*2, num+1});
        if(a*10+1 <= B)
            q.push({a*10+1, num+1});
    }
}

int main(){
    cin >> A >> B;

    q.push({A,1});

    BFS();

    cout << ret;
    return 0;
}