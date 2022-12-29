#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N,M;
int maze[101][101];
int visit[101][101];
int num[101][101];
queue<pair<int,int>> q;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};

void BFS(int n, int m){
	visit[n][m] = 1;
	q.push(make_pair(n,m));
	num[n][m]++;

	while(!q.empty()){

		int n1 = q.front().first;
		int m1 = q.front().second;

		q.pop();

		for(int i=0;i<4;i++){
			int n2 = n1 + x[i];
			int m2 = m1 + y[i];

			if((0<=n2 && n2 <N) && (0<=m2 && m2 < M) && !visit[n2][m2] && maze[n2][m2] == 1){
				visit[n2][m2] = 1;
				q.push(make_pair(n2,m2));
				num[n2][m2] = num[n1][m1] + 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> N >> M;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<M;j++)
			maze[i][j] = s[j] - '0';
	}

	BFS(0,0);

	cout << num[N-1][M-1];
	return 0;
}