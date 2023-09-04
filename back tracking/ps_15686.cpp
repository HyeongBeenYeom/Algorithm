#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int N,M;
int a,tmp,ret=10000;
int val = 10000;
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
vector<int> order;

void backTracking(int n){
    if(order.size()>=M){        
        tmp = 0;
        for(int i=0;i<home.size();i++){
            val = 10000;
            for(int j=0;j<M;j++){
                val = min(val, (abs(home[i].first - chicken[order[j]].first) + abs(home[i].second - chicken[order[j]].second)));
            }
            tmp += val;
        }

        ret = min(ret,tmp);
        return;
    }


    for(int i=n;i<chicken.size();i++){
        if(order.size() < M){
            order.push_back(i);
            backTracking(i+1);
            order.pop_back();    
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a;
            if(a == 1)
                home.push_back({i,j});
            else if(a == 2)
                chicken.push_back({i,j});
        }
    }

    backTracking(0);

    cout << ret;
    return 0;
}