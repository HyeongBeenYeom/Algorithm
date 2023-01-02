//최소 힙

#include <cstdio>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    cin >> N;
    int x;
    for(int i=0;i<N;i++){
        
        cin >> x;

        if(x==0){
            if(pq.size()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}