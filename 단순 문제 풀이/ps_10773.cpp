#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int K;
	int tmp,ret=0;
	cin >> K;
	stack<int> s;
	for(int i=0;i<K;i++){
		cin >> tmp;
		if(tmp != 0){
			s.push(tmp);
		}
		else{
			if(!s.empty())
				s.pop();
		}
	}

	while(!s.empty()){
		ret += s.top();
		s.pop();
	}
	cout << ret;

	return 0;
}