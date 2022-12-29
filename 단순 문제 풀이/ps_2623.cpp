#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> node[1001];
	queue<int> q;
	int ret[1001];
	int tmp=0;
	int condition[1001] = {0,};
	int N,M;
	int s,a,b;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> s >> a;
		for(int j=0;j<s-1;j++){
			cin >> b;
			node[a].push_back(b);
			condition[b]++;
			a=b;
		}
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
	if(tmp == N){
		for(int k=0;k<tmp;k++)
			cout << ret[k] << '\n';	
	}
	else
		cout<<0;
	
}