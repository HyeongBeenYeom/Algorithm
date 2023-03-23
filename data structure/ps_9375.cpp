#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int T,ret;
    cin >> T;
    int n;
    string type,name;
    map<string,int> m;

    for(int t=0;t<T;t++){
        ret = 1;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> name >> type;
            if(m.find(type) != m.end())
                m[type]++;
            else
                m.insert({type,1});
        }
        for(auto i:m){
            ret *= i.second+1;
        }
        ret--;
        cout << ret << '\n';
        m.clear();
    }
    return 0;
}