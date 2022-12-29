//DFS와 BFS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> g[1001];
int visit[1001] = {0,};

void BFS(int n){
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while(!q.empty()) {
	    int a = q.front();
	    q.pop();
	    cout << a << " ";
	    for(int i=0;i<g[a].size();i++){
	    	if(!visit[g[a][i]]){
	    		q.push(g[a][i]);
	    		visit[g[a][i]] = 1;
	    	}
	    }
	}
}

void DFS(int n){
	visit[n] = 1;
	cout << n << " ";
	for(int i=0;i<g[n].size();i++){
		if(!visit[g[n][i]])
			DFS(g[n][i]);
	}
}

int main(){
	int N,M,V,start,end;
	cin >> N >> M >> V;

	for(int i=0;i<M;i++){
		cin >> start >> end;
		g[start].push_back(end);
		g[end].push_back(start);
	}
	for(int i=1;i<=N;i++){
		sort(g[i].begin(), g[i].end());
	}

	DFS(V);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	BFS(V);

	return 0;
}