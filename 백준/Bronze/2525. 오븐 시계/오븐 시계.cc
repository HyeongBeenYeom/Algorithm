#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    int H,M,a;

    cin >> H >> M;
    cin >> a;

    H += a/60;
    M += a%60;

    if(M>=60){
        H += M/60;
        M %= 60;
    }
    if(H>=24){
        H%=24;
    }

    cout << H << ' ' << M;

    return 0;
}