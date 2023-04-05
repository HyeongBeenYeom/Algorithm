#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N;
int video[65][65];
string ret;

void DNQ(int x, int y, int size){
    int tmp=0;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(video[i][j])
                tmp++;
        }
    }
    if(tmp == size*size){
        ret += '1';
        return;
    }
    else if(tmp == 0){
        ret += '0';
        return;
    }
    else{
        ret += '(';
        DNQ(x,y,(size/2));
        DNQ(x,y+(size/2),(size/2));
        DNQ(x+(size/2),y,(size/2));
        DNQ(x+(size/2),y+(size/2),(size/2));
        ret+=')';
    }
    return;
}
int main(){
    cin >> N;
    string input;
    for(int i=0;i<N;i++){
        cin >> input;
        for(int j=0;j<N;j++){
            video[i][j] = input[j]-'0';
        }
    }

    DNQ(0,0,N);

    cout << ret;
    return 0;
}