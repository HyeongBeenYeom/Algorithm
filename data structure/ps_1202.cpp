#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> gem;
vector<int> bag;
priority_queue<int> tmp;

int main(){
    int N,K;
    long long ret=0;
    int idx=0;
    cin >> N >> K;    
    int M,V,C;
    for(int i=0;i<N;i++){
        cin >> M >> V;
        gem.push_back(make_pair(M,V));
    }
    sort(gem.begin(), gem.end());

    for(int i=0;i<K;i++){
        cin >> C;
        bag.push_back(C);
    }
    sort(bag.begin(), bag.end());

    for(int i=0;i<K;i++){
        while(idx < N && gem[idx].first <= bag[i]){
            tmp.push(gem[idx].second);
            idx++;
        }
        if(!tmp.empty()){
            ret += (long long)tmp.top();
            tmp.pop();
        }
    }
    cout << ret;
    return 0;
}