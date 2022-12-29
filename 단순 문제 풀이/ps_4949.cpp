#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(1){
		string tmp;
		getline(cin, tmp);

		if(tmp == ".")
			break;

		stack<char> s;
		int flag = 0;

		for(int i=0;i<tmp.length();i++){
			char c = tmp[i];

			if((c == '(' || c == '[')){
				s.push(c);
			}
			else if(c == ')'){
				if(!s.empty() && s.top() == '(')
					s.pop();
				else{
					flag = 1;
					break;
				}
			}
			else if(c==']'){
				if(!s.empty() && s.top() == '[')
					s.pop();
				else{
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0 && s.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}


	return 0;
}