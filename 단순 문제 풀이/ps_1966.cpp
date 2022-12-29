#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T;
	cin >> T;
	
	int count,N,M,V;
	for(int i=0;i<T;i++){
		count = 0;
		cin >> N >> M;
		queue<pair<int,int>> q;
		priority_queue<int> pq;	
		for(int j=0;j<N;j++){
			cin >> V;
			q.push({j,V});
			pq.push(V);
		}
		while(!q.empty()){
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if(pq.top() == val){
				pq.pop();
				++count;
				if(idx == M){
					cout << count << '\n';
					break;
				}
			}
			else q.push({idx,val});
		}
	}
	return 0;
}