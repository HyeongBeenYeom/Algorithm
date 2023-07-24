#include <cstdio>
#include <iostream>

using namespace std;

int max_map[4];
int min_map[4];
int map[100001][4];
int N,a;

int main(){
    cin >> N;


    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> a;
            map[i][j] = a;
        }
    }

    max_map[0] = map[0][0];
    max_map[1] = map[0][1];
    max_map[2] = map[0][2];
    min_map[0] = map[0][0];
    min_map[1] = map[0][1];
    min_map[2] = map[0][2];

    for(int i=1;i<N;i++){
        int max_tmp0 = max_map[0];
        int max_tmp2 = max_map[2];
        max_map[0] = max(max_map[0],max_map[1]) + map[i][0];        
        max_map[2] = max(max_map[1], max_map[2]) + map[i][2];
        max_map[1] = max(max(max_tmp0, max_map[1]), max_tmp2) + map[i][1];
        int min_tmp0 = min_map[0];
        int min_tmp2 = min_map[2];
        min_map[0] = min(min_map[0], min_map[1]) + map[i][0];        
        min_map[2] = min(min_map[1], min_map[2]) + map[i][2];
        min_map[1] = min(min(min_tmp0, min_map[1]), min_tmp2) + map[i][1];        
    }

    cout << max(max(max_map[0], max_map[1]), max_map[2]) << ' ' << min(min(min_map[0], min_map[1]), min_map[2]);


    return 0;
}