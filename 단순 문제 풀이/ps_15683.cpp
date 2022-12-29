#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int N, M, ret;
int space[8][8];
vector<tuple<int, int, int>> v;

void fill(int i, int j, int d){
    if(d == 1){
        for(int k=i; k>=0; k--){                            
            if(space[k][j] == 6)
                break;
            if(space[k][j] == 0)                            
                space[k][j] = 7;
        }
    }//up
    if(d == 2){
        for(int k=i; k<N; k++){                            
            if(space[k][j] == 6)
                break;
            if(space[k][j] == 0)
                space[k][j] = 7;
        }
    }//down
    if(d == 3){
        for(int k=j; k>=0; k--){
            if(space[i][k] == 6)
                break;
            if(space[i][k] == 0)                            
                space[i][k] = 7;
        }
    }//left
    if(d == 4){
        for(int k=j; k<M; k++){
            if(space[i][k] == 6)
                break;
            if(space[i][k] == 0)
                space[i][k] = 7;
        }
    }//right
    return;
}
void Reset(int tmp_space[8][8]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            space[i][j] = tmp_space[i][j];
    }
    return;
}
int check(){
    int zero=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(space[i][j] == 0)
                zero++;
        }
    }
    return zero;
}
void Find_ret(int idx){

    if(idx == v.size()){
        ret = min(ret, check());
        return;
    }
    int x = get<0>(v[idx]);
    int y = get<1>(v[idx]);
    int cctv = get<2>(v[idx]);
    int tmp_space[8][8];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            tmp_space[i][j] = space[i][j];
    }

    if(cctv == 1){
        for(int i=1; i<=4; i++){
            fill(x, y, i);
            Find_ret(idx+1);
            Reset(tmp_space);
        }    
    }
    else if(cctv == 2){
        fill(x,y,3);
        fill(x,y,4);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,1);
        fill(x,y,2);
        Find_ret(idx+1);
        Reset(tmp_space);
    }
    else if(cctv == 3){
        fill(x,y,1);
        fill(x,y,3);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,1);
        fill(x,y,4);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,2);
        fill(x,y,3);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,2);
        fill(x,y,4);
        Find_ret(idx+1);
        Reset(tmp_space);
    }
    else if(cctv == 4){
        fill(x,y,1);
        fill(x,y,3);
        fill(x,y,4);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,1);
        fill(x,y,4);
        fill(x,y,2);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,4);
        fill(x,y,2);
        fill(x,y,3);
        Find_ret(idx+1);
        Reset(tmp_space);

        fill(x,y,2);
        fill(x,y,3);
        fill(x,y,1);
        Find_ret(idx+1);
        Reset(tmp_space);
    }
    else if(cctv == 5){
        for(int i=1; i<=4; i++)
            fill(x,y,i);
        Find_ret(idx+1);
        Reset(tmp_space);
    }




}

int main(){
    
    cin >> N >> M;
    ret = N*M;
    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            cin >> space[i][j];
            if(space[i][j] != 0 && space[i][j] != 6)
                v.push_back(make_tuple(i,j,space[i][j]));
        }
    }
    

    Find_ret(0);

    
    
    printf("%d\n", ret);
    return 0;
}