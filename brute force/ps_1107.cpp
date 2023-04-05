#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N,M,start=100,ret;
string target,tmp;
bool broken[11];

int main(){
    cin >> N;
    cin >> M;
    int a;
    bool flag=false;
    target = to_string(N);
    ret = abs(N-100);
    for(int i=0;i<M;i++){
        cin >> a;
        broken[a] = true;
    }

    if(N==start){
        cout << 0;
        return 0;
    }

    for(int i=0;i<=1000000;i++){
        flag = false;
        tmp = to_string(i);
        for(int j=0;j<tmp.size();j++){
            if(broken[tmp[j]-'0']){
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        int a = abs(N-i)+tmp.size();
        ret = min(ret, a);
    }

    cout << ret;
    return 0;
}