#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
string fact[101][101];

string recur(string s1, string s2){
    int sum=0;
    string ret;

    while(!s1.empty() || !s2.empty() || sum){
        if(!s1.empty()){
            sum += s1.back()-'0';
            s1.pop_back();
        }
        if(!s2.empty()){
            sum += s2.back() -'0';
            s2.pop_back();
        }
        ret.push_back((sum%10) + '0');
        sum /= 10;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

string combination(int n, int r){
    if(n == r || r == 0)
        return "1";

    string &ret = fact[n][r];

    if(ret != "")
        return ret;

    ret = recur(combination(n-1,r-1), combination(n-1,r));
    return ret;
}

int main(){
    cin >> n >> m;

    cout << combination(n,m);

    return 0;
}