#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int x1,y1,r1,x2,y2,r2;
    double origin_dist, radius_dist;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        origin_dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
        if(r1>r2)
            radius_dist = r1-r2;
        else
            radius_dist = r2-r1;

        if(origin_dist == 0 && r1 == r2)
            cout << -1 << '\n';
        else if(origin_dist == radius_dist || origin_dist == r1 + r2)
            cout << 1 << '\n';
        else if(origin_dist < r1+r2 && radius_dist < origin_dist)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
    



    return 0;
}