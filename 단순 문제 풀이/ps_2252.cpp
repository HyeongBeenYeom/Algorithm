#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	int N,M;
	cin >> N >> M;

	vector<int> node[32001];
	queue<int> q;
	int tmp=0;
	int ret[32001];
	int condition[32001] = {0,};
	int a,b;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		node[a].push_back(b);
		condition[b]++;
	}
	for(int i=1;i<=N;i++){
		if(condition[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int idx = q.front();
		ret[tmp++] = q.front();
		q.pop();

		for(int i=0;i<node[idx].size();i++){
			int next = node[idx][i];
			condition[next]--;

			if(condition[next] == 0)
				q.push(next);
		}
	}
	for(int i=0;i<tmp;i++){
		cout << ret[i] << ' ';
	}
}