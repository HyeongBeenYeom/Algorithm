#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int A[51][51];
int rot[51][51];
int tmp[51][51];
int N,M,K;
int r,c,s;
int val=10000;
vector<tuple<int,int,int>> v;
vector<int> order;
bool visit[6];

void rotate(int R, int C, int S){
    int x = R-S;
    int y = C-S;
    for(int i=0;i<2*S+1;i++){
        for(int j=0;j<2*S+1;j++){
            rot[i][j] = tmp[x+i][y+j];
        }
    }

    for(int i=0;i<2*S+1;i++){
        for(int j=0;j<2*S+1;j++){
            if(i<S){
                if(j<i){
                    tmp[x+i-1][y+j] = rot[i][j];
                }
                else if(j>=2*S-i){
                    tmp[x+i+1][y+j] = rot[i][j];
                }
                else{
                    tmp[x+i][y+j+1] = rot[i][j];
                }
            }
            else if(i>S){
                if(j<=2*S-i){
                    tmp[x+i-1][y+j] = rot[i][j];
                }
                else if(j>i){
                    tmp[x+i+1][y+j] = rot[i][j];
                }
                else{
                    tmp[x+i][y+j-1] = rot[i][j];
                }
            }
            else{
                if(j<S)
                    tmp[x+i-1][y+j] = rot[i][j];
                else if(j>S)
                    tmp[x+i+1][y+j] = rot[i][j];
                else
                    tmp[x+i][y+j] = rot[i][j];
            }
        }
    }
}

void findMin(){
    for(int i=1;i<=N;i++){
        int tmp_val=0;
        for(int j=1;j<=M;j++){
            tmp_val += tmp[i][j];
        }
        val = min(val,tmp_val);
    }
}

void backTracking(int n){

    if(n>=K){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                tmp[i][j] = A[i][j];
            }
        }

        for(int i=0;i<order.size();i++){
            rotate(get<0>(v[order[i]]),get<1>(v[order[i]]),get<2>(v[order[i]]));
        }

        findMin();
        return;
    }

    for(int i=0;i<K;i++){
        if(visit[i])
            continue;
        visit[i] = true;
        order.push_back(i);
        backTracking(n+1);
        order.pop_back();
        visit[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> N >> M >> K;

    for(int i=1;i<=N;i++){
        int tmp_val=0;
        for(int j=1;j<=M;j++){
            cin >> A[i][j];
        }
    }

    

    for(int i=0;i<K;i++){
        cin >> r >> c >> s;
        v.push_back({r,c,s});
    }

    backTracking(0);

    cout << val;

    return 0;
}