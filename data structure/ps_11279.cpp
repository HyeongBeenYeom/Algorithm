#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> max_heap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N,x;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> x;
        if(!x){
            if(max_heap.empty())
                cout << 0 << '\n';
            else{
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else{
            max_heap.push(x);
        }
    }

    return 0;
}