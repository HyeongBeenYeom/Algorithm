#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;

	stack<int> s;
	string tmp;

	for(int i=0;i<N;i++){
		cin >> tmp;

		if(tmp == "push"){
			int num;
			cin >> num;
			s.push(num);
		}
		else if(tmp ==  "pop"){
			if(!s.empty()){
				cout << s.top() << '\n';
				s.pop();
			}
			else{
				cout << "-1" << '\n';
			}
		}
		else if(tmp == "size"){
			cout << s.size() << '\n';
		}
		else if(tmp == "empty"){
			if(s.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if(tmp == "top"){
			if(!s.empty())
				cout << s.top() << '\n';
			else
				cout << "-1" << '\n';
		}
	}
	return 0;
}