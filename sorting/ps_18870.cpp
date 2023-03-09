#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> input_num;
vector<int> tmp;

int main(){

    int N;
    cin >> N;
    int num;
    for(int i=0;i<N;i++){
        cin >> num;
        input_num.push_back(num);
        tmp.push_back(num);
    }
    
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()),tmp.end());

    for(int i=0;i<N;i++){        
        cout << lower_bound(tmp.begin(), tmp.end(), input_num[i]) - tmp.begin() << ' ';
    }

    return 0;
}