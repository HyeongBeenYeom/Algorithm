#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
double sum=0;
int ret=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    int a;
    if(n==0){
        cout << 0;
        return 0;
    }
    int except = round(n*0.15);
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i=except;i<(n-except);i++){
        sum += v[i];
    }
    ret = round(sum/(n-2*except));
    cout << ret;
    return 0;
}