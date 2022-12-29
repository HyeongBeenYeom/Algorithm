#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int sudoku[10][10];
int R[10][10];
int C[10][10];
int area[10][10];

int dfs(int k){
	int x = k/9; // row
	int y = k%9; // column

	if(k == 81){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout << sudoku[i][j];
		}
		cout << '\n';
	}
		return 1;
	}

	if(sudoku[x][y] == 0){
		for(int i=1;i<=9;i++){
			if(R[x][i] == 0 && C[y][i] == 0 && area[(x/3)*3 + (y/3)][i] == 0){
				R[x][i] = 1;
				C[y][i] = 1;
				area[(x/3)*3 + (y/3)][i] = 1;
				sudoku[x][y] = i;
				if(dfs(k+1))
					return 1;
				R[x][i] = 0;
				C[y][i] = 0;
				area[(x/3)*3 + (y/3)][i] = 0;
				sudoku[x][y] = 0;
			}
		}
	}
	else
		return dfs(k+1);

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	string tmp;

	for(int i=0;i<9;i++){
		cin >> tmp;
		for(int j=0;j<9;j++){
			sudoku[i][j] = tmp[j] - '0';
			if(sudoku[i][j] != 0){
				R[i][sudoku[i][j]] = 1;
				C[j][sudoku[i][j]] = 1;
				area[(i/3) * 3 + (j/3)][sudoku[i][j]] = 1;
			}
		}
	}

	dfs(0);
	return 0;
}	