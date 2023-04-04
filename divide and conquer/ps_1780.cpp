#include <cstdio>
#include <iostream>

using namespace std;

int paper[2188][2188];
int pos_paper=0, zero_paper=0, neg_paper=0;

void dnq(int x, int y, int size){
    int neg=0, ze=0, pos=0;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(paper[i][j]==1)
                pos++;
            else if(paper[i][j]==0)
                ze++;
            else
                neg++;
        }
    }
    if(pos == size*size)
        pos_paper++;
    else if(ze == size*size){
        zero_paper++;
    }
    else if(neg == size*size)
        neg_paper++;
    else{
        dnq(x,y,(size/3));
        dnq(x,y+(size/3),(size/3));
        dnq(x,y+2*(size/3),(size/3));
        dnq(x+(size/3),y,(size/3));
        dnq(x+(size/3),y+(size/3),(size/3));
        dnq(x+(size/3),y+2*(size/3),(size/3));
        dnq(x+2*(size/3),y,(size/3));
        dnq(x+2*(size/3),y+(size/3),(size/3));
        dnq(x+2*(size/3),y+2*(size/3),(size/3));
    }
    return;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> paper[i][j];
        }
    }
    
    dnq(0,0,N);

    cout << neg_paper << '\n' << zero_paper << '\n' << pos_paper;
    return 0;
}