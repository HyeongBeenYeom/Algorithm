#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string str;

int main(){
    cin >> str;
    int ret=0;
    string tmp;
    bool flag=false;

    for(int i=0;i<=str.size();i++){
        if(str[i] == '-' || str[i] == '+' || i == str.size()){
            if(flag){
                ret -= stoi(tmp);
                tmp = "";
            }
            else{
                ret += stoi(tmp);
                tmp = "";
            }
        }
        else
            tmp += str[i];

        if(str[i] == '-')
            flag = true;
    }

    cout << ret;
    return 0;
}