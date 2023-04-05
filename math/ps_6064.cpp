#include <cstdio>
#include <iostream>

using namespace std;
int GCD(int a, int b){
    while(b != 0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int LCM(int a, int b){
    return (a*b)/GCD(a,b);
}

int main(){
    int T;
    cin >> T;
    int M,N,x,y,i;
    for(int t=0;t<T;t++){
        cin >> M >> N >> x >> y;
        int last = LCM(M,N);
        for(i=x;i<=last;i += M){
            int tmp;
            if(i%N==0){
                tmp = N;
            }
            else
                tmp = i%N;

            if(tmp == y){
                cout << i << '\n';
                break;
            }
        }
        if(i>last)
            cout << -1 << '\n';
    }
    return 0;
}