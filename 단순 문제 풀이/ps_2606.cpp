#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V,E;
vector<int> v[101];
int check[101];
int ret=0;
void DFS(int a){
	check[a] = 1;
	for(int i=0;i<v[a].size();i++){
		int b = v[a][i];
		if(!check[b]){
			DFS(b);
			ret++;
		}
	}
}

int main(){
	cin >> V >> E;

	for(int i=0;i<E;i++){
		int n,m;
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}
	DFS(1);

	cout << ret;

	return 0;
}