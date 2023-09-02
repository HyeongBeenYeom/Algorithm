#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> ret;
int N;
int S,T;
bool flag = false;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S >> T;
        v.push_back({S,T});
    }
    
    sort(v.begin(),v.end());    

    for(int i=0;i<v.size();i++){
        if(i==0){
            ret.push(v[i].second);
        }
        else{
            if(ret.top()>v[i].first){
                ret.push(v[i].second);            
            }
            else{
                ret.pop();
                ret.push(v[i].second);
            }
        }
    }
    
    cout << ret.size();
    return 0;
}