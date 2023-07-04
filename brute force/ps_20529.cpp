#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;
int N;


int dist(string a, string b){
    int ret=0;
    for(int i=0;i<4;i++){
        if(a[i] != b[i]){
            ret++;
        }
    }
    return ret;
}

int main(){
    cin >> T;
    while(T--){
        vector<string> v;
        int minimum = 1000;
        cin >> N;
        for(int i=0;i<N;i++){
            string tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        if(N>32){
            cout << 0 << '\n';
            continue;
        }
        for(int i=0;i<N-2;i++){
            for(int j=i+1;j<N-1;j++){
                for(int k=j+1;k<N;k++){
                    minimum = min(minimum, dist(v[i],v[j]) + dist(v[i],v[k]) + dist(v[j], v[k]));
                }
            }
        }
        cout << minimum << '\n';
    }
    return 0;
}