#include <cstdio>
#include <iostream>

using namespace std;

int n;
int paper[129][129];
int w_ret = 0, b_ret = 0;

void dnq(int x, int y, int size){
    int tmp = 0;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(paper[i][j])
                tmp++;
        }
    }
    if(tmp == size * size){
        b_ret++;
    }
    else if(!tmp){
        w_ret++;
    }
    else{
        dnq(x, y, size/2);
        dnq(x, y + (size/2), size/2);
        dnq(x + (size/2), y, size/2);
        dnq(x + (size/2), y + (size/2), size/2);
    }
    return;
}

int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> paper[i][j];
    }
    dnq(0,0,n);
    cout << w_ret << '\n' << b_ret;
    return 0;
}