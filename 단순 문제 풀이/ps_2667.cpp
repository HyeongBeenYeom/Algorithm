#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int map[26][26];
int ret=0;
int visit[26][26];
queue<pair<int,int>> q;
vector<int> v;
int x_dir[4] = {-1,1,0,0};
int y_dir[4] = {0,0,-1,1};
int num;

void BFS(int x, int y){
	num = 0;
	visit[x][y] = 1;
	q.push(make_pair(x,y));
	num++;

	while(!q.empty()){
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int x2 = x1 + x_dir[i];
			int y2 = y1 + y_dir[i];

			if((0<=x2&&x2<N) && (0<=y2 && y2 < N) && !visit[x2][y2] && map[x2][y2] == 1){
				visit[x2][y2] = 1;
				q.push(make_pair(x2,y2));
				num++;
			}
		}
	}
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0; j<N;j++){
			map[i][j] = s[j] - '0';
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]){
				if(!visit[i][j]){
					BFS(i,j);
					v.push_back(num);	
					ret++;			
				}
			}
		}
	}
	sort(v.begin(),v.end());
	cout << ret << '\n';
	for(int i=0;i<v.size();i++)
		cout << v[i] << '\n';
	return 0;
}