#include <cstdio>
#include <iostream>

using namespace std;

long long int A,B,C;

int dnq(int cnt){
    if(cnt == 1){
        return A%C;
    }
    if((cnt%2) == 0){
        return ((dnq(cnt/2)%C)*(dnq(cnt/2)%C)%C);
    }
    else{
        return ((dnq(cnt/2)%C)*(dnq(cnt/2)%C)%C)*A%C;
    }

}

int main(){
    
    long long int ret;
    cin >> A >> B >> C;
    
    ret = dnq(B);

    cout << ret;
    return 0;
}