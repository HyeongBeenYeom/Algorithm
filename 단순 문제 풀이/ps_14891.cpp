#include <iostream>
#include <cstdio>

using namespace std;
int is_Spin = 0;

void Spin_clockwise(int arr1[], int arr2[], int idx_1, int idx_2){
    if(idx_1 + 2 > 7){
        if(idx_2 + 6 > 7){
            if(arr1[idx_1 - 6] != arr2[idx_2 - 2]){
                is_Spin += 1;
            }
        }
        else{
            if(arr1[idx_1 - 6] != arr2[idx_2 + 6]){
                is_Spin += 1;
            }    
        }
    }
    else{
        if(idx_2 + 6 > 7){
            if(arr1[idx_1 + 2] != arr2[idx_2 - 2]){
                is_Spin += 1;
            }    
        }
        else{
            if(arr1[idx_1 + 2] != arr2[idx_2 + 6]){
                is_Spin += 1;
            }    
        }        
    }
}

int main()
{
    int g1[8];
    int g2[8];
    int g3[8];
    int g4[8];
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    int idx4 = 0;
    int K, gear, s;
    int ret=0;
    int spin1 = 0;
    int spin2 = 0;
    int spin3 = 0;
    int spin4 = 0;

    for(int i=0; i<8; i++){
        scanf("%1d", &g1[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &g2[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &g3[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &g4[i]);
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        scanf("%d %d", &gear, &s);
        switch(gear){
            case 1:
                if(s==1){
                    Spin_clockwise(g1, g2, idx1, idx2);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin2 += 1;
                        Spin_clockwise(g2, g3, idx2, idx3);
                        if(is_Spin == 1){
                            is_Spin -= 1;
                            spin3 += 1;
                            Spin_clockwise(g3, g4, idx3, idx4);
                        }
                        if(is_Spin == 1){
                            is_Spin -=1;
                            spin4 +=1;
                        }
                    }
                    if(idx1 == 0){
                        idx1 += 7;
                    }
                    else{
                        idx1 -= 1;
                    }
                    if(spin2 == 1){
                        if(idx2 == 7){
                            idx2 -= 7;
                        }
                        else{
                            idx2 += 1;
                        }
                        spin2 -= 1;
                    }
                    if(spin3 == 1){
                        if(idx3 == 0){
                            idx3 += 7;
                        }
                        else{
                            idx3 -= 1;
                        }
                        spin3 -= 1;
                    }
                    if(spin4 == 1){
                        if(idx4 == 7){
                            idx4 -= 7;
                        }
                        else{
                            idx4 += 1;
                        }
                        spin4 -= 1;
                    }
                }
                else{
                    Spin_clockwise(g1, g2, idx1, idx2);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin2 += 1;
                        Spin_clockwise(g2, g3, idx2, idx3);
                        if(is_Spin == 1){
                            is_Spin -= 1;
                            spin3 += 1;
                            Spin_clockwise(g3, g4, idx3, idx4);
                            if(is_Spin == 1){
                                is_Spin -= 1;
                                spin4 += 1;
                            }
                        }                                   
                    }
                    if(idx1 == 7){
                        idx1 -= 7;
                    }
                    else{
                        idx1 += 1;
                    }
                    if(spin2 == 1){
                        if(idx2 == 0){
                            idx2 += 7;
                        }
                        else{
                            idx2 -= 1;
                        }
                        spin2 -= 1;
                    }
                    if(spin3 == 1){
                        if(idx3 == 7){
                            idx3 -= 7;
                        }
                        else{
                            idx3 += 1;
                        }
                        spin3 -= 1;
                    }
                    if(spin4 == 1){
                        if(idx4 == 0){
                            idx4 += 7;
                        }
                        else{
                            idx4 -= 1;
                        }
                        spin4 -= 1;
                    }         
                }
                break;
            case 2:
                if(s==1){
                    Spin_clockwise(g1, g2, idx1, idx2);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin1 += 1;
                    }                        
                    Spin_clockwise(g2, g3, idx2, idx3);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin3 += 1;
                        Spin_clockwise(g3, g4, idx3, idx4);
                        if(is_Spin == 1){
                            is_Spin -= 1;
                            spin4 += 1;
                        }
                    }
                    if(idx2 == 0){
                        idx2 += 7;
                    }
                    else{
                        idx2 -= 1;
                    }
                    if(spin1 == 1){
                        spin1 -=1;
                        if(idx1 == 7){
                            idx1 -= 7;
                        }
                        else{
                            idx1 += 1;
                        }
                    }                 
                    if(spin3 == 1){
                        spin3 -= 1;
                        if(idx3 == 7){
                            idx3 -= 7;
                        }
                        else{
                            idx3 += 1;
                        }
                    }   
                    if(spin4 == 1){
                        spin4 -= 1;
                        if(idx4 == 0){
                            idx4 += 7;
                        }
                        else{
                            idx4 -= 1;
                        }
                    }
                }
                else{
                    Spin_clockwise(g1, g2, idx1, idx2);
                    if(is_Spin == 1){
                        is_Spin -=1;
                        spin1 += 1;
                    }
                    Spin_clockwise(g2, g3, idx2, idx3);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin3 +=1;
                        Spin_clockwise(g3, g4, idx3, idx4);
                        if(is_Spin == 1){
                            is_Spin -=1;
                            spin4 += 1;
                        }
                    }
                    if(idx2 == 7){
                        idx2 -= 7;
                    }
                    else{
                        idx2 += 1;
                    }
                    if(spin1 == 1){
                        spin1 -=1;
                        if(idx1 == 0){
                            idx1 += 7;
                        }
                        else{
                            idx1 -= 1;
                        }
                    }
                    if(spin3 == 1){
                        spin3 -= 1;
                        if(idx3 == 0){
                            idx3 += 7;
                        }
                        else{
                            idx3 -= 1;
                        }
                    }
                    if(spin4 == 1){
                        spin4 -= 1;
                        if(idx4 == 7){
                            idx4 -= 7;
                        }
                        else{
                            idx4 += 1;
                        }
                    }
                }
                break;
            case 3:
                if(s==1){
                    Spin_clockwise(g3, g4, idx3, idx4);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin4 += 1;
                    }
                    Spin_clockwise(g2, g3, idx2, idx3);
                    if(is_Spin ==1){
                        is_Spin -= 1;
                        spin2 += 1;
                        Spin_clockwise(g1, g2, idx1, idx2);
                        if(is_Spin == 1){
                            is_Spin -=1;
                            spin1 += 1;
                        }
                    }
                    if(idx3 == 0){
                        idx3 += 7;
                    }
                    else{
                        idx3 -= 1;
                    }
                    if(spin4 == 1){
                        spin4 -=1;
                        if(idx4 == 7){
                            idx4 -= 7;
                        }
                        else{
                            idx4 += 1;
                        }
                    }                 
                    if(spin2 == 1){
                        spin2 -= 1;
                        if(idx2 == 7){
                            idx2 -= 7;
                        }
                        else{
                            idx2 += 1;
                        }
                    }   
                    if(spin1 == 1){
                        spin1 -= 1;
                        if(idx1 == 0){
                            idx1 += 7;
                        }
                        else{
                            idx1 -= 1;
                        }
                    }
                }
                else{
                    Spin_clockwise(g3, g4, idx3, idx4);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin4 += 1;
                    }
                    Spin_clockwise(g2, g3, idx2, idx3);
                    if(is_Spin == 1){
                        is_Spin -=1;
                        spin2 += 1;
                        Spin_clockwise(g1, g2, idx1, idx2);
                        if(is_Spin == 1){
                            is_Spin -=1;
                            spin1 += 1;
                        }
                    }
                    if(idx3 == 7){
                        idx3 -= 7;
                    }
                    else{
                        idx3 += 1;
                    }
                    if(spin4 == 1){
                        spin4 -=1;
                        if(idx4 == 0){
                            idx4 += 7;
                        }
                        else{
                            idx4 -= 1;
                        }
                    }
                    if(spin2 == 1){
                        spin2 -= 1;
                        if(idx2 == 0){
                            idx2 += 7;
                        }
                        else{
                            idx2 -= 1;
                        }
                    }
                    if(spin1 == 1){
                        spin1 -= 1;
                        if(idx1 == 7){
                            idx1 -= 7;
                        }
                        else{
                            idx1 += 1;
                        }
                    }                    
                }
                break;
            case 4:
                if(s==1){
                    Spin_clockwise(g3, g4, idx3, idx4);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin3 += 1;
                        Spin_clockwise(g2, g3, idx2, idx3);
                        if(is_Spin == 1){
                            is_Spin -= 1;
                            spin2 += 1;
                            Spin_clockwise(g1, g2, idx1, idx2);
                            if(is_Spin == 1){
                                is_Spin -= 1;
                                spin1 += 1;
                            }
                        }
                    }
                    if(idx4 == 0){
                        idx4 += 7;
                    }
                    else{
                        idx4 -= 1;
                    }
                    if(spin3 == 1){
                        if(idx3 == 7){
                            idx3 -= 7;
                        }
                        else{
                            idx3 += 1;
                        }
                        spin3 -= 1;
                    }
                    if(spin2 == 1){
                        if(idx2 == 0){
                            idx2 += 7;
                        }
                        else{
                            idx2 -= 1;
                        }
                        spin2 -= 1;
                    }
                    if(spin1 == 1){
                        if(idx1 == 7){
                            idx1 -= 7;
                        }
                        else{
                            idx1 += 1;
                        }
                        spin1 -= 1;
                    }                    
                }
                else{
                    Spin_clockwise(g3, g4, idx3, idx4);
                    if(is_Spin == 1){
                        is_Spin -= 1;
                        spin3 += 1;
                        Spin_clockwise(g2, g3, idx2, idx3);
                        if(is_Spin == 1){
                            is_Spin -= 1;
                            spin2 += 1;
                            Spin_clockwise(g1, g2, idx1, idx2);
                            if(is_Spin == 1){
                                is_Spin -= 1;
                                spin1 += 1;
                            }
                        }                       
                    }
                    if(idx4 == 7){
                        idx4 -= 7;
                    }
                    else{
                        idx4 += 1;
                    }
                    if(spin3 == 1){
                        if(idx3 == 0){
                            idx3 += 7;
                        }
                        else{
                            idx3 -= 1;
                        }
                        spin3 -= 1;
                    }
                    if(spin2 == 1){
                        if(idx2 == 7){
                            idx2 -= 7;
                        }
                        else{
                            idx2 += 1;
                        }
                        spin2 -= 1;
                    }
                    if(spin1 == 1){
                        if(idx1 == 0){
                            idx1 += 7;
                        }
                        else{
                            idx1 -= 1;
                        }
                        spin1 -= 1;
                    }                      
                }
                break;
        }
    }
    if(g1[idx1]==1){
        ret += 1;
    }
    if(g2[idx2]==1){
        ret += 2;
    }
    if(g3[idx3]==1){
        ret +=4;
    }
    if(g4[idx4]==1){
        ret += 8;
    }
    printf("%d\n",ret);
    return 0;
}