#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int M, D;
    int days = 0;
    int ret;

    scanf("%d %d", &M, &D);

    int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i<M-1; i++){
        days += Month[i];
    }

    days += D;
    ret = days % 7;
    switch(ret){
        case 1:
            printf("MON");
            break;
        case 2:
            printf("TUE");
            break;
        case 3:
            printf("WED");
            break;
        case 4:
            printf("THU");
            break;
        case 5:
            printf("FRI");
            break;
        case 6:
            printf("SAT");
            break;
        case 0:
            printf("SUN");
            break;
    }
    
    return 0;
}