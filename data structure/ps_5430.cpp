#include <cstdio>
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T,n;
string p,x;

int main(){
    cin >> T;

    for(int t=0;t<T;t++){
        deque<int> dq;
        cin >> p;
        cin >> n;
        cin >> x;
        string tmp = "";
        bool R=false,error=false;

        for(int i=0;i<x.size();i++){
            if(isdigit(x[i]))
                tmp += x[i];
            else{
                if(!tmp.empty()){
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        for(int i=0;i<p.size();i++){
            if(p[i] == 'R'){
                if(R)
                    R=false;
                else
                    R=true;
            }
            else{
                if(!dq.empty()){
                    if(R)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
                else{
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
            }
        }
        if(!error){
            cout << '[';
            if(R && !dq.empty()){
                for(auto iter = dq.rbegin(); iter!=dq.rend(); iter++){
                    if(iter == dq.rend()-1)
                        cout << *iter;
                    else
                        cout << *iter << ',';
                }
            }
            else if(!R && !dq.empty()){
                for(auto iter = dq.begin(); iter!=dq.end(); iter++){
                    if(iter == dq.end()-1)
                        cout << *iter;
                    else
                        cout << *iter << ',';
                }
            }
            cout << ']' << '\n';
        }            
    }    
    return 0;
}