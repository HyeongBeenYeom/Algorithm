#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
    cin >> N;

    int a,b;
    for(int i=0;i<N;i++){
        cin >> a;
        if(a){
           b = abs(a);
           pq.push({b,a}); 
        }
        else{
            if(!pq.empty()){
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    

    return 0;
}