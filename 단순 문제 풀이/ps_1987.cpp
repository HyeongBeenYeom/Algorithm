#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
int result = 0;
char board[20][20];
int visit[26];

void dfs(int x, int y, int ret){
	result = max(result,ret);
	for(int i=0;i<4;i++){
		switch(i){
			case 0:
				if(x+1<R && y < C && x+1>=0 && y>=0){
					if(visit[board[x+1][y] - 'A'] == 0){
						visit[board[x+1][y] - 'A'] = 1;
						dfs(x+1,y,ret + 1);
						visit[board[x+1][y] - 'A'] = 0;
					}
				}
				break;
			case 1:
				if(x-1>=0 && y>=0 && x-1<R && y<C){
					if(visit[board[x-1][y] - 'A'] == 0){
						visit[board[x-1][y] - 'A'] = 1;
						dfs(x-1,y,ret + 1);
						visit[board[x-1][y] - 'A'] = 0;
					}
				}
				break;
			case 2:
			if(x<R && y+1 <C && x>=0 && y+1 >=0){
				if(visit[board[x][y+1]-'A'] == 0){
					visit[board[x][y+1] - 'A'] = 1;
					dfs(x,y+1,ret + 1);
					visit[board[x][y+1] - 'A'] = 0;
				}
			}
				break;
			case 3:
				if(x>=0 && y-1 >=0 && x<R && y-1 <C){
					if(visit[board[x][y-1] - 'A'] == 0){
						visit[board[x][y-1] - 'A'] = 1;
						dfs(x,y-1,ret + 1);
						visit[board[x][y-1] - 'A'] = 0;
					}
				}
				break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);


	cin >> R >> C;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> board[i][j];
		}
	}

	visit[board[0][0] - 'A'] = 1;
	dfs(0,0,1);

	cout << result;
}