#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	stack<int> s;
	vector<char> ret;
	int N;
	cin >> N;
	int num = 1;
	int a;
	for(int i=0;i<N;i++){
		cin >> a;
		while(num <= a){
			s.push(num);
			num++;
			ret.push_back('+');
		}
		if(s.top() == a){
			s.pop();
			ret.push_back('-');
		}
		else{
			cout << "NO";
			return 0;
		}

	}

	for(int i=0;i<ret.size();i++){
		cout << ret[i] << '\n';
	}

	return 0;
}