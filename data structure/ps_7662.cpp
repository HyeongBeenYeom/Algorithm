#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int T,k;
    cin >> T;
    
    string str;
    int n;
    for(int t=0;t<T;t++){
        cin >> k;
        multiset<int> ms;
        for(int i=0;i<k;i++){
            cin >> str >> n;
            if(str == "I"){
                ms.insert(n);
            }
            else if(!ms.empty() && n == -1){                
                ms.erase(ms.begin());
            }
            else if(!ms.empty() && n == 1){
                auto a = ms.end();
                a--;
                ms.erase(a);
            }
        }
        if(!ms.empty()){
            auto b = ms.end();
            b--;
            cout << *b << ' ' << *ms.begin() << '\n';
        }
        else
            cout << "EMPTY" << '\n';
    }
    return 0;
}