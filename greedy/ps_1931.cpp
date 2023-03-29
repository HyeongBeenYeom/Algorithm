#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main(){
    cin >> N;
    int a,b;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        v.push_back({b,a});
    }

    sort(v.begin(), v.end());

    int tmp = v[0].first;
    int ret = 1;
    for(int i=1;i<N;i++){
        if(tmp <= v[i].second){
            tmp = v[i].first;
            ret++;
        }
    }
    cout << ret;
    return 0;
}