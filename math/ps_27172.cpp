#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,a;
vector<int> v;
int player[1000001];
int score[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> a;
        v.push_back(a);
        player[a] = 1;
    }

    for(int i=0;i<N;i++){
        for(int j=v[i]*2;j<1000001;j+= v[i]){
            if(player[j] == 1){
                score[v[i]]++;
                score[j]--;
            }
        }
    }

    for(int i=0;i<v.size();i++){
        cout << score[v[i]] << ' ';
    }
    return 0;
}