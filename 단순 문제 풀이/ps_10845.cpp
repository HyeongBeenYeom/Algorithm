#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	queue<int> q;
	string s;
	int tmp;
	for(int i=0; i<N; i++){
		cin >> s;
		if(s == "push"){
			cin >> tmp;
			q.push(tmp);	
		}
		else if(s == "pop"){
			if(q.empty())
				cout << -1 << '\n';
			else{
				cout << q.front() << '\n';
				q.pop();	
			}
		}
		else if(s == "size")
			cout << q.size() << '\n';
		else if(s == "empty")
			cout << q.empty() << '\n';
		else if(s == "front"){
			if(q.empty())
				cout << -1 << '\n';
			else{
				cout << q.front() << '\n';	
			}
		}
		else if(s == "back"){
			if(q.empty())
				cout << -1 << '\n';
			else{
				cout << q.back() << '\n';
			}
		}		
	}
	return 0;
}