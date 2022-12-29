#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int num[3];

    while(1){
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if(num[0] == 0 && num[1] == 0 && num[2] == 0)
            break;
        sort(num, num+3);

        printf(pow(num[2],2) == pow(num[1],2) + pow(num[0],2) ? "right\n": "wrong\n");

        
    }
}