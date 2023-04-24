#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;
int N,K;
string s;
deque<char> d;

int main(){
    cin >> N >> K;    
    cin >> s;

    for (int i=0;i<N;i++) {
        while (!d.empty() && K && d.back() < s[i]) {
            d.pop_back();
            K--;
        }
        d.push_back(s[i]);
    }

    for (int i=0;i<d.size()-K;i++){
        cout << d[i];
    }

    return 0;
}