//위상정렬
//ACM Craft

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T,N,K,W;
int time[1001] = {0,};

int main(){
	cin >> T;

	int a,b;

	for(int i=0;i<T;i++){
		int ret=0;
		cin >> N >> K;
		for(int j=1;j<=N;j++){
			cin >> time[j];
		}
		vector<int> node[1001];
		int condition[1001] = {0,};
		queue<int> q;
		int cost[1001] = {0,};
		for(int j=0;j<K;j++){
			cin >> a >> b;
			node[a].push_back(b);
			condition[b]++;
		}
		
		cin >> W;
		for(int j=1;j<=N;j++){
			if(condition[j] == 0)
				q.push(j);
			cost[j] = time[j];
		}

		while(!q.empty()){
			int idx = q.front();
			q.pop();

			for(int j=0; j<node[idx].size();j++){
				int next = node[idx][j];
				condition[next]--;
				cost[next] = max(cost[next], cost[idx]+time[next]);

				if(condition[next] == 0)
					q.push(next);
			}
		}
		cout << cost[W] << '\n';
	}
}